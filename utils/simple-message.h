//
// Created by piotr on 03.12.2020.
//
#include <stdlib.h>
#include <string.h>
#include "stringops.h"

// const int MESSAGES = 20;
// number of messages in on run
#define MESSAGES 20
// const int MESSAGE_SIZE = 200;
// max single message length
#define MESSAGE_SIZE 200

// each key-value pair have LINE_DELIMITER
const char * MESSAGE_LINE_DELIMITER = "\n";
// before any key-value pair header occurs
const char * MESSAGE_HEADER = "{\n";
// after last key-value pair footrt is inserted
const char * MESSAGE_FOOTER = "}";
// each key-value pair has delimiter
const char * FIELDS_DELIMITER = ":";
// maximal size of single serialized message
const int SERIALIZED_SIZE = 20*20*200 + 200;

// message passed between clients and server
struct SimpleMessage {
    char keys[MESSAGES][MESSAGE_SIZE];
    char values[MESSAGES][MESSAGE_SIZE];
};

// serialize simple message int string =
char * SM_Serialize(struct SimpleMessage * message, int size){
    char * result = "";
    // insert header
    result = append(result, MESSAGE_HEADER);
    // put rest of key-value pairs
    for(int i = 0; i < size; i++){
        result = append(result, message->keys[i]);
        result = append(result, FIELDS_DELIMITER);
        result = append(result, message->values[i]);
        result = append(result, MESSAGE_LINE_DELIMITER);
    }
    // add footer
    result = append(result, MESSAGE_FOOTER);
    return result;
}

// inflate string into simple message
struct SimpleMessage SM_Deserialize(char * string){
    // remove header and footer
    string = substring(string, 0, strlen(string) - strlen(MESSAGE_FOOTER));
    string = substring(string, strlen(MESSAGE_HEADER) - 1, strlen(string));
    // new line mark is begin leaved as it's also line delimiter
    // each next key-value pair begins with delimiter so first
    // inedx used to track position in newly forming
    // tuple like key-value pairs
    int idx = 0;
    char keys[MESSAGES][MESSAGE_SIZE];
    char values[MESSAGES][MESSAGE_SIZE];
    // previously found delimiter position
    int lastPos = 0;
    // next delimiter position
    int findAt = find(string, '\n', lastPos + 1);;
    while(findAt != -1){
        // single line without new line chars
        char * keyValuePair = substring(string, lastPos + 1, findAt);
        // delimiter pos
        int delimiterPos = find(keyValuePair, ':', 0);
        // separation of key and value
        // no further casting is made as there is no culprits to decide upon things
        char * key = substring(keyValuePair, 0, delimiterPos);
        char * value = substring(keyValuePair, delimiterPos + 1, strlen(keyValuePair));
        // put on indexes new values
        // simple assignment is not enough
        strcpy(values[idx], value);
        strcpy(keys[idx], key);
        idx++;
        lastPos = findAt;
        findAt = find(string, '\n', findAt + 1);
    }
    // form new SM
    struct SimpleMessage sm;
    // as previously simple assignment is insufficient
    memcpy(sm.keys, keys, sizeof(char) * MESSAGES * MESSAGE_SIZE);
    memcpy(sm.values, values, sizeof(char) * MESSAGES * MESSAGE_SIZE);
    return sm;
}

// find value for given key
char * findValue(struct SimpleMessage * simpleMessage, char * key, int size){
    // marks if key was found
    int found = 0;
    // tracks pos of key
    int idx = 0;
    while(found == 0){
        if(strcmp(simpleMessage->keys[idx], key) == 0) found = 1;
        else idx++;
    }
    return simpleMessage->values[idx];
}

// get number of messages in SM
int getSize(struct SimpleMessage * simpleMessage){
    int size = 0;
    while(strcmp(simpleMessage->keys[size], "") != 0) size++;
    return size;
}

