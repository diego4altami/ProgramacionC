/*
    @file funcones.c
    @brief este archivo contiene las funciones que son llamadas
           desde listaLIFO.c, permite crear una lista simple y 
           varias operaciones en los nodos de la lista
    @author Diego Altamirano Tovar
    @date 21/09/23

*/

/*
    @brief esta función agrega un nodo al inicio de la lista con la función
           push en una lista LIFO
    @author Diego Altamirano Tovar
    @date 21/09/23
    @param pal[] es una cadena de char
    @param *pt es un apuntador del tipo nodo del inicio de la lista
    @return *pt es un apuntador que devuelve en nuevo inicio de la lista
*/

#include "defTipos.h"

extern nodo * pop(nodo *pt);
void comprobarLista(nodo *pt);

extern nodo *push(char pal[], nodo *pt)
{
    nodo *nuevo;

    nuevo = (nodo*)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1); 
    }
    strcpy(nuevo->palabra,pal);
    nuevo->next=pt;
    pt = nuevo;

    return pt;
}

extern void comprobarLista(nodo *pt)
{
    printf("\nComprobando que la lista esta completa:\n");
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            printf("%s\t",pt->palabra);
            pt = pt->next;
        }
        printf("\n");
    }
    else
    {
        printf("\nLista vacia.\n");
    }
    
    return;
}


extern void dibujarNodos(nodo *pt)
{
    printf("\nGráfico de los apuntadores:\n");
    printf("\ninicio(%p)->",pt);
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            printf("|%s||(%p)|->",pt->palabra,pt->next);
            pt = pt->next;
        }
        printf("NULL\n");
    }
    else
    {
        printf("NULL\n");
    }
    
    return;
}

extern nodo * pop(nodo *pt)
{
    nodo *borra;
    if(pt != NULL)
    {
        borra=pt;
        pt = pt->next;
        free(borra);
    }
    else
    {
        printf("\nLa lista es vacía. \n");
    }

    return pt;
}

extern nodo *borrarTodos(nodo *pt)
{
    while(pt != NULL)
    {
        pt=pop(pt);
    }
    comprobarLista(pt);
    return pt;
}

extern nodo *eliminarPalabra(char pal[], nodo *pt)
{
    nodo *ubica, *recorre;

    ubica = pt;
    recorre = pt;

    if(strcmp(pt->palabra,pal)==0)
    {
        pt=pop(pt);
    }
    else
    {
        while()
        {
            recorre = recorre->next;
            if(strcmp(pal,recorre->palabra)==0)
            {
                ubica->next = recorre->next;
                free(recorre);
                break;
            }
            ubica = recorre;
        }
    }
    return pt;
}