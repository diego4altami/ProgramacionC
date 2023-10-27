/*
@file funciones.c
@brief Este programa contiene las funciones que utiliza el programa frutas.c
@author Diego Altamirano Tovar
@date 27/10/2023
*/

#include "deftipos.h"

/*
    @brief Esta función crea una lista doble circular con datos obtenidos a partir de un 
           archivo de texto, estos datos se guardan en orden alfabético.
    @author Diego Altamirano Tovar
    @date 27/10/23
    @param dat es un struct de tipo frut que contiene el nombre de la fruta, el precio 
    y la cantidad de estas frutas que tiene la frutería.
    @param nav es un apuntador de tipo refs que tiene la dirección del inicio y fin de la lista.
*/

extern void insertarListaDobleOrdenada(refs *nav, frut dat)
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
        nuevo->der = NULL;
        nuevo->izq = NULL;
        nav->inicio = nuevo;
        nav->fin = nuevo;
    }
    else
    {
        if(nuevo->datos.nombre[0] < nav->inicio->datos.nombre[0])
        {
            nuevo->der = nav->inicio;
            nuevo->izq = NULL;
            nav->inicio->izq = nuevo;
            nav->inicio = nuevo;
        }
        else
        {
            if(nuevo->datos.nombre[0] > nav->fin->datos.nombre[0])
            {
                nuevo->der = NULL;
                nuevo->izq= nav->fin;
                nav->fin->der = nuevo;
                nav->fin = nuevo;
            }
            else
            {
                nav->aux = nav->inicio->der;
                while(nuevo->datos.nombre[0]>nav->aux->datos.nombre[0])
                {
                    nav->aux = nav->aux->der;
                }
                nuevo->der = nav->aux;
                nuevo->izq = nav->aux->izq;
                nav->aux->izq->der = nuevo;
                nav->aux->izq = nuevo;
            }
        }
    }
    return;
}

/*
    @brief Esta función imprime en pantalla los contenido de una lista doble que esta 
           referenciada usando el apuntador nav. 
    @author Diego Altamirano Tovar
    @date 27/10/23
    @param nav es un apuntador de tipo referencias que tiene la dirección del inicio y fin de la lista.
*/

extern void imprimirListaDoble(refs nav)
{
    nav.aux = nav.inicio;

    while(nav.aux != NULL)
    {
        printf("\nNombre: %s, Precio: $%.2f, Inventario: %i\n", nav.aux->datos.nombre,nav.aux->datos.precio,nav.aux->datos.inventario);
        nav.aux=nav.aux->der;
    }
    if((nav.inicio == NULL) && (nav.fin == NULL))
    {
        printf("\nLa lista se encuentra vacía.\n");
    }
    return;
}

/*
    @brief Esta función calcula el valor del inventario con el que cuenta la frutería, 
    tanto fruta por fruta como el total e imprime un informa en pantalla. 
    @author Diego Altamirano Tovar
    @date 27/10/23
    @param nav es un apuntador de tipo referencias que tiene la dirección del inicio y fin de la lista.
*/

extern void revisarInventario(refs nav)
{
    float inv, sum = 0.00;
    nav.aux = nav.inicio;
    printf("\nValor del inventario de la frutería\n");
    while(nav.aux != NULL)
    {
        inv = nav.aux->datos.precio*nav.aux->datos.inventario;
        printf("\n%s $%.2f\n", nav.aux->datos.nombre,inv);
        sum += inv;
        nav.aux=nav.aux->der;
    }
    printf("\nEl inventario total es de: $%.2f\n",sum);
}

/*
    @brief Esta función recibe un input de un usuario, el input es el porcentaje
    con el cuál el usuario desea aumentar los precios. El programa aumenta los precios de todas las 
    frutas e imprime un informe con los nuevos precios 
    @author Diego Altamirano Tovar
    @date 27/10/23
    @param nav es un apuntador de tipo referencias que tiene la dirección del inicio y fin de la lista.
*/

extern void actualizarPrecios(refs *nav)
{
    float perc = 0;
    printf("\nAumento porcentual de precio\n");
    printf("\nInserte el porcentaje con el que desea aumentar los precios: \n");
    scanf("%f",&perc);

    printf("\nPrecios actaulizados con un aumento del %.2f \n",perc);
    printf("Fruta    Nuevo Precio    Inventario");
    nav->aux = nav->inicio;
    while(nav->aux != NULL)
    {
        nav->aux->datos.precio = nav->aux->datos.precio+(nav->aux->datos.precio * (perc/100));
        printf("\n%s    %.2f    %i\n", nav->aux->datos.nombre,nav->aux->datos.precio,nav->aux->datos.inventario);
        nav->aux=nav->aux->der;
    }
}