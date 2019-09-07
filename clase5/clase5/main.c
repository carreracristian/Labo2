#include <stdio.h>
#include <stdlib.h>

int main()
{
    int suma=0,aux;
    int numeros[]={5,3,4,1,9};
    int i;

    for(i=0;i<5;i++){
        printf("Ingrese un numero: ");
        scanf("%d",&aux);
        numeros[i]=aux;
    }
    for(i=0;i<5;i++){
       printf(" %d ",numeros[i]);
    }
    //printf("%d",*numeros);"numeros" direccion de memoria del primer elemento.
    //Acceso aleatorio = printf("%d",numeros[4]);
    for(i=0;i<5;i++)
       suma=suma+numeros[i];
       printf("\nLa suma es: %d",suma);

    printf("\n\n");
    return 0;
}
