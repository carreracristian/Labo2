#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

#include "juegos.h"
#include "cliente.h"
#include "alquileres.h"
typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int id;
    int idJuegos;
    int idClientes;
    eFecha fecha;
    int isEmpty;
}eAlquiler;


eAlquiler newAlquiler(int id, int idJuegos, int idClientes, eFecha fecha);
int altaAlquiler(int idAlquiler, eAlquiler alquileres[], int tamAlquileres, eJuego juegos[], int tamJuegos, eCliente clientes[], int tamClientes, eCategoria categorias[], int tamCategorias);
void inicializarAlquileres(eAlquiler alquileres[], int tam);
int hardcodearAlquileres( eAlquiler vec[], int tam, int cantidad);
void mostrarAlquileres(eAlquiler alquileres[],int tam, eJuego juegos[], int tamC);
void mostrarAlquiler(eAlquiler alquiler, eJuego juegos[], int tamC);
int buscarAlquilerLibre(eAlquiler vec[], int tam);

#endif // ALQUILERES_H_INCLUDED
