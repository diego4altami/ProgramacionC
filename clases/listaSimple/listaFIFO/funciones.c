/*
    @file funcones.c
    @brief este archivo contiene las funciones que son llamadas
           desde listaFIFO.c, permite crear una lista simple y 
           varias operaciones en los nodos de la lista
    @author Diego Altamirano Tovar
    @date 26/09/23

*/

#include "defFIFO.h"

/*
    @author Diego Altamirano Tovar
    @brief 
    @date 26/09/23
    @param 
    @return 
*/
extern void enQueue(char pal[], nodo **ptInicio,nodo ** ptUltimo)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1); 
    }
    strcpy(nuevo->palabra,pal);
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

/*
    @author Diego Altamirano Tovar
    @brief 
    @date 26/09/23
    @param 
    @return 
*/

extern void imprimirListaFIFO(nodo *aux)
{
    printf("\n");
    while(aux != NULL)
    {
        printf("%s\t",aux->palabra);
        aux = aux->next;
    }
    printf("\n");
    return;
}

extern void deQueue(nodo **ptInicio,nodo **ptUltimo)
{
    nodo *nuevo;

    nuevo = *ptInicio;


    if((*ptInicio == NULL) && (*ptUltimo == NULL))
    {
        printf("\nCola vacía.\n");
    }
    else
    {
        if(*ptInicio==*ptUltimo) //Un solo nodo en cola.
        {
            printf("\nSe va a borrar la pabra : %s\n",nuevo->palabra);
            *ptInicio = NULL;
            *ptUltimo = NULL;
            free(nuevo); 
        }
        else
        {
            printf("\nSe va a borrar la pabra : %s\n",nuevo->palabra);
            *ptInicio = (*ptInicio)->next;
            free(nuevo);
        }
    }

    return;

}