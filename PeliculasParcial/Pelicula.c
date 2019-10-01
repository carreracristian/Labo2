#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"

#include "Pelicula.h"
#include "Actor.h"
#include "genero.h"

#define ID_INICIO 1000

static void cargarGenero(char mensaje[], ePelicula listadoPel[], int indice, eGenero listadoGen[], int tg);

static void cargarActor(char[], ePelicula[], int indice, eActor[], int ta);

void Pelicula_mostrarUno(ePelicula pel, eActor listaActores[], int tamA, eGenero listaGeneros[], int tamG);

int menu(char texto[])
{
    int opcion;

    printf("%s", texto);
    scanf("%d", &opcion);

    return opcion;
}
void Pelicula_mostrarEncabezado(void){
    printf("\n\t\t\t\t\t----LISTADO DE PELICULAS----\n");
    printf("\n ID \t\t\tTITULO \t\tDIA \tMES \tANIO \t\t\tACTOR \t\t\t\t GENERO \n");
}

void Pelicula_mostrarUno(ePelicula pel, eActor listaActores[], int tamA, eGenero listaGeneros[], int tamG)
{

    int indiceActor= Actor_buscarPorId(listaActores, tamA, pel.idActor);
    int indiceGenero= Genero_buscarPorId(listaGeneros, tamG, pel.idGenero);
    printf("\n %2d \t%2d \t%20s \t\t\t%2d \t%15s \t\t%15s", pel.id, pel.codigo, pel.titulo, pel.anio,
          listaGeneros[indiceGenero].genero, listaActores[indiceActor].nombre  );
}

int Pelicula_mostrarListado(ePelicula listaPeliculas[] ,int tamP, eActor listaActores[], int tamA, eGenero listaGeneros[], int tamG){

    printf("\n ID \tCODIGO \t\tTITULO \t\t\tANIO \t\t\tGENERO \t\tACTOR\n");

    int i;
    for(i=0;i<tamP;i++){
        if( listaPeliculas[i].estado==OCUPADO && listaPeliculas[i].id >= ID_INICIO){
            Pelicula_mostrarUno(listaPeliculas[i], listaActores, tamA, listaGeneros, tamG);
        }

    }
    printf("\n\n\n");
    return 0;
}

int Pelicula_init(ePelicula listado[],int limite){
    int retorno = 0;
    int i;
    for(i=0; i<limite; i++){
        listado[i].estado= LIBRE;
        listado[i].id= 0;
    }
    return retorno;
}

void harcodearPeliculas(ePelicula listaPeliculas[], int tamP, eActor listaActores[], int tamA, eGenero listaGeneros[], int tamG){
    int ids[]= {1000,1001,1002,1003,1004,1005,1006,1007};
    int codigos[]= {999,666,555,777,111,222,101,102};
    char titulos[][TAM_TIT]= {"Terminator","Thor","IT","El Gladiador","Scary Movie 4","Yo soy asi",
    "Scary Movie 2","Sexto Sentido"};
    int anios[]= {2012,1986,1975,1990,2012,1990,2015,1999};
    int idActores[]= {1,5,4,4,4,4,1,1};
    int idGeneros[]= {1,1,3,4,2,5,2,5};

    int i;
    for(i=0;i<8;i++){
        listaPeliculas[i].id= ids[i];
        listaPeliculas[i].codigo= codigos[i];
        strcpy(listaPeliculas[i].titulo, titulos[i]);
        listaPeliculas[i].anio= anios[i];
        listaPeliculas[i].idActor= idActores[i];
        listaPeliculas[i].idGenero= idGeneros[i];
        listaPeliculas[i].estado= OCUPADO;
    }
}

int dameLugar (ePelicula listaPeliculas[], int tam)
{
   int indice = -1;
   int i;
    for(i=0; i< tam ; i++)
    {
        if( listaPeliculas[i].estado == LIBRE)
        {
            indice = i ;
            break;
        }
    }
    return indice ;
}
int Pelicula_siguienteID (ePelicula listaDePeliculas[], int limite)
{
    int retorno=0;
    int i;
    if (limite > 0 && listaDePeliculas != NULL)
    {
        for (i=0; i<limite; i++)
        {
            if(listaDePeliculas[i].estado==OCUPADO)
            {
                if(listaDePeliculas[i].id>retorno)
                {
                    retorno=listaDePeliculas[i].id;
                }
            }
        }
    }

    return retorno+1;

}
int Pelicula_buscarCodigo(ePelicula listaDePeliculas[], int limite, int codigo)
{
    //Supongo que el codigo no fue usado en las peliculas ya cargadas
   int retorno=0;
    int i;
    if (limite > 0 && listaDePeliculas != NULL)
    {
        for (i=0; i<limite; i++)
        {
            if(listaDePeliculas[i].estado==OCUPADO && listaDePeliculas[i].codigo == codigo)
            {
                //Encontre una pelicula que tiene el mismo codigo
                retorno= -1;
                break;
            }
        }
    }
    return retorno;
}

static void cargarActor(char mensaje[], ePelicula listadoPel[], int indice, eActor listadoAct[], int ta){
    int idActor= pedirEnteroPositivo(mensaje);
    while(Actor_buscarPorId(listadoAct,ta,idActor) < 0 ){
        printf("\nError.\n");
        idActor= pedirEnteroPositivo(mensaje);
    }
    listadoPel[indice].idActor= idActor;
}

static void cargarGenero(char mensaje[], ePelicula listadoPel[], int indice, eGenero listadoGen[], int tg){

    int idGenero= pedirEnteroPositivo(mensaje);
    while(Genero_buscarPorId(listadoGen,tg,idGenero) < 0 ){
        printf("\nError.\n");
        idGenero= pedirEnteroPositivo(mensaje);
    }

    listadoPel[indice].idGenero= idGenero;
}

int cargarPelicula (ePelicula listaPelicula[], int tPel, eActor listaActores[], int tAct, eGenero listaGeneros[], int tGen)
{
 int resultado= -1;
    int indice= dameLugar(listaPelicula,tPel);
    char auxTitulo[TAM_TIT];
    if (indice < 0){
        printf("\nNo hay espacio suficiente para agregar una nueva pelicula.\n");
    }else{

        listaPelicula[indice].id= Pelicula_siguienteID(listaPelicula,tPel);


        int codigo;
        do{
            codigo= pedirEnteroRango("Ingrese un codigo de 3 cifras (de 100 a 999)", 100,999);
            if(Pelicula_buscarCodigo(listaPelicula,tPel,codigo) == -1){
                printf("\nError. El codigo ya esta usado en otra pelicula.\n");
            }
        }while(Pelicula_buscarCodigo(listaPelicula,tPel,codigo)== -1);

        listaPelicula[indice].codigo= codigo;

        pedirCadena("Ingrese el titulo",auxTitulo,TAM_TIT);


        strcpy(listaPelicula[indice].titulo,auxTitulo);
        listaPelicula[indice].anio=validarDato("\nIngrese anio de estreno: ",1894 , 2025);

        Actor_mostrarLista(listaActores,tAct);
        cargarActor("Ingrese el id de actor", listaPelicula, indice, listaActores, tAct);
        Genero_mostrarLista(listaGeneros,tGen);
        cargarGenero("Ingrese el id de genero",listaPelicula, indice, listaGeneros, tGen);
        listaPelicula[indice].estado= OCUPADO;
        printf("\n\nPelicula cargada.\n");

        resultado= 0;
    }
    return resultado;
}
int yaHayPelicula (ePelicula listaPeliculas[], int tPel)
{
    int resultado= -1;
    int i;
    for(i=0;i<tPel;i++){
        if(listaPeliculas[i].estado == OCUPADO){
            resultado= 0;
            break;
        }
    }
    return resultado;
}
int borrarPelicula (ePelicula listaP[], int tamP, int id, eGenero ListaG[], int tamG, eActor listaA[], int tamA)
{
    int indice;
    int retorno;
    int ordenar=0;
    char auxID[10];
    char seguir[1];

    if(listaP != NULL && tamP > 0)
    {
        system("cls");
        printf("\n--> BAJA DE PELICULA <--\n\n");

        ordenarPeliculaIdAscYDesc(listaP, tamP, ordenar);
        Pelicula_mostrarListado(listaP ,tamP, listaA,  tamA, ListaG,  tamG);

        if (!funcionGetStringNumeros("Ingrese Id\n",auxID))
        {
            printf("Error el id solo debe tener numeros..");
            system("pause");
            system("cls");
        }else{

        id=atoi(auxID);
        indice=Pelicula_buscarPorId(listaP, tamP, id);
        if (indice==-1)
        {
            printf("\n No hay ninguna pelicula con ese ID..");
        }else{
        retorno=0;
        Pelicula_mostrarUno(listaP[indice], listaA, tamA, ListaG, tamG);
        funcionContinuarSiONo("\nDesea Eliminarlo s/n: ",seguir);
                if(seguir[0] == 'n' || seguir[0] == 'N')
        {
            printf("Baja cancelada\n\n");
        }else{
            listaP[indice].estado = LIBRE;
            printf("Borrado exitoso\n\n");}

        system("pause");}

      }

    }
    return retorno;

    }
    int Pelicula_buscarPorId(ePelicula listaPeliculas[] ,int limite, int id)
    {
    int retorno = -1;
    int i;
    for(i=0;i<limite;i++){
        if(listaPeliculas[i].id == id){
            retorno = i;
            break;
        }
    }
    return retorno;
}
int ordenarPeliculaAnioAscYDesc (ePelicula listaPelicula[], int tamP, int ordenar)
{
    ePelicula auxPelicula;
    char auxOrdenar[1] ;
    int i;
    int j;
    if(!funcionGetStringNumeros("\n Ingrese 1 para ordenar de manera ascendente o ingrese 2 para ordenar de manera descendente: ",auxOrdenar))
    {
        printf("\nError debe ingresar un numero..");

    }

    ordenar = atoi(auxOrdenar);

     switch(ordenar)
    {
    case 1:
        for(i = 0; i < tamP - 1; i++)
        {
            for(j = i + 1; j < tamP; j++)
            {
                if(listaPelicula[i].estado == OCUPADO && listaPelicula[i].id >= ID_INICIO){
                        if (listaPelicula[i].anio > listaPelicula[j].anio)
                        {
                             auxPelicula = listaPelicula[i];
                             listaPelicula[i] = listaPelicula[j];
                             listaPelicula[j] = auxPelicula;
                    }
                }
            }
        }
        printf("\n\nEl ordenado ascendente se ha realizado con exito.\n");
        system("pause") ;
        system("cls") ;
        break;
   //Revisar
    case 2:

        for( i = 0; i < tamP-1; i++)
        {
            for( j = i+1; j < tamP; j++)
            {
                if(listaPelicula[i].estado == OCUPADO && listaPelicula[i].id >= ID_INICIO){
                        if (listaPelicula[i].anio < listaPelicula[j].anio){

                             auxPelicula = listaPelicula[i];
                             listaPelicula[i] = listaPelicula[j];
                             listaPelicula[j] = auxPelicula;

                             }

              /*  else if(strcmp(lista[j].apellido, lista[i].apellido) == 0 && lista[j].sector > lista[i].sector  && lista[j].estado == 0 && lista[i].estado == 0)
                {
                    auxEmpleado = lista[i];
                    lista[i] = lista[j];
                    lista[j] = auxEmpleado;
                }*///Por si me piden ordenar anio con otra cosa.
                }
            }
        }

        system("pause") ;
        system("cls") ;
        break;
    default:
        printf("No ingreso 1 o 2");
    }
    return 0;
}
void listarPeliculas (ePelicula listaPeliculas[], int tamP, eActor listaActores[], int tamA, int ordenar, eGenero listaGenero[], int tamG)
{
    char continuar= 's';

    do
    {

    int opcion= menu("\n\nIngrese las siguientes opciones:"
                     "\n 1.Mostrar la lista de peliculas con actor"
                     "\n 2.Mostrar la lista de peliculas sin Actor."
                     "\n 3.Ordenar peliculas por anio de estreno."
                     "\n 4.Ordenar Actores por Pais de Origen.\n "
                     "\n 5.Volver al menu principal.\n\nElija una opcion:  ");

                     switch (opcion)

                     {
                    case 1:

                        ordenarPeliculaIdAscYDesc(listaPeliculas, tamP, ordenar);
                        Pelicula_mostrarListado(listaPeliculas, tamP, listaActores, tamA, listaGenero, tamG);
                        break;
                    case 2:
                        ordenarPeliculaIdAscYDesc(listaPeliculas, tamP, ordenar);
                        Pelicula_mostrarListaDePeliculaSinActor(listaPeliculas, tamP, listaGenero, tamG);
                        break;
                    case 3:
                        ordenarPeliculaAnioAscYDesc(listaPeliculas, tamP, ordenar);
                        Pelicula_mostrarListado(listaPeliculas, tamP, listaActores, tamA, listaGenero, tamG);
                        break;
                    case 4:
                       ordenarActoresPorPaisAscYDesc(listaActores, tamA, ordenar);
                       Actor_mostrarLista(listaActores, tamA);
                        break;
                    case 5:
                        printf(" Salir \n\n");
                        continuar = 'n';
                        system("pause");
                        break;
                     }
    }while(continuar=='s');
}
void modificarPelicula (ePelicula listaPel[], int tamP, eActor listaActor[], int tamA, eGenero listaGenero[], int tamG)
{
    int id;
    int ordenar=0;
    int indice;
    char auxId[5];
    char seguir[1];
    char nuevoTitulo[5];
    char nuevoAnio[5];


    system("cls");
    printf("-->MODIFICAR PELICULA<-- \n\n");

    ordenarPeliculaIdAscYDesc(listaPel, tamP, ordenar);
    Pelicula_mostrarListado(listaPel, tamP, listaActor, tamA, listaGenero, tamG);

    if (!funcionGetStringNumeros("Ingrese el id de la Pelicula: ",auxId))
    {
        printf("Error, el id solo debe contener numeros..");
    }

    id= atoi(auxId);
    indice= Pelicula_buscarPorId(listaPel , tamP, id);

    if(indice== -1)
    {
        printf("No hay ninguna pelicula con ese numero id.. %d \n\n", id);
        system("pause");

    }else{
    Pelicula_mostrarUno(listaPel[indice], listaActor, tamA, listaGenero, tamG);

    funcionContinuarSiONo("\nDesea modificar el titulo: s/n",seguir);
    if(seguir[0] == 'n'|| seguir[0] == 'N')
        {
            printf("\n  No modifico el titulo. \n\n");
            system("cls") ;

        } else if(!funcionGetStringLetras("Ingrese nuevo titulo: ",nuevoTitulo))
            {
                printf("\n Error. El titulo debe tener al menos una letra.");
            }else
            {
            strcpy(listaPel[indice].titulo,nuevoTitulo);
            printf("\n\n  Usted a modificado el nombre. \n\n");
            }
    //MODIFICAR AÑO
    Pelicula_mostrarUno(listaPel[indice], listaActor, tamA, listaGenero, tamG);

   funcionContinuarSiONo("Desea modificar el anio de estreno: s/n",seguir);
    if(seguir[0] == 'n'|| seguir[0] == 'N')
        {
            printf("\n  No modifico el anio. \n\n");
            system("cls") ;

        } else if(!funcionGetStringNumeros("Ingrese el nuevo anio de estreno: ",nuevoAnio))
            {
                printf("\n Error. El anio debe tener solo numeros..");
            }else{
            listaPel[indice].anio= atoi(nuevoAnio);
            printf("\n\n  Usted a modificado el anio de estreno. \n\n");
            }
  //MODIFICAR ACTOR
            funcionContinuarSiONo("Desea modificar el Actor: s/n",seguir);
            if(seguir[0] == 'n'|| seguir[0] == 'N')
                {
                    printf("\n  No modifico el actor. \n\n");
                    system("cls") ;
                }else{
            Actor_ordenarPorIdAsc(listaActor, tamA);
            Actor_mostrarLista(listaActor,tamA);
            PedirActores("Ingrese el nuevo id de actor", listaPel,indice,listaActor,tamA);
            printf("\nActor modificado.\n");}
    }
}
int ordenarPeliculaIdAscYDesc (ePelicula listaPelicula[], int tamP, int ordenar)
{
    ePelicula auxPelicula;
    char auxOrdenar[1] ;
    int i;
    int j;
    if(!funcionGetStringNumeros("\n Ingrese 1 para ordenar el id de manera ascendente o ingrese 2 para ordenar de manera descendente: ",auxOrdenar))
    {
        printf("\nError debe ingresar un numero..");

    }

    ordenar = atoi(auxOrdenar);

     switch(ordenar)
    {
    case 1:
        for(i=0;i<tamP-1;i++){
        for(j=i+1;j<tamP;j++){
            if(listaPelicula[i].estado == OCUPADO && listaPelicula[i].id >= ID_INICIO){
                if (listaPelicula[i].id > listaPelicula[j].id){
                             auxPelicula = listaPelicula[i];
                             listaPelicula[i] = listaPelicula[j];
                             listaPelicula[j] = auxPelicula;
                    }
                }
            }
        }
        printf("\n\nEl ordenado ascendente se ha realizado con exito.\n");
        system("pause") ;
        system("cls") ;
        break;
    case 2:
       for(i=0;i<tamP-1;i++){
        for(j=i+1;j<tamP;j++){
            if(listaPelicula[i].estado == OCUPADO && listaPelicula[i].id >= ID_INICIO){
                if (listaPelicula[i].id < listaPelicula[j].id){

                             auxPelicula = listaPelicula[i];
                             listaPelicula[i] = listaPelicula[j];
                             listaPelicula[j] = auxPelicula;

                             }
                }
            }
        }

        system("pause") ;
        system("cls") ;
        break;
    default:
        printf("No ingreso 1 o 2");
    }
    return 0;
}
int Pelicula_mostrarUnaSinActor(ePelicula pel, eGenero generos[], int tg)
{
    int id= pel.id;
    char titulo[TAM_TIT];
    int anio= pel.anio;
    char genero[TAM_GEN];
    strcpy(titulo, pel.titulo);
    int indice= Genero_buscarPorId(generos,tg,pel.idGenero);
    strcpy(genero, generos[indice].genero);

    printf("\n%d \t%25s \t%d \t%15s",id,titulo,anio,genero);
    return 0;
}
int Pelicula_mostrarListaDePeliculaSinActor(ePelicula listadoPel[] ,int tp, eGenero listadoGen[], int tg)
{

    int i;
    for(i=0;i<tp;i++){
        if((listadoPel[i].estado==OCUPADO) && (listadoPel[i].id >= ID_INICIO)){
            Pelicula_mostrarUnaSinActor(listadoPel[i],listadoGen,tg);
        }

    }
    printf("\n\n\n");
    return 0;
}
int Pelicula_mostrarListaPeliculasConBorrados(ePelicula listaPel[] ,int tamP, eActor listaAct[], int tamA, eGenero listaGen[], int tamG)
{

    int i;
    for(i=0;i<tamP;i++){
        if((listaPel[i].estado==OCUPADO ||
            listaPel[i].estado==LIBRE) && (listaPel[i].id >= ID_INICIO)){
            Pelicula_mostrarUno(listaPel[i],listaAct,tamA,listaGen,tamG);
        }

    }
    printf("\n\n\n");
    return 0;

}
