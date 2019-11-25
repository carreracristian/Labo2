#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int ok = 0;
    if( (path != NULL) && (pArrayListEmployee != NULL) )
    {
        FILE* auxFile = fopen(path,"r");
        if(auxFile == NULL)
        {
            printf("\nNo se pudo cargar el archivo.\n\n");
            exit(1);
        }
        parser_EmployeeFromText(auxFile, pArrayListEmployee);
        printf("\nArchivo cargado con exito (modo texto).\n\n");
        ok = 1;
        fclose(auxFile);
    }
    return ok;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ok = 0;
    if( (path != NULL) && (pArrayListEmployee != NULL) )
    {
        FILE* auxFile = fopen(path, "rb");
        if(auxFile == NULL)
        {
            printf("\nNo se pudo cargar el archivo.\n\n");
            exit(1);
        }
        parser_EmployeeFromBinary(auxFile, pArrayListEmployee);
        printf("\nArchivo cargado con exito (modo binario).\n\n");
        ok = 1;
        fclose(auxFile);
    }
    return ok;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 0;
    if(pArrayListEmployee != NULL)
    {
        Employee* auxEmployee = employee_new();
        char auxNombre[50];
        int auxId, auxSueldo, auxHoras;
        auxId = employee_generateId(pArrayListEmployee);
        getOnlyLetter("Ingrese el nombre: ", "Ha ocurrido un error. Ingrese nuevamente: ", auxNombre);
        getOnlyNumber("Ingrese las horas trabajadas: ", "Ha ocurrido un error. Ingrese nuevamente: ", &auxHoras);
        getOnlyNumber("Ingrese el sueldo: ", "Ha ocurrido un error. Ingrese nuevamente: ", &auxSueldo);
        if(auxEmployee != NULL)
        {
            employee_setId(auxEmployee, auxId);
            employee_setNombre(auxEmployee, auxNombre);
            employee_setHorasTrabajadas(auxEmployee, auxHoras);
            employee_setSueldo(auxEmployee, auxSueldo);
            ll_add(pArrayListEmployee, auxEmployee);
            printf("\nAlta exitosa.\n\n");
            ok = 1;
        }
    }
    return ok;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ok = -1;
    if(pArrayListEmployee != NULL)
    {
        Employee* auxEmployee;
        char auxNombre[50];
        int indice, option, auxId, arrayId, auxHoras, auxSueldo;
        getOnlyNumber("\nIngrese el numero de ID: ", "Ha ocurrido un error. Ingrese nuevamente: ", &auxId);
        for(indice=0; indice < ll_len(pArrayListEmployee); indice++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, indice);
            employee_getId(auxEmployee, &arrayId);
            if(auxId == arrayId)
            {
                printf("\nID encontrado.\n");
                ok = 0;
                break;
            }
            else
                ok = -2;
        }
        if(ok == 0)
        {
            printf("\nOpcion 1: Modificar Nombre.\nOpcion 2: Modificar Horas Trabajadas.\nOpcion 3: Modificar Sueldo.\nOpcion 4: Cancelar.\n");
            getOnlyNumber("Que campo desea modificar: ", "Ha ocurrido un error. Ingrese nuevamente: ", &option);
            switch(option)
            {
                case 1:
                    getOnlyLetter("\nIngrese el nuevo nombre: ", "Ha ocurrido un error. Ingrese nuevamente: ", auxNombre);
                    employee_setNombre(auxEmployee, auxNombre);
                    printf("\nModificacion exitosa.\n\n");
                    ok = 1;
                    break;
                case 2:
                    getOnlyNumber("\nIngrese las nuevas horas: ", "Ha ocurrido un error. Ingrese nuevamente: ", &auxHoras);
                    employee_setHorasTrabajadas(auxEmployee, auxHoras);
                    printf("\nModificacion exitosa.\n\n");
                    ok = 1;
                    break;
                case 3:
                    getOnlyNumber("\nIngrese el nuevo sueldo: ", "Ha ocurrido un error. Ingrese nuevamente: ", &auxSueldo);
                    employee_setSueldo(auxEmployee, auxSueldo);
                    printf("\nModificacion exitosa.\n\n");
                    ok = 1;
                    break;
                case 4:
                    printf("\nModificacion cancelada.\n\n");
                    break;
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    break;
            }
        }
        else
        {
            if(ok == -2)
                printf("\nID inexistente.\n\n");
        }
    }
    return ok;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ok = -1;
    if(pArrayListEmployee != NULL)
    {
        Employee* auxEmployee;
        int indice, option, auxId, arrayId;
        getOnlyNumber("\nIngrese el numero de ID: ", "Ha ocurrido un error. Ingrese nuevamente: ", &auxId);
        for(indice=0; indice < ll_len(pArrayListEmployee); indice++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, indice);
            employee_getId(auxEmployee, &arrayId);
            if(auxId == arrayId)
            {
                printf("\nID encontrado.\n");
                ok = 0;
                break;
            }
            else
                ok = -2;
        }
        if(ok == 0)
        {
            getOnlyNumber("Esta seguro que desea dar la baja (1 = Si || 0 = No): ", "Ha ocurrido un error. Ingrese nuevamente: ", &option);
            switch(option)
            {
                case 0:
                    printf("\nBaja cancelada.\n\n");
                    break;
                case 1:
                    employee_delete(auxEmployee);
                    ll_remove(pArrayListEmployee, indice);
                    printf("\nBaja exitosa.\n\n");
                    ok = 1;
                    break;
                default:
                    printf("\nOpcion incorrecta.\n\n");
                    break;
            }
        }
        else
        {
            if(ok == -2)
                printf("\nID inexistente.\n\n");
        }
    }
    return ok;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 0;
    if( pArrayListEmployee != NULL)
    {
        Employee* auxEmployee;
        int indice, auxId, auxSueldo, auxHoras;
        char auxNombre[50];
        employee_headers();
        for(indice = 0; indice < ll_len(pArrayListEmployee); indice++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, indice);
            employee_getId(auxEmployee, &auxId);
            employee_getNombre(auxEmployee, auxNombre);
            employee_getHorasTrabajadas(auxEmployee, &auxHoras);
            employee_getSueldo(auxEmployee, &auxSueldo);
            employee_showAnEmployee(auxId, auxNombre, auxHoras, auxSueldo);
        }
        printf("\n");
        ok = 1;
    }
    return ok;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 0;
    if(pArrayListEmployee != NULL)
    {
        employee_sortList(pArrayListEmployee);
        ok = 1;
    }
    return ok;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int ok = 0, indice;
    if( (path != NULL) && (pArrayListEmployee != NULL) )
    {
        FILE* auxFile = fopen(path,"w");
        if(auxFile == NULL)
        {
            printf("\nNo se pudo guardar el archivo.\n\n");
            exit(1);
        }
        Employee* auxEmployee;
        int *auxId = (int*) malloc (sizeof(int));
        char *auxNombre = (char*) malloc (sizeof(char));
        int *auxHoras = (int*) malloc (sizeof(int));
        int *auxSueldo = (int*) malloc (sizeof(int));
        ll_sort(pArrayListEmployee, employee_sortById, 1);
        fprintf(auxFile,"id,nombre,horasTrabajadas,sueldo\n");
        for(indice=0; indice<ll_len(pArrayListEmployee); indice++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, indice);
            employee_getId(auxEmployee, auxId);
            employee_getNombre(auxEmployee, auxNombre);
            employee_getHorasTrabajadas(auxEmployee, auxHoras);
            employee_getSueldo(auxEmployee, auxSueldo);
            fprintf(auxFile,"%d,%s,%d,%d\n",*auxId, auxNombre, *auxHoras, *auxSueldo);
        }
        fclose(auxFile);
        printf("\nArchivo guardado con exito (modo texto).\n\n");
        ok = 1;
    }
    return ok;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ok = 0, indice;
    if( (path != NULL) && (pArrayListEmployee != NULL) )
    {
        FILE* auxFile;
        auxFile = fopen(path, "wb");
        if(auxFile == NULL)
        {
            printf("\nNo se pudo cargar el archivo.\n\n");
            exit(1);
        }
        Employee* auxEmployee;
        ll_sort(pArrayListEmployee, employee_sortById, 1);
        for(indice=0; indice < ll_len(pArrayListEmployee); indice++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, indice);
            fwrite(auxEmployee, sizeof(Employee), 1, auxFile);
        }
        printf("\nArchivo cargado con exito (modo binario).\n\n");
        ok = 1;
        fclose(auxFile);
    }
    return ok;
}
