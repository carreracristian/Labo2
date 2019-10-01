#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

#define TAM_NOM 51
#define TAM_PAIS 51

typedef struct
{
    int id;
    char nombre[TAM_NOM];
    char pais[TAM_PAIS];
}eActor;

#endif // ACTOR_H_INCLUDED
/** \brief se harcodean peliculas
 *
 * \param array lista
 * \param array tamaño
 * \return nada
 *
 */

void harcodearActores(eActor listaActores[],int tam);
/** \brief muestra la lista completa de actores
 *
 * \param array de la lista
 * \param array tamaño
 * \return nada
 *
 */

void Actor_mostrarLista(eActor listaActores[], int tam);
/** \brief busca al actor por su respectivo id
 *
 * \param array lista
 * \param tamaño del array y id del actor
 * \return 1 si realiza 0 si no
 *
 */

int Actor_buscarPorId(eActor[] ,int tam, int id);
/** \brief ordena la lista de actores por pais en asc y desc
 *
 * \param array lista de actores
 * \param  tamaño del array y ordenar array
 * \return 1 si realiza o si no
 *
 */

int ordenarActoresPorPaisAscYDesc (eActor listaActores[], int tamA, int ordenar);
/** \brief mostrar un actor de la lista
 *
 * \param muestra un actor del array
 * \param
 * \return void nada
 *
 */

void Actor_mostrarUno(eActor unActor);
/** \brief valida la existencia del actor
 *
 * \param id del actor, array de lista de actores
 * \param  tamañano del array de actores
 * \return 1 si realiza y 0 si no
 *
 */
int validarActor(int idActores, eActor listaActores[], int tam);
/** \brief pedir actor para ver si existe
 *
 * \param mensjae, array de lista de actores
 * \param  tamañano del array de actores
 * \return 1 si realiza y 0 si no
 *
 */

int pedirActor(char mensaje[], eActor listaActores[], int tam);
/** \brief ordenar actores por id en ascendente
 *
 * \param array lista de actores
 * \param array tamaño de actores
 * \return 0 si lo realiza y 1 si no
 *
 */

int Actor_ordenarPorIdAsc(eActor listado[], int limite);

