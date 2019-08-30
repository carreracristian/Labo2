#include <stdio.h>
#include <stdlib.h>

void getAreaCircle(float radio);

int main()
{
    float radio;

    printf("Ingrese radio: ");
    scanf("%f", &radio);

    getAreaCircle(radio);

    return 0;
}

void getAreaCircle(float radio)
{

    float area;

    area = 3.14 * radio * radio;

    printf("El area del circulo de radio %.2f es %.2f\n\n", radio, area);

}
