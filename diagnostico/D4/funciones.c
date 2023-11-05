/*
@file funciones.c
@brief Este programa incluye las funciones utilizadas en el programa listaDobleCirc.c
@author Diego Altamirano Tovar
@date 17/10/2023
*/

#include "deftipos.h"

void shuffle(int *arreglo);

/*
 * @brief Esta función recibe un puntero de referencia y un entero;
 * construye un árbol jerárquico ascendente (del nivel 0 al n)
 * @author/autor caso de Guillermo Gómez Abascal
 * @param *pt es un puntero de tipo nodo.
 * @param *num es un entero.
 * @return pt es un puntero de tipo nodo que apunta al raíz del árbol construido.
 */

extern void colocarEnteros(char nomArch[], int arr[])
{
    int i = 0, numero;
    FILE *fp;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }
    while(fscanf(fp, "%d", &numero)==1)
    {
        arr[i] = numero;
        i=i+1;
    }
    fclose(fp);

    return;
}

extern int calcularTam(char nomArch[])
{
    FILE *fp;
    int tam = 0, numero = 0;

    fp = fopen(nomArch,"r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while((fscanf(fp, "%d", &numero)) == 1)
    {
        tam++;
    }
    fclose(fp);

    return tam;
}

extern void imprimirArreglo(int arr[], int size)
{
    int i;

    printf("\nLos enteros en el arreglo están ahora así: \n");
    for(i = 0; i<size; i++)
    {
        printf("\n %d\n", arr[i]);
    }

    return;
}

// extern void arreglorand(int min, int max, int step)
// {
//     int arreglo[max/step];

//     printf("\n");
//     for (int i = 0, j = min; i <= max/step; i++, j += step) {
//         arreglo[i] = j;
//     }

//     shuffle(arreglo);

//     for (int i = min; i <= max/step; i++) {
//         printf("%d ", arreglo[i]);
//     }
//     printf("\n");
//     return;
// }

// extern void shuffle(int arreglo[])
// {
//     int n;
//     n = sizeof(arreglo);

//     if(n > 1)
//     {
//         int i;
//         for(i = 0; i < n - 1; i++)
//         {
//             int j = i + rand() / (RAND_MAX / (n - i) + 1);
//             int t = arreglo[j];
//             arreglo[j] = arreglo[i];
//             arreglo[i] = t;
//         }
//     }
//     return;
// }