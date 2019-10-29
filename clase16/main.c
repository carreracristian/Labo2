#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int legajo;
    char nombre[30];
    float salario;

}eEmpleado;
void escribirBinario(char* path);
void leerBinario(char* path);
int main()
{
   /* eEmpleado miEmpleado={100,"Pepe",1000};
    FILE* miArchivo;

    //miArchivo = fopen("D:\\descargas\\mitexto.txt","w");
    //archivo.bin o .dat para guardarlo de manera binaria y wb para escritura en forma binaria//
    miArchivo = fopen("miEmpleado.dat","wb");
    if(miArchivo!=NULL)
    {
        fwrite(&miEmpleado,sizeof(eEmpleado),1,miArchivo);
        fclose(miArchivo);
    }*/
    escribirBinario("miEmpleado.dat");
    leerBinario("miEmpleado.dat");


    return 0;
}
void escribirBinario(char* path)
{
    eEmpleado miEmpleado[2]={{100,"Pepe",1000},{101,"Luis",1001}};
    FILE* miArchivo;
    int i;
    int len=2;

    //miArchivo = fopen("D:\\descargas\\mitexto.txt","w");
    //archivo.bin o .dat para guardarlo de manera binaria y wb para escritura en forma binaria//
    miArchivo = fopen(path,"wb");
    if(miArchivo!=NULL)
    {
        fwrite(&len,sizeof(eEmpleado),2,miArchivo);

        for(i=0;i<2;i++)
        {
            fwrite(&miEmpleado[i],sizeof(eEmpleado),2,miArchivo);
            fclose(miArchivo);
        }

    }

}
void leerBinario(char* path)
{
    eEmpleado miEmpleado[2];
    FILE* miArchivo;
    int i=0;
    int len=2;

    miArchivo=fopen(path,"rb");

    fread(&len,sizeof(int),1,miArchivo);
    printf("%d\n",len);
    fread(&miEmpleado,sizeof(eEmpleado),2,miArchivo);
    /*while(!feof(miArchivo))
    {
        fread(&miEmpleado,sizeof(eEmpleado),2,miArchivo);
        i++;
    }*/

    fclose(miArchivo);
    for(i=0;i<2;i++)
    {
        printf("%d-%s-%f\n",miEmpleado[i].legajo,miEmpleado[i].nombre,miEmpleado[i].salario);
    }
}
