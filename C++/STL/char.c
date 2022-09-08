#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

int getMinTotalNumChanges(char* oldPassStr, char* newPassStr) {
    int i = 0, changes = 0, flag = 0;
    int oldPassHash[128]= {0}, newPassHash[128]={0};
    
  
    
    
    while(oldPassStr[i] != '\0'){
        ++oldPassHash[(int)oldPassStr[i]];
        ++i;
    }
    i=0;
    while(newPassStr[i] != '\0'){
        ++newPassHash[(int)newPassStr[i]];
        ++i;
    }
    
    for(i=0;i<128;++i){
        if( oldPassHash[i] != 0 && newPassHash[i]!= 0 && oldPassHash[i] != newPassHash[i]){
            changes++;
        }       
    }
    return changes;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* oldPassStr = readline();

    char* newPassStr = readline();

    int result = getMinTotalNumChanges(oldPassStr, newPassStr);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}