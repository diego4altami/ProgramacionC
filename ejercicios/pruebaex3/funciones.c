/*
@file funciones.c
@brief Este programa incluye las funciones utilizadas en el programa listaDobleCirc.c
@author Diego Altamirano Tovar
@date 17/10/2023
*/


/*
    @brief Esta función crea una lista doble circular con datos obtenidos a partir de un 
           archivo de texto.
    @author Diego Altamirano Tovar
    @date 17/10/23
    @param dat es un struct de tipo alum que contiene el número de cuenta, el nombre y el promedio del alumno
    @param nav es un apuntador de tipo referencias que tiene la dirección del inicio y fin de la lista.
*/

#include "deftipos.h"

/*
    @brief Esta función crea una lista doble circular con datos obtenidos a partir de un 
           archivo de texto.
    @author Diego Altamirano Tovar
    @date 17/10/23
    @param dat es un struct de tipo alum que contiene el número de cuenta, el nombre y el promedio del alumno
    @param nav es un apuntador de tipo referencias que tiene la dirección del inicio y fin de la lista.
*/

extern void insertarCola(refs *nav, alum dat)
{
    nodo *nuevo;
    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1);
    }
    nuevo->datos = dat;
    if((nav->inicio == NULL) && (nav->fin == NULL))
    {
        nuevo->der = nuevo;
        nuevo->izq = nuevo;
        nav->inicio = nuevo;
        nav->fin = nuevo;
    }
    else
    {
        nuevo->izq = nav->fin;
        nuevo->der = nav->inicio;
        nav->fin->der = nuevo;
        nav->inicio->izq = nuevo;
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

    if((nav.inicio == NULL) && (nav.fin == NULL))
    {
        printf("\nLa lista se encuentra vacía.\n");
    }
    else
    {
        do
        {
            printf("\nCuenta: %i Nombre: %s Promedio: %f\n", nav.aux->datos.cuenta,nav.aux->datos.nombre,nav.aux->datos.promedio);
            nav.aux=nav.aux->der;
        }while(nav.aux != nav.inicio);
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

// extern nodo *buscarAlumno(refs nav,int cta)
// {
//     nav.aux = nav.inicio; 

//     if(nav.aux == NULL)
//     {
//         printf("\nLista vacia. \n");
//     }
//     else
//     {
//         while(nav.aux != NULL)
//         {
//             if(cta == nav.aux->datos.cuenta)
//             {
//                 return nav.aux;
//             }
//             else
//             {
//                 nav.aux = nav.aux->der;
//             }
//         }
//     }
    
//     return nav.aux;
// }