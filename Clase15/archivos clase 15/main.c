#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    char nombre[]="Juan Carlos";
    char nombre2[20];

    f=fopen("archivo.txt","r");

    if(f==NULL)
    {
        printf("No se pudo abrir el archivo.");
        system("pause");
        //Salida con falla//
        exit(EXIT_FAILURE);
    }
    //fprintf para guardar caracteres//

    //fprintf(f,"Hola mundo");
    //fprintf(f,"%s",nombre);

    //fwrite para guardar en binario//

    //fwrite(nombre,sizeof(char),strlen(nombre),f);
    while(!feof(f))
    {

        fread(nombre2,sizeof(char),20,f);
        printf("%s",nombre2);
    }

    fclose(f);

    return 0;
}
