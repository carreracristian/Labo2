#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "categoria.h"
#include "juegos.h"


void mostrarCategorias(eCategoria categoria[], int tam){
    int i;
    printf("\n    Id        Descripcion\n\n");
    for( i=0; i < tam; i++){
        mostrarCategoria(categoria[i]);
    }
    printf("\n");
}

void mostrarCategoria(eCategoria categoria){
    printf("  %d      %10s\n", categoria.id, categoria.descripcion);
}

int cargarDesccategoria(int id, eCategoria categoria[], int tam, char desc[]){
    int todoOk = 0;
    int i;
    for( i=0; i < tam; i++){
        if( id == categoria[i].id){
            strcpy(desc, categoria[i].descripcion);
            todoOk = 1;
            break;
        }
    }

    return todoOk;
}
