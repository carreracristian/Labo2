#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "categoria.h"

typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    char sexo;
    int telefono;
    int isEmpty;
}eCliente;


eCliente newCliente(int leg, char nombre[], char apellido[], char sexo, int telefono);
void mostrarCliente( eCliente al, eCategoria categorias[], int tam);
void mostrarClientes(eCliente vec[], int tam, eCategoria categorias[], int tamC);
void inicializarClientes(eCliente vec[], int tam);
void ordenarClientes(eCliente vec[], int tam);
int modificarCliente(eCliente vec[], int tam, eCategoria categorias[], int tamC);
int altaCliente(eCliente vec[], int tam, int leg, eCategoria categorias[], int tamC);
int bajaCliente(eCliente vec[], int tam, eCategoria categorias[], int tamC);
int buscarLibre(eCliente vec[], int tam);
int buscarCliente(eCliente vec[], int tam, int legajo);
int hardcodearClientes( eCliente vec[], int tam, int cantidad);
int menuModificarCliente();


#endif // CLIENTE_H_INCLUDED
