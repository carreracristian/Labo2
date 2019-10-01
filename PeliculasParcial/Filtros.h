#ifndef FILTROS_H_INCLUDED
#define FILTROS_H_INCLUDED

#include "Actor.h"
#include "genero.h"
#include "Pelicula.h"

//Estructura auxiliar
typedef struct{
    int id;
    int cantPeliculas;
    char pais[TAM_PAIS];
    //char genero[TAM_GEN];
    int estado;
}eAux;


#endif // FILTROS_H_INCLUDED
/** \brief Muestra las peliculas segun el pais escogido  del actor.
 *
 * \param aray lista de peliculas, array lista de generos, array lista de actores
 * \param array tamaño de peliculas, tamaño array de actores, tamaño array de generos
 * \return contador de peliculas
 *
 */

int Informes_peliculasPorUnPais(ePelicula listaPel[], int tp, eActor listaAct[], int ta, eGenero listaGen[], int tg, char paisElegido[TAM_PAIS]);
/** \brief pelicula que muestra pais por consola
 *
 * \param aray lista de peliculas, array lista de generos, array lista de actores
 * \param array tamaño de peliculas, tamaño array de actores, tamaño array de generos
 * \return contador de peliculas
 *
 */


int Informes_peliculasPorUnPaisConsola(ePelicula listaPel[], int tp, eActor listaAct[], int ta, eGenero listaGen[], int tg);
/** \brief cantidad de pelicuas por genero
 *
 * \param aray lista de peliculas, array lista de generos, array lista de actores
 * \param array tamaño de peliculas, tamaño array de actores, tamaño array de generos
 * \return contador de peliculas
 *
 */

int Informes_cantPeliculasPorGenero(ePelicula[], int tp, eGenero[], int tg);
/** \brief Muestra las peliculas de los actores con mas peliculas
 *
 * \param array list peliculas, array lista de actores
 * \param tamaño del array de peliculas, tamaño del array del actor
 * \return contador.
 *
 */


int Informes_actorConMasPeliculas(ePelicula listaPel[], int tp, eActor listaAct[], int ta);
/** \brief  muestra el genero que tiene menos peliculas
 *
 * \param aray lista de peliculas, array lista de generos,
 * \param array tamaño de peliculas, tamaño array de generos
 * \return contador de peliculas
 *
 */
int Informes_generoConMenosPeliculas(ePelicula[], int tp, eGenero[], int tg);
/** \brief muestra el actor con menos peliculas
 *
 * \param aray lista de peliculas, array lista de generos,
 * \param array tamaño de peliculas, tamaño array de generos
 * \return contador de peliculas
 *
 */

int Informes_actorConMenosPeliculas(ePelicula listaPel[], int tp, eActor listaAct[], int ta);




//----------------------------------------------------------------------------------------------------------------------------
//Otros filtros no usados y sin revisar (quizas haya que refactorizar:
  //peliculas de un actor de algun pais
int Informes_peliculasPorUnPais(ePelicula[], int tp, eActor[], int ta, eGenero[], int tg, char[]);
//clasificacion de peliculas en genero
int Informes_peliculasPorGenero(ePelicula[], int tp, eGenero[], int tg);
//cantidad de peloculas que hay en cada genero
int Informes_cantPeliculasPorGenero(ePelicula[], int tp, eGenero[], int tg);
//el genero con menos peliculas
int Informes_generoConMenosPeliculas(ePelicula[], int tp, eGenero[], int tg);
//cantidad de peliculas por cada actor
int Informes_cantPeliculasPorActor(ePelicula[], int tp, eActor[], int ta, eGenero[], int tg);
//actor con mas peliculas
int Informes_actorConMasPeliculas(ePelicula listaPel[], int tp, eActor listaAct[], int ta);
//genero que tiene mas peliculas
int Informes_generoConMasPeliculas(ePelicula[], int tp, eGenero[], int tg);
//cual y cuantas peliculas fueron estrenadas en un año en especifico
int Informes_estrenadasAnio(ePelicula[], int tp, eActor[], int ta, eGenero[], int tg);
//cuantas peliculas fueron estrenadas en eun rango de años
int Informes_estrenadasAnioRango(ePelicula[], int tp, eActor[], int ta, eGenero[], int tg);
int Informes_peliculasPorPais(ePelicula[], int tp, eActor[], int ta, eGenero[], int tg);
//Cantidad de peliculas de actores de un pais en especifico en el rando de años
int Informes_peliculasPorPaisRangoEstreno(ePelicula[], int tp, eActor[], int ta, eGenero[], int tg);
