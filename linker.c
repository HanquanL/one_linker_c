#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h> // for isappha(), isdigit() etc.

#define MAX_STR_LEN 1024

bool ifDetail = false;
int lineNumber = 1;
int charNumber = 1;
FILE *inputFile;

char *getToken();

int main(int argc, char *argv[])
{
    int c;
    char *token;

    while ((c = getopt(argc, argv, "d")) != -1)
    {
        switch (c)
        {
        case 'd':
            ifDetail = true;
            break;
        default:
            abort();
        }
    }
    if ((inputFile = fopen(argv[argc - 1], "r")) == NULL)
    {
        printf("Error: Cannot open file %s\n", argv[argc - 1]);
        exit(EXIT_FAILURE);
    }
    printf("Symbol Table\n");
    // while((token = getToken()) != NULL){
    //     printf("token=<%s> positon=%d:%d\n", token, lineNumber, charNumber);
    // }
    // printf("EOF position %d:%d\n", lineNumber, charNumber);
    if (!ifDetail)
    {
        printf("Memory Map\n");
    }
    else
    {
        printf("Memory Map| Label | Instr -> Explanation | Warn/Errors\n");
        printf("-------------------------------------------------------\n");
    }
    return 0;
}

char *getToken()
{
    char tempToken[MAX_STR_LEN];

    return NULL;
}