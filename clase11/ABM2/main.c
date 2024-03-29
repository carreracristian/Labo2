#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define TAM 10

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
    int isEmpty;
} eAlumno;
int hardcodearAlumnos( eAlumno vec[], int cant,int cantidad);
void mostrarAlumno(eAlumno x);
void mostrarAlumnos(eAlumno vec[], int tam);
void ordenarAlumnos(eAlumno vec[], int tam);
void inicializarAlumnos(eAlumno vec[], int tam);
int buscarLibre(eAlumno vec[], int tam);
int buscarAlumno(int legajo, eAlumno vec[], int tam);
int altaAlumno(eAlumno vec[], int tam, int leg);
eAlumno newAlumno(int leg,char nombre[],int edad, char sexo, int nota1, int nota2, eFecha f);
int bajaAlumno(eAlumno vec[], int tam);
int ModificarAlumno(eAlumno vec[], int tam);
int menu();

int main()
{
    int legajo=20000;
    eAlumno lista[TAM];
    char salir = 'n';

    inicializarAlumnos( lista, TAM);

    legajo=legajo + hardcodearAlumnos(lista, TAM, 9);

    printf("%d",legajo);
    system("pause");

    do
    {
        switch( menu())
        {
        case 1:
            if(altaAlumno(lista, TAM, legajo))
            {
                legajo++;
            };
            break;

        case 2:
            bajaAlumno(lista, TAM);
            break;

        case 3:
            ModificarAlumno(lista, TAM);
            break;

        case 4:
            mostrarAlumnos(lista, TAM);
            break;

        case 5:

            ordenarAlumnos(lista, TAM);
            break;

        case 6:
            printf("Informes Alumno\n\n");
            break;

        case 7:
            printf("Confirma salir?:");
            fflush(stdin);
            salir = getche();
            break;

        default:
            printf("\nOpcion Invalida!\n\n");
        }
        system("pause");
    }
    while(salir == 'n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("****** ABM Alumnos *******\n\n");
    printf("1-Alta alumno\n");
    printf("2-Baja alumno\n");
    printf("3-Modificar alumno\n");
    printf("4-Listar alumnos\n");
    printf("5-Ordenar alumnos\n");
    printf("6-Informes alumno\n");
    printf("7-Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


void mostrarAlumno(eAlumno x)
{
    printf("  %d     %8s     %d    %c   %4d  %4d    %.2f    %02d/%02d/%d\n",
           x.legajo,
           x.nombre,
           x.edad,
           x.sexo,
           x.nota1,
           x.nota2,
           x.promedio,
           x.fechaIngreso.dia,
           x.fechaIngreso.mes,
           x.fechaIngreso.anio);
}

void mostrarAlumnos(eAlumno vec[], int tam)
{
    int i;
    int flag = 0;
    system("cls");

    printf(" Legajo        Nombre   Edad  Sexo Nota1 Nota2 Promedio  FIngreso\n");

    for( i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAlumno(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay alumnos que mostrar\n");
    }

    printf("\n\n");
}

void ordenarAlumnos(eAlumno vec[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for( i= 0; i < tam-1 ; i++)
    {
        for( j= i+1; j <tam; j++)
        {
            if( vec[i].edad > vec[j].edad)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
            else if( vec[i].edad == vec[j].edad && vec[i].legajo > vec[j].legajo)
            {
                auxAlumno = vec[i];
                vec[i] = vec[j];
                vec[j] = auxAlumno;
            }
        }
    }
}

void inicializarAlumnos(eAlumno vec[], int tam)
{
    int i;
    for( i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


int buscarLibre(eAlumno vec[], int tam)
{
    int i;
    int indice = -1;

    for( i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarAlumno(int legajo, eAlumno vec[], int tam)
{
    int i;
    int indice = -1;

    for( i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaAlumno(eAlumno vec[], int tam,int leg){
    int todoOk = 0;
    int indice;
    int esta;
    int legajo;
    char nombre[20];
    char sexo;
    int edad;
    int n1;
    int n2;
    eFecha fecha;

    system("cls");

    printf("*****Alta Alumno*****\n\n");

    indice = buscarLibre(vec, tam);

    if( indice == -1){
        printf("\nSistema completo\n\n");
    }
    else{

       printf("Ingrese nombre: ");
                fflush(stdin);
                gets(nombre);

                printf("Ingrese edad: ");
                scanf("%d", &edad);

                printf("Ingrese sexo: ");
                fflush(stdin);
                scanf("%c", &sexo);

                printf("Ingrese nota 1: ");
                scanf("%d", &n1);

                printf("Ingrese nota 2: ");
                scanf("%d", &n2);

                printf("Ingrese fecha ingreso: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

                vec[indice] = newAlumno(leg, nombre, edad, sexo, n1, n2, fecha);
                todoOk = 1;
                printf("Alta exitosa!!\n\n");

                esta = buscarAlumno(legajo, vec, tam);

        if( esta != -1){
            printf("\nEse legajo ya se encuentra registrado\n\n");
            mostrarAlumno(vec[esta]);

        }

    }

    return todoOk;
}

eAlumno newAlumno(
                  int leg,
                  char nombre[],
                  int edad,
                  char sexo,
                  int nota1,
                  int nota2,
                  eFecha fecha){

    eAlumno al;
    al.legajo = leg;
    strcpy( al.nombre, nombre);
    al.sexo = sexo;
    al.edad = edad;
    al.nota1 = nota1;
    al.nota2 = nota2;
    al.promedio = (float) (nota1 + nota2 )/2;
    al.fechaIngreso = fecha;
    al.isEmpty = 0;

    return al;
}


int bajaAlumno(eAlumno vec[], int tam){
    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Alumno *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarAlumno(legajo, vec , tam);

    if( indice == -1){
        printf("No existe un alumno con ese legajo\n\n");

    }
    else{

        mostrarAlumno(vec[indice]);

        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's'){
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else{
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}
int ModificarAlumno(eAlumno vec[], int tam){

    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Modificar Alumno *****\n\n");
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    int opcion;

    indice = buscarAlumno(legajo, vec , tam);

    if( indice == -1){
        printf("No existe un alumno con ese legajo\n\n");

    }
    else{

        mostrarAlumno(vec[indice]);

        printf("1- Modificar nota1\n");
        printf("2- Modificar nota2\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
    case 1:
        printf("Ingrese nueva nota: ");
        scanf("%d", &vec[indice].nota1);
        vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
        break;

    case 2:
        printf("Ingrese nueva nota: ");
        scanf("%d", &vec[indice].nota2);
        vec[indice].promedio = (float) (vec[indice].nota1  + vec[indice].nota2)/2;
        break;
    case 3:
        printf("Se ha cancelado la mofdificacion ");
        break;

        }
    }
    return todoOk;
}


int hardcodearAlumnos( eAlumno vec[], int tam, int cantidad)
{
    int i;
    int cont=0;
    eAlumno suplentes[]={
    {20000, "Juan",20,'m',5,7,6,{12,5,2018},0},
    {20001, "Alberto",21,'m',2,8,5,{1,6,2015},0},
    {20002, "Ana",22,'f',3,7,5,{2,5,2011},0},
    {20003, "Luis",20,'m',8,8,8,{15,12,2013},0},
    {20004, "Alicia",21,'f',6,6,6,{22,2,2010},0},
    {20005, "Diego",23,'m',5,7,6,{12,9,2015},0},
    {20006, "Sofia",19,'f',7,7,7,{16,4,2018},0},
    {20007, "Clara",21,'f',9,7,8,{19,9,2019},0},
    {20008, "Mauro",20,'m',5,7,6,{7,11,2012},0},
    {20009, "Danbiela",22,'f',3,7,5,{1,5,2003},0},
    {20010, "Agustin",24,'m',2,2,2,{4,3,2010},0},
    };
    if(cantidad<=10 && tam>=cantidad){
        for(i=0;i<cantidad;i++)
        {
            vec[i]=suplentes[i];
            cont++;
        }
    }

    return cont;
}
