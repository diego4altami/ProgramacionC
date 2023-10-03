/*
    @file circular.c
    @brief: Este ejemplo es para una lista simple circular que simula
            una cola de personas que cuenta con un número de prioridad.
            1) Cree una lista circular a partir de los datos de un archivo de texto.
            2)imprima la lista creada
    @author Diego Altamirano Tovar
    @date 26/09/23
*/

#include "defcircular.h"
void enQueueCirc(nodo **ptPrimero, nodo **ptUltimo, char nom[], int pri);
void imprimirColaCirc(nodo *first, nodo *last);

int main(int argc, char)
{
    char nombre[80];
    int prioridad;

    FILE *fp;
    nodo *primero, *ultimo;

    primero = NULL;
    ultimo = NULL;

    fp = fopen(argv[1],"r");
    if(fp == NULL)
    {
        printf("\nArchvio no disponible");
        exit(1);
    }
    fclose(fp);

    while(fscanf(fp,"%[^\t]%d\n",nombre, &prioridad)==2)
    {
        enQueueCirc(&primero,&ultimo, nombre, prioriodad);
    }
    imprimirColaCirc(primero,ultimo);
    return 0;
}