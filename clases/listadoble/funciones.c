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
    if((nav.inicio == NULL) && (nav.fin == NULL))
    {
        printf("\nLa lista se encuentra vacía.\n");
    }
    return;
}

extern void borrarNodo(refs *nav)
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

extern void borrarTodos(refs *nav)
{
    char res;

    printf("\n¿Quieres borrar todos los nodos? ['s' | 'n']:\n");
    scanf(" %c", &res);
    if(res == 's')
    {
        while ((nav->inicio != NULL) && (nav->fin != NULL))
        {
            borrarNodo(nav);
        }
    }

    return;
}

extern nodo *buscarAlumno(refs nav,int cta)
{
    nav.aux = nav.inicio; 

    if(nav.aux == NULL)
    {
        printf("\nLista vacia. \n");
    }
    else
    {
        while(nav.aux != NULL)
        {
            if(cta == nav.aux->datos.cuenta)
            {
                return nav.aux;
            }
            else
            {
                nav.aux = nav.aux->der;
            }
        }
    }
    
    return nav.aux;
}

extern void borrarNodoCuenta(refs *nav, nodo *borra)
{
    nav->aux = nav->inicio;

    if(nav->inicio == nav->fin)
    {
        nav->fin = NULL;
        nav->fin = NULL;
        free(borra);
    }
    else
    {
        if(borra->izq == NULL)
        {
            nav->inicio = nav->inicio->der;
            nav->inicio->izq = NULL;
            free(borra);            
        }
        else
        {
            nav->fin = nav->fin->izq;
            nav->fin->der = NULL;
            free(borra);        
        }
    }

    return;
}