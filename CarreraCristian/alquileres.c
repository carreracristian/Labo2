#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "alquileres.h"
//#include "biblioteca.h"

void inicializarAlquileres(eAlquiler Alquileres[], int tam){
    int i;
    for( i=0; i<tam; i++){
        Alquileres[i].isEmpty = 1;
    }
}

/*int hardcodearAlquileres( eAlquiler vec[], int tam, int cantidad){
    int cont = 0;

    eAlquiler suplentes[]=
    {
        { 60000, 20000, 5000, {12, 10, 2019}, 0},
        { 60001, 20001, 5004, {10, 10, 2019}, 0},
        { 60002, 20002, 5002, { 9, 10, 2019}, 0},
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}*/

void mostrarAlquiler(eAlquiler Alquiler, eJuego juegos[], int tamC){
    char descJuegos[20];

    cargarDescJuegos(Alquiler.idJuegos, juegos, tamC, descJuegos );

    printf(" %d      %10s       %2d       %d/%d/%d \n\n", Alquiler.id, descJuegos, Alquiler.idClientes, Alquiler.fecha.dia, Alquiler.fecha.mes, Alquiler.fecha.anio);
}


void mostrarAlquileres(eAlquiler Alquileres[],int tam, eJuego juegos[], int tamC){

    int i;
    int flag = 0;

    system("cls");

    printf("\n  ID            Juegos      idCliente       FECHA\n");
    printf("************************************************\n");


    for( i=0; i<tam; i++){
        if(Alquileres[i].isEmpty == 0){
           mostrarAlquiler(Alquileres[i], juegos, tamC);
           flag = 1;
        }

    }
    if(flag == 0){
        printf("No hay Alquileres que mostrar");
    }
    printf("\n\n");
}


int buscarAlquilerLibre(eAlquiler vec[], int tam){
    int indice = -1;
    int i;

    for(i=0; i<tam; i++){
        if(vec[i].isEmpty == 1){
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlquiler(int idAlquiler, eAlquiler alquileres[], int tamAlquileres, eJuego juegos[], int tamJuegos, eCliente clientes[], int tamClientes, eCategoria categorias[], int tamCategorias)
{

    int todoOk = 0;
    int indice;
    int esta;

    int idCliente;
    eFecha fecha;
    int idJuegos;

        system("cls");
        printf("******* ALTA Alquiler *******\n\n");

        indice = buscarAlquilerLibre(alquileres, tamAlquileres);

        if(indice == -1){
            printf("NO HAY LUGAR EN EL SISTEMA \n\n");
        }
        else{
                mostrarclientes(clientes, tamClientes, categorias, tamCategorias);

                printf("Ingrese id Cliente: ");
                scanf("d",&idCliente);

                esta = buscarCliente(clientes, tamClientes, idCliente);

                if(esta == -1){
                    printf("no existe ese cliente \n\n");
                }
                else{
                    mostrarjuegos(juegos, tamJuegos);

                    printf("Ingrese id juego: ");
                    scanf("d",&idJuegos);
                   // getInt(&idJuegos, "Ingrese ID: ", "Error, Reingrese ID: ");


                    printf("Ingrese Fecha dd/mm/aaaa: ");
                    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio );

                    alquileres[indice] = newAlquiler(idAlquiler, idJuegos, idCliente, fecha);

                    todoOk = 1;
                }


                if(todoOk){
                    printf("\n\nALTA ALQUILER EXITOSA !!! \n\n");
                }
        }

    return todoOk;
}


eAlquiler newAlquiler(int id, int idJuegos, int idClientes, eFecha fecha){
    eAlquiler al;

    al.id = id;
    al.idJuegos = idJuegos;
    al.idClientes = idClientes;
    al.fecha = fecha;
    al.isEmpty = 0;

    return al;
}
