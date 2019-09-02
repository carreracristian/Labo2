#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main()
{
    int opcion;
    float primerOperando=0;
    float segundoOperando=0;
    int numeroUnoIngresado=0;
    int numeroDosIngresado=0;
    int operacionesRealizadas=0;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    float factorialPrimero;
    float factorialSegundo;

    do
    {
        opcion=menuDeOpciones(primerOperando,segundoOperando);
        switch(opcion)
        {
            case 1:
                primerOperando=pedirNumero("\nIngrese el 1er operando: ");
                numeroUnoIngresado=1;
                break;

            case 2:
                segundoOperando=pedirNumero("\nIngrese el 2do operando: ");
                numeroDosIngresado=1;
                break;

            case 3:
                if(numeroUnoIngresado==1 && numeroDosIngresado==1)
                {
                    printf("\nCalculando todas las operaciones...\n\n");
                    suma=operacionSumar(primerOperando,segundoOperando);
                    resta=operacionRestar(primerOperando,segundoOperando);
                    division=operacionDividir(primerOperando,segundoOperando);
                    multiplicacion=operacionMultiplicar(primerOperando,segundoOperando);
                    factorialPrimero=operacionFactorial(primerOperando);
                    factorialSegundo=operacionFactorial(segundoOperando);
                    operacionesRealizadas=1;
                }
                else
                {
                    printf("\nATENCION!!!\nDeben ingresarse dos numeros para calcular las operaciones.\n\n");
                }

                break;

            case 4:
                if(numeroUnoIngresado==1 && numeroDosIngresado==1)
                {
                    if(operacionesRealizadas==1)
                    {
                        printf("\nInformando resultados:\n");
                        informarSuma(primerOperando,segundoOperando,suma);
                        informarResta(primerOperando,segundoOperando,resta);
                        informarDivision(primerOperando,segundoOperando,division);
                        informarMultiplicacion(primerOperando,segundoOperando,multiplicacion);
                        informarFactorial(primerOperando,segundoOperando,factorialPrimero,factorialSegundo);
                    }
                    else
                    {
                        printf("\nATENCION!!!\nDeben calcularse las operaciones primero.\n\n");
                    }
                }
                else
                {
                    printf("\nATENCION!!!\nDeben ingresarse dos numeros y calcularse las operaciones.\n\n");
                }

                break;

            case 5:
                printf("\nSaliendo...\n\n");
                break;

            default:
                printf("\nOpcion incorrecta!!!\n\n");
                break;
        }

        system("pause");
        system("cls");

    } while(opcion!=5);

    return 0;
}
