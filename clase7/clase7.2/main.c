#include <stdio.h>
#include <stdlib.h>

void mostrarVectorChar(char vec[],int tam);
int main()
{
    //De la siguiente manera evitamos desbordamiento xq el dato de almacena en otra variable
    char nombre[20];
    char auxCad[100];

    //printf("Ingrese un nombre: ");
    fflush(stdin);
   // gets(auxCad);
    //Esto seria validacion tipica de una cadena caracteres
    while(strlen(auxCad)>19)
    {
        printf("Error. Reingrese un nombre: ");
        fflush(stdin);
        gets(auxCad);
    }
        //strcpy(nombre,auxCad);
    char cad1[20]="Hola";
    char cad2[20]="mundo";
    char cad3[39];
        //printf("El nombre es: %s",nombre);
    printf("%d",strcmp(cad1,cad2));//strcmp compara cadenas, si son iguales devuelve cer, iguales 1 y si el 2ndo es mayor tira -1
    strupr(cad1);//pasa a mayuscula
    strlwr(cad2);//pasa a minuscula
    printf("%s %s",cad1,cad2);
    if(strlen(cad1)+strlen(cad2))
    {
        strcat(cad1,cad2);
    }

    printf("");//concatena la segunda cadena con la primera solo si la suma de caracteres es menor a la cantidad reservada en la primer cadena
    //Si usamos stricmp no le importa si son mayusculas o minusculas
    /*char x[21]="Juan Sebastian Veron";
    char y[10];

    strncpy(y,x,9); //En vez de strcpy uso esta para que no haya dsbordamiento de memoria, pongo 9 xq y reserva un lugas para el barra cero
    y[9]='\0';//Hay que delimitarlo a mano el barra cero sino desborda
    printf("%s\n",y);
    printf("%d",strlen(x));//Este comando cuenta los caracteres de la cadena
   // mostrarVectorChar(l,20);*/

    return 0;
}
void mostrarVectorChar(char vec[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%c ",vec[i]);
    }
}
