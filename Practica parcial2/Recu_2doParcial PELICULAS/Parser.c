#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Movies.h"
#include "Parser.h"
#include "Input.h"

int parser_MoviesFromText(FILE* pFile , LinkedList* pArrayList)
{
    int ok = 0;

    if( (pFile != NULL) && (pArrayList != NULL) )
    {
        ePelicula* auxMovie;
        char auxParameters[4][128];

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxParameters[0], auxParameters[1], auxParameters[2] , auxParameters[3]);

        while(!feof(pFile))
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxParameters[0], auxParameters[1], auxParameters[2] , auxParameters[3]);
            auxMovie = movie_newParameters(auxParameters[0], auxParameters[1], auxParameters[2] , auxParameters[3]);

            if(auxMovie != NULL)
            {
                ll_add(pArrayList, auxMovie);
                ok = 1;
            }
        }
    }

    return ok;
}

int parser_MoviesListToText (FILE* pFile , LinkedList* pArrayList)
{
    int ok = 0;

    if( (pFile != NULL) && (pArrayList != NULL) )
    {
        ePelicula* auxMovie;
        char title[128], gender[128];
        int id, year;
        int i;

        ll_sort(pArrayList, movies_sortById, 1);
        fprintf(pFile,"id,titulo,anio,genero\n");

        for(i=0; i<ll_len(pArrayList); i++)
        {
            auxMovie = (ePelicula*) ll_get(pArrayList, i);

            if(auxMovie != NULL)
            {
                movie_getId(auxMovie, &id);
                movie_getTitle(auxMovie, title);
                movie_getYear(auxMovie, &year);
                movie_getGenero(auxMovie, gender);

                fprintf(pFile,"%d,%s,%d,%s\n",id,title,year,gender);
            }
        }

        ok = 1;
    }

    return ok;
}

FILE* openFileRead(char* path , LinkedList* pArrayList)
{
    FILE* auxFile = NULL;

    if( (path != NULL) && (pArrayList != NULL) )
    {
        auxFile = fopen(path,"r");

        if(auxFile == NULL)
        {
            printf("\nNo es posible abrir el archivo.\n");
            exit(1);
        }

        parser_MoviesFromText(auxFile, pArrayList);
        printf("\nArchivo cargado con exito.\n");
        fclose(auxFile);
    }

    return auxFile;
}

FILE* openFileWrite(char* path , LinkedList* pArrayList)
{
    FILE* auxFile = NULL;

    if( (path != NULL) && (pArrayList != NULL) )
    {
        auxFile = fopen(path,"w");

        if(auxFile == NULL)
        {
            printf("\nNo es posible abrir el archivo.\n");
            exit(1);
        }

        parser_MoviesListToText(auxFile, pArrayList);
        printf("\nArchivo guardado con exito.\n");
        fclose(auxFile);
    }

    return auxFile;
}

