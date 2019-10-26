#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* aux;
    int* numeros=(int*)malloc(sizeof(int)+5);

    for(int i=0;i<5;i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d",numeros+i);
    }
    for(int i=0;i<5;i++)
    {
        printf("El numero es: %d \n",*(numeros+i));
    }
    numeros=(int*)realloc(numeros,sizeof(int)*10);
    if(aux!=NULL)
    {
        numeros=aux;
    }
    for(int i=0;i<10;i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d",numeros+i);
    }
    for(int i=0;i<10;i++)
    {
        printf("El numero es: %d \n",*(numeros+i));
    }

    numeros=(int*)realloc(numeros,sizeof(int)*6);

    for(int i=0;i<6;i++)
    {
        printf("Ingrese un numero: \n");
        scanf("%d",numeros+i);
    }
    for(int i=0;i<6;i++)
    {
        printf("El numero es: %d \n",*(numeros+i));
    }
    free(numeros);
    return 0;
}
