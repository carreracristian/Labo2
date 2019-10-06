#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "Filtros.h"
#include "Pelicula.h"
#include "Actor.h"
#include "genero.h"


//Muestra las peliculas con el pais.
static int mostrarPeliculaConPais(ePelicula pel, eActor actores[], int ta, eGenero generos[], int tg, char pais[]);

static void mostrarPaises(eAux listaAux[], int ta);

static void encabezadoPeliculasPorPais(void);
static void encabezadoPais(void);
static void encabezadoActor(void);
static void encabezadoGenero(void);

static void cargarPaisAuxiliar(eActor listaAct[], int ta, eAux listaAux[]);
static void cargarActorAuxiliar(ePelicula listaPel[], int tp, eActor listaAct[], int ta, eAux listaAux[]);
static void cargarGeneroAuxiliar(ePelicula listaPel[], int tp, eGenero listaGen[], int tg, eAux listaAux[]);

//mostrar pelicula con pais
static int mostrarPeliculaConPais(ePelicula pel, eActor actores[], int ta, eGenero generos[], int tg, char pais[])
{
    int id= pel.id;
    int codigo= pel.codigo;
    char titulo[TAM_TIT];
    int anio= pel.anio;
    char actor[TAM_NOM];
    char genero[TAM_GEN];
    strcpy(titulo, pel.titulo);
    int indice= Actor_buscarPorId(actores,ta,pel.idActor);
    strcpy(actor, actores[indice].nombre);
    indice= Genero_buscarPorId(generos,tg,pel.idGenero);
    strcpy(genero, generos[indice].genero);

    printf("\n%d \t%ds \t%15s \t%5d \t%20s \t%10s \t\t%5s",id,codigo,titulo,anio,actor,genero,pais);
    return 0;
}
static void mostrarPaises(eAux listaAux[], int ta)
{
    encabezadoPais();
    int i;
    for(i=0;i<ta;i++){
        if(listaAux[i].estado== OCUPADO){
            printf("\n%5d \t%15s",listaAux[i].id,listaAux[i].pais);
        }
    }
    printf("\n");
}

static void encabezadoPeliculasPorPais(void)
{
    printf("\n\t\t\t\t\t----LISTADO DE PELICULAS POR PAIS----\n");
    printf("\n ID \t\t\tTITULO \t\tDIA \tMES \tANIO \t\t\tACTOR \t\t\t\t PAIS \n");
}
static void encabezadoPais(void)
{
    printf("\n ID PAIS\tPAIS\n");
}

static void encabezadoActor(void)
{
    printf("\n ID ACTOR\tNOMBRE\t\tCANTIDAD DE PELICULAS\n");
}

static void encabezadoGenero(void)
{
    printf("\n ID GENERO\tTEXTO\t\tCANTIDAD DE PELICULAS\n");
}
static void cargarActorAuxiliar(ePelicula listaPel[], int tp, eActor listaAct[], int ta, eAux listaAux[]){
    int i;
    int j;
    int contador;
    for(i=0; i<ta; i++){
        listaAux[i].id= listaAct[i].id;
    }

    for(i=0;i<ta;i++){
        contador= 0;
        for(j=0;j<tp;j++){
            if(listaPel[j].estado== OCUPADO && listaPel[j].idActor == listaAux[i].id){
                contador++;
            }
            listaAux[i].cantPeliculas= contador;
        }
    }
}

static void cargarGeneroAuxiliar(ePelicula listaPel[], int tp, eGenero listaGen[], int tg, eAux listaAux[]){
    int i;
    int j;
    int contador;
    /*
    for(i=0; i<tg; i++){
        listaAux[i].id= listaGen[i].id;

        //strcpy(listaAux[i].genero,listaGen[i].texto); //
    }
*/
    for(i=0;i<tg;i++){
        contador= 0;
        for(j=0;j<tp;j++){
            if(listaPel[j].estado== OCUPADO && listaPel[j].idGenero == listaGen[i].id){
                contador++;
            }
            listaAux[i].cantPeliculas= contador;
        }
    }
}
int Informes_cantPeliculasPorActor(ePelicula listaPel[], int tp, eActor listaAct[], int ta, eGenero listaGen[], int tg){
    int contador= 0;

    eAux listaAux[ta];
    cargarActorAuxiliar(listaPel,tp,listaAct,ta,listaAux);

    int i;
    int primeraOpcion= 1;
    int ultimaOpcion= 1;

    for(i=0;i<ta;i++){
        if(listaAux[i].id > ultimaOpcion){
            ultimaOpcion= listaAux[i].id;
        }
    }
    Actor_mostrarLista(listaAct,ta);


    /*
    //Actores y su cantidad de peliculas en forma de tabla
    encabezadoActor();
    for(i=0;i<ta;i++){
        printf("\n%5d\t%20s\t%5d",listaAux[i].id,listaAct[i].nombre,listaAux[i].cantPeliculas);
    }
    */
    printf("\n\n");
    int id= pedirEnteroRango("Ingrese el id de actor",primeraOpcion,ultimaOpcion);


    for(i=0;i<tp;i++){
        if(listaPel[i].estado == OCUPADO && listaPel[i].idActor== id){
            Pelicula_mostrarUno(listaPel[i],listaAct,ta,listaGen,tg);
            contador++;
        }
    }
    int indice= Actor_buscarPorId(listaAct,ta,id);
    printf("\n\nCantidad de peliculas del actor %s: %d\n",listaAct[indice].nombre,contador);
    return contador;
}
int Informes_actorConMasPeliculas(ePelicula listaPel[], int tp, eActor listaAct[], int ta){

    eAux listaAux[ta];
    cargarActorAuxiliar(listaPel,tp,listaAct,ta,listaAux);

    int i;
    int contador= 0;
    for(i=0;i<ta;i++){
        if(listaAux[i].cantPeliculas > contador){
            contador= listaAux[i].cantPeliculas;
        }
    }
    encabezadoActor();
    for(i=0;i<ta;i++){
        if(listaAux[i].cantPeliculas == contador){
            printf("\n%5d\t%20s\t%5d",listaAux[i].id,listaAct[i].nombre,listaAux[i].cantPeliculas);
        }
    }
    printf("\n");
    return 0;
}
int Informes_generoConMasPeliculas(ePelicula listaPel[], int tp, eGenero listaGen[], int tg){

    eAux listaAux[tg];
    cargarGeneroAuxiliar(listaPel,tp,listaGen,tg,listaAux);

    int i;
    int contador= 0;
    for(i=0;i<tg;i++){
        if(listaAux[i].cantPeliculas > contador){
            contador= listaAux[i].cantPeliculas;
        }
    }

    encabezadoGenero();
    for(i=0;i<tg;i++){
        if(listaAux[i].cantPeliculas == contador){
            printf("\n%5d\t%15s\t\t%5d",listaAux[i].id,listaGen[i].genero,listaAux[i].cantPeliculas);
        }
    }
    printf("\n");
    return 0;
}
int Informes_estrenadasAnio(ePelicula listaPel[], int tp, eActor listaAct[], int ta, eGenero listaGen[], int tg){
    int contador= 0;
    int i;
    int anio= pedirEnteroPositivo("Ingrese el año de estreno");
    Pelicula_mostrarEncabezado();
    for(i=0;i<tp;i++){
        if(listaPel[i].estado== OCUPADO && listaPel[i].anio == anio){
            Pelicula_mostrarUno(listaPel[i],listaAct,ta,listaGen,tg);
            contador++;
        }
    }
    return contador;
}
int Informes_estrenadasAnioRango(ePelicula listaPel[], int tp, eActor listaAct[], int ta, eGenero listaGen[], int tg){
    int contador= 0;
    int i;
    int anioInicio;
    int anioFin;
    int ordenar=0;
    do{
        printf("\n--Peliculas estrenadas en un rango de anios--\n\n");
        anioInicio= pedirEnteroPositivo("Ingrese el anio de estreno (desde)");
        anioFin= pedirEnteroPositivo("Ingrese el anio de estreno (hasta)");
        if(anioFin - anioInicio < 0){
            printf("\nError en el rango.\n");
        }
    }while(anioFin - anioInicio < 0);

    Pelicula_mostrarEncabezado();
    ordenarPeliculaAnioAscYDesc(listaPel,tp, ordenar);
    for(i=0;i<tp;i++){
        if(listaPel[i].estado== OCUPADO && listaPel[i].anio >= anioInicio && listaPel[i].anio <= anioFin){
            Pelicula_mostrarUno(listaPel[i],listaAct,ta,listaGen,tg);
            contador++;
        }
    }
    return contador;

}
static void cargarPaisAuxiliar(eActor listaAct[], int ta, eAux listaAux[])
{
    int i;
    int ordenar=0;
    for(i=0;i<ta;i++){
        listaAux[i].estado= LIBRE;
        strcpy(listaAux[i].pais,"");
        listaAux[i].id= 0;
    }
    ordenarActoresPorPaisAscYDesc(listaAct,ta, ordenar);

    listaAux[0].id= 1;
    strcpy(listaAux[0].pais,listaAct[0].pais);
    listaAux[0].estado= OCUPADO;

    int idPais= 0;
    for(i=0;i<ta;i++){
        if( stricmp(listaAux[idPais].pais,listaAct[i].pais) == 0){
            continue;
        }
        idPais++;
        strcpy(listaAux[idPais].pais, listaAct[i].pais);
        listaAux[idPais].estado= OCUPADO;
        listaAux[idPais].id= idPais+1;
    }
}
int Informes_peliculasPorPais(ePelicula listaPel[], int tp, eActor listaAct[], int ta, eGenero listaGen[], int tg){
    int contador= 0;

    eAux listaAux[ta];
    cargarPaisAuxiliar(listaAct,ta,listaAux);
    mostrarPaises(listaAux,ta);
    printf("\n--Peliculas por pais--\n");
    int i;
    int primeraOpcion= 1;
    int ultimaOpcion= 1;

    for(i=0;i<ta;i++){
        if(listaAux[i].id > ultimaOpcion){
            ultimaOpcion= listaAux[i].id;
        }
    }

    int idPais= pedirEnteroRango("Ingrese el id de pais",primeraOpcion,ultimaOpcion);



    for(i=0;i<ta;i++){
        if(listaAux[i].estado== OCUPADO && listaAux[i].id == idPais){
            break;
        }
    }
    char paisElegido[TAM_PAIS];
    strcpy(paisElegido,listaAux[i].pais);

    printf("\nPais elegido: %s\n", paisElegido);

    encabezadoPeliculasPorPais();
    int j;
    for(i=0;i<ta;i++){
        for(j=0;j<tp;j++){
            if( stricmp(listaAct[i].pais,paisElegido) == 0){
                if (listaPel[j].estado == OCUPADO && listaPel[j].idActor== listaAct[i].id){
                    mostrarPeliculaConPais(listaPel[j],listaAct,ta,listaGen,tg,paisElegido);
                    contador++;
                }
            }
        }
    }
    printf("\n\nCantidad de peliculas: %d\n\n", contador);

    return contador;
}
int Informes_peliculasPorPaisRangoEstreno(ePelicula listaPel[], int tp, eActor listaAct[], int ta, eGenero listaGen[], int tg)
{
    int contador= 0;
    int ordenar=0;

    eAux listaAux[ta];
    cargarPaisAuxiliar(listaAct,ta,listaAux);
    mostrarPaises(listaAux,ta);
    printf("\n--Peliculas por pais--\n");


    int i;
    int primeraOpcion= 1;
    int ultimaOpcion= 1;

    for(i=0;i<ta;i++){
        if(listaAux[i].id > ultimaOpcion){
            ultimaOpcion= listaAux[i].id;
        }
    }

    int idPais= pedirEnteroRango("Ingrese el id de pais",primeraOpcion,ultimaOpcion);

    for(i=0;i<ta;i++){
        if(listaAux[i].estado== OCUPADO && listaAux[i].id == idPais){
            break;
        }
    }
    char paisElegido[TAM_PAIS];
    strcpy(paisElegido,listaAux[i].pais);

    printf("\nPais elegido: %s\n", paisElegido);

    int anioInicio;
    int anioFin;
    do{
        printf("\n--Peliculas de actores %s estrenadas en un rango de anios--\n\n",paisElegido);
        anioInicio= pedirEnteroPositivo("Ingrese el anio de estreno (desde)");
        anioFin= pedirEnteroPositivo("Ingrese el anio de estreno (hasta)");
        if(anioFin - anioInicio < 0){
            printf("\nError en el rango.\n");
        }
    }while(anioFin - anioInicio < 0);





    //Mostrar ordenando por año de estreno
    ordenarPeliculaAnioAscYDesc(listaPel,tp, ordenar);
    encabezadoPeliculasPorPais();
    int j;
    for(i=0;i<tp;i++){
        for(j=0;j<ta;j++){
            if(listaPel[i].estado==OCUPADO && listaPel[i].anio >= anioInicio && listaPel[i].anio <= anioFin){
               if(stricmp(listaAct[j].pais,paisElegido) == 0 && listaPel[i].idActor== listaAct[j].id){
                    mostrarPeliculaConPais(listaPel[i],listaAct,ta,listaGen,tg,paisElegido);
                    contador++;
               }
            }
        }
    }

/*
    //Mostrar ordenando por nombre de actor
    int j;
    for(i=0;i<ta;i++){
        for(j=0;j<tp;j++){
            if( stricmp(listaAct[i].pais,paisElegido) == 0){
                if (listaPel[j].estado == OCUPADO && listaPel[j].idActor== listaAct[i].id &&
                    listaPel[j].fecha.anio >= anioInicio && listaPel[j].fecha.anio <= anioFin){
                        mostrarPeliculaConPais(listaPel[j],listaAct,ta,listaGen,tg,paisElegido);
                        contador++;
                }
            }
        }
    }
  */

    printf("\n\nCantidad de peliculas de actores %s en el rango: %d\n\n", paisElegido, contador);

    return contador;

}
int Informes_peliculasPorUnPais(ePelicula listaPel[], int tp, eActor listaAct[], int ta, eGenero listaGen[], int tg, char paisElegido[TAM_PAIS]){

    int contador= 0;


    encabezadoPeliculasPorPais();
    int i;
    int j;
    for(i=0;i<ta;i++){
        for(j=0;j<tp;j++){
            if( stricmp(listaAct[i].pais,paisElegido) == 0){
                if (listaPel[j].estado == OCUPADO && listaPel[j].idActor== listaAct[i].id){
                    mostrarPeliculaConPais(listaPel[j],listaAct,ta,listaGen,tg,paisElegido);
                    contador++;
                }
            }
        }
    }
    printf("\n\nCantidad de peliculas: %d\n\n", contador);

    return contador;

}
int Informes_peliculasPorGenero(ePelicula listaPel[], int tp, eGenero listaGen[], int tg)
{
    int result=0;
    int i;
    int j;
    for(i=0;i<tg;i++){
        printf("\n\n-- PELICULAS DEL GENERO %s --\n", listaGen[i].genero);
        for(j=0;j<tp;j++){

            if(listaPel[j].estado== OCUPADO && listaPel[j].idGenero == listaGen[i].id ){
                printf("\n%s",listaPel[j].titulo);
            }
        }
    }

    printf("\n");
    return result;
}
int Informes_cantPeliculasPorGenero(ePelicula listaPel[], int tp, eGenero listaGen[], int tg)
{

    eAux listaAux[tg];
    cargarGeneroAuxiliar(listaPel,tp,listaGen,tg,listaAux);

    encabezadoGenero();
    int i;
    for(i=0;i<tg;i++){
        printf("\n%5d\t%15s\t\t%5d",listaGen[i].id,listaGen[i].genero,listaAux[i].cantPeliculas);
    }
    printf("\n");
    return 0;

}

int Informes_generoConMenosPeliculas(ePelicula listaPel[], int tp, eGenero listaGen[], int tg)
{

    eAux listaAux[tg];
    cargarGeneroAuxiliar(listaPel,tp,listaGen,tg,listaAux);

    int i;
    int flag= 1;
    int contador= 0;


    for(i=0;i<tg;i++){
        if(flag== 1  || listaAux[i].cantPeliculas < contador ){
            contador= listaAux[i].cantPeliculas;
            flag= 0;
        }
    }

    encabezadoGenero();
    for(i=0;i<tg;i++){
        if(listaAux[i].cantPeliculas == contador){
            printf("\n%5d\t%15s\t\t%5d",listaGen[i].id,listaGen[i].genero,listaAux[i].cantPeliculas);
        }
    }

    printf("\n");
    return contador;
}
int Informes_peliculasPorUnPaisConsola(ePelicula listaPel[], int tp, eActor listaAct[], int ta, eGenero listaGen[], int tg){

    int contador= 0;
    char paisElegido[TAM_PAIS];

    printf("\n\nIngrese el pais: ");
    scanf("%s", paisElegido);


    //encabezadoPeliculasPorPais();
    int i;
    int j;
    for(i=0;i<ta;i++){
        for(j=0;j<tp;j++){
            if( stricmp(listaAct[i].pais,paisElegido) == 0){
                if (listaPel[j].estado == OCUPADO && listaPel[j].idActor== listaAct[i].id){
                        mostrarPeliculaConPais(listaPel[j],listaAct,ta,listaGen,tg,paisElegido);
                    contador++;
                if(contador==0){
                    printf("No hay peliculas");
                }
                }
            }
        }
    }
    printf("\n\nCantidad de peliculas: %d\n\n", contador);

    return contador;

}
int Informes_actorConMenosPeliculas(ePelicula listaPel[], int tp, eActor listaAct[], int ta){

    eAux listaAux[ta];
    cargarActorAuxiliar(listaPel,tp,listaAct,ta,listaAux);

    int i;
    int contador= 0;
    for(i=0;i<ta;i++){
        if(listaAux[i].cantPeliculas < contador){
            contador= listaAux[i].cantPeliculas;
        }
    }
    encabezadoActor();
    for(i=0;i<ta;i++){
        if(listaAux[i].cantPeliculas == contador){
            printf("\n%5d\t%20s\t%5d",listaAux[i].id,listaAct[i].nombre,listaAux[i].cantPeliculas);
        }
    }
    printf("\n");
    return 0;
}



