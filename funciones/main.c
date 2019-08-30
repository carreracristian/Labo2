#include <stdio.h>
#include <stdlib.h>



int main()
{

    float radio;
    float area;

    printf("Ingrese radio: ");
    scanf("%f", &radio);

    area = 3.14 * radio * radio;

    printf("El area del circulo de radio %.2f es %.2f\n\n", radio, area);


    return 0;
}
