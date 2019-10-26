#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
typedef struct{
    int id;
    char nombre[20];
    float sueldo;
    int estado;

} eEmpleado;
int mostrarEmpleado(eEmpleado* unEmpleado);
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int id, char* nombre,float sueldo);
int inicializarEmpleado(eEmpleado* vec,int tam);
int main()
{
    int tam=0;
    eEmpleado* lista=(eEmpleado*) malloc(sizeof(eEmpleado)*(tam+1));
    eEmpleado* aux;
    //eEmpleado emp1;
/*eEmpleado* lista=(eEmpleado*) malloc(sizeof(eEmpleado)*TAM);
    if(inicializarEmpleado(lista,TAM))
    {
        printf("Empleados inicializados.\n\n");
    }
eEmpleado* emp2=newEmpleado();*/
    // MANERAS DE CARGAR UN ID

    /*emp2->id=1234;

    printf("Ingrese id: ");
    scanf("%d",&emp2->id);
    printf("%d",emp2->id);*/

    eEmpleado* emp3=newEmpleadoParam(3322,"Jose",34000);
    *(lista+tam)=*emp3;
    mostrarEmpleado(emp3);
    tam++;

    aux=(eEmpleado*) realloc(lista, sizeof(eEmpleado)*(tam+1));
    //EL SIZEOF MUESRTA LA CANTIDAD DE MEMORIA DE LA ESTRUCTURA eEmpleado EN BYTES//
    printf("%d",sizeof(eEmpleado));
    return 0;
}
eEmpleado* newEmpleado()
{
    eEmpleado* e=(eEmpleado*) malloc( sizeof(eEmpleado));
    if(e != NULL)
    {
        e->id=0;
        strcpy(e->nombre,"");
        e->sueldo=0;
        e->estado=0;
    }
    return e;
}
int mostrarEmpleado(eEmpleado* unEmpleado)
{
    int todoOk=0;
    if(unEmpleado != NULL)
    {
       printf("%d    %s     %.2f\n ",unEmpleado->id,unEmpleado->nombre,unEmpleado->sueldo);
       todoOk=1;
    }
    return todoOk;
}
int mostrarEmpleados(eEmpleado* unEmpleado,int tam)
{

}
//valida los datos y luego devuelve la estrura cargada//
eEmpleado* newEmpleadoParam(int id, char* nombre,float sueldo)
{
    eEmpleado* e=newEmpleado();

     if(e != NULL)
    {
        e->id=id;
        strcpy(e->nombre,nombre);
        e->sueldo=sueldo;
        e->estado=0;
    }
    return e;
}
int inicializarEmpleado(eEmpleado* vec,int tam)
{
    int todoOk=0;
    if(vec != NULL && tam>=0)
    {
        for(int i=0;i<tam;i++)
        {
            (vec+i)->estado=0;
        }
        todoOk=1;
    }
}
