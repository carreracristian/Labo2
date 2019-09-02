#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArraysEmployee.h"
#define LIBRE 0
#define OCUPADO 1

eEmpleado ingresarSoloUnEmpleado()
{
    eEmpleado empleadoRetorno;
    printf("\n");
    getSoloLetras("INGRESE SU NOMBRE: ", empleadoRetorno.nombre);
    getSoloLetras("INGRESE SU APELLIDO: ", empleadoRetorno.apellido);
    empleadoRetorno.sector = getSoloEnteros("INGRESE SU SECTOR: ");
    empleadoRetorno.salario = getSoloFlotantes("INGRESE SU SALARIO: ");
    empleadoRetorno.estado = OCUPADO;

    return empleadoRetorno;
}

void mostrarSoloUnEmpleado(eEmpleado unEmpleado)
{
    printf("%10d %15s %15s %15.2f %10d\n", unEmpleado.id, unEmpleado.apellido, unEmpleado.nombre, unEmpleado.salario, unEmpleado.sector);
}

void inicializarListadoEmpleados(eEmpleado listado[], int tamanio)
{
    int i;

    for(i=0; i<tamanio; i++)
    {
        listado[i].estado = LIBRE;
        listado[i].id = 0;
        listado[i].salario = 0;
        listado[i].sector = 0;
        strcpy(listado[i].nombre, "");
        strcpy(listado[i].apellido, "");
    }
}

void mostrarListadoEmpleados(eEmpleado listado[], int tamanio)
{
    int i;

    printf("\n        ID        APELLIDO          NOMBRE         SALARIO     SECTOR\n");
    printf("       _______________________________________________________________\n\n");

    for(i=0; i<tamanio; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            mostrarSoloUnEmpleado(listado[i]);
        }
    }

    printf("\n");
}

int generarId(eEmpleado listado[], int tamanio)
{
    int i;
    int idParaRetornar;

    idParaRetornar = 0;

    for(i=0; i<tamanio; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
                if(listado[i].id > idParaRetornar)
                {
                    idParaRetornar = listado[i].id;
                }
        }
    }

    return (idParaRetornar+1);
}

int buscarEmpleadoPorId(eEmpleado listado[], int tamanio, int id)
{
    int i;
    int retorno;

    retorno = -1;

    for(i=0; i<tamanio; i++)
    {
        if( (listado[i].estado == OCUPADO) && (listado[i].id == id) )
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int buscarLugarLibre(eEmpleado listado[], int tamanio)
{
    int i;
    int indice;

    indice = -1;

    for(i=0; i<tamanio; i++)
    {
        if(listado[i].estado == LIBRE)
        {
            indice = i;
            break;
        }
    }

    if(indice == -1)
    {
        printf("\nNO HAY MAS ESPACIO DISPONIBLE.\n\n");
    }

    return indice;
}

int darDeAltaEmpleado(eEmpleado listado[], int tamanio)
{
    int indice;
    int id;

    indice = buscarLugarLibre(listado, tamanio);
    id = generarId(listado, tamanio);

    if(indice >= 0)
    {
        listado[indice] = ingresarSoloUnEmpleado();
        listado[indice].id = id;
        printf("\nBIENVENIDO/A: %s.SU NRO. DE ID ES: %d\n\n", listado[indice].nombre, listado[indice].id);
    }

    return indice;
}

int darDeBajaEmpleado(eEmpleado listado[], int tamanio)
{
    int id;
    int opcion;
    int retorno;
    int indice;

    retorno = 0;

    mostrarListadoEmpleados(listado,tamanio);
    id = getSoloEnteros("\nINGRESE SU NRO. DE ID: ");
    indice = buscarEmpleadoPorId(listado,tamanio,id);

    if(indice >= 0)
    {
            retorno = 1;
            opcion = getSoloEnteros("\nESTA SEGURO QUE DESEA DAR LA BAJA? (1 = SI / 0 = NO): ");

            if(opcion == 1)
            {
                listado[indice].estado = LIBRE;
                listado[indice].id = 0;
                printf("\nBAJA EXITOSA.\n\n");
            }
            else
            {
                if(opcion == 0)
                {
                    printf("\nBAJA CANCELADA.\n\n");
                }
                else
                {
                    printf("\nOPCION INCORRECTA.\n\n");
                }
            }
    }

    if(retorno == 0)
    {
        printf("\nNRO DE ID INEXISTENTE.\n\n");
    }

    return retorno;
}

int modificarEmpleado(eEmpleado listado[], int tamanio)
{
    int id;
    int opcion;
    int retorno;
    int indice;
    char auxNombre[50];
    char auxApellido[50];
    float auxSalario;
    int auxSector;

    retorno = 0;

    mostrarListadoEmpleados(listado,tamanio);
    id = getSoloEnteros("\nINGRESE SU NRO. DE ID: ");
    indice = buscarEmpleadoPorId(listado,tamanio,id);

    if(indice >= 0)
    {
            retorno = 1;
            opcion = getSoloEnteros("\nQUE DATO DESEA MODIFICAR?\n\n1. NOMBRE.\n2. APELLIDO.\n3. SALARIO.\n4. SECTOR\n\nELEGIR OPCION: ");

            switch(opcion)
            {
                case 1:
                    getSoloLetras("\nINGRESE SU NUEVO NOMBRE: ", auxNombre);
                    strcpy(listado[indice].nombre, auxNombre);
                    printf("\nMODIFICACION EXITOSA.\n\n");
                    break;

                case 2:
                    getSoloLetras("\nINGRESE SU NUEVO APELLIDO: ", auxApellido);
                    strcpy(listado[indice].apellido, auxApellido);
                    printf("\nMODIFICACION EXITOSA.\n\n");
                    break;

                case 3:
                    auxSalario = getSoloFlotantes("\nINGRESE SU NUEVO SALARIO: ");
                    listado[indice].salario = auxSalario;
                    printf("\nMODIFICACION EXITOSA.\n\n");
                    break;

                case 4:
                    auxSector = getSoloEnteros("\nINGRESE SU NUEVO SECTOR: ");
                    listado[indice].sector = auxSector;
                    printf("\nMODIFICACION EXITOSA.\n\n");
                    break;

                default:
                    printf("\nOPCION INVALIDA.\n\n");
                    break;
            }
    }

    if(retorno == 0)
    {
        printf("\nNRO DE ID INEXISTENTE.\n\n");
    }

    return retorno;
}

void ordenarListadoPorApellidoySector(eEmpleado listado[], int tamanio)
{
    int i, j;
    eEmpleado auxiliar;

    for(i=0; i<tamanio; i++)
    {
        for(j=0; j<tamanio-1; j++)
        {
            if(stricmp(listado[i].apellido, listado[j].apellido) == -1)
            {
                auxiliar = listado[i];
                listado[i] = listado[j];
                listado[j] = auxiliar;
            }
            else
            {
                if(stricmp(listado[i].apellido, listado[j].apellido) == 0)
                {
                    if(listado[i].sector < listado[j].sector)
                    {
                        auxiliar = listado[i];
                        listado[i] = listado[j];
                        listado[j] = auxiliar;
                    }
                }
            }
        }
    }
}

void informarSalarios(eEmpleado listado[], int tamanio)
{
    int i;
    float acumuladorSalarios = 0;
    float promedioSalarios = 0;
    int contadorSalarios = 0;
    int contadorSalariosMayores = 0;

    for(i=0; i<tamanio; i++)
    {
        if(listado[i].estado == OCUPADO)
        {
            acumuladorSalarios = acumuladorSalarios + listado[i].salario;
            contadorSalarios++;
        }
    }

    promedioSalarios = (acumuladorSalarios) / (contadorSalarios);

    for(i=0; i<tamanio; i++)
    {
        if( (listado[i].estado == OCUPADO) && (listado[i].salario > promedioSalarios) )
        {
            contadorSalariosMayores++;
        }
    }

    printf("\nTOTAL DE SALARIOS: %.2f", acumuladorSalarios);
    printf("\nPROMEDIO DE SALARIOS: %.2f", promedioSalarios);
    printf("\nCANTIDAD DE EMPLEADOS CON SALARIO MAYOR AL PROMEDIO: %d\n\n", contadorSalariosMayores);
}

void informarEmpleados(eEmpleado listado[], int tamanio)
{
    int opcion;

    opcion = menu("\n1. LISTADO ORDENADO POR APELLIDO Y SECTOR.\n2. TOTAL Y PROMEDIO DE SALARIOS.\n\nELEGIR OPCION: ");

    switch(opcion)
    {
        case 1:
            ordenarListadoPorApellidoySector(listado, tamanio);
            mostrarListadoEmpleados(listado, tamanio);
            break;
        case 2:
            mostrarListadoEmpleados(listado, tamanio);
            informarSalarios(listado, tamanio);
            break;
        default:
            printf("\nOPCION INVALIDA.\n\n");
            break;
    }

}

void hardcodearEmpleados(eEmpleado listado[], int tamanio)
{
    int id[5] = {1,2,3,4,5};
    char nombre[5][50] = {"Pablo","Manuela","Jose","Alejandro","Valeria"};
    char apellido[5][50] = {"Arellano","Hernandez","Ahumada","Romero","Gutierrez"};
    float salario[5] = {10000,11000,12000,13000,14000};
    int sector[5] = {12,4,8,2,16};
    int i;

    for(i=0; i<5; i++)
    {
        listado[i].id = id[i];
        strcpy(listado[i].nombre, nombre[i]);
        strcpy(listado[i].apellido, apellido[i]);
        listado[i].salario = salario[i];
        listado[i].sector = sector[i];
        listado[i].estado = OCUPADO;
    }
}

