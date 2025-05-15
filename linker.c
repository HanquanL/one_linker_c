#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

bool ifDetail = false;

int main(int argc, char *argv[]){
    int c;
    int ch;
    FILE *inputFile;

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
    while((ch = getc(inputFile)) != EOF){
        printf("%c", ch);
    }
    fclose(inputFile);
    return 0;
}