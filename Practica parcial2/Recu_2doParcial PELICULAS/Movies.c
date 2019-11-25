#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Movies.h"
#include "Parser.h"
#include "Input.h"

ePelicula* movie_new(void)
{
    ePelicula* auxMovie = (ePelicula*) malloc (sizeof(ePelicula));
    return auxMovie;
}

ePelicula* movie_newParameters(char* idStr , char* titleStr , char* yearStr , char* generoStr )
{
    ePelicula* auxMovie = movie_new();

    if( (auxMovie != NULL) && (idStr != NULL) && (titleStr != NULL) && (yearStr != NULL) && (generoStr != NULL) )
    {
        int auxId, auxYear;

        auxId = atoi(idStr);
        auxYear = atoi(yearStr);

        movie_setId(auxMovie, auxId);
        movie_setTitle(auxMovie, titleStr);
        movie_setYear(auxMovie, auxYear);
        movie_setGenero(auxMovie, generoStr);
    }
    else
        movie_delete(auxMovie);

    return auxMovie;
}

void movie_delete(ePelicula* auxMovie)
{
    if(auxMovie != NULL)
        free(auxMovie);
}


/***************************************************************** GETTERS ***********************************************************************/

int movie_getId(ePelicula* auxMovie , int* auxId)
{
    int ok = 0;

    if( (auxMovie != NULL) && (auxId != NULL) )
    {
        *auxId = auxMovie->id;
        ok = 1;
    }

    return ok;
}

int movie_getTitle(ePelicula* auxMovie , char* auxName )
{
    int ok = 0;

    if( (auxMovie != NULL) && (auxName != NULL) )
    {
        strcpy(auxName, auxMovie->title);
        ok = 1;
    }

    return ok;
}

int movie_getGenero(ePelicula* auxMovie , char* auxGenero )
{
    int ok = 0;

    if( (auxMovie != NULL) && (auxGenero != NULL) )
    {
        strcpy(auxGenero, auxMovie->genero);
        ok = 1;
    }

    return ok;
}

int movie_getYear(ePelicula* auxMovie , int* auxYear )
{
    int ok = 0;

    if( (auxMovie != NULL) && (auxYear != NULL) )
    {
        *auxYear = auxMovie->year;
        ok = 1;
    }

    return ok;
}


/********************************************************************* SETTERS **************************************************************************/


int movie_setId(ePelicula* auxMovie , int auxId )
{
    int ok = 0;

    if( (auxMovie != NULL) && (auxId > 0) )
    {
        auxMovie->id = auxId;
        ok = 1;
    }

    return ok;
}

int movie_setTitle(ePelicula* auxMovie , char* auxName )
{
    int ok = 0;

    if( (auxMovie != NULL) && (auxName != NULL) )
    {
        strcpy(auxMovie->title, auxName);
        ok = 1;
    }

    return ok;
}

int movie_setGenero(ePelicula* auxMovie , char* auxName )
{
    int ok = 0;

    if( (auxMovie != NULL) && (auxName != NULL) )
    {
        strcpy(auxMovie->genero, auxName);
        ok = 1;
    }

    return ok;
}

int movie_setYear(ePelicula* auxMovie , int auxYear )
{
    int ok = 0;

    if( (auxMovie != NULL) && (auxYear > 0) )
    {
        auxMovie->year = auxYear;
        ok = 1;
    }

    return ok;
}


/************************************************************************ PRINTS ***********************************************************************/


void movie_printHeader(void)
{
    printf("\n-------------------------------------------------------------------------------\n");
    printf(" ID                                              NOMBRE    ANIO          GENERO");
    printf("\n-------------------------------------------------------------------------------\n");
}

void movie_print(ePelicula* auxMovie)
{
    if(auxMovie != NULL)
    {
        int id, year;
        char name[128];
        char genero[128];

        movie_getId(auxMovie, &id);
        movie_getTitle(auxMovie, name);
        movie_getYear(auxMovie, &year);
        movie_getGenero(auxMovie, genero);

        printf("%2d %52s %7d %15s\n", id, name, year, genero);
    }
}

void movie_printFooter(void)
{
    printf("-------------------------------------------------------------------------------\n");
}

void movie_printList(LinkedList* pArrayList)
{
    if(pArrayList != NULL)
    {
        int i;
        ePelicula* auxMovie;

        movie_printHeader();

        for(i=0; i<ll_len(pArrayList); i++)
        {
            auxMovie = (ePelicula*)ll_get(pArrayList, i);
            movie_print(auxMovie);
        }

        movie_printFooter();
    }
}

int movies_sortById(void* aux1,void* aux2)
{
    int returnAux = 0;

    if( (aux1 != NULL) && (aux2 != NULL) )
    {
        int id1, id2;

        movie_getId(aux1, &id1);
        movie_getId(aux2, &id2);

        if(id1 > id2)
            returnAux = 1;
        else
        {
            if(id1 < id2)
                returnAux = -1;
        }
    }

    return returnAux;
}

int movies_sortByGender(void* aux1,void* aux2)
{
    int returnAux = 0;

    if( (aux1 != NULL) && (aux2 != NULL) )
    {
        char name1[128], name2[128];

        movie_getGenero(aux1,name1);
        movie_getGenero(aux2,name2);

        returnAux = strcmp(name1, name2);
    }

    return returnAux;
}

int movies_sortByYear(void* aux1,void* aux2)
{
    int returnAux = 0;

    if( (aux1 != NULL) && (aux2 != NULL) )
    {
        int year1, year2;

        movie_getYear(aux1, &year1);
        movie_getYear(aux2, &year2);

        if(year1 > year2)
            returnAux = 1;
        else
        {
            if(year1 < year2)
                returnAux = -1;
        }
    }

    return returnAux;
}

int movies_filterByGender(void* auxMovie , char* auxGenero)
{
    int returnAux = 0;

    if(auxMovie != NULL)
    {
        char genero[128];
        auxMovie = (ePelicula*)auxMovie;
        movie_getGenero(auxMovie, genero);

        if( (stricmp(genero, auxGenero) == 0) )
            returnAux = 1;
    }

    return returnAux;
}

int movies_filterByYear(void* auxMovie , char* auxYear )
{
    int returnAux = 0;

    if(auxMovie != NULL)
    {
        int year , auxIntYear;

        auxMovie = (ePelicula*)auxMovie;
        movie_getYear(auxMovie, &year);

        auxIntYear = atoi(auxYear);

        if( year == auxIntYear )
            returnAux = 1;
    }

    return returnAux;
}

LinkedList* movies_depurated(LinkedList* pArrayList)
{
    LinkedList* depuratedList = ll_clone(pArrayList);

    if(pArrayList != NULL && depuratedList != NULL)
    {
        int i, j;
        void* auxMovie1;
        void* auxMovie2;
        char auxName1[128] , auxName2[128];
        char auxGen1[128] , auxGen2[128]  , auxGenFin[128];

        int seAgregoBien;
        int elementosLista;

        for(i=0; i<ll_len(depuratedList); i++)
        {
            auxMovie1 = ll_get(depuratedList, i);
            auxMovie1 = (ePelicula*)auxMovie1;
            movie_getTitle(auxMovie1, auxName1);

            for(j=0; j< (ll_len(depuratedList)) - 1; j++)
            {
                auxMovie2 = ll_get(depuratedList, j);
                auxMovie2 = (ePelicula*)auxMovie2;
                movie_getTitle(auxMovie2, auxName2);

                if( ( strcmp(auxName1 , auxName2) ) == 0 )
                {
                    movie_getGenero(auxMovie1 , auxGen1);
                    movie_getGenero(auxMovie2 , auxGen2);

                    strcat(auxGen1, "\nTiene otro genero.");

                    movie_setGenero(auxMovie1 , auxGen1);
                    //ll_set(depuratedList , i , auxMovie1);

                    //movie_setGenero(auxMovie1 , auxGen1);
                    //seAgregoBien = ll_add(depuratedList , auxMovie1);

                    ll_remove(depuratedList , j);

                }
            }
        }
        elementosLista = ll_len(depuratedList);
        printf("\nAgregados correctamente: %d" , seAgregoBien);
        printf("\nElementos de la lista: %d" , elementosLista);

    }

    return depuratedList;
}

/**
int employee_sortByHours(void* aux1,void* aux2)
{
    int returnAux = 0;

    if( (aux1 != NULL) && (aux2 != NULL) )
    {
        int hours1, hours2;

        employee_getWorkedHours(aux1, &hours1);
        employee_getWorkedHours(aux2, &hours2);

        if(hours1 > hours2)
            returnAux = 1;
        else
        {
            if(hours1 < hours2)
                returnAux = -1;
        }
    }

    return returnAux;
}



int employee_calculateDedication(void* auxEmployee)
{
    int returnAux = 0;

    if(auxEmployee != NULL)
    {
        int hours;
        auxEmployee = (Employee*)auxEmployee;

        employee_getWorkedHours(auxEmployee, &hours);

        if(hours > 0 && hours <= 200)
            employee_setDedication(auxEmployee, "estandar");
        if(hours > 200 && hours <= 300)
            employee_setDedication(auxEmployee, "sobre la media");
        if(hours > 300)
            employee_setDedication(auxEmployee, "excesivo");

        returnAux = 1;
    }

    return returnAux;
}

int employee_filterUnder21(void* auxEmployee)
{
    int returnAux = 0;

    if(auxEmployee != NULL)
    {
        int age;
        auxEmployee = (Employee*)auxEmployee;

        employee_getAge(auxEmployee, &age);

        if(age < 21)
            returnAux = 1;
    }

    return returnAux;
}

**/
