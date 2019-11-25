#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ok = 0;

    if( (pFile != NULL) && (pArrayListEmployee != NULL) )
    {
        Employee* auxEmployee;
        char auxParameters[7][128];

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxParameters[0], auxParameters[1], auxParameters[2], auxParameters[3], auxParameters[4], auxParameters[5], auxParameters[6]);

        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxParameters[0], auxParameters[1], auxParameters[2], auxParameters[3], auxParameters[4], auxParameters[5], auxParameters[6]);
            auxEmployee = employee_newParameters(auxParameters[0], auxParameters[1], auxParameters[2], auxParameters[3], auxParameters[4], auxParameters[5], auxParameters[6]);

            if(auxEmployee != NULL)
            {
                ll_add(pArrayListEmployee, auxEmployee);
                ok = 1;
            }
        }
    }

    return ok;
}

int parser_EmployeeListToText (FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ok = 0;

    if( (pFile != NULL) && (pArrayListEmployee != NULL) )
    {
        Employee* auxEmployee;
        char name[128], job[128], dedication[128];
        int id, age, workedHours, salary;
        int i;

        ll_sort(pArrayListEmployee, employee_sortByHours, 1);
        fprintf(pFile,"id,name,job,age,worked_hours,dedication,salary\n");

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);

            if(auxEmployee != NULL)
            {
                employee_getId(auxEmployee, &id);
                employee_getName(auxEmployee, name);
                employee_getJob(auxEmployee, job);
                employee_getAge(auxEmployee, &age);
                employee_getWorkedHours(auxEmployee, &workedHours);
                employee_getDedication(auxEmployee, dedication);

                fprintf(pFile,"%d,%s,%s,%d,%d,%s\n",id,name,job,age,workedHours,dedication);
            }
        }

        ok = 1;
    }

    return ok;
}

FILE* openFileRead(char* path , LinkedList* pArrayListEmployee)
{
    FILE* auxFile = NULL;

    if( (path != NULL) && (pArrayListEmployee != NULL) )
    {
        auxFile = fopen(path,"r");

        if(auxFile == NULL)
        {
            printf("\nNo es posible abrir el archivo.\n");
            exit(1);
        }

        parser_EmployeeFromText(auxFile, pArrayListEmployee);
        printf("\nArchivo cargado con exito.\n");
        fclose(auxFile);
    }

    return auxFile;
}

FILE* openFileWrite(char* path , LinkedList* pArrayListEmployee)
{
    FILE* auxFile = NULL;

    if( (path != NULL) && (pArrayListEmployee != NULL) )
    {
        auxFile = fopen(path,"w");

        if(auxFile == NULL)
        {
            printf("\nNo es posible abrir el archivo.\n");
            exit(1);
        }

        parser_EmployeeListToText(auxFile, pArrayListEmployee);
        printf("\nArchivo guardado con exito.\n");
        fclose(auxFile);
    }

    return auxFile;
}
