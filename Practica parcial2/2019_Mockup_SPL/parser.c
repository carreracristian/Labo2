#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "LinkedList.h"
#include "employee.h"

FILE* openFILE (char* filename)
{
    FILE* ret = NULL;
    if (filename!=NULL)
    {
        ret = fopen(filename,"r");
    }
    return ret;
}
FILE* openFILEwrite(char* filename)
{
    FILE* ret = NULL;
    if (filename!=NULL)
    {
        ret = fopen(filename,"w");
    }
    return ret;
}
int parser_EmployeeFromText(FILE* pFile , void* this)
{
    int retVal = 0;
    if (pFile!=NULL&&this!=NULL)
    {
        this = (LinkedList*)this;
        char buffer [6][128];
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
        while (!feof(pFile))
        {
            Employee* new_employee;
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);// "%[^,],%[^,],%[^,],%[^\n]\n"
            new_employee = employee_new_text(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
            if (new_employee!=NULL)
            {
                ll_add(this,new_employee);
                retVal++;
            }
        }
    }
    return retVal;
}

int parser_EmployeeListToText (FILE* pFile, void* this)
{
    int retVal = 0;
    if (pFile!=NULL&&this!=NULL)
    {
        this = (LinkedList*)this;
        char name[128] , title[128];
        int id , age , hours , salary;
        Employee* auxEmp;
        int i;
        fprintf(pFile,"id,first_name,job_title,age,worked_hours,salary\n");
        for (i=0;i<ll_len(this);i++)
        {
            auxEmp = (Employee*)ll_get(this,i);
            if (auxEmp!=NULL)
            {
                employee_get_id(auxEmp,&id);
                employee_get_name(auxEmp,name);
                employee_get_jobTitle(auxEmp,title);
                employee_get_age(auxEmp,&age);
                employee_get_workedHours(auxEmp,&hours);
                employee_get_salary(auxEmp,&salary);
                fprintf(pFile,"%d,%s,%s,%d,%d,%d\n",id,name,title,age,hours,salary);
            }
        }
        retVal = 0;
    }
    return retVal;
}
