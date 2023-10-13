#include "tiposDoble.h"

extern void insertarListaDoble(refs *nav, alum dat)
{
    nodo *nuevo;
    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1);
    }

    nuevo->izq = NULL;
    nuevo->der = NULL;

    nuevo->datos = dat;

    if((nav->inicio == NULL) && (nav->fin == NULL))
    {
        nav->inicio = nuevo;
        nav->fin = nuevo;
        nav->aux = nuevo;
    }
    else
    {
        nuevo->izq = nav->fin;
        nav->fin->der = nuevo;
        nav->fin = nuevo;
    }

    return;
}

extern void imprimirListaDoble(refs nav)
{
    nav.aux = nav.inicio;

    while(nav.aux != NULL)
    {
        printf("\nCuenta: %i Nombre: %s Promedio: %f\n", nav.aux->datos.cuenta,nav.aux->datos.nombre,nav.aux->datos.promedio);
        nav.aux=nav.aux->der;
    }
    return;
}

extern void borrarPrimero(refs *nav)
{
    nav->aux = nav->inicio;
    if((nav->inicio == NULL) && (nav->fin == NULL))
    {
        printf("\nNo se puede borrar un nodo, la lista se encuentra vacía.\n");
    }
    else
    {
        if(nav->inicio == nav->fin)
        {
            nav->inicio = NULL;
            nav->fin = NULL;
            free(nav->aux);
        }
        else
        {
            nav->inicio = nav->inicio->der;
            nav->inicio->izq = NULL;
            free(nav->aux);
        }
    }

    return;
}

extern void borrarTodo(refs *nav)
{
    while()
    {
        borrarPrimero(nav);
    }
    return;
}