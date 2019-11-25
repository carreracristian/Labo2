#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"

int getString(char* msj, char* aux)
{
    int ok = 0;
    if(aux != NULL)
    {
        printf(msj);
        fflush(stdin);
        gets(aux);
        ok = 1;
    }
    return ok;
}

int isOnlyNumber(char* aux)
{
	int i, ok = 0;
    if(aux != NULL)
    {
        for(i=0; aux[i] != '\0'; i++)
        {
            if( (aux[i] < '0' || aux[i] > '9') )
                break;
        }
        if( (aux[i] == '\0') )
            ok = 1;
    }
	return ok;
}

int isOnlyLetter(char* aux)
{
	int i, ok = 0;
    if(aux != NULL)
    {
        for(i=0; aux[i] != '\0'; i++)
        {
            if( (aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z') && (aux[i] != ' ') )
                break;
        }
        if(aux[i] == '\0')
            ok = 1;
    }
	return ok;
}

int getOnlyNumber(char* msj, char* msjError, int* numero)
{
    int valido, ok = 0;
    char aux[50];
    if(numero != NULL)
    {
        getString(msj,aux);
        valido = isOnlyNumber(aux);
        while(!valido)
        {
            getString(msjError, aux);
            valido = isOnlyNumber(aux);
        }
        *numero = atoi(aux);
        ok = 1;
    }
    return ok;
}

int getOnlyLetter(char* msj, char* msjError, char* str)
{
	int valido, ok = 0;
	char aux[50];
	if(str != NULL)
	{
		getString(msj,aux);
		valido = isOnlyLetter(aux);
		while(!valido)
		{
			getString(msjError,aux);
			valido = isOnlyLetter(aux);
		}
		strcpy(str,aux);
		ok = 1;
	}
	return ok;
}
