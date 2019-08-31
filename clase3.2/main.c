#include <stdio.h>
#include <stdlib.h>
int getRango(int, int);
int main()
{
   int numMax;
   int numMin;

   printf("El maximo numero es: %d",numMax);
   scanf("%d",numMax);
   printf("El maximo numero es: %d",numMin);
   scanf("%d",numMin);

    return 0;
}
int getRango(int a, int b){

    int x;

    printf("Ingrese un numero entre %d y %d: ",a,b);
    scanf("%d",&x);

    while(x > a || x < b){

        printf("Numero invalido. Ingrese un numero entre 200 y 500: ");
        scanf("%d",&x);
    }



}
