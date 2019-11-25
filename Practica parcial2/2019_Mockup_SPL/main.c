#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "employee.h"
#include "parser.h"

void printList (LinkedList* this);

int main()
{
    LinkedList* employeeList = ll_newLinkedList();
    FILE* fl = openFILE("MOCK_DATA.csv");
    parser_EmployeeFromText(fl,employeeList);
    printList(employeeList);
    ll_map(employeeList,employee_calculate_salary);
    ll_sort(employeeList,employee_sortByName,1);
    LinkedList* over40;
    over40 = ll_filter(employeeList,employee_filter);
    printList(over40);
    fclose(fl);
    FILE* fl2 = openFILEwrite("MOCK_DATA_2.csv");
    parser_EmployeeListToText(fl,over40);
    fclose(fl2);
}
void printList (LinkedList* this)
{
    if (this!=NULL)
    {
        employee_print_header();
        int i;
        Employee* temp;
        for (i=0;i<ll_len(this);i++)
        {
            temp =(Employee*)ll_get(this,i);
            employee_print_employee(temp);
        }
        employee_print_footer();
    }

}
