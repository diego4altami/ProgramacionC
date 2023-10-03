/*
    @file lisFIFO.c
    @brief: Este programa permite la creación de una lista FIFO de palabras.
            1) Haga una función que ponga en cola palabras que se leen de un 
            archivo de texto que contiene un frase.
            2)Haga una función que permita atender/borrar 
    @author Diego Altamirano Tovar
    @date 26/09/23
*/

#include "defFIFO.h"

void enQueue(char pal[], nodo **ptInicio,nodo ** ptUltimo);
void deQueue(nodo **ptInicio,nodo **ptUltimo);
void imprimirListaFIFO(nodo *aux);

int main(int agrc, char *argv[])
{
    FILE *fp;
    char pal[40];
    nodo *primero, *ultimo;
    char opcion = 's';

    primero = NULL;
    ultimo = NULL;

    fp = fopen(argv[1],"r");
    if(fp ==  NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fscanf(fp,"%s",pal)==1)
    {
        enQueue(pal,&primero,&ultimo);
    }
    fclose(fp);

    imprimirListaFIFO(primero);

    while(opcion == 's')
    {
        printf("\nDeseas borrar el nodo (deQueue)?: ");
        scanf(" %c", &opcion);
        if(opcion == 's')
        {
            deQueue(&primero,&ultimo);
        }
        imprimirListaFIFO(primero);
    }

    return 0;
}