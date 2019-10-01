#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "validaciones.h"




int funcionSoloLetras(char letra[])
{
    int i=0;
    while(letra[i] != '\0')
    {
        if((letra[i] != ' ') && (letra[i] < 'a' || letra[i] > 'z') && (letra[i] < 'A' || letra[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}
void FuncionGetString (char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin) ;
    gets(input) ;
}
int funcionGetStringLetras(char mensaje[],char input[])
{
    int retorno =0;
    char aux[256];
    FuncionGetString(mensaje,aux);
    if(funcionSoloLetras(aux))
    {
        strcpy(input,aux);
        retorno= 1;
    }
    return retorno ;
}
int funcionEsNum(char letra[])
{
     int i=0;
    while(letra[i] != '\0')
    {
        if(letra[i] < '0' || letra[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int funcionGetStringNumeros(char mensaje[],char input[])
{
   char aux[256];
   FuncionGetString(mensaje,aux);
   if(funcionEsNum(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
void funcionContinuarSiONo(char mensaje[],char input[])
{
    do
    {
        if(!funcionGetStringLetras(mensaje,input))
        {
            printf("Error Debe ingresar la letra S o N");
            system("pause");
            system("cls");
        }

    }
    while(!(input[0] == 's' || input[0] == 'n' || input[0] == 'S' || input[0] == 'N'));

}


void validarTamCadena(char mensaje[], char cadena[], int tam){
    while( strlen(cadena) > tam){
        printf("Error. %s: ", mensaje);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
}

void pedirCadena(char mensaje[], char cadena[], int tam){
    char buffer[1000];
    printf("%s: ", mensaje);
    fflush(stdin);
    scanf("%[^\n]", buffer);
    validarTamCadena(mensaje, buffer, tam);
    strcpy(cadena, buffer);
}



int pedirEnteroPositivo(char mensaje[]){
    int unEntero;
    printf("%s: ", mensaje);
    scanf("%d", &unEntero);
    while(unEntero <= 0){
        printf("Error. %s: ", mensaje);
        scanf("%d", &unEntero);
    }
    return unEntero;
}

int validarDato(char mensaje[], int minimo, int maximo)
{
    int numero;

    printf(mensaje);
    scanf("%d",&numero);
    while(numero>maximo || numero<minimo)
    {
        printf("Error. Por favor, reingrese: ");
        scanf("%d",&numero);
    }
    return numero;
}

int pedirEnteroRango(char mensaje[], int minimo, int maximo){
    int unEntero;
    printf("%s: ", mensaje);
    scanf("%d", &unEntero);
    while(unEntero < minimo || unEntero > maximo){
        printf("Error. %s: ", mensaje);
        scanf("%d", &unEntero);
    }
    return unEntero;
}

