#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"

Employee* employee_new()
{
    Employee* auxEmployee = (Employee*) malloc (sizeof(Employee));
    return auxEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* auxEmployee = employee_new();
    int auxId, auxHoras, auxSueldo;
    auxId= atoi(idStr);
    auxHoras= atoi(horasTrabajadasStr);
    auxSueldo= atoi(sueldoStr);
    if( (auxEmployee != NULL) && (idStr != NULL) && (nombreStr != NULL) && (horasTrabajadasStr != NULL) && (sueldoStr != NULL) )
    {
        employee_setNombre(auxEmployee, nombreStr);
        employee_setId(auxEmployee, auxId);
        employee_setHorasTrabajadas(auxEmployee, auxHoras);
        employee_setSueldo(auxEmployee, auxSueldo);
    }
    else
        employee_delete(auxEmployee);
    return auxEmployee;
}

void employee_delete(Employee* auxEmployee)
{
    if(auxEmployee != NULL)
        free(auxEmployee);
}

int employee_setId(Employee* auxEmployee,int id)
{
    int ok = 0;
    if( (auxEmployee != NULL) && (id >= 0) )
    {
        auxEmployee->id = id;
        ok = 1;
    }
    return ok;
}

int employee_getId(Employee* auxEmployee,int* id)
{
    int ok = 0;
    if( (auxEmployee != NULL) && (id != NULL) )
    {
        *id = auxEmployee->id;
        ok = 1;
    }
    return ok;
}

int employee_setNombre(Employee* auxEmployee,char* nombre)
{
    int ok = 0;
    if( (auxEmployee != NULL) && (nombre != NULL) )
    {
        strcpy(auxEmployee->nombre, nombre);
        ok = 1;
    }
    return ok;
}

int employee_getNombre(Employee* auxEmployee,char* nombre)
{
    int ok = 0;
    if( (auxEmployee != NULL) && (nombre != NULL) )
    {
        strcpy(nombre, auxEmployee->nombre);
        ok = 1;
    }
    return ok;
}

int employee_setHorasTrabajadas(Employee* auxEmployee,int horasTrabajadas)
{
    int ok = 0;
    if( (auxEmployee != NULL) && (horasTrabajadas >= 0) )
    {
        auxEmployee->horasTrabajadas = horasTrabajadas;
        ok = 1;
    }
    return ok;
}

int employee_getHorasTrabajadas(Employee* auxEmployee,int* horasTrabajadas)
{
    int ok = 0;
    if( (auxEmployee != NULL) && (horasTrabajadas != NULL) )
    {
        *horasTrabajadas = auxEmployee->horasTrabajadas;
        ok = 1;
    }
    return ok;
}

int employee_setSueldo(Employee* auxEmployee,int sueldo)
{
    int ok = 0;
    if(auxEmployee != NULL)
    {
        auxEmployee->sueldo = sueldo;
        ok = 1;
    }
    return ok;
}

int employee_getSueldo(Employee* auxEmployee,int* sueldo)
{
    int ok = 0;
    if( (auxEmployee != NULL) && (sueldo != NULL) )
    {
        *sueldo = auxEmployee->sueldo;
        ok = 1;
    }
    return ok;
}

void employee_headers(void)
{
    printf("\n             ID             NOMBRE            HORAS         SUELDO\n");
    printf("           __________________________________________________________\n\n");
}

void employee_showAnEmployee(int id, char* nombre, int horas, int sueldo)
{
    printf("%15d %18s %15d %15d\n", id, nombre, horas, sueldo);
}

int employee_generateId(LinkedList* pArrayListEmployee)
{
    int indice, auxId, idGenerado = 0, anteriorId;
    Employee* auxEmployee;
    if( (pArrayListEmployee != NULL) )
    {
        if( (ll_len(pArrayListEmployee)) > 0)
        {
            for(indice=0; indice<(ll_len(pArrayListEmployee)); indice++)
            {
                auxEmployee = (Employee*) ll_get(pArrayListEmployee, indice);
                employee_getId(auxEmployee, &auxId);
                if(auxId > idGenerado)
                {
                    anteriorId = idGenerado;
                    idGenerado = auxId;
                    if(anteriorId+1 != idGenerado)
                    {
                        idGenerado = anteriorId;
                        break;
                    }
                }
            }
        }
    }
    return (idGenerado+1);
}

int employee_sortById(void* aux1,void* aux2)
{
    int id1, id2, comparacion = 0;
    employee_getId(aux1, &id1);
    employee_getId(aux2, &id2);
    if(id1 > id2)
        comparacion = 1;
    else
    {
        if(id1 < id2)
            comparacion = -1;
    }
    return comparacion;
}

int employee_sortByName(void* aux1,void* aux2)
{
    char name1[50], name2[50];
    employee_getNombre(aux1,name1);
    employee_getNombre(aux2,name2);
    int comparacion = strcmp(name1, name2);
    return comparacion;
}

int employee_sortByHours(void* aux1,void* aux2)
{
    int hour1, hour2, comparacion = 0;
    employee_getHorasTrabajadas(aux1, &hour1);
    employee_getHorasTrabajadas(aux2, &hour2);
    if(hour1 > hour2)
        comparacion = 1;
    else
    {
        if(hour1 < hour2)
            comparacion = -1;
    }
    return comparacion;
}

int employee_sortBySalary(void* aux1,void* aux2)
{
    int salary1, salary2, comparacion = 0;
    employee_getSueldo(aux1, &salary1);
    employee_getSueldo(aux2, &salary2);
    if(salary1 > salary2)
        comparacion = 1;
    else
    {
        if(salary1 < salary2)
            comparacion = -1;
    }
    return comparacion;
}

int employee_sortList(LinkedList* pArrayListEmployee)
{
    int option, ok = 0;
    if(pArrayListEmployee != NULL)
    {
        getOnlyNumber("\n1. Ordenar empleados por ID (Ascendente).\n2. Ordenar empleados por ID (Descendente).\n3. Ordenar empleados por Nombre (Ascendente).\n4. Ordenar empleados por Nombre (Descendente).\n5. Ordenar empleados por Horas Trabajadas (Ascendente).\n6. Ordenar empleados por Horas Trabajadas (Descendente).\n7. Ordenar empleados por Salario (Ascendente).\n8. Ordenar empleados por Salario (Descendente).\n9. Cancelar.\n\nElija la opcion deseada: ", "Ha ocurrido un error. Ingrese nuevamente: ", &option);
        switch(option)
        {
            case 1:
                printf("\nOrdenando... Por favor, aguarde un momento.\n");
                ll_sort(pArrayListEmployee, employee_sortById, 1);
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 2:
                printf("\nOrdenando... Por favor, aguarde un momento.\n");
                ll_sort(pArrayListEmployee, employee_sortById, 0);
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 3:
                printf("\nOrdenando... Por favor, aguarde un momento.\n");
                ll_sort(pArrayListEmployee, employee_sortByName, 1);
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 4:
                printf("\nOrdenando... Por favor, aguarde un momento.\n");
                ll_sort(pArrayListEmployee, employee_sortByName, 0);
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 5:
                printf("\nOrdenando... Por favor, aguarde un momento.\n");
                ll_sort(pArrayListEmployee, employee_sortById, 1);
                ll_sort(pArrayListEmployee, employee_sortByHours, 1);
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 6:
                printf("\nOrdenando... Por favor, aguarde un momento.\n");
                ll_sort(pArrayListEmployee, employee_sortById, 1);
                ll_sort(pArrayListEmployee, employee_sortByHours, 0);
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 7:
                printf("\nOrdenando... Por favor, aguarde un momento.\n");
                ll_sort(pArrayListEmployee, employee_sortById, 1);
                ll_sort(pArrayListEmployee, employee_sortBySalary, 1);
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 8:
                printf("\nOrdenando... Por favor, aguarde un momento.\n");
                ll_sort(pArrayListEmployee, employee_sortById, 1);
                ll_sort(pArrayListEmployee, employee_sortBySalary, 0);
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 9:
                printf("\nRegresando al menu principal.\n");
                break;
            default:
                printf("\nOpcion invalida.\n");
                break;
            }
        ok = 1;
    }
    return ok;
}
