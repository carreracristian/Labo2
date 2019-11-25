#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Reserva memoria para la construccion de un empleado.
 *
 * \return [NULL] si no hay memoria disponible.
 *              [Employee*] si el empleado fue construido correctamente.
 */
Employee* employee_new();

/** \brief Inicializa los campos de la entidad Empleado.
 *
 * \param char* id del empleado.
 * \param char* nombre del empleado.
 * \param char* horas del empleado.
 * \param char* salario del empleado.
 * \return [NULL] si no hay memoria disponible.
 *              [Employee*] si el empleado fue construido correctamente.
 */
Employee* employee_newParametros(char*,char*,char*, char*);

/** \brief Libera memoria destruyendo un empleado.
 *
 * \param Employee* empleado a destruir.
 * \return void
 *
 */
void employee_delete(Employee*);

/** \brief Asigna un valor al ID de un empleado.
 *
 * \param Employee* empleado que se desea setear.
 * \param int id a setear.
 * \return int [0] si ocurrio un error.
 *                    [1] si se pudo setear correctamente.
 */
int employee_setId(Employee*,int);

/** \brief Obtiene el ID de un empleado.
 *
 * \param Employee* empleado.
 * \param int* id.
 * \return int [0] si ocurrio un error.
 *                    [1] si se pudo setear correctamente.
 */
int employee_getId(Employee*,int*);

/** \brief Asigna una cadena al Nombre de un empleado.
 *
 * \param Employee* empleado que se desea setear.
 * \param char* nombre a setear.
 * \return int [0] si ocurrio un error.
 *                    [1] si se pudo setear correctamente.
 */
int employee_setNombre(Employee*,char*);

/** \brief Obtiene el Nombre de un empleado.
 *
 * \param Employee* empleado.
 * \param char* nombre.
 * \return int [0] si ocurrio un error.
 *                    [1] si se pudo setear correctamente.
 */
int employee_getNombre(Employee*,char*);

/** \brief Asigna un valor a las Horas trabajadas de un empleado.
 *
 * \param Employee* empleado que se desea setear.
 * \param int horas a setear.
 * \return int [0] si ocurrio un error.
 *                    [1] si se pudo setear correctamente.
 */
int employee_setHorasTrabajadas(Employee*,int);

/** \brief Obtiene las Horas Trabajadas de un empleado.
 *
 * \param Employee* empleado.
 * \param int* horas.
 * \return int [0] si ocurrio un error.
 *                    [1] si se pudo setear correctamente.
 */
int employee_getHorasTrabajadas(Employee*,int*);

/** \brief Asigna un valor al Sueldo de un empleado.
 *
 * \param Employee* empleado que se desea setear.
 * \param int horas a setear.
 * \return int [0] si ocurrio un error.
 *                    [1] si se pudo setear correctamente.
 */
int employee_setSueldo(Employee*,int);

/** \brief Obtiene el Sueldo de un empleado.
 *
 * \param Employee* empleado.
 * \param int* sueldo.
 * \return int [0] si ocurrio un error.
 *                    [1] si se pudo setear correctamente.
 */
int employee_getSueldo(Employee*,int*);

/** \brief Imprime los titulos para el listado de los empleados.
 *
 * \param void
 * \return void
 *
 */
void employee_headers(void);

/** \brief Imprime los datos de un empleado.
 *
 * \param int id del empleado.
 * \param char* nombre del empleado.
 * \param int horas trabajadas por el empleado.
 * \param int sueldo del empleado.
 * \return void
 *
 */
void employee_showAnEmployee (int, char*, int, int);

/** \brief Genera el ID de un empleado.
 *
 * \param LinkedList* puntero a la lista de empleados.
 * \return int ID generado.
 *
 */
int employee_generateId(LinkedList*);

/** \brief Ordena los empleados por ID.
 *
 * \param void* elemento auxiliar 1.
 * \param void* elemento auxiliar 2.
 * \return int [1] orden ascendente.
 *                    [-1] orden descendente.
 */
int employee_sortById(void*,void*);

/** \brief Ordena los empleados por Nombre.
 *
 * \param void* elemento auxiliar 1.
 * \param void* elemento auxiliar 2.
 * \return int [1] orden ascendente.
 *                    [0] si los nombres son iguales.
 *                    [-1] orden descendente.
 */
int employee_sortByName(void*,void*);

/** \brief Ordena los empleados por Horas Trabajadas.
 *
 * \param void* elemento auxiliar 1.
 * \param void* elemento auxiliar 2.
 * \return int [1] orden ascendente.
 *                    [0] si las horas son iguales.
 *                    [-1] orden descendente.
 */
int employee_sortByHours(void*,void*);

/** \brief Ordena los empleados por Salario.
 *
 * \param void* elemento auxiliar 1.
 * \param void* elemento auxiliar 2.
 * \return int [1] orden ascendente.
 *                    [0] si los salarios son iguales.
 *                    [-1] orden descendente.
 */
int employee_sortBySalary(void*,void*);

/** \brief Imprime un sub-menu para que el usuario elija como ordenar el listado.
 *
 * \param LinkedList* puntero a la lista de empleados.
 * \return int [0] si ocurrio un error.
 *                    [1] si se pudo setear correctamente.
 */
int employee_sortList(LinkedList*);

#endif // employee_H_INCLUDED
