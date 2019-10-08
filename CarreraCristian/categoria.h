#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

    typedef struct{
    int id;
    char descripcion[20];
    }eCategoria;


void mostrarCategorias(eCategoria categorias[], int tam);
void mostrarCategoria(eCategoria categoria);
int cargarDescCategoria(int id, eCategoria categorias[], int tam, char desc[]);


#endif // CATEGORIA_H_INCLUDED
