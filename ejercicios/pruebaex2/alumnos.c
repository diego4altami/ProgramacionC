/*
    @file   alumnos.c
    @brief: Este programa toma un lista de alumnos con el 
            formato: <nombre>\t<cal_cálculo>\t<cal_física>\t<cal_programación>\n
            y los guarda en una lista LIFO
    @author Diego Altamirano Tovar
    @date   25/09/23
*/

nodo *leerDatos(char nomArch[]);

#include "tipos.h"

int main(int argc, char *argv[])
{
    nodo *inicio;

    
    inicio = NULL;


    inicio = leerDatos(argv[1]);


    return 0;
}