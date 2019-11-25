#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Parser.h"

int main()
{
    LinkedList* pArrayListEmployee = ll_newLinkedList();
    LinkedList* pArraySubList;
    int option, flag = 0;

    do
    {
        option = employee_menu( "1. Cargar archivo 'datos.csv'.\n"
                                                        "2. Listar empleados por nombre (ascendente).\n"
                                                        "3. Cargar 'Dedicacion' de empleados.\n"
                                                        "4. Listar empleados por dedicacion (ascendente).\n"
                                                        "5. Generar listado con empleados menores de 21 anios.\n"
                                                        "6. Guardar resultados en 'resultados.csv'.\n"
                                                        "7. Salir.\n\n"
                                                        "Elegir opcion: ");

        switch(option)
        {
            case 1:
                if(flag == 0)
                {
                    openFileRead("datos.csv", pArrayListEmployee);
                    flag = 1;
                }
                else
                    printf("\nEl archivo ya ha sido cargado.\n");
                break;

            case 2:
                if(flag == 1)
                {
                    ll_sort(pArrayListEmployee, employee_sortByName, 1);
                    employee_printListOfEmployees(pArrayListEmployee);
                }
                else
                    printf("\nEl archivo aun no ha sido cargado.\n");
                break;

            case 3:
                if(flag == 1)
                {
                    ll_map(pArrayListEmployee, employee_calculateDedication);
                    printf("\nHa sido cargada la columna de Dedicacion.\n");
                }
                else
                    printf("\nEl archivo aun no ha sido cargado.\n");
                break;

            case 4:
                if(flag == 1)
                {
                    ll_sort(pArrayListEmployee, employee_sortByHours, 1);
                    employee_printListOfEmployees(pArrayListEmployee);
                }
                else
                    printf("\nEl archivo aun no ha sido cargado.\n");
                break;

            case 5:
                if(flag == 1)
                {
                    pArraySubList = ll_filter(pArrayListEmployee, employee_filterUnder21);
                    ll_sort(pArraySubList, employee_sortById, 1);
                    employee_printListOfEmployees(pArraySubList);
                }
                else
                    printf("\nEl archivo aun no ha sido cargado.\n");
                break;

            case 6:
                if(flag == 1)
                {
                    openFileWrite("resultados.csv", pArraySubList);
                }
                else
                    printf("\nEl archivo aun no ha sido cargado.\n");
                    break;

            case 7:
                printf("\nSaliendo...\n");
                break;

            default:
                printf("\nOpcion incorrecta.\n");
                break;

        }

        system("pause");
        system("cls");

    } while(option != 7);

    return 0;
}


