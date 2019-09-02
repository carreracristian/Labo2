#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InputAndValidate.h"

int menu(char mensaje[])
{
    int opcion;

    printf(mensaje);
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void getString(char mensaje[], char dato[])
{
    printf(mensaje);
    fflush(stdin);
    gets(dato);
}

void getSoloLetras(char mensaje[], char palabra[])
{
    int i;
    char auxiliar[50];
    int esLetra = 0;

    do
    {
        getString(mensaje, auxiliar);

        for(i=0; auxiliar[i] != '\0'; i++)
        {
            if( (auxiliar[i] < 'a' || auxiliar[i] > 'z') && (auxiliar[i] < 'A' || auxiliar[i] > 'Z') && (auxiliar[i] != ' ') )
            {
                break;
            }
        }

        if(auxiliar[i] == '\0')
        {
            strcpy(palabra, auxiliar);
            esLetra = 1;
        }

    } while(esLetra == 0);
}

int getSoloEnteros(char mensaje[])
{
    int i;
    char numero[50];
    int numeroConvertido;
    int esNumero = 0;

    do
    {
        getString(mensaje, numero);

        for(i=0; numero[i] != '\0'; i++)
        {
            if(numero[i] < '0' || numero[i] > '9')
            {
                break;
            }
        }

        if(numero[i] == '\0')
        {
            numeroConvertido = atoi(numero);
            esNumero = 1;
        }

    } while(esNumero == 0);

    return numeroConvertido;
}

float getSoloFlotantes(char mensaje[])
{
    int i;
    char numero[50];
    float numeroConvertido;
    int esFlotante = 0;

    do
    {
        getString(mensaje, numero);

        for(i=0; numero[i] != '\0'; i++)
        {
            if( (numero[i] < '0' || numero[i] > '9') && (numero[i] != '.') )
            {
                break;
            }
        }

        if(numero[i] == '\0')
        {
            numeroConvertido = atof(numero);
            esFlotante = 1;
        }

    } while(esFlotante == 0);

    return numeroConvertido;
}

