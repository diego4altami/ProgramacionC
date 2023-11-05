/*
@file: archivoaleatorios.c
@brief: Este programa pregunta el mínimo, máximo y cuántos números quieres que esten en el arreglo
y devuelve el archvio de texto que tiene el archivo de texto.
@author Diego Altamirano Tovar
@date 02/11/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // Agregar esta línea para usar srand() y evitar resultados aleatorios repetidos

void arreglorand(int min, int max, int step);
void shuffle(int arreglo[], int n); // Declarar la función shuffle

int main()
{
    int min;
    int max;
    int step;

    printf("\n¿Cuál es el mínimo número del arreglo?\n");
    scanf("%i", &min);
    printf("\n¿Cuál es el máximo número del arreglo?\n");
    scanf("%i", &max); // Cambiar min a max en esta línea
    printf("\n¿Cada cuántos pasos?\n");
    scanf("%i", &step);

    arreglorand(min, max, step);

    return 0;
}

void arreglorand(int min, int max, int step)
{
    int size = (max - min) / step + 1; // Calcular el tamaño del arreglo
    int arreglo[size];

    FILE *fp; 

    fp = fopen("numerosaleatorios.txt","w");
    if(fp ==NULL)
    {
        printf("Archvio no disponible");
        exit(1);
    }
    for (int i = 0, j = min; i < size; i++, j += step) {
        arreglo[i] = j;
    }
    // Llamar a la función shuffle para mezclar el arreglo
    shuffle(arreglo, size);

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%d\t ", arreglo[i]);
    }
    fclose(fp);
}

void shuffle(int arreglo[], int n)
{
    srand(time(0)); // Inicializar la semilla del generador de números aleatorios

    if (n > 1)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = arreglo[j];
            arreglo[j] = arreglo[i];
            arreglo[i] = t;
        }
    }
}