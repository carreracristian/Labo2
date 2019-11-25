typedef struct
{
    int id;
    char name[128];
    char job[128];
    int age;
    int workedHours;
    char dedication[128];
} Employee;

Employee* employee_new (void);
Employee* employee_newParameters(char* , char* , char* , char* , char* , char* );
void employee_delete(Employee*);

/*********************************************************
******************** GETTERS ****************************
*********************************************************/

int employee_getId(Employee* , int* );
int employee_getName(Employee* , char* );
int employee_getJob(Employee* , char* );
int employee_getAge(Employee* , int* );
int employee_getWorkedHours(Employee* , int* );
int employee_getDedication(Employee* , char* );

/*********************************************************
*********************** SETTERS *************************
*********************************************************/

int employee_setId(Employee* , int );
int employee_setName(Employee* , char* );
int employee_setJob(Employee* , char* );
int employee_setAge(Employee* , int );
int employee_setWorkedHours(Employee* , int );
int employee_setDedication(Employee* , char* );

/*********************************************************
*********************** PRINTS **************************
*********************************************************/

void employee_printHeader(void);
void employee_printEmployee(Employee* );
void employee_printFooter(void);
void employee_printListOfEmployees(LinkedList* );

int employee_sortById(void* ,void* );
int employee_sortByHours(void* ,void* );
int employee_sortByName(void* , void* );
int employee_calculateDedication(void* );
int employee_filterUnder21(void* );

int employee_menu(char*  );



