/* 
@file valRet.c
@brief  este ejemplo es para comprender el uso del valor de retorno de una función; es un atajo es un atajo útil en lenguaje c.
    Ejemplo: haga un programa que se quede en un ciclo leyendo número enteros positivos (reales). Si se ingresa un dato diferente,
    el programa temina el ciclo y entrega la suma todal de los reales.
@author Diego Altamirano 
@date 24/ago/2023
*/

#include <stdio.h>
#define PI 3.14159

int main(void)
{
    int numero, suma=0;

    printf("\nEste programa suma naturales, dame un número: ");
    while((scanf("%d",&numero)==1) && (numero >= 0))
    {
        suma = suma+numero;
        printf("\nDame otro número: ");
    }
    printf("\nTu suma de naturales es: %d\n",suma);
    printf("\nEl valor de PI x suma es: %f\n", suma*PI);
#undef PI //asi quitamos el valor de PI
    return 0;
}