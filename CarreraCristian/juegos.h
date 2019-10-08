#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

typedef struct{
    int codigo;
    char descripcion[20];
    float importe;
    int idCategoria;
}eJuego;

void mostrarjuego(eJuego juegos);
void mostrarjuegos(eJuego juegos[], int tam);
int cargarDescjuego(int id, eJuego juegos[], int tam, char desc[]);

#endif // JUEGOS_H_INCLUDED
