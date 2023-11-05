/*
@file: diagnostico4.c
@brief: El objetivo de este programa es conocer 
y evaluar los distintos métodos de ordenamiento y búsqueda.
A) a partir de n datos enteros contenidos en un 
archivo de texto y, con el uso de memoria dinámicam tenemos que generar:
A.1) Tener un archivo de enteros sin repeticiones que estén ordenados. 
A.2) Tener esos mismos enteros sin repeticiones en un arreglo
B) El programa debe de manejar un archivo de entrada que contiene enteros con la línea de comandos.
C) Calcule el tamaño que debe tener el arreglo dinámico. Para ello, calcule cuántos enteros
tiene el archivo.
@author Diego Altamirano Tovar
@date 02/11/2023
*/

#include "deftipos.h"
void colocarEnteros(char nomArch[], int arr[]);
int calcularTam(char nomArch[]);
void imprimirArreglo(int arr[], int size);
void arreglorand(int min, int max, int step);

int main(int argc, char  *argv[])
{
    // int *enteros;
    // int tam;

    // tam = calcularTam(argv[1]);
    // enteros = (int *)malloc(tam *sizeof(int));
    // if(enteros == NULL)
    // {
    //     printf("\nNo hay memoria disponible. \n");
    //     exit(1);
    // }
    // colocarEnteros(argv[1], enteros);
    // printf("\nNúmerod desordenados\n");
    // imprimirArreglo(enteros, tam);


    arreglorand(0,11,1);

    
    return 0;
}