#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "cliente.h"
//#include "biblioteca.h"



void inicializarClientes(eCliente vec[], int tam){
    int i;
    for( i=0; i<tam; i++){
        vec[i].isEmpty = 1;
    }
}

int buscarLibre(eCliente vec[], int tam){
    int indice = -1;
    int i;
    for( i=0; i<tam; i++){
        if(vec[i].isEmpty == 1){
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarCliente(eCliente vec[], int tam, int legajo){
    int indice = -1;
    int i;
        for( i=0; i<tam; i++){
            if(vec[i].legajo == legajo && vec[i].isEmpty == 0){
                indice = i;
                break;
            }
        }
    return indice;
}


void mostrarClientes(eCliente vec[], int tam, eCategoria categorias[], int tamC){

    int flag = 0;
    int i;
    system("cls");

    printf("\n LEGAJO   NOMBRE    APELLIDO    SEXO   TELEFONO\n");
    printf("****************************************************\n");


    for( i=0; i<tam; i++){
        if(vec[i].isEmpty == 0){
           mostrarCliente(vec[i], categorias, tamC);
           flag = 1;
        }

    }
    if(flag == 0){
        printf("No hay Clientes que mostrar");
    }
    printf("\n\n");
}

void mostrarCliente( eCliente al, eCategoria categorias[], int tam){
   printf("%d    %10s     %10s    %c     %2d");
}


int altaCliente(eCliente vec[], int tam, int leg, eCategoria categorias[], int tamC){
    int todoOk = 0;
    int indice;

    char nombre[20];
    char apellido[20];
    char sexo;
    int telefono;
    int idCarrera;

        system("cls");
        printf("******* ALTA *******\n\n");

        indice = buscarLibre(vec, tam);

        if(indice == -1){
            printf("NO HAY LUGAR EN EL SISTEMA \n\n");
        }
        else{
                printf("Ingrese Nombre: ");
                fflush(stdin);
               // getString(nombre, "Ingrese Nombre: ", "Error. Reingrese Nombre: ", 3,19);
                gets(nombre);
                //strlwr(nombre);
                //nombre[0] = toupper(nombre[0]);
                printf("Ingrese Apellido: ");
                fflush(stdin);
               // getString(nombre, "Ingrese Nombre: ", "Error. Reingrese Nombre: ", 3,19);
                gets(apellido);
                //getIntRange(&edad, "Ingrese Edad: ", "Error. Ingrese Edad entre 17 y 100: ", 17, 100);

                 printf("Ingrese Sexo: ");
                 fflush(stdin);
                 scanf("c",&sexo);
                //sexo = tolower(getchar());
                //getCharSex(&sexo, "Ingrese Sexo: ", "Error. Ingrese Sexo (F o M): ", 'F', 'M');

                //printf("Ingrese Nota 1: ");
                //scanf("%d", &nota1);
                //getIntRange(&nota1, "Ingrese Nota 1: ", "Error. Ingrese Nota 1 entre 1 y 10: ", 1, 10);

                //printf("Ingrese Nota 2: ");
                //scanf("%d", &nota2);
                //getIntRange(&nota2, "Ingrese Nota 2: ", "Error. Ingrese Nota 2 entre 1 y 10: ", 1, 10);
                printf("Ingrese telefono: ");
                scanf("%d",&telefono);
               /* printf("Ingrese Fecha de Ingreso dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio );*/

               /* mostrarCategorias(categorias, tamC);
                printf("Ingrese ID categoria: ");
                scanf("%d", &idCategoria);*/


               // getIntCarrera(&idCarrera, "Ingrese ID carrera: ", "Error. Ingrese ID valido: ", 1000, 1002, 1002);

                vec[indice] = newCliente(leg, nombre, apellido, sexo, telefono);

                todoOk = 1;
                if(todoOk){
                    printf("\n\nALTA EXITOSA !!! \n\n");
                }
        }

    return todoOk;
}

eCliente newCliente(int leg, char nombre[], char apellido[], char sexo, int telefono){
    eCliente al;

    al.legajo = leg;
    strcpy( al.nombre, nombre );
    strcpy( al.apellido, apellido );
    al.sexo = sexo;
    al.telefono = telefono;
    al.isEmpty = 0;

    return al;
}


int bajaCliente(eCliente vec[], int tam, eCategoria categorias[], int tamC){

    int todoOk = 0;
    int legajo;
    char confirma='S';
    int esta;

        system("cls");
        printf("******* BAJA *******\n\n");

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
       // getIntRange(&legajo,"Ingrese legajo: ", "Error. Ingrese legajo de 20000 al 50000: ", 20000, 50000);

        esta = buscarCliente(vec, tam, legajo);

        if(esta == -1){
            printf("NO EXISTE CLIENTE CON ESE LEGAJO\n\n");
        }
        else{
            mostrarCliente(vec[esta], categorias, tamC);
            printf("Confirma la baja? ");
            fflush(stdin);

            if(confirma == 'S'){
                vec[esta].isEmpty = 1;
                todoOk = 1;
                printf("BAJA EXITOSA\n\n");
            }
            else{
                printf(" SE CANCELO LA OPERACION!! \n\n");
            }
        }
        return todoOk;
}


int modificarCliente(eCliente vec[], int tam, eCategoria categorias[], int tamC){

    int todoOk = 0;
    int legajo;
    int indice;
    int flag = 0;

        system("cls");
        printf("******* MODIFICAR *******\n\n");

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        //getIntRange(&legajo,"Ingrese legajo: ", "Error. Ingrese legajo de 20000 al 50000: ", 20000, 50000);

        indice = buscarCliente(vec, tam, legajo);

        if(indice == -1){
            printf("NO EXISTE CLIENTE CON ESE LEGAJO\n\n");
        }
        else{
            mostrarCliente(vec[indice], categorias, tamC);

            switch(menuModificarAlumno()){
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    scanf("%s", &vec[indice].nombre);
                    //getIntRange(&vec[indice].nota1, "Ingrese nueva Nota 1: ", "Error. Ingrese nueva Nota 1 entre 1 y 10: ", 1, 10);

                   // vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
                    flag = 1;
                    break;

                case 2:
                    printf("Ingrese nuevo telefono: ");
                    scanf("%d", &vec[indice].telefono);
                    //getIntRange(&vec[indice].nota2, "Ingrese nueva Nota 2: ", "Error. Ingrese nueva Nota 2 entre 1 y 10: ", 1, 10);
                    //vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
                    flag = 2;
                    break;
                case 3:
                    printf("Se ha cancelado la mofdificacion \n\n");
                    break;
            }
        }
        if(flag == 1){
            printf("SE MODIFICO NOMBRE \n\n");

        }else if(flag == 2){
            printf("SE MODIFICO TELEFONO \n\n");
        }

        return todoOk;
}

void ordenarClientes(eCliente vec[], int tam){

    eCliente auxCliente;
    int i;
    int j;
    for( i= 0; i < tam-1 ; i++)
    {
        for( j= i+1; j <tam; j++)
        {
            if( vec[i].sexo > vec[j].sexo )
            {
                auxCliente = vec[i];
                vec[i] = vec[j];
                vec[j] = auxCliente;
            }
        }
    }
    printf("Clientes Ordenados\n\n");
}


int hardcodearClientes( eCliente vec[], int tam, int cantidad){
    int cont = 0;
    int i;
    eCliente suplentes[]=
    {
        { 20000, "Juan","Correa", 'M',  1000, 0},
        { 20001, "Alberto", "Godoy", 'M', 1001, 0},
        { 20002, "Ana", "Partero", 'F', 1002, 0},
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for( i=0; i < cantidad; i++)
        {
            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}



int menuModificarAlumno(){
    int opcion;
        printf("1- Modificar nombre 1\n");
        printf("2- Modificar telefono 2\n");
        printf("3- Salir\n\n");

        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        //getIntRange(&opcion, "Ingrece opcion: ", "Error. Ingrese opcion entre 1 y 3", 1, 3);

    return opcion;
}
