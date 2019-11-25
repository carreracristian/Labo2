#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"

int main()
{
    int option = 0, fileLoaded = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
    	getOnlyNumber("Menu de opciones:\n\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n3. Alta de empleado.\n4. Modificar datos de empleado.\n5. Baja de empleado.\n6. Listar empleados.\n7. Ordenar empleados.\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n10. Salir.\n\nElija la opcion deseada: ", "Ha ocurrido un error. Ingrese nuevamente: ", &option);
        switch(option)
        {
            case 1:
                if(fileLoaded == 0)
                {
                    controller_loadFromText("data.csv",listaEmpleados);
                    fileLoaded = 1;
                }
                else
                    printf("\nYa se ha cargado el archivo.\n\n");
                break;
            case 2:
                if(fileLoaded == 0)
                {
                    controller_loadFromBinary("data.bin",listaEmpleados);
                    fileLoaded = 1;
                }
                else
                    printf("\nYa se ha cargado el archivo.\n\n");
            	break;
            case 3:
                if(fileLoaded == 1)
                    controller_addEmployee(listaEmpleados);
                else
                    printf("\nNo se ha cargado ningun archivo.\n\n");
            	break;
            case 4:
                if(fileLoaded == 1)
                    controller_editEmployee(listaEmpleados);
                else
                    printf("\nNo se ha cargado ningun archivo.\n\n");
            	break;
            case 5:
                if(fileLoaded == 1)
                    controller_removeEmployee(listaEmpleados);
                else
                    printf("\nNo se ha cargado ningun archivo.\n\n");
            	break;
            case 6:
                if(fileLoaded == 1)
                {
                    ll_sort(listaEmpleados,employee_sortById,1);
                    controller_ListEmployee(listaEmpleados);
                }
                else
                    printf("\nNo se ha cargado ningun archivo.\n\n");
            	break;
            case 7:
                if(fileLoaded == 1)
                    controller_sortEmployee(listaEmpleados);
                else
                    printf("\nNo se ha cargado ningun archivo.\n\n");
            	break;
            case 8:
                if(fileLoaded == 1)
                    controller_saveAsText("data.csv",listaEmpleados);
                else
                    printf("\nNo se ha cargado ningun archivo.\n\n");
            	break;
            case 9:
                 if(fileLoaded == 1)
                    controller_saveAsBinary("data.bin",listaEmpleados);
                else
                    printf("\nNo se ha cargado ningun archivo.\n\n");
            	break;
            case 10:
            	printf("\nHasta luego.\n\n");
            	break;
            default:
                printf("\nOpcion incorrecta.\n\n");
            	break;
        }
        system("pause");
        system("cls");
    } while(option != 10);
    return 0;
}
