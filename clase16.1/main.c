#include <stdio.h>
#include <stdlib.h>
typedef struct{

    int legajo;
    char nombre[20];
    char apellido[20];
    float sueldo;
    //int primero;

}eEmpleado;

eEmpleado* newEmpleado();
int main()
{
    //arrays que guarda punteros//
    eEmpleado* lista[50];

    eEmpleado* emple;//=newEmpleado();

    int i=0;

    FILE* miArchivo;
    char legajo[10];
    char nombre[20];
    char apellido[20];
    char sueldo[20];
    char line[100];
    int primero=0;

    //eEmpleado emple;

    miArchivo=fopen("datos.csv","r");

    fscanf(miArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",legajo,nombre,apellido,sueldo);

    while(!feof(miArchivo))
    {
        fscanf(miArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",legajo,nombre,apellido,sueldo);
        /*if(primero==0)
        {
             fscanf(miArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",legajo,nombre,apellido,sueldo);
             primero=1;
             continue;
        }*/

        emple=newEmpleado();
        emple->legajo=atoi(legajo);
        strcpy(emple->nombre,nombre);
        strcpy(emple->apellido,apellido);
        emple->sueldo=atof(sueldo);
        //lista[i]=emple;
        *(lista+i)=emple;
        i++;
        //Almacenamiento estatico//
        /*emple.legajo=atoi(legajo);
        strcpy(emple.nombre,nombre);
        strcpy(emple.apellido,apellido);
        emple.sueldo=atof(sueldo);
              //fscanf(miArchivo,"%s",line);
        printf("%d---%10s---%10s---%f\n",emple.legajo,emple.nombre,emple.apellido,emple.sueldo);*/
    }
    fclose(miArchivo);

    for(i=0;i<50;i++)
    {
        printf("%d---%s---%s---%f\n",lista[i]->legajo,lista[i]->nombre,lista[i]->apellido,lista[i]->sueldo);
    }

    return 0;
}
eEmpleado* newEmpleado()
{
    eEmpleado* e;

    e=(eEmpleado*) malloc(sizeof(eEmpleado));

    return e;
}
