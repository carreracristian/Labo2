#include <stdio.h>
#include <stdlib.h>

 float getAreaCircle(float radio);

int main()
{
    float radio;
    float area;

    printf("Ingrese radio: ");
    scanf("%f", &radio);


    area = getAreaCircle(radio);

    printf("El area del circulo de radio %.2f es %.2f\n\n", radio, area);




    return 0;
}

/** \brief Calcula el area de un circulo
 *
 * \param radio es el radio de la circunferencia
 *
 * \return devuelve el area del circulo
 *
 */

float getAreaCircle(float radio){

    float area;

    area = 3.14 * radio * radio;

    return area;
}



