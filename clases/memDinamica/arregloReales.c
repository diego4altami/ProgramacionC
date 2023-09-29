/* 
@file darResultados.c
@brief  Haga un programa que le permita crear un arreglo de reales del 
        tamaño que indique un usuario.
        Haga las siguientes funciones en un archivo extra:
        1) sumarReales, que recibe el arreglo y entregue la suma.
@author Diego Altamirano 
@date 01/sep/2023
*/

#include "defTipos.h"
float sumarReales(float arreglo[],int tam);

int main(void)
{
    int tam;
    float reales;
    float *apReales;
s
    printf("\nDame el tamaño de reales que desees sumar: \n");
    scanf(" %d",&tam);

    apReales = (float * )malloc(tam*sizeof(float));
    if(apReales == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }

    printf("\nLa suma de tus reales es: %f\n",sumarReales(apReales,tam));
    free(apReales);

    return 0;
}