/*
@file funciones.c
@brief Este programa contiene varias funciones que serán usadas en distintos programas
        mult: esta función multiplica 2 números
        @params n,m son floats
        @return res es un float 
        suma: esta función suma 2 números
        @params n,m son floats
        @return res es un float 
        resta: esta función resta 2 números
        @params n,m son floats
        @return res es un float 
        div: esta función divide 2 números
        @params n,m son floats
        @return res es un float 
        OrdenaNom: esta función compara 2 nombres y los ordena alfabéticamente
        @params nombres[] es una cadena
@autor Diego Altamirano Tovar, Alberto Parera, Ariadna Pedraza
@fecha 25/08/2023
*/

#include "inclusiones.h"

extern float mult(float n, float m)
{
    float res;

    res=n*m;

    return res;
}
extern float suma(float n, float m)
{
    float res;

    res=n+m;

    return res;
}
extern float resta(float n, float m)
{
    float res;

    res=n-m;

    return res;
}
extern float div(float n, float m)
{
    float res;

    res=n/m;

    return res;
}

extern void OrdenaNom(char *nombres[]) {
    for (int i = 0; i < 2; i++) 
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (strcmp(nombres[i], nombres[j]) > 0) 
            {
                char *temp = nombres[i];
                nombres[i] = nombres[j];
                nombres[j] = temp;
            }
        }
    }
}