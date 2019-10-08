#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "juegos.h"
#include "categoria.h"


/*void mostrarjuego(eJuego juegos[],int tamJ, eCategoria categorias[], int tam){

    char descCategoria[20];
    cargardescCategoria(juegos.idCategoria, categorias, tam, descCategoria);

    printf(" %d   %s      %.2f      $s \n\n", juegos.id,  juegos.descripcion, juegos.precio,descCategoria );
}*/
void mostrarjuego(eJuego juegos)
{
    printf("%d     %s      %f  ",juegos.codigo,juegos.descripcion,juegos.importe);
}

void mostrarjuegos(eJuego juegos[], int tam){
    system("cls");
    int i;
    printf("\n JUEGO   PRECIO \n");
    printf("**********************\n");

    for( i=0; i<tam; i++){
        mostrarjuego(juegos[i]);
    }
}


int cargarDescjuego(int id, eJuego juegos[], int tam, char desc[]){
    int todoOk = 0;
    int i;
    for( i=0; i < tam; i++){
        if( id == juegos[i].codigo){
            strcpy(desc, juegos[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}
