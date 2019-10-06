#ifndef GENERO_H_INCLUDED
#define GENERO_H_INCLUDED

#define TAM_GEN 51

typedef struct
{
    int id;
    char genero[TAM_GEN];
}eGenero;

#endif // GENERO_H_INCLUDED
void harcodearGeneros(eGenero listaGeneros[],int tam);
void Genero_mostrarLista(eGenero listaGenero[], int tam);
int pedirGenero(char mensaje[], eGenero listaGeneros[], int tam);
int Genero_buscarPorId(eGenero [] ,int tam, int id);
