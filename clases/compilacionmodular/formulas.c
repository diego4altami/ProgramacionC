#include "defTipos.h"

/* 
@file formulas.c
@brief  Ese es un ejemplo para hacer un programa que utilice la compulación modular.
        En este ejercicio vamos aconcoer el uso de lso header files (archivos de encabezado de módulos)
        Ejercicio: un usuario desea calcular diversos valores a partir de un número entero: cubo de un número entero n;
            1) Calcular el cubo de n (interna)
            2) Calcular el factorial de n (externa, funciones1.c)
            3) Calcular la raíz de n (externa, funciones2.c)
@author Diego Altamirano 
@date 17/ago/2023
*/

//Directivas del Preprocesador
#include <math.h>

//Declaración de los prototipos de función 
float cubo(int datoin);
float factorial(int n);
float raiz(int n);

int main(void)
{
    int n;
    float resultado;

    printf("\nEste programa calcula el cubo, factorial y la raíz de n. Ingrese n: ");
    scanf(" %d",&n);
    resultado = cubo(n);
    printf("\nEl cubo de n es: %0.2f\n", resultado);
#ifdef DEBUG
    resultado = factorial(n);
    printf("\nEl factorial de n es: %0.2f\n",resultado);
#endif
    resultado = raiz(n);
    printf("\nLa raíz de n es: %0.2f\n",resultado);
    printf("\nEl valor de pi es: %f\n",PI);

    return 0;
}

/* 
@brief  Esta función calcula el cubo de un número
@author Diego Altamirano 
@date 17/ago/2023
@params datoin es un entero
@return resultado es un real
*/

float cubo(int datoin)
{
    float resultadocubo;

    resultadocubo = datoin*datoin*datoin;

    return resultadocubo;
}