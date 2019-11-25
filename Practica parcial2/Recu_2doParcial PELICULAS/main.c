#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Movies.h"
#include "Parser.h"
#include "Input.h"

int main()
{
    LinkedList* pArrayMovies = ll_newLinkedList();
    LinkedList* pArraySubList = NULL;
    LinkedList* pArrayDepuratedList = NULL;
    int option, fileLoaded = 0;
    //char fileName[128];

    do
    {
        option = menu( "1. Cargar archivo 'datosMF1.csv'.\n"
                                    "2. Listar por ID.\n"
                                    "3. Listar por Anio.\n"
                                    "4. Listar por Genero.\n"
                                    "5. Filtrar por Genero.\n"
                                    "6. Filtrar por Anio.\n"
                                    "7. Guardar filtrado en 'Filtrado.csv'.\n"
                                    "8. Depurar peliculas.\n"
                                    "10. Salir.\n\n"
                                    "Elegir opcion: ");

        switch(option)
        {
            case 1:
                fileLoaded = optionMenu_LoadFile( fileLoaded , "datosMF1.csv" , pArrayMovies );
                break;

            case 2:
                optionMenu_ListById( fileLoaded , pArrayMovies );
                break;

            case 3:
                optionMenu_ListByYear( fileLoaded , pArrayMovies );
                break;

            case 4:
                optionMenu_ListByGender( fileLoaded , pArrayMovies );
                break;

            case 5:
                pArraySubList = optionMenu_FilterByGender( fileLoaded , pArrayMovies );
                break;

            case 6:
                pArraySubList = optionMenu_FilterByYear( fileLoaded , pArrayMovies );
                break;

            case 7:
                optionMenu_WriteFile( fileLoaded , "filtrado2017.csv" , pArraySubList );
                break;

            case 8:
                pArrayDepuratedList = movies_depurated(pArrayMovies);
                movie_printList(pArrayDepuratedList);
                break;

            case 10:
                printf("\nSaliendo...\n");
                break;

            default:
                printf("\nOpcion incorrecta.\n");
                break;
        }

        system("pause");
        system("cls");

    } while(option != 10);

    return 0;
}




