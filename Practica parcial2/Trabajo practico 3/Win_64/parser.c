#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ok = 0;
    if( (pFile != NULL) && (pArrayListEmployee != NULL) )
    {
        Employee* auxEmployee;
        char auxId[50], auxNombre[50], auxHoras[50], auxSueldo[50];
        fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", auxId, auxNombre, auxHoras, auxSueldo);
        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", auxId, auxNombre, auxHoras, auxSueldo);
            auxEmployee = employee_newParametros(auxId, auxNombre, auxHoras, auxSueldo);
            if(auxEmployee != NULL)
            {
                ll_add(pArrayListEmployee, auxEmployee);
                ok = 1;
            }
        }
    }
    return ok;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ok = 0, leidos = 0;
    if( (pFile != NULL) && (pArrayListEmployee != NULL) )
    {
        Employee* auxEmployee = employee_new();
        leidos = fread(auxEmployee, sizeof(Employee), 1, pFile);
        while(leidos != 0)
        {
            ll_add(pArrayListEmployee, auxEmployee);
            auxEmployee = employee_new();
            leidos = fread(auxEmployee, sizeof(Employee), 1, pFile);
        }
        ok = 1;
    }
    return ok;
}
