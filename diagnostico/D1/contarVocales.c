/*
@file contarVocales.c
@brief Haga un programa que reciba en la línea de comandos varias palabras y
       al final muestre una lista de cada palabra indicando el número de 
       vocales que contiene cada palabra como lo muestra el ejemplo:
       $./contarVocales.exe gato animal iguana mono ornitorrinco
       Las vocales que contiene cada palabra son las siguientes:
       gato 2
       animal 3
       iguana 4
       mono 2
       ornitorrinco 5
       Restricción: las vocales de las palabras no estás acentuadas y todas 
       son minúsculas.
@autor Diego Altamirano Tovar, Alberto Parera, Ariadna Pedraza
@fecha 25/08/2023
*/

#include "inclusiones.h"

int main (int argc, char *argv[])
{
    int i, j, voc, cont;
    char pal[100];

    i=1;
    cont=0;

    while (i < argc)
    {
        sscanf(argv[i], " %s[^\n]", pal);

        for(j = 0; j <= strlen(pal); j++)
        {
            if((pal[j] == 97) || (pal[j] == 101) || (pal[j] == 105) 
            || (pal[j] == 111) || (pal[j] == 117))
            {
                cont++;
            }
            
            if((pal[j] > 65) && (pal[j] < 90))
            {
                printf("\nLa palabra no puede tener mayusculas");

            }
        
        }
        printf("\n%s %i\n", pal, cont);
        i++; 
        cont = 0;
    }

    return 0;
}