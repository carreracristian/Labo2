#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED

#include "Actor.h"
#include "genero.h"

#define TAM_TIT 51
#define LIBRE 1
#define OCUPADO 0

typedef struct
{
    int id;
    int codigo;
    char titulo[TAM_TIT];
    int anio;
    int idGenero;
    int idActor;
    int estado;
}ePelicula;

#endif // PELICULA_H_INCLUDED
/** \brief crea menu de opciones
 *
 * \param texto
 * \param
 * \return 0 si funciona 1 si no
 *
 */

int menu(char texto[]);
/** \brief inicializa la pelicula recorriendo la lista ya existente
 *
 * \param lista del array
 * \param tamaño del array
 * \return 0 si funciona y 1 si no
 *
 */

int Pelicula_init(ePelicula[], int tam);
/** \brief harcodea peliculas nuevas y las agrega al sistema
 *
 * \param array lista de peliculas, array lista de actores, array lista de generos.
 * \param array tamaño de pelicula, array tamaño de actores. array tamaño de genero
 * \return nada
 *
 */

void harcodearPeliculas(ePelicula[], int tamP, eActor[], int tamA, eGenero[], int tamG);
/** \brief muesta la lista de peliculas
 *
 * \param array lista de peliculas, array lista de actores, array lista de generos.
 * \param array tamaño de pelicula, array tamaño de actores. array tamaño de genero
 * \return 0 si funciona y 1 si no
 *
 */

int Pelicula_mostrarListado(ePelicula[] ,int tamP, eActor[], int tamA, eGenero[], int tamG);
/** \brief bsca un lugar disponible en el sistema
 *
 * \param lista de peliculas
 * \param tamaño del array
 * \return 0 si funciona y 1 si no
 *
 */

int dameLugar (ePelicula listaPeliculas[], int tam);
/** \brief genera un id siguiente al existente
 *
 * \param lista de peliculas
 * \param tamaño del array
 * \return 0 si funciona 1 si no
 *
 */

int Pelicula_siguienteID (ePelicula listaDePeliculas[], int limite);
/** \brief busca la pelicua por si codigo
 *
 * \param  lista de peliculas
 * \param codigo del array y su tamaño
 * \return 0 si funciona y 1 sino
 *
 */

int Pelicula_buscarCodigo(ePelicula listaDePeliculas[], int limite, int codigo);
/** \brief verifica la existencia de la pelicula
 *
 * \param lsta de peliculas
 * \param tamaño de array
 * \return 0 si funciona 1 si no
 *
 */

int yaHayPelicula (ePelicula listaPeliculas[], int tPel);
/** \brief busca una pelicula por su id
 *
 * \param array peliculas lista
 * \param array tamaño peliculas, array id
 * \return 0 si realiza 1 si no
 *
 */

int Pelicula_buscarPorId(ePelicula listaPeliculas[] ,int limite, int id);
/** \brief elimina una pelicula de la lista (no del todo)
 *
 * \param array lista de peliculas, array lista de actores, array lista de generos.
 * \param array tamaño de pelicula, array tamaño de actores. array tamaño de genero
 * \return  0 si lo realiza 1 si no
 *
 */

int borrarPelicula (ePelicula listaP[], int tamP, int id, eGenero ListaG[], int tamG, eActor listaA[], int tamA);
/** \brief ordena las peliculas de por su año de forma asc y desc
 *
 * \param array lista de peliculas
 * \param tamaño array pelicula, array ordenar
 * \return 0 si realiza 1 si no
 *
 */

int ordenarPeliculaAnioAscYDesc (ePelicula listaPelicula[], int tamP, int ordenar);
/** \brief muestra la informacion de las peliculas, sus listas, y se ordenan segun paises o año
 *
 * \param array lista de peliculas, array lista de actores, array lista de generos.
 * \param array tamaño de pelicula, array tamaño de actores. array tamaño de genero
 * \return nada
 *
 */

void listarPeliculas (ePelicula listaPeliculas[], int tamP, eActor listaActores[], int tamA, int ordenar, eGenero listaGenero[], int tamG);
/** \brief pedir actores para validar que exista
 *
 * \param array peloculas array lista de actores
 * \param tamaño array pelicula array tamaño actores
 * \return nada
 *
 */

void PedirActores(char mensaje[], ePelicula listadoPel[], int indice, eActor listadoAct[], int ta);
/** \brief Ordenar los id de las peliculas en forma ascendente y descendente
 *
 * \param lista de peliculas del array
 * \param tamaño de peliculas del array y ordenar del array
 * \return retorna 0 si lo realizo y 1 si no lo ordeno
 *
 */

int ordenarPeliculaIdAscYDesc (ePelicula listaPelicula[], int tamP, int ordenar);
/** \brief Funcion para modificar algunas caracteristicas de la pelicula ya agregada
 *
 * \param array lista de peliculas, array lista de actores, array lista de generos.
 * \param array tamaño de pelicula, array tamaño de actores. array tamaño de genero
 * \return nada.
 *
 */


void modificarPelicula (ePelicula listaPel[], int tamP, eActor listaActor[], int tamA, eGenero listaGenero[], int tamG);
/** \brief funcion para agregar nuevas peliculas
 *
 * \param array lista de peliculas, array lista de actores, array lista de generos.
 * \param array tamaño de pelicula, array tamaño de actores. array tamaño de genero
 * \return 0 si realizo el alta, 1 si no lo realizo
 *
 */

int cargarPelicula (ePelicula listaPelicula[], int tPel, eActor listaActores[], int tAct, eGenero listaGeneros[], int tGen);
/** \brief Mostrar una pelicula sin actor
 *
 * \param array peliculas, array generos
 * \param tamaño array denero
 * \return 0 si lo realiza y 1 si no
 *
 */

int Pelicula_mostrarUnaSinActor(ePelicula pel, eGenero generos[], int tg);
/** \brief mostrar lista de peliculas sin actor
 *
 * \param array peliculas, array generos
 * \param tamaño array denero
 * \return 0 si lo realiza y 1 si no
 *
 */

int Pelicula_mostrarListaDePeliculaSinActor(ePelicula listadoPel[] ,int tp, eGenero listadoGen[], int tg);
/** \brief muestra la lista de peliculas con las que tambien se borraron
 *
 * \param array peliculas, array genero, array actores
 * \param tamaño array peliculas, tamaño array genero, tamaño array actores
 * \return 0 si funciona 1 si no
 *
 */

int Pelicula_mostrarListaPeliculasConBorrados(ePelicula listaPel[] ,int tamP, eActor listaAct[], int tamA, eGenero listaGen[], int tamG);
/** \brief muesta una pelicula de la lita
 *
 * \param array peliculas, array genero, array actores
 * \param tamaño array peliculas, tamaño array genero, tamaño array actores
 * \return nada
 *
 */

void Pelicula_mostrarUno(ePelicula pel, eActor listaActores[], int tamA, eGenero listaGeneros[], int tamG);
/** \brief Procedimiento que muestra un encabezado en forma de tabla para informar los datos
 *          de las películas
 *
 * \param void
 * \return void
 *
 */
void Pelicula_mostrarEncabezado(void);


