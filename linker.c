#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h> // for isappha(), isdigit() etc.

bool ifDetail = false;
int lineNumber = 0;
int charNumber = 0;
FILE *inputFile;

char *getToken();

int main(int argc, char *argv[]){
    int c;
    char *token;

    while((c = getopt(argc, argv, "d")) != -1){
        switch(c){
            case 'd':
                ifDetail = true;
                break;
            default:
                abort();
        }
    }
    if((inputFile = fopen(argv[argc - 1], "r")) ==NULL){
        printf("Error: Cannot open file %s\n", argv[-1]);
        exit(EXIT_FAILURE);
    }
    while((token = getToken()) != NULL){
        printf("token=<%s> positon=%d:%d\n", token, lineNumber, charNumber);
    }
    printf("EOF position %d:%d\n", lineNumber, charNumber);
    return 0;
}

char *getToken(){
    char* token;
    fgets(token, 2, inputFile);
    charNumber++;
    if(token[0] == '\n'){
        lineNumber++;
        charNumber = 0;
    }
    return token;
};