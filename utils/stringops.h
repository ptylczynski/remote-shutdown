//
// Created by piotr on 03.12.2020.
//
#include <stdlib.h>
#include <string.h>

// wrapper to append dest string into source string
// returns concat of strings
char * append(char * src, char * dest){
    // 1 for null terminator
    char * tmp = (char *) malloc(1 + strlen(src)+ strlen(dest));
    strcpy(tmp, src);
    strcat(tmp, dest);
    return tmp;
}

// same as append but destination is char
char * appendc(char * src, char dst){
    char * tmp = (char *) malloc(1 + strlen(src)+ 1);
    strcpy(tmp, src);
    tmp[strlen(src)] = dst;
    return tmp;
}

// returns position of char in source string with given offset
int find(char * source, char c, int offset){
    char * pos = strchr(source + offset, c);
    if(pos == NULL) return -1;
    else return pos - source;
}

// create a substring of given string
char * substring(char * source, const int begin, const int end){
    char * subbuff = (char *) malloc(end - begin + 1);
    memcpy( subbuff, source + begin, end - begin + 1);
    subbuff[end - begin] = '\0';
    return subbuff;
}
