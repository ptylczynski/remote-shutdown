//
// Created by piotr on 03.12.2020.
//
#include <stdio.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <zconf.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <wait.h>
#include <pthread.h>
#include "utils/simple-message.h"


#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"

const int PORT = 7021;
const char * SECRET = "super_secret";

enum ACTION {STOP, SUSPEND, UNRECOGNIZED};

// describe incoming connection
struct client {
    int client_desc;
    struct sockaddr_in address;
};

// reads data from clien and transforms them into Simple Message
struct SimpleMessage readData(struct client * clnt){
    // already collected data
    char * data = "";
    // last fetched character
    char last = ' ';
    // grand total of fetched characters
    int size = 0;
    // read on char at once until termination sign found
    while(last != '}'){
        read(clnt->client_desc, &last, 1);
        data = appendc(data, last);
        size++;
    }
    return SM_Deserialize(data);
}

// flattens and send data back to client
void writeData(struct client * clnt, struct SimpleMessage * simpleMessage, int size){
    char * data = SM_Serialize(simpleMessage, size);
    write(clnt->client_desc, data, strlen(data));
}

// find key action and check what is written under it
enum ACTION checkAction(struct SimpleMessage * simpleMessage){
    // number of messages sent by user
    int size = getSize(simpleMessage);
    // value under action key
    char * action = findValue(simpleMessage, "action", size);
    // check what is it
    if(strcmp(action, "STOP") == 0) return STOP;
    else if(strcmp(action, "SUSPEND") == 0) return SUSPEND;
    else return UNRECOGNIZED;
}

// check if secret sends by user is same as set by administrator
int checkSecret(struct SimpleMessage * simpleMessage){
    int size = getSize(simpleMessage);
    char * secret = findValue(simpleMessage, "secret", size);
    if(strcmp(secret, SECRET) == 0) return 1;
    else return 0;
}

// mock stopping of computer
void stop(){
    // system("shutdown -P now");
    printf("Shutting down");
}

// mock hibernation of system
void suspend(){
    printf("Suspending");
}

// sends Simple message with action key response and given message
void sendResponse(char * message, struct client * clnt){
    // c dont allows to staticaly init with variables
    struct SimpleMessage sm = {
            {"action", "message"},
            {"response"}
    };
    // soo memes (xD) copy is used
    memcpy(sm.values[1], message, strlen(message));
    // send memes to user
    writeData(clnt, &sm, 2);
}

void makeAction(enum ACTION action, struct client * clnt){
    switch(action){
        case SUSPEND: {
            sendResponse("Suspending system", clnt);
            suspend();
            break;
        }
        case STOP: {
            sendResponse("Stopping system", clnt);
            stop();
            break;
        }
        default: {
            sendResponse("Unrecognized action", clnt);
            break;
            // do nothing
        }
    }
}

// for each new request server spawns new worker as pthread
void* worker(void* arguments){
    // cast args into client structure
    struct client* c = (struct client*) arguments;
    // inflate data sent by user
    struct SimpleMessage sm = readData(c);
    // authorize user
    if(checkSecret(&sm) == 0) sendResponse("Wrong secret", c);
    else{
        // make proper action
        enum ACTION action = checkAction(&sm);
        makeAction(action, c);
    }
    // writeData(c, &sm, 2);
    close(c->client_desc);
}

int server(){
    int server_desc = socket(AF_INET, SOCK_STREAM, 0);
    int client_desc;
    int on = 1;
    struct sockaddr_in server_addr, client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    // create socket
    setsockopt(server_desc, SOL_SOCKET, SO_REUSEADDR, (char*) &on, sizeof(on));
    // bind to socket
    bind(server_desc, (struct sockaddr*) &server_addr, sizeof(server_addr));
    // start listening for incoming connections
    listen(server_desc, 5);
    while(1){
        // create pthread instance in advance
        pthread_t thread_id;
        // precreate client struct
        struct client* c = malloc(sizeof(struct client*));
        unsigned int cld = sizeof(client_desc);
        // accept new connection and finalize creation of descriptors and threads
        c->client_desc = accept(server_desc, (struct sockaddr*) &c->address, &cld);
        // start and detach thread
        pthread_create(&thread_id, NULL, worker, c);
        pthread_detach(thread_id);
    }
    close(server_desc);
    return EXIT_SUCCESS;
}
#pragma clang diagnostic pop

