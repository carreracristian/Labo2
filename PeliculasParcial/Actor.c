#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

#include "Actor.h"
#include "Pelicula.h"



void Actor_mostrarUno(eActor unActor)
{
    printf("\n %2d \t%20s \t%15s",unActor.id,unActor.nombre,unActor.pais);
}

void harcodearActores(eActor listaActores[],int tam)
{
    int ids[]={1,2,3,4,5};
    char nombres[][TAM_NOM]={"Julieta Roberto","Richard Darin","Nicole Kidman","Tita Merello", "Natalia Oreiro"};
    char paises[][TAM_PAIS]={"EEUU","Argentina","Australia","Argentina", "Uruguay"};

    int i;

    for(i=0;i<tam;i++)
    {
        listaActores[i].id=ids[i];
        strcpy(listaActores[i].nombre, nombres[i]);
        strcpy(listaActores[i].pais, paises[i]);
    }
}


int Actor_buscarPorId(eActor listado[] ,int limite, int id){
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

//Revisar funciones



void Actor_mostrarLista(eActor listaActores[], int tam)
{
    printf("\n----LISTA DE ACTORES----\n\n");
    printf("\n ID \t\tNOMBRE \t\t\tPAIS\n");
    int i;
    for(i=0;i<tam;i++){
        Actor_mostrarUno(listaActores[i]);
    }
    printf("\n");
}

int validarActor(int idActores, eActor listaActores[], int tam)
{

    int esValido= 0;
    int i;
    for(i=0;i<tam;i++){
        if(idActores == listaActores[i].id){
            esValido= 1;
            break;
        }
    }
    return esValido;
}
int pedirActor(char mensaje[], eActor listaActores[], int tam)
{

    Actor_mostrarLista(listaActores, tam);
    int idActor= pedirEnteroPositivo(mensaje);
    //printf("%s: ", mensaje);
    //scanf("%d", &idSector);
    while( ! validarActor(idActor, listaActores, tam )){
        Actor_mostrarLista(listaActores, tam);
        printf("Error. ");
        idActor= pedirEnteroPositivo(mensaje);

        //scanf("%d", &idSector);
    }
    return idActor;
}
int ordenarActoresPorPaisAscYDesc (eActor listaActores[], int tamA, int ordenar)
{
    eActor auxActor;
    char auxOrdenar[1] ;
    int i;
    int j;
    if(!funcionGetStringNumeros("\n Ingrese 1 para ordenar de manera ascendente o ingrese 2 para ordenar de manera descendente: ",auxOrdenar))
    {
        printf("\nError debe ingresar un numero..");

    }

    ordenar = atoi(auxOrdenar);

     switch(ordenar)
    {
    case 1:
        for(i = 0; i < tamA - 1; i++)
        {
            for(j = i + 1; j < tamA; j++)
            {
                if (stricmp(listaActores[i].pais,listaActores[j].pais)>0){

                    auxActor= listaActores[i];
                    listaActores[i]= listaActores[j];
                    listaActores[j]= auxActor;
                    }
                    if ( (stricmp(listaActores[i].pais,listaActores[j].pais)==0) &&((stricmp(listaActores[i].nombre,listaActores[j].nombre)>0))  ){

                    auxActor= listaActores[i];
                    listaActores[i]= listaActores[j];
                    listaActores[j]= auxActor;
                }
                    }
                }


        printf("\n\nEl ordenado ascendente se ha realizado con exito.\n");
        system("pause") ;
        system("cls") ;
        break;
    case 2:
       for(i=0;i<tamA-1;i++){
        for(j=i+1;j<tamA;j++){

                if (stricmp(listaActores[i].pais,listaActores[j].pais)<0){

                    auxActor= listaActores[i];
                    listaActores[i]= listaActores[j];
                    listaActores[j]= auxActor;
                }
                if ( (stricmp(listaActores[i].pais,listaActores[j].pais)==0) &&((stricmp(listaActores[i].nombre,listaActores[j].nombre)<0))  ){

                    auxActor= listaActores[i];
                    listaActores[i]= listaActores[j];
                    listaActores[j]= auxActor;
                }
        }
    }


        system("pause") ;
        system("cls") ;
        break;
    default:
        printf("No ingreso 1 o 2");
    }
    return 0;
}
void PedirActores(char mensaje[], ePelicula listadoPel[], int indice, eActor listadoAct[], int ta)
{
    int idActor= pedirEnteroPositivo(mensaje);
    while(Actor_buscarPorId(listadoAct,ta,idActor) < 0 ){
        printf("\nError.\n");
        idActor= pedirEnteroPositivo(mensaje);
    }
    listadoPel[indice].idActor= idActor;
}
int Actor_ordenarPorIdAsc(eActor listado[], int limite)
{
    int i,j;
    eActor auxActor;
    //Ordena por id ascendente
    for(i=0;i<limite-1;i++){
        for(j=i+1;j<limite;j++){
            if (listado[i].id > listado[j].id){
                auxActor= listado[i];
                listado[i]= listado[j];
                listado[j]= auxActor;
            }
        }
    }
    return 0;
}


