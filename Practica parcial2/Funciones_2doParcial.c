int employee_calculateSalary(void* auxEmployee)
{
    int returnAux = 0;

    if(auxEmployee != NULL)
    {
        int hours, salary;
        auxEmployee = (Employee*)auxEmployee;

        employee_getWorkedHours(auxEmployee, &hours);
        salary = hours * 300; /// valor por hora.
        employee_setSalary(auxEmployee, salary);

        returnAux = 1;
    }

    return returnAux;
}

int employee_filterJob(void* auxEmployee)
{
    int returnAux = 0;

    if(auxEmployee != NULL)
    {
        char job[128];
        auxEmployee = (Employee*)auxEmployee;

        employee_getJob(auxEmployee, job);

        if( (strcmp(job, "programador") == 0) )
            returnAux = 1;
    }

    return returnAux;
}

int employee_filterDedication(void* auxEmployee)
{
    int returnAux = 0;

    if(auxEmployee != NULL)
    {
        char dedication[128];
        auxEmployee = (Employee*)auxEmployee;

        employee_getDedication(auxEmployee, dedication);

        if( (strcmp(dedication, "estandar") == 0) )
            returnAux = 1;
    }

    return returnAux;
}