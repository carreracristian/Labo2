#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

int employee_get_id (Employee* ptrEmp,int* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrEmp->id;
            ret = 0;
        }
    }
    return ret;
}
int employee_get_name (Employee* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(this,ptrEmp->name);
            ret = 0;
        }
    }
    return ret;
}
int employee_get_jobTitle (Employee* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(this,ptrEmp->job_title);
            ret = 0;
        }
    }
    return ret;
}
int employee_get_age (Employee* ptrEmp,int* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrEmp->age;
            ret = 0;
        }
    }
    return ret;
}
int employee_get_workedHours (Employee* ptrEmp,int* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrEmp->worked_hours;
            ret = 0;
        }
    }
    return ret;
}
int employee_get_salary (Employee* ptrEmp,int* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            *this = ptrEmp->salary;
            ret = 0;
        }
    }
    return ret;
}

int employee_set_id (Employee* ptrEmp,int this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this>0)
        {
            ptrEmp->id = this;
            ret = 0;
        }
    }
    return ret;
}
int employee_set_name (Employee* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(ptrEmp->name,this);
            ret = 0;
        }
    }
    return ret;
}
int employee_set_jobTitle (Employee* ptrEmp,char* this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this!=NULL)
        {
            strcpy(ptrEmp->job_title,this);
            ret = 0;
        }
    }
    return ret;
}
int employee_set_age (Employee* ptrEmp,int this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this>0)
        {
            ptrEmp->age = this;
            ret = 0;
        }
    }
    return ret;
}
int employee_set_workedHours (Employee* ptrEmp,int this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this>-1)
        {
            ptrEmp->worked_hours = this;
            ret = 0;
        }
    }
    return ret;
}
int employee_set_salary (Employee* ptrEmp,int this)
{
    int ret = -1;
    if (ptrEmp!=NULL)
    {
        if (this>-1)
        {
            ptrEmp->salary = this;
            ret = 0;
        }
    }
    return ret;
}

Employee* employee_new (void)
{
    Employee* ret = NULL;
    ret = (Employee*)malloc(sizeof(Employee));
    return ret;
}
Employee* employee_new_parameters (int id,char* name,char* title,int age,int hours,int salary)
{
    Employee* ret = NULL;
    if (id>0)
    {
        if (name!=NULL)
        {
            if (title!=NULL)
            {
                if (age > 0)
                {
                    if (hours >=0)
                    {
                        if (salary>=0)
                        {
                            ret = employee_new();
                            employee_set_id(ret,id);
                            employee_set_name(ret,name);
                            employee_set_jobTitle(ret,title);
                            employee_set_age(ret,age);
                            employee_set_workedHours(ret,hours);
                            employee_set_salary(ret,salary);
                        }
                    }
                }
            }
        }
    }
    return ret;
}
Employee* employee_new_text (char* id,char* name,char* title,char* age,char* hours,char* salary)
{
    Employee* ret = NULL;
    if (id!=NULL&&name!=NULL&&title!=NULL&&age!=NULL&&hours!=NULL&&salary!=NULL)
    {
        int inid , inage , inhours , insalary;
        inid = atoi(id);
        inage = atoi(age);
        inhours = atoi(hours);
        insalary = atoi(salary);
        ret = employee_new_parameters(inid,name,title,inage,inhours,insalary);
    }
    return ret;
}
int employee_sortByName(void* ptrEmp1 ,void* ptrEmpTwo)
{
    int retVal = 0;
    if (ptrEmp1!=NULL&&ptrEmpTwo!=NULL)
    {
        ptrEmp1 = (Employee*)ptrEmp1;
        ptrEmpTwo = (Employee*)ptrEmpTwo;
        char auxName1 [128] , auxNameTwo [128];
        employee_get_name(ptrEmp1, auxName1);
        employee_get_name(ptrEmpTwo, auxNameTwo);
        retVal = strcmp(auxName1,auxNameTwo);
    }
    return retVal;
}
int employee_calculate_salary (void* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        int salary;
        this = (Employee*)this;
        employee_get_workedHours(this,&salary);
        salary = salary * 300;  // <-------------------- Salario por hora
        employee_set_salary(this,salary);
        retVal = -1;
    }
    return retVal;
}
/* employee_toString (Employee* this, char retStr)
{
    int retVal = -1;
    if (this!=NULL&&retStr!=NULL)
    {
        char buffer [6][128];
        int id , age , hours , salary;
        employee_get_id(this,&id);
        employee_get_name(this,buffer[1]);
        employee_get_jobTitle(this,buffer[2]);
        employee_get_age(this,&age);
        employee_get_workedHours(this,&hours);
        employee_get_salary(this,salary);
        strcpy(buffer[0],itoa())
    }
    return retVal;
}*/
int employee_filter (void* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        retVal = 0;
        int temp;
       // char str [128];
        this = (Employee*)this;
        employee_get_age(this,&temp);
        if (temp>40)
        {
            retVal = 1;
        }
    }
    return retVal;
}
void employee_print_header (void)
{
    printf("\n");
    printf(" ------------------------------------------------------------------------------------------------------\n");
    printf("| ID   |     Nombre                |    Puesto                                | Edad | Horas | Sueldo  |\n");
    printf(" ------------------------------------------------------------------------------------------------------\n");
}
void employee_print_footer (void)
{
    printf(" ------------------------------------------------------------------------------------------------------\n");
}
void employee_print_employee (Employee* this)
{
    if (this!=NULL)
    {
        int id , age , hours , salary;
        char temp [128];
        char temp2 [128];
        employee_get_id(this,&id);
        employee_get_name(this,temp);
        employee_get_jobTitle(this,temp2);
        employee_get_age(this,&age);
        employee_get_workedHours(this,&hours);
        employee_get_salary(this,&salary);
        printf("| %4d | %25s | %40s | %4d | %5d | %7d |\n",id,temp,temp2,age,hours,salary);
    }
}







