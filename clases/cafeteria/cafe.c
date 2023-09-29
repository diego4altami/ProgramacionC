/*
    @file cafe.c
    @brief: Este programa permite administrar las colas de clientes
            de una cafetería. Crea listas LIFO y FIFO para dar de alta
            dos clientes en memoria. Con las pilas y las colas
            podemos crear informes de datos de los clientes.
    @author Diego Altamirano Tovar
    @date 28/09/23
*/

#include "tipos.h"

nodo *push(cliente persona, nodo *pt);
void imprimirLista(nodo *pt);
void imprimirListaFIFO(nodo *aux);
void enQueue(cliente persona, nodo **ptInicio,nodo ** ptUltimo);

int main(int argc, char *argv[])
{
    FILE *fp;
    cliente persona; 

    nodo *inicio,*primero, *ultimo;

    inicio = NULL;
    primero = NULL;
    ultimo = NULL;

    fp = fopen(argv[1],"r");
    if(fp ==NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }

    while(fscanf(fp," %[^\t]%s\n", persona.nombre, persona.cafe)==2)
    {
        if(strcmp(persona.cafe,"americano")==0)
        {
            persona.precio = 20.00;
            enQueue(persona,primero,ultimo);
        }
        if(strcmp(persona.cafe,"latte")==0)
        {
            persona.precio = 35.00;
            enQueue(persona,primero,ultimo);
        }
        if(strcmp(persona.cafe,"expres")==0) 
        {
            persona.precio = 30.00;
            inicio = push(persona,inicio);
        }
    }
    imprimirListaFIFO(primero);
    imprimirLista(inicio);

    fclose(fp);

    return 0;
}