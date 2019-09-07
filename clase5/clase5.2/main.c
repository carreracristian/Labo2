#include <stdio.h>
#include <stdlib.h>
void mostrarVectorInt(int vec[], int tam);
void cargarVectorInt(int vec[], int tam);
int mostrarNumMax(int vec[], int tam);
int mostrarNumMin(int vec[], int tam);
int main()
{
    int menor;
    int mayor;
    int suma=0,aux;
    int numeros[]={5,3,4,1,9};
    int i;
    int max=numeros[0],min=numeros[0];
     cargarVectorInt(numeros,5);
     mostrarVectorInt(numeros,5);
    for(i=0;i<5;i++)
       suma=suma+numeros[i];
       printf("\nLa suma es: %d",suma);

    mayor=mostrarNumMax(numeros,5);

    printf("\nEl mayor es: %d",mayor);

    menor=mostrarNumMin(numeros,5);

     printf("\nEl menor es: %d",menor);

    return 0;
}
void mostrarVectorInt(int vec[], int tam){
    int i;
    for(i=0;i<tam;i++){
        printf(" %d ",vec[i]);
    }
}
int mostrarNumMax(int vec[], int tam){
    int i, max=vec[0];

    for(i=0;i<tam;i++){
       if(vec[i]>max){
        max=vec[i];
        }
       }

       return max;
}
int mostrarNumMin(int vec[], int tam){
    int i, min=vec[0];
    for(i=0;i<tam;i++){
       if(vec[i]<min){
        min=vec[i];
        }
       }
        return min;
}
void cargarVectorInt(int vec[], int tam){
    int i, aux;
    for(i=0;i<tam;i++){
        printf("Ingrese un numero: ");
        scanf("%d",&aux);
        vec[i]=aux;
    }


}
