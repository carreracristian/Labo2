#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#define TAM 5
typedef struct{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}eNotebook;
//FUNCION DEVOLVER AUMENTO
float devolverPrecioConAumento(float x);
//FUNCIONES DE LA ESTRUCTURA NOTEBOOK
void mostrarNotes(eNotebook carreras[], int tam);
void mostrarNote(eNotebook carrera);
int hardcodearNote( eNotebook vec[],int tam,int cant);
int ordenarNotebooks(eNotebook vec[], int tam);
//FUNCION DEVOLVER CANTIDAD DE VOCALES
void contarVocales(char cadena[]);
//FUNCION DEVOLVER CANTIDAD DE CARACTERES
void contarCaracteres(char cadena[],char caracter);
int main()
{
    float num;
    float numConDesc;
    char palabra[20];
    char otraPalabra[20];
    char caracter;

    printf("\nIngrese numero: ");
    scanf("%f",&num);

    numConDesc=devolverPrecioConAumento(num);

    printf("\nEl numero con aumento es: %.2f\n",numConDesc);

    eNotebook lista[TAM];

    hardcodearNote(lista,TAM,5);

    ordenarNotebooks(lista,TAM);
    mostrarNotes(lista,TAM);

    printf("\nIngrese la palabra: ");
    scanf("%s",&palabra);
    fflush(stdin);
    contarVocales(palabra);

    printf("\n\nIngrese la palabra: ");
    scanf("%s",&otraPalabra);
    fflush(stdin);
    printf("\nIngrese el caracter: ");
    scanf("%c",&caracter);
    fflush(stdin);

    contarCaracteres(otraPalabra,caracter);



    return 0;
}
float devolverPrecioConAumento(float x)
{
    float devolver;
    float aumento;

    aumento = x * 0.10;
    devolver = x + aumento;

    return devolver;
}
void mostrarNotes(eNotebook carreras[], int tam)
{
    printf("\n Id         Procesador         Marca      Precio\n\n");
    for(int i=0; i < tam; i++)
    {
        mostrarNote(carreras[i]);
    }
    printf("\n");
}

void mostrarNote(eNotebook carrera)
{

    printf("\n  %d      %10s      %10s      %.2f\n", carrera.id, carrera.procesador,carrera.marca,carrera.precio);

}
int hardcodearNote( eNotebook vec[],int tam,int cant)
{
    int cont=0;

    eNotebook datos []=
    {

        {1,"INTEL","HP",2000},
        {2,"AMD","DELL",1800},
        {3,"AMD","LENOVO",2400},
        {4,"INTEL","IMAC",3400},
        {5,"AMD","TOSHIBA",1400}

    };

    if(cant <= 5 && tam >= cant)
    {
        for(int i=0; i<cant; i++)
        {
            vec[i] = datos[i];
            cont++;
        }
    }

    return cont;
}
int ordenarNotebooks(eNotebook vec[], int tam)
{
    eNotebook auxNote;
    int retorno=-1;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( strcmp(vec[i].marca,vec[j].marca)==1 )
            {
                auxNote = vec[i];
                vec[i] = vec[j];
                vec[j] = auxNote;
                retorno=1;
            }
        }
    }

    return retorno;
}
void contarVocales(char cadena[])
{
    int cantidad=0;
    int i;
    int x = strlen(cadena);

    strupr(cadena);

    for(i=0;i<x;i++)
    {
        if(cadena[i]=='A')
        {
            cantidad++;
        }
        if(cadena[i]=='E')
        {
            cantidad++;
        }
        if(cadena[i]=='I')
        {
            cantidad++;
        }
        if(cadena[i]=='O')
        {
            cantidad++;
        }
        if(cadena[i]=='U')
        {
            cantidad++;
        }
    }
    printf("\nLa cantidad de vocales son: %d",cantidad);
}
void contarCaracteres(char cadena[],char caracter)
{
    int cantidad=0;
    int i;
    int x = strlen(cadena);

    strupr(cadena);

    for(i=0;i<x;i++)
    {
        if(cadena[i]==caracter)
        {
            cantidad++;
        }
    }
    printf("\nLa cantidad de caracteres son: %d",cantidad);

}
