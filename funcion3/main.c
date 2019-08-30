#include <stdio.h>
#include <stdlib.h>

float getAreaCircle( );

int main()
{
    float area;

    area = getAreaCircle();

     printf("El area del circulo es %.2f\n\n", area);

    return 0;
}

float getAreaCircle( ){

    float radio;
    float area;

    printf("Ingrese radio: ");
    scanf("%f", &radio);

    area = 3.14 * radio * radio;

    return area;

}
