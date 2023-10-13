#include "tiposDoble.h"

void insertarListaDoble(refs *nav, alum dat);
void imprimirListaDoble(refs nav);
void borrarPrimero(refs *nav);
void borrarSegundo(refs *nav);
void borrarTodo(refs *nav);

int main(int argc,char *argv[])
{
    FILE *fp;
    alum datos;
    refs navegador;

    navegador.inicio = NULL;
    navegador.fin = NULL;
    navegador.aux = NULL;

    fp =fopen(argv[1],"r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fscanf(fp, "%d\t %[^\t] %f\n", &datos.cuenta, datos.nombre, &datos.promedio)==3)
    {
        insertarListaDoble(&navegador,datos);
    }
    fclose(fp);
    imprimirListaDoble(navegador);
    printf("\nSe borrarán dos nodos: \n");
    borrarPrimero(&navegador);
    imprimirListaDoble(navegador);
    borrarSegundo(&navegador);
    imprimirListaDoble(navegador);
    borrarTodo(navegador);
    imprimirListaDoble(navegador);

    return 0;
}