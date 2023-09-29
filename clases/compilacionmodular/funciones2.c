/* 
@file funciones2.c
@brief  Esta función calcula la raiz de un número
@author Diego Altamirano 
@date 18/ago/2023
@params n es un entero
@return resultado es un real
*/

#include <math.h>
extern float raiz(int n)
{
    float root;
    root = sqrt(n);
    return root;
}