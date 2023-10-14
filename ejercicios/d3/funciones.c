/*
@file funciones.c
@brief Este programa incluye las funciones utilizadas en el programa canes.c
@author Diego Altamirano Tovar
@date 14/10/2023
*/

#include "deftipos.h"

/*
    @brief Esta función crea una lista doble con datos de perros a partir de un 
           archivo de texto, también calcula el promedio de las edades de los perros en la lista.
    @author Diego Altamirano Tovar
    @date 14/10/23
    @param archNom es un char que contiene el nombre del archvio a analizar
    @param nav es un apuntador de tipo referencias que tiene la dirección del inicio y fin de la lista.
    @return prom es un float que contiene el promedio de las edades de los perros.
*/
extern float insertarListaDoble(char archNom[],refs *nav)
{
    FILE *fp;
    tipoMascota datos;
    float prom, sum = 0;
    int i;

    fp =fopen(archNom,"r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fscanf(fp, " %[^\t] %f\t %i\n", datos.raza, &datos.peso, &datos.edad)==3)
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
        nuevo->datos = datos;

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
        sum += nuevo->datos.edad;
        i++;

    }
    fclose(fp);
    prom = sum/i;

    return prom;
}

/*
    @brief Esta función imprime en pantalla los contenido de una lista doble que esta 
           referenciada usando el apuntador nav. Imprime el promedio de edades de los perros
           previamente calculado.
    @author Diego Altamirano Tovar
    @date 14/10/23
    @param nav es un apuntador de tipo referencias que tiene la dirección del inicio y fin de la lista.
    @param prom es un float que contiene el promedio de las edades de los perros.
*/

extern void imprimirListaDoble(refs nav, float prom)
{
    nav.aux = nav.inicio;

    while(nav.aux != NULL)
    {
        printf("\nRaza: %s Peso: %f Edad: %i\n", nav.aux->datos.raza,nav.aux->datos.peso,nav.aux->datos.edad);
        nav.aux=nav.aux->der;
    }
    if((nav.inicio == NULL) && (nav.fin == NULL))
    {
        printf("\nLa lista se encuentra vacía.\n");
    }
    else
    {
        printf("\nEl promedio de edad de los perros es de %f años.\n", prom);
    }
    return;
}

/*
    @brief Esta función imprime en pantalla los perros cuyas razas empiecen con las letras
           entre la 'a' y la 'h'.
    @author Diego Altamirano Tovar
    @date 14/10/23
    @param nav es un apuntador de tipo referencias que tiene la dirección del inicio y fin de la lista.
*/

extern void buscarRazas(refs nav)
{
    nav.aux = nav.inicio;

    if((nav.inicio == NULL) && (nav.fin == NULL))
    {
        printf("\nLa lista se encuentra vacía.\n");
    }
    else
    {
        printf("\nEstos son los perros cuya razas empieza con letras entre la 'a'  y la 'h': \n");
        while(nav.aux != NULL)
        {
            if((nav.aux->datos.raza[0]>='a') && (nav.aux->datos.raza[0]<='h'))
            {
                printf("\nRaza: %s Peso: %f Edad: %i\n", nav.aux->datos.raza,nav.aux->datos.peso,nav.aux->datos.edad);
            }
            nav.aux = nav.aux->der;
        }
    }

    return;
}