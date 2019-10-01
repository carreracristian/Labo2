#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "genero.h"
#include "Pelicula.h"

static void Genero_mostrarUno(eGenero);

static void Genero_mostrarUno(eGenero unGenero)
{
    printf("\n %2d \t%20s",unGenero.id,unGenero.genero);
}

void harcodearGeneros(eGenero listaGeneros[],int tam)
{

    int ids[]= {1,2,3,4,5};
    char generos[][TAM_GEN]= {"Accion","Comedia","Terror","Romantica","Otro"};

    int i;

    for(i=0;i<tam;i++)
    {
        listaGeneros[i].id= ids[i];
        strcpy(listaGeneros[i].genero, generos[i]);

    }
}


void Genero_mostrarLista(eGenero listaGenero[], int tam)
{
    printf("\n----LISTA DE GENEROS----\n\n");
    printf("\n ID \t\tGENERO\n");
    int i;
    for(i=0;i<tam;i++){
        Genero_mostrarUno(listaGenero[i]);
    }
    printf("\n");

}

int Genero_buscarPorId(eGenero listado[] ,int limite, int id)
{
    int indice = -1;
    int i;
    for(i=0;i<limite;i++){
        if(listado[i].id == id){
            indice = i;
            break;
        }
    }
    return indice;
}


int validarGenero(int idGenero, eGenero listaGeneros[], int tam)
{

    int esValido= 0;
    int i;
    for(i=0;i<tam;i++){
        if(idGenero == listaGeneros[i].id){
            esValido= 1;
            break;
        }
    }
    return esValido;
}
int pedirGenero(char mensaje[], eGenero listaGeneros[], int tam)
{

    Genero_mostrarLista(listaGeneros, tam);
    int idGenero= pedirEnteroPositivo(mensaje);
    //printf("%s: ", mensaje);
    //scanf("%d", &idSector);
    while( ! validarGenero(idGenero, listaGeneros, tam ))
        {
        Genero_mostrarLista(listaGeneros, tam);
        printf("Error. ");
        idGenero= pedirEnteroPositivo(mensaje);

        //scanf("%d", &idSector);
    }
    return idGenero;
}


