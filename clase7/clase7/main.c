#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarAlumnos(int leg[],int age[], char sex[], int n1[], int n2[], float prom[],int tam);
void mostrarAlumno(int leg,int age, char sex, int n1, int n2, float prom);
void ordenarAlumnos(int leg[],int age[], char sex[], int n1[], int n2[], float prom[],int tam);
void ordenarSexoLeg(int leg[],int age[], char sex[], int n1[], int n2[], float prom[],int tam);

int main()
{
    int legajo[TAM]={1,2,3,4,5};
    int edad[TAM]={23,18,25,40,31};
    char sexo[TAM]={'f','m','f','m','f'};
    int nota1[TAM]={8,9,5,4,10};
    int nota2[TAM]={4,3,2,9,7};
    float promedio[TAM]={6,6,3.5,6.5,8.5};

    mostrarAlumnos( legajo, edad, sexo,   nota1,  nota2,  promedio,  TAM);
    ordenarAlumnos( legajo, edad, sexo,   nota1,  nota2,  promedio, TAM);
    ordenarSexoLeg( legajo, edad, sexo,   nota1,  nota2,  promedio, TAM);
    return 0;
}
void mostrarAlumnos(int leg[],int age[], char sex[], int n1[], int n2[], float prom[],int tam)
{
    int i;
    printf("Legajo     Edad     Sexo     Nota 1     Nota 2     Promedio\n\n");
    for(i=0;i<tam;i++)
        {
            mostrarAlumno(leg[i], age[i], sex[i], n1[i], n2[i], prom[i]);
        }

}
void mostrarAlumno(int leg,int age, char sex, int n1, int n2, float prom)
{
    printf("  %d      %d         %c       %d          %d        %f\n\n",leg,age,sex,n1,n2,prom);
}
void ordenarAlumnos(int leg[],int age[], char sex[], int n1[], int n2[], float prom[],int tam)
{
    int auxInt;
    float auxFloat;
    char auxChar;
    int i;
    int j;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(leg[i]>leg[j])//Este punto define el ordenamiento, puedo cambiar leg por sex.
            {
                auxInt=leg[i];
                leg[i]=leg[j];
                leg[j]=auxInt;

                auxInt=age[i];
                age[i]=age[j];
                age[j]=auxInt;

                auxChar=sex[i];
                sex[i]=sex[j];
                sex[j]=auxChar;

                auxInt=n1[i];
                n1[i]=n1[j];
                n1[j]=auxInt;

                auxInt=n2[i];
                n2[i]=n2[j];
                n2[j]=auxInt;

                auxFloat=prom[i];
                prom[i]=prom[j];
                prom[j]=auxFloat;
            }
        }
    }

}
void ordenarSexoLeg(int leg[],int age[], char sex[], int n1[], int n2[], float prom[],int tam)
{
     int auxInt;
    float auxFloat;
    char auxChar;
    int i;
    int j;
    int swap=0;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(sex[i]>sex[j])
            {
                swap=1;

            }
            else if(sex[i]==sex[j] && leg[i]>leg[i])
            {
                swap=1;
            }
            if(swap)
            {
                auxInt=leg[i];
                leg[i]=leg[j];
                leg[j]=auxInt;

                auxInt=age[i];
                age[i]=age[j];
                age[j]=auxInt;

                auxChar=sex[i];
                sex[i]=sex[j];
                sex[j]=auxChar;

                auxInt=n1[i];
                n1[i]=n1[j];
                n1[j]=auxInt;

                auxInt=n2[i];
                n2[i]=n2[j];
                n2[j]=auxInt;

                auxFloat=prom[i];
                prom[i]=prom[j];
                prom[j]=auxFloat;
            }
        }
    }

}
