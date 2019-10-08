#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "categoria.h"
#include "cliente.h"
//#include "biblioteca.h"
//#include "Informes.h"
#include "alquileres.h"
#include "juegos.h"

#define TAM 10
#define TAMC 3
#define TAMCOM 5
#define TAMALM 10

// ESTRUCTURAS


////////////////////////////////// PROTOTIPOS

int menu();




//////////////////////////////// MAIN
int main()
{
    int legajo = 20000;
    int idAlquiler = 60000;

    eJuego juegos[TAMCOM] = {
        {5000, "Dardo", 250},
        {5001, "Ruleta", 200},
        {5002, "Truco", 190},
        {5003, "Pocker", 200},
        {5004, "Tragamonedas", 220}
    };

    eAlquiler alquileres[TAMALM];

    eCategoria categorias[TAMC]={{1000,"MEZA"},{1001,"AZAR"},{1002,"ESTRATEGIA"},{1003,"SALON"},{1004,"MAGIA"}};

    eCliente lista[TAM];

    inicializarClientes(lista, TAM);

    inicializarAlquileres(alquileres, TAMALM);

    legajo = legajo + hardcodearClientes(lista, TAM, 6);
    idAlquiler = idAlquiler + hardcodearalquileres(alquileres, TAMALM, 6);

    char salir = 'n';

    do{

        switch(menu1()){

        case 1:
            //  ALTA ALUMNO
            if(altaCliente(lista, TAM, legajo, categorias, TAMC)){
                legajo++;
            }

            break;
        case 2:
           //  BAJA ALUMNJO
            bajaCliente(lista, TAM, categorias, TAMC);
            break;
        case 3:
            // MODIFICAR ALUMNO
            modificarCliente(lista, TAM, categorias, TAMC);
            break;
        case 4:
            // MOSTRAR ALUMNOS
            mostrarClientes(lista, TAM, categorias, TAMC);
            break;
        case 5:
            // ORDENAR ALUMNOS
            ordenarClientes(lista, TAM);
            break;
        case 6:
            // IFORMES
            mostrarInformes(lista, TAM, categorias, TAMC, alquileres, TAMALM, juegos, TAMCOM);
            break;
        case 7:
            // MOSTRAR categorias
            mostrarCategorias(categorias, TAMC);
            break;
        case 8:
            // MOSTRAR juegos
            mostrarjuegos(juegos, TAMCOM);
            break;
         case 9:
            // MOSTRAR ALMUERZO
            mostrarAlquileres(alquileres, TAMALM, juegos, TAMCOM);
            break;
         /*case 10:
               if(altaAlmuerzo(idAlquiler, alquileres, TAMALM, juegos, TAMCOM, lista, TAM, categorias, TAMC)){
                    idAlquiler++;
                }
            break;*/
        case 11:
            printf("Confirma Salir?  ");

            printf("\n\n");
            break;


        default:
            printf("Opcion invalida.");
            break;
        }

        system("pause");
    }while(salir == 'n');



    return 0;
}


int menu1(){

    int opcion;

    system("cls");

    printf("\n***** ABM de Clientes  ********\n\n");
    printf("1- Alta \n");
    printf("2- Baja \n");
    printf("3- Modificar  \n");
    printf("4- Mostrar Clientes \n");
    printf("5- Ordenar Clientes \n");
    printf("6- Informes \n");
    printf("7- Listar categorias \n");
    printf("8- Mostrar juegos \n");
    printf("9- Mostrar alquileres \n");
   // printf("10- Alta alquileres \n");

    printf("11- Salir \n");

    printf("Ingrese opcion: ");
    scanf("%d",opcion);
   // getIntRange(&opcion, "Ingrese Opcion: ", "Error. Ingrese un entero entre 1 y 8: ", 1, 11);

    return opcion;
}
