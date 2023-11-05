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
 * @brief Esta función recibe un puntero de referencia y un entero;
 * construye un árbol jerárquico ascendente (del nivel 0 al n)
 * @author/autor caso de Guillermo Gómez Abascal
 * @param *pt es un puntero de tipo nodo.
 * @param *num es un entero.
 * @return pt es un puntero de tipo nodo que apunta al raíz del árbol construido.
 */

extern nodo *insertarNodArbol(nodo *pt, int num)
{
    nodo *nuevo, *aux;

    aux = pt;
    int salir = 1;
    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.");
        exit(1);
    }
    nuevo->num = num;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    if(aux == NULL) pt = nuevo;
    while((aux != NULL) && (salir != 0))
    {
        // if(num == aux->num)
        // {
        //     printf("\n El número %i esta repetido\n ", num); 
        //     free(nuevo); 
        //     return pt;
        // }
        if(num > aux->num) //mover a la derecha
        {
            if(aux->der != NULL) aux = aux->der;
            else
            {
                aux->der = nuevo;
                salir = 0;
            }
        }
        if(num <= aux->num) //mover a la izquierda
        {
            if(aux->izq != NULL) aux = aux->izq;
            else
            {
                aux->izq = nuevo;
                salir = 0;
            }
        }
    }
    return pt;
}

/*
 * @brief Esta función recibe un puntero de referencia y recorre
 * el árbol de izquierda a derecha de forma recursiva.
 * Imprime en pantalla el recorrido.
 * @author/autor Guillermo Gómez Abascal
 * @param *aux es un puntero de tipo nodo.
 * @return aux es un puntero de tipo nodo que apunta al raíz del árbol construido.
 */

extern void recorrer(nodo *aux) // en orden ascendente
{
    if(aux != NULL)
    {
        recorrer(aux->izq);
        printf("%i\n", aux->num);
        recorrer(aux->der);
    }

    return;
}
/*
 * @brief Esta función recibe un puntero de referencia y recorre
 * el árbol de izquierda a derecha de forma recursiva.
 * Imprime en pantalla el recorrido.
 * @author/autor Guillermo Gómez Abascal
 * @param *aux es un puntero de tipo nodo.
 * @return aux es un puntero de tipo nodo que apunta al raíz del árbol construido.
 */

extern void imprimirOrdenados(nodo *aux, FILE *fp)
{
    if(aux != NULL)
    {
        imprimirOrdenados(aux->izq, fp);  
        fprintf(fp, "%i\n", aux->num);
        imprimirOrdenados(aux->der, fp);  
    }
    return;
}

nodo *buscarDirecto(int busca, nodo *aux)
{
    int comparaciones = 1;
    while((aux != NULL) && (aux->num != busca))
    {
        if(busca < aux->num)
        {
            aux = aux->izq;
        }
        else
        {
            aux = aux->der;
        }
        comparaciones++;
    }
    printf("\nSe realizaron %d comparaciones. \n", comparaciones);
    printf("\nSe llego al nivel %d. \n", comparaciones-1);
    return aux;
}