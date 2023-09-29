/* 
@file funciones.c
@brief  Esta función calcula el factorial de un número
@author Diego Altamirano 
@date 17/ago/2023
@params n es un entero
@return resultado es un entero
*/

extern float factorial(int n)
{
    int resfact=1;
    if(n >0)
    {
        resfact = n*factorial(n-1);
    }
    return resfact;
}