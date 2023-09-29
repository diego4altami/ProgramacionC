/* 
@file darResultados.c
@brief  Ese archivo tiene  las funciones externas que son
        utilizadas por el programa apuntArreglos.c
@author Diego Altamirano 
@date 31/ago/2023
*/

#include "incluido.h"

/*
@brief Esta función recibe un arreglo de enteros y calcula el promedio de lso números;
       encuentra los valores que son el menor y el mayor de ese conjunto de datos
@author Diego Altamirano 
@date 31/ago/2023
@params tam es el tamaño del archivo entero
@params arreglo[] es un arreglo de enteros 
@params *min es un apuntador de tipo entero, el menor
@params *max es un apuntador de tipo entero, el mayor
@return promedio que es el resultado real del promedio de número
*/

extern float darResultados(int tam, float arreglo[], float *min, float *max)
{
    int i;
    float promedio;
    float suma = 0;
{}
    *min = arreglo[0];
    *max = arreglo[0];

    for(i=0; i < tam; i++)
    {
        if (*min >arreglo[i])
        {
            *min =arreglo[i];
        }
        if (*max <arreglo[i])
        {
            *max =arreglo[i];
        }
        suma = suma +arreglo[i];
    }
    promedio = suma/tam;

    return promedio;
}


/*
@brief Esta funció recibe un arreglo para que se capturen los datos 
       del usuario en este
@author Diego Altamirano 
@date 31/ago/2023
@params tam es el tamaño del archivo entero
@params arreglo[] es un arreglo  
@return promedio que es el resultado real del promedio de número
*/
extern void capturarArreglo(int tam, float arreglo[])
{
    int i;
    for(i = 0; i < tam; i++)
    {
        printf("\nDame el dato %d del arreglo: \n",i+1);
        scanf("%f",&arreglo[i]); // scanf("%d",(arreglo+1));
    }
    
    return;
}