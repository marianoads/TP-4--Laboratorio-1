
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int valor;
    int returnScanf;
    int error = -1;

    printf("%s ", message);
    returnScanf = scanf("%d", &valor);

    while(returnScanf == 0 || valor < lowLimit || valor > hiLimit)
    {

        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        returnScanf = scanf("%d", &valor);
    }

    *input = valor;
    error = 0;

    return error;
}

int getNombre(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char valor[50];
    int error = -1;

    printf("%s ", message);
    fflush(stdin);
    gets(valor);

    while(strlen(valor) < lowLimit || strlen(valor) > hiLimit)
    {
        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        gets(valor);
    }

    strcpy(input,valor);

    error = 0;

    return error;
}


