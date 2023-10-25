/*
@file funciones.c
@brief Este programa incluye las funciones utilizadas en el programa listaDoble.c
@author Diego Altamirano Tovar
@date 17/10/2023
*/

#include "tiposDoble.h"

/*
    @brief Esta función crea una lista doble con datos obtenidos a partir de un 
           archivo de texto.
    @author Diego Altamirano Tovar
    @date 17/10/23
    @param dat es un struct de tipo alum que contiene el número de cuenta, el nombre y el promedio del alumno
    @param nav es un apuntador de tipo referencias que tiene la dirección del inicio y fin de la lista.
*/

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

/*
    @brief Esta función imprime en pantalla los contenido de una lista doble que esta 
           referenciada usando el apuntador nav. 
    @author Diego Altamirano Tovar
    @date 17/10/23
    @param nav es un apuntador de tipo referencias que tiene la dirección del inicio y fin de la lista.
*/

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

/*
    @brief Esta función borra el primer nodo que se encuentre en la lista doble referenciada usando nav
    @author Diego Altamirano Tovar
    @date 17/10/23
    @param nav es un apuntador de tipo referencias que tiene la dirección del inicio y fin de la lista.
*/

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

/*
    @brief Esta función borra todos los nodos que se encuentren en la lista doble referenciada usando nav
    @author Diego Altamirano Tovar
    @date 17/10/23
    @param nav es un apuntador de tipo referencias que tiene la dirección del inicio y fin de la lista.
*/

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

/*
    @brief Esta función busca un alumno dentro de una lista circular referenciada usando nadv, busca el numero de cuenta previa
           previamente dado
    @author Diego Altamirano Tovar
    @date 17/10/23
    @param nav es un apuntador de tipo referencias que tiene la dirección del inicio y fin de la lista.
    @param cta es un entero que contiene el número de cuenta que se va a buscar dentro del arreglo
    @return regresa un nodo que contiene la dirección del nodo encontrado
*/

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

/*
    @brief Esta función crea una lista doble con datos de perros a partir de un 
           archivo de texto, también calcula el promedio de las edades de los perros en la lista.
    @author Diego Altamirano Tovar
    @date 14/10/23
    @param archNom es un char que contiene el nombre del archvio a analizar
    @param nav es un apuntador de tipo referencias que tiene la dirección del inicio y fin de la lista.
    @return prom es un float que contiene el promedio de las edades de los perros.
*/

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