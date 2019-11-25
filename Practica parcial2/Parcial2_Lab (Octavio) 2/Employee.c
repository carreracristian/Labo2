#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Parser.h"

Employee* employee_new(void)
{
    Employee* auxEmployee = (Employee*) malloc (sizeof(Employee));
    return auxEmployee;
}

Employee* employee_newParameters(char* idStr , char* nameStr , char* jobStr , char* ageStr , char* workedHoursStr , char* dedicationStr , char*salaryStr )
{
    Employee* auxEmployee = employee_new();

    if( (auxEmployee != NULL) && (idStr != NULL) && (nameStr != NULL) && (jobStr != NULL) && (ageStr != NULL) && (workedHoursStr != NULL) && (dedicationStr != NULL) && (salaryStr != NULL) )
    {
        int auxId, auxAge, auxHours, auxSalary;

        auxId = atoi(idStr);
        auxAge = atoi(ageStr);
        auxHours = atoi(workedHoursStr);
        auxSalary = atoi(salaryStr);

        employee_setId(auxEmployee , auxId);
        employee_setName(auxEmployee , nameStr);
        employee_setJob(auxEmployee , jobStr);
        employee_setAge(auxEmployee , auxAge);
        employee_setWorkedHours(auxEmployee , auxHours);
        employee_setDedication(auxEmployee, dedicationStr);
        employee_setSalary(auxEmployee, auxSalary);
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


/***************************************************************** GETTERS ***********************************************************************/

int employee_getId(Employee* auxEmployee , int* auxId)
{
    int ok = 0;

    if( (auxEmployee != NULL) && (auxId != NULL) )
    {
        *auxId = auxEmployee->id;
        ok = 1;
    }

    return ok;
}

int employee_getName(Employee* auxEmployee , char* auxName )
{
    int ok = 0;

    if( (auxEmployee != NULL) && (auxName != NULL) )
    {
        strcpy(auxName, auxEmployee->name);
        ok = 1;
    }

    return ok;
}

int employee_getJob(Employee* auxEmployee , char* auxJob )
{
    int ok = 0;

    if( (auxEmployee != NULL) && (auxJob != NULL) )
    {
        strcpy(auxJob, auxEmployee->job);
        ok = 1;
    }

    return ok;
}

int employee_getAge(Employee* auxEmployee , int* auxAge )
{
    int ok = 0;

    if( (auxEmployee != NULL) && (auxAge != NULL) )
    {
        *auxAge = auxEmployee->age;
        ok = 1;
    }

    return ok;
}

int employee_getWorkedHours(Employee* auxEmployee , int* auxHours )
{
    int ok = 0;

    if( (auxEmployee != NULL) && (auxHours != NULL) )
    {
        *auxHours = auxEmployee->workedHours;
        ok = 1;
    }

    return ok;
}

int employee_getDedication(Employee* auxEmployee , char* auxDedication )
{
    int ok = 0;

    if( (auxEmployee != NULL) && (auxDedication != NULL) )
    {
        strcpy(auxDedication, auxEmployee->dedication);
        ok = 1;
    }

    return ok;
}

int employee_getSalary(Employee* auxEmployee , int* auxSalary )
{
    int ok = 0;

    if( (auxEmployee != NULL) && (auxSalary != NULL) )
    {
        *auxSalary = auxEmployee->salary;
        ok = 1;
    }

    return ok;
}

/********************************************************************* SETTERS **************************************************************************/


int employee_setId(Employee* auxEmployee , int auxId )
{
    int ok = 0;

    if( (auxEmployee != NULL) && (auxId > 0) )
    {
        auxEmployee->id = auxId;
        ok = 1;
    }

    return ok;
}

int employee_setName(Employee* auxEmployee , char* auxName )
{
    int ok = 0;

    if( (auxEmployee != NULL) && (auxName != NULL) )
    {
        strcpy(auxEmployee->name, auxName);
        ok = 1;
    }

    return ok;
}

int employee_setJob(Employee* auxEmployee , char* auxJob )
{
    int ok = 0;

    if( (auxEmployee != NULL) && (auxJob != NULL) )
    {
        strcpy(auxEmployee->job, auxJob);
        ok = 1;
    }

    return ok;
}

int employee_setAge(Employee* auxEmployee , int auxAge )
{
    int ok = 0;

    if( (auxEmployee != NULL) && (auxAge > 0) )
    {
        auxEmployee->age = auxAge;
        ok = 1;
    }

    return ok;
}

int employee_setWorkedHours(Employee* auxEmployee , int auxHours )
{
    int ok = 0;

    if( (auxEmployee != NULL) && (auxHours >= 0) )
    {
        auxEmployee->workedHours = auxHours;
        ok = 1;
    }

    return ok;
}

int employee_setDedication(Employee* auxEmployee , char* auxDedication )
{
    int ok = 0;

    if( (auxEmployee != NULL) && (auxDedication != NULL) )
    {
        strcpy(auxEmployee->dedication, auxDedication);
        ok = 1;
    }

    return ok;
}

int employee_setSalary(Employee* auxEmployee , int auxSalary )
{
    int ok = 0;

    if( (auxEmployee != NULL) && (auxSalary >= 0) )
    {
        auxEmployee->salary = auxSalary;
        ok = 1;
    }

    return ok;
}

/************************************************************************ PRINTS ***********************************************************************/


void employee_printHeader(void)
{
    printf("\n-------------------------------------------------------------------------------\n");
    printf("ID      NOMBRE       PROFESION    EDAD   HORAS TRABAJADAS  DEDICACION   SALARIO");
    printf("\n-------------------------------------------------------------------------------\n");
}

void employee_printEmployee(Employee* auxEmployee)
{
    if(auxEmployee != NULL)
    {
        int id, age, hours, salary;
        char name[128], job[128], dedication[128];

        employee_getId(auxEmployee, &id);
        employee_getName(auxEmployee, name);
        employee_getJob(auxEmployee, job);
        employee_getAge(auxEmployee, &age);
        employee_getWorkedHours(auxEmployee, &hours);
        employee_getDedication(auxEmployee, dedication);
        employee_getSalary(auxEmployee, &salary);

        printf("%d %12s %15s %6d %12d %17s %10d\n", id, name, job, age, hours, dedication, salary);
    }
}

void employee_printFooter(void)
{
    printf("-------------------------------------------------------------------------------\n");
}

void employee_printListOfEmployees(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL)
    {
        int i;
        Employee* auxEmployee;

        employee_printHeader();

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            employee_printEmployee(auxEmployee);
        }

        employee_printFooter();
    }
}



int employee_sortById(void* aux1,void* aux2)
{
    int returnAux = 0;

    if( (aux1 != NULL) && (aux2 != NULL) )
    {
        int id1, id2;

        employee_getId(aux1, &id1);
        employee_getId(aux2, &id2);

        if(id1 > id2)
            returnAux = 1;
        else
        {
            if(id1 < id2)
                returnAux = -1;
        }
    }

    return returnAux;
}

int employee_sortByHours(void* aux1,void* aux2)
{
    int returnAux = 0;

    if( (aux1 != NULL) && (aux2 != NULL) )
    {
        int hours1, hours2;

        employee_getWorkedHours(aux1, &hours1);
        employee_getWorkedHours(aux2, &hours2);

        if(hours1 > hours2)
            returnAux = 1;
        else
        {
            if(hours1 < hours2)
                returnAux = -1;
        }
    }

    return returnAux;
}

int employee_sortByName(void* aux1,void* aux2)
{
    int returnAux = 0;

    if( (aux1 != NULL) && (aux2 != NULL) )
    {
        char name1[50], name2[50];

        employee_getName(aux1,name1);
        employee_getName(aux2,name2);

        returnAux = strcmp(name1, name2);
    }

    return returnAux;
}

int employee_calculateDedication(void* auxEmployee)
{
    int returnAux = 0;

    if(auxEmployee != NULL)
    {
        int hours;
        auxEmployee = (Employee*)auxEmployee;

        employee_getWorkedHours(auxEmployee, &hours);

        if(hours > 0 && hours <= 200)
            employee_setDedication(auxEmployee, "estandar");
        if(hours > 200 && hours <= 300)
            employee_setDedication(auxEmployee, "sobre la media");
        if(hours > 300)
            employee_setDedication(auxEmployee, "excesivo");

        returnAux = 1;
    }

    return returnAux;
}

int employee_calculateSalary(void* auxEmployee , char* price)
{
    int returnAux = 0;
    int auxPrice;

    if(auxEmployee != NULL)
    {
        int hours, salary;
        auxEmployee = (Employee*)auxEmployee;
        employee_getWorkedHours(auxEmployee, &hours);

        auxPrice = atoi(price);

        salary = hours * auxPrice;
        employee_setSalary(auxEmployee, salary);

        returnAux = 1;
    }

    return returnAux;
}


int employee_filterUnder21(void* auxEmployee)
{
    int returnAux = 0;

    if(auxEmployee != NULL)
    {
        int age;
        auxEmployee = (Employee*)auxEmployee;

        employee_getAge(auxEmployee, &age);

        if(age < 21)
            returnAux = 1;
    }

    return returnAux;
}




int employee_menu(char* msj )
{
    int aux;
    printf(msj);
    fflush(stdin);
    scanf("%d", &aux);
    return aux;
}


int getString(char* msj, char* aux)
{
    int ok = 0;
    if(aux != NULL)
    {
        printf(msj);
        fflush(stdin);
        gets(aux);
        ok = 1;
    }
    return ok;
}

