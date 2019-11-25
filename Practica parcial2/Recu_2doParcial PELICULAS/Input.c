#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Movies.h"
#include "Parser.h"
#include "Input.h"

int menu(char* msj )
{
    int aux;
    printf(msj);
    fflush(stdin);
    scanf("%d", &aux);
    return aux;
}

int getString(char* msj, char* aux)
{
    int ok = 0;
    if(aux != NULL)
    {
        printf(msj);
        fflush(stdin);
        gets(aux);
        ok = 1;
    }
    return ok;
}

int isOnlyNumber(char* aux)
{
	int i, ok = 0;
    if(aux != NULL)
    {
        for(i=0; aux[i] != '\0'; i++)
        {
            if( (aux[i] < '0' || aux[i] > '9') )
                break;
        }
        if( (aux[i] == '\0') )
            ok = 1;
    }
	return ok;
}

int isOnlyLetter(char* aux)
{
	int i, ok = 0;
    if(aux != NULL)
    {
        for(i=0; aux[i] != '\0'; i++)
        {
            if( (aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z') && (aux[i] != ' ') )
                break;
        }
        if(aux[i] == '\0')
            ok = 1;
    }
	return ok;
}

int getOnlyLetter(char* msj, char* msjError, char* str)
{
	int valido, ok = 0;
	char aux[50];
	if(str != NULL)
	{
		getString(msj,aux);
		valido = isOnlyLetter(aux);
		while(!valido)
		{
			getString(msjError,aux);
			valido = isOnlyLetter(aux);
		}
		strcpy(str,aux);
		ok = 1;
	}
	return ok;
}

int getOnlyNumber(char* msj, char* msjError, int* numero)
{
    int valido, ok = 0;
    char aux[50];
    if(numero != NULL)
    {
        getString(msj,aux);
        valido = isOnlyNumber(aux);
        while(!valido)
        {
            getString(msjError, aux);
            valido = isOnlyNumber(aux);
        }
        *numero = atoi(aux);
        ok = 1;
    }
    return ok;
}




int optionMenu_LoadFile (int fileLoaded , char* fileName , LinkedList* pArrayMovies)
{
    if( !fileLoaded )
    {
        openFileRead(fileName, pArrayMovies);
        fileLoaded = 1;
    }
    else
    {
        printf("\nEl archivo ya ha sido cargado.\n");
    }

    return fileLoaded;
}

int optionMenu_ListById (int fileLoaded , LinkedList* pArrayMovies)
{
    int returnAux = 0;

    if(fileLoaded)
    {
        ll_sort(pArrayMovies, movies_sortById, 1);
        movie_printList(pArrayMovies);

        returnAux = 1;
    }
    else
    {
        printf("\nEl archivo aun no ha sido cargado.\n");
    }

    return returnAux;
}

int optionMenu_ListByYear (int fileLoaded , LinkedList* pArrayMovies)
{
    int returnAux = 0;

    if(fileLoaded)
    {
        ll_sort(pArrayMovies, movies_sortByYear, 1);
        movie_printList(pArrayMovies);

        returnAux = 1;
    }
    else
    {
        printf("\nEl archivo aun no ha sido cargado.\n");
    }

    return returnAux;
}

int optionMenu_ListByGender (int fileLoaded , LinkedList* pArrayMovies)
{
    int returnAux = 0;

    if(fileLoaded)
    {
        ll_sort(pArrayMovies, movies_sortByGender, 1);
        movie_printList(pArrayMovies);

        returnAux = 1;
    }
    else
    {
        printf("\nEl archivo aun no ha sido cargado.\n");
    }

    return returnAux;
}

LinkedList* optionMenu_FilterByGender (int fileLoaded , LinkedList* pArrayMovies )
{
    char aux[128];
    LinkedList* pArraySubList = ll_newLinkedList();

    if(fileLoaded)
    {
        getString("Por favor, ingrese el genero que desea filtrar: ", aux);

        pArraySubList = ll_filter(pArrayMovies , movies_filterByGender , aux);

        if( ! (ll_isEmpty(pArraySubList)) )
        {
            ll_sort(pArraySubList , movies_sortById, 1);
            movie_printList(pArraySubList);
        }
        else
        {
            printf("\nGenero no encontrado.\n");
        }
    }
    else
    {
        printf("\nEl archivo aun no ha sido cargado.\n");
    }

    return pArraySubList;
}

LinkedList* optionMenu_FilterByYear (int fileLoaded , LinkedList* pArrayMovies )
{
    char aux[128];
    LinkedList* pArraySubList = ll_newLinkedList();

    if(fileLoaded)
    {
        getString("Por favor, ingrese el anio que desea filtrar: " , aux);
        pArraySubList = ll_filter(pArrayMovies , movies_filterByYear , aux);

        if( (ll_len(pArraySubList)) > 0 )
        {
            ll_sort(pArraySubList , movies_sortById, 1);
            movie_printList(pArraySubList);
        }
        else
        {
            printf("\nAnio no encontrado.\n");
        }
    }
    else
    {
        printf("\nEl archivo aun no ha sido cargado.\n");
    }

    return pArraySubList;
}


int optionMenu_WriteFile (int fileLoaded , char* fileName , LinkedList* pArrayMovies)
{
    int returnAux = 0;

    if( fileLoaded )
    {
        openFileWrite(fileName, pArrayMovies);
        returnAux = 1;
    }
    else
    {
        printf("\nEl archivo aun no ha sido cargado.\n");
    }

    return returnAux;
}


