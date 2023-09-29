/*
    @file funcones.c
    @brief este archivo contiene las funciones que son llamadas
           desde listaFIFO.c, permite crear una lista simple y 
           varias operaciones en los nodos de la lista
    @author Diego Altamirano Tovar
    @date 26/09/23

*/
#include "tipos.h"

/*
    @author Diego Altamirano Tovar
    @brief 
    @date 26/09/23
    @param 
    @return 
*/

/* 
@brief Esta función agrega un nodo al inicio de la lista con la operación
       en invertirFrase.c
@author Diego Altamirano Tovar
@date 23/sept/2023
@param pal[] y es una cadena de char
@param  *pt es un apuntador del tipo nodo.
@return *pt es apuntador de tipo nodo que devuelve el 
        el nuevo inico de la lista
*/
extern nodo *push(cliente datos, nodo *pt)
{
    nodo *nuevo;

    nuevo = (nodo*)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1); 
    }
    nuevo->ticket=datos;
    nuevo->next=pt;
    pt = nuevo;

    return pt;
}

extern void imprimirLista(nodo *aux)
{
    while(aux != NULL)
    {
        printf("\n%s\t%s\t%f\n", aux->ticket.nombre,aux->ticket.cafe,aux->ticket.precio);
        aux = aux->next;
    }
    return;
}

extern void enQueue(cliente persona, nodo **ptInicio,nodo ** ptUltimo)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1); 
    }
    nuevo->ticket = persona;
    nuevo->next = NULL;

    if((*ptInicio == NULL) && (*ptUltimo == NULL))
    {
        *ptInicio = nuevo;
        *ptUltimo = nuevo;
    }
    else
    {
        (*ptUltimo)->next = nuevo;
        *ptUltimo = nuevo;
    }

    return;
}

extern void imprimirListaFIFO(nodo *aux)
{
    while(aux != NULL)
    {
        printf("\n%s\t%s\t%f\n", aux->ticket.nombre,aux->ticket.cafe,aux->ticket.precio);
        aux = aux->next;
    }
    printf("\n");
    return;
}