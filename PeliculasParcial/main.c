#include <stdio.h>
#include <stdlib.h>
#include "Pelicula.h"
#include "genero.h"
#include "Actor.h"

#define TPEL 1000
#define TACT 5
#define TGEN 5

int main()
{
    char seguir='s';
    int id=0;
    int ordenar=0;
    ePelicula listaDePeliculas[TPEL];
    eGenero listaDeGeneros[TGEN];
    eActor listaDeActores[TACT];

    harcodearGeneros(listaDeGeneros, TGEN);
    harcodearActores(listaDeActores, TACT);

    Pelicula_init(listaDePeliculas,TPEL);
    harcodearPeliculas(listaDePeliculas,TPEL,listaDeActores,TACT,listaDeGeneros,TGEN);

    Pelicula_mostrarListado(listaDePeliculas,TPEL,listaDeActores,TACT,listaDeGeneros,TGEN);

    int opcion;

    do
    {
       opcion=menu("\n  Bienvenidos al menu de opciones \n\n"
                    "1. Altas \n"
                    "2. Modificar\n"
                    "3. Bajas \n"
                    "4. Informar\n"
                    "5. Filtros \n"
                    "6. Salir\n\nElija una opcion: ");

            switch (opcion)
            {
            case 1:
                cargarPelicula (listaDePeliculas, TPEL , listaDeActores , TACT , listaDeGeneros , TGEN);
                break;

            case 2:
                if (yaHayPelicula(listaDePeliculas, TPEL)!= -1)
                    {

                        modificarPelicula(listaDePeliculas, TPEL, listaDeActores, TACT, listaDeGeneros, TGEN);
                    }
                break;
            case 3:
                if(yaHayPelicula(listaDePeliculas,TPEL) != -1){
                    borrarPelicula(listaDePeliculas,TPEL, id, listaDeGeneros,TGEN, listaDeActores, TACT);
                }
                break;
            case 4:
                if (yaHayPelicula(listaDePeliculas, TPEL) != -1)
                {
                    listarPeliculas(listaDePeliculas, TPEL,listaDeActores, TACT ,ordenar,listaDeGeneros, TGEN);
                }
                break;
            case 5:
                printf("-->INFORMES--<");
                if(yaHayPelicula(listaDePeliculas,TPEL) != -1){
                    opcion = menu("\n1.a_ Todas las peliculas con genero y actor."
                                  "\n2.b_ Peliculas cuya nacionalidad del actor sea EEUU"
                                  "\n3.c_ Peliculas cuya nacionalidad del actor sea de un pais ingresado por consola"
                                  "\n4.d_ Por cada genero el titulo de las peliculas que pertenecen a ese genero. "
                                  "\n5.e_ cantidad de peliculas por genero"
                                  "\n6.f_ Actor con mas peliculas protagonizadas"
                                  "\n7.g_ Genero con menos peliculas"
                                  "\n8.h_Actor que no trabajo en ninguna pelicula"
                                  "\n9._Volver al menu principal."
                                  "\n\nElija una opcion");

            switch(opcion){
                        case 1:
                            printf("\n\nEstas son todas las peliculas con genero y actor\n");
                            ordenarPeliculaIdAscYDesc(listaDePeliculas, TPEL, ordenar);
                            Pelicula_mostrarListado(listaDePeliculas, TPEL, listaDeActores, TACT, listaDeGeneros, TGEN);

                            break;
                        case 2:
                            printf("\n\nLas peliculas del Actor con nacionalidad EEUU.\n");
                            ordenarPeliculaIdAscYDesc(listaDePeliculas, TPEL, ordenar);
                            Informes_peliculasPorUnPais(listaDePeliculas,TPEL,listaDeActores,TACT,listaDeGeneros,TGEN, "EEUU");

                            break;
                        case 3:
                            printf("\n\nLas peliculas del Actor con nacionalidad ingresada por consola\n");
                            ordenarPeliculaIdAscYDesc(listaDePeliculas, TPEL, ordenar);
                            Informes_peliculasPorUnPaisConsola(listaDePeliculas,TPEL,listaDeActores,TACT,listaDeGeneros,TGEN);
                            break;
                        case 4:
                            printf("\n\nlista de peliculas por genero\n");
                            ordenarPeliculaIdAscYDesc(listaDePeliculas, TPEL, ordenar);
                            Informes_peliculasPorGenero(listaDePeliculas, TPEL, listaDeGeneros, TGEN);

                            break;
                        case 5:
                            printf("\n\ncantidad de peliculas por genero:\n");

                            Informes_cantPeliculasPorGenero(listaDePeliculas, TPEL, listaDeGeneros, TGEN);
                            break;
                        case 6:
                            printf("\n\nActor con mas peliculas:\n");

                            Informes_actorConMasPeliculas(listaDePeliculas, TPEL, listaDeActores, TACT);
                            break;
                        case 7:
                            printf("\n\nGenero con menos peliculas:\n");

                            Informes_generoConMenosPeliculas(listaDePeliculas, TPEL, listaDeGeneros, TGEN);
                            break;
                        case 8:
                            printf("\n\nActor con menos Peliculas:\n");

                            Informes_actorConMenosPeliculas(listaDePeliculas, TPEL, listaDeActores, TACT);
                            break;
                        case 9:
                            printf("\nVolviendo");
                            seguir = 'n';
                            system("pause");
                            break;
                            }
                }

                break;
            case 6:
                printf(" Salir \n\n");
                seguir = 'n';
                system("pause");
                break;
            default:
                printf("Error.Debe ingresar un numero del 1 al 5\n\n") ; // el default se utiliza por si se ingresa un numero que no sea del 1 al 5
                system("pause");
                break;
        }
    }while(seguir=='s');

    return 0;
}
