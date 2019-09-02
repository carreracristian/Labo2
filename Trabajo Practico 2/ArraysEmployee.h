#include "InputAndValidate.h"

typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    float salario;
    int sector;
    int estado;

} eEmpleado;

/** \brief pide el ingreso de un empleado (nombre, apellido, sector y salario) y retorna la estructura con dichos datos.
 *
 * \return eEmpleado estructura de datos del empleado.
 *
 */
eEmpleado ingresarSoloUnEmpleado();

/** \brief muestra los datos de un empleado de manera tabulada.
 *
 * \param eEmpleado recibe la estructura de un empleado.
 * \return void
 *
 */
void mostrarSoloUnEmpleado(eEmpleado );

/** \brief inicializa los valores de la estructura. Los numericos: en 0. Las cadenas: vacias. El estado: libre.
 *
 * \param [] eEmpleado recibe un array de la estructura empleado.
 * \param int recibe el tamanio del array.
 * \return void
 *
 */
void inicializarListadoEmpleados(eEmpleado [], int );

/** \brief muestra el listado de los empleados en forma encolumnada.
 *
 * \param [] eEmpleado recibe un array de la estructura empleado.
 * \param int recibe el tamanio del array.
 * \return void
 *
 */
void mostrarListadoEmpleados(eEmpleado [], int );

/** \brief genera un numero de ID autoincremental en 1.
 *
 * \param [] eEmpleado recibe un array de la estructura empleado.
 * \param int recibe el tamanio del array.
 * \return int retorna el numero de ID correspondiente.
 *
 */
int generarId(eEmpleado [], int );

/** \brief busca la coincidencia entre el ID que recibe y el de un empleado de la estructura.
 *
 * \param [] eEmpleado recibe un array de la estructura empleado.
 * \param int recibe el tamanio del array.
 * \param int recibe el numero de ID a buscar.
 * \return int retorna el indice al que corresponde el ID, o un -1 si el ID no existe.
 *
 */
int buscarEmpleadoPorId(eEmpleado [], int , int );

/** \brief busca un lugar libre en la estructura.
 *
 * \param [] eEmpleado recibe un array de la estructura empleado.
 * \param int recibe el tamanio del array.
 * \return int retorna el primer indice del primer elemento que encontro libre, o un -1 si no hay mas espacio.
 *
 */
int buscarLugarLibre(eEmpleado [], int );

/** \brief da de alta a un empleado de la estructura.
 *
 * \param [] eEmpleado recibe un array de la estructura empleado.
 * \param int recibe el tamanio del array.
 * \return int retorna el indice del nuevo empleado, o un -1 si no hay mas espacio.
 *
 */
int darDeAltaEmpleado(eEmpleado [], int );

/** \brief da de baja a un empleado de la estructura, pidiendo que ingrese su ID.
 *
 * \param [] eEmpleado recibe un array de la estructura empleado.
 * \param int recibe el tamanio del array.
 * \return int retorna un 0 si el ID ingresado no coincide, o un 1 si es correcto.
 *
 */
int darDeBajaEmpleado(eEmpleado [], int );

/** \brief modifica un dato de un empleado de la estructura, pidiendo que ingrese su ID y dando a elegir entre nombre, apellido, sector o salario.
 *
 * \param [] eEmpleado recibe un array de la estructura empleado.
 * \param int recibe el tamanio del array.
 * \return int retorna un 0 si el ID ingresado no coincide, o un 1 si es correcto.
 *
 */
int modificarEmpleado(eEmpleado [], int );

/** \brief ordena el listado de empleados alfabeticamente por apellido y por sector.
 *
 * \param [] eEmpleado recibe un array de la estructura empleado.
 * \param int recibe el tamanio del array.
 * \return void
 *
 */
void ordenarListadoPorApellidoySector(eEmpleado [], int);

/** \brief informa el total y el promedio de los salarios, y cantidad de salarios mayores al promedio.
 *
 * \param [] eEmpleado recibe un array de la estructura empleado.
 * \param int recibe el tamanio del array.
 * \return void
 *
 */
void informarSalarios(eEmpleado [], int );

/** \brief informa el listado de empleados dando a elegir entre 3 opciones: por apellido, por sector, e informe de salarios.
 *
 * \param [] eEmpleado recibe un array de la estructura empleado.
 * \param int recibe el tamanio del array.
 * \return void
 *
 */
void informarEmpleados(eEmpleado [], int );

/** \brief hardcodea los datos de 5 empleados.
 *
 * \param [] eEmpleado recibe un array de la estructura empleado.
 * \param int recibe el tamanio del array.
 * \return void
 *
 */
void hardcodearEmpleados(eEmpleado [], int );
