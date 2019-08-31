#include <stdio.h>
#include <stdlib.h>
int getMax(int a, int b, int c);
int main()
{
    int a;
    int b;
    int c;

    printf("Ingrese numero 1: ");
    scanf("%d",&a);
    printf("Ingrese numero 2: ");
    scanf("%d",&b);
    printf("Ingrese numero 3: ");
    scanf("%d",&c);

    getMax(a, b, c);


    return 0;
}
int getMax(int a, int b, int c){

    int numMax;

    if(a>b && a>c){

        numMax=a;
    }
    if(b>a && b>c){

        numMax=b;
    }
    if(c>b && c>a){

        numMax=c;
    }

 printf("El mayor es: %d",numMax);

}
