#include <stdio.h>
#include "biblioteca.h"

int menuDeOpciones(float a, float b)
{
    int opcion;
    printf("Menu de la calculadora:\n");
    printf("\n1) Ingresar 1er operando: (A= %.1f)", a);
    printf("\n\n2) Ingresar 2do operando: (B= %.1f)", b);
    printf("\n\n3) Calcular todas las operaciones.");
    printf("\n\ta. Calcular la suma (A+B)");
    printf("\n\tb. Calcular la resta (A-B)");
    printf("\n\tc. Calcular la division (A/B)");
    printf("\n\td. Calcular la multiplicacion (A*B)");
    printf("\n\te. Calcular el factorial (A!) (B!)");
    printf("\n\n4) Informar resultados.");
    printf("\n\n5) Salir");
    printf("\n\nIngrese la opcion deseada: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while (opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5)
    {
        printf("\nOpcion incorrecta!!!\n");
        printf("Ingrese la opcion deseada: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}

float pedirNumero(char mensaje[])
{
    float a;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f", &a);
    return a;
}

float operacionSumar(float a, float b)
{
    float resultado=a+b;
    return resultado;
}

float operacionRestar(float a, float b)
{
    float resultado=a-b;
    return resultado;
}

float operacionDividir(float a, float b)
{
    float resultado=a/b;
    if(a==0 && b<0)
    {
        resultado=0;
    }
    return resultado;
}

float operacionMultiplicar(float a, float b)
{
    float resultado=a*b;
    if( (a<0 && b==0) || (a==0 && b<0) )
    {
        resultado=0;
    }
    return resultado;
}

int operacionFactorial(float a)
{
    int numero;
    int resultado;
    numero=(int)a;
    if(numero<0)
    {
        resultado=0;
    }
    else
    {
        if(numero==0 || numero==1)
        {
            resultado=1;
        }
        else
        {
            resultado=(numero*operacionFactorial(numero-1));
        }
    }

    return resultado;
}

void informarSuma(float a, float b, float c)
{
    printf("\na) El resultado de: %.1f + %.1f es: %.1f\n",a,b,c);
}

void informarResta(float a, float b, float c)
{
    printf("\nb) El resultado de: %.1f - %.1f es: %.1f\n",a,b,c);
}

void informarDivision(float a, float b, float c)
{
    if(b==0)
    {
        printf("\nc) No es posible dividir a un numero entre cero.\n");
    }
    else
    {
        printf("\nc) El resultado de: %.1f / %.1f es: %.1f\n",a,b,c);
    }
}

void informarMultiplicacion(float a, float b, float c)
{
    printf("\nd) El resultado de: %.1f * %.1f es: %.1f\n",a,b,c);
}

void informarFactorial(float a, float b, float c, float d)
{
    if(a<0 && b<0)
    {
        printf("\ne) No se puede calcular el factorial de un numero negativo (A= %.1f).",a);
        printf("\n   No se puede calcular el factorial de un numero negativo (B= %.1f).\n\n",b);
    }
    else
    {
        if(a<0)
        {
            printf("\ne) No se puede calcular el factorial de un numero negativo (A= %.1f).",a);
            printf("\n   El factorial de %.1f es: %.1f\n\n",b,d);
        }
        else
        {
            if(b<0)
            {
                printf("\ne) El factorial de %.1f es: %.1f",a,c);
                printf("\n   No se puede calcular el factorial de un numero negativo (B= %.1f).\n\n",b);
            }
            else
            {
                printf("\ne) El factorial de %.1f es: %.1f\n   El factorial de %.1f es: %.1f\n\n",a,c,b,d);
            }
        }
    }
}
