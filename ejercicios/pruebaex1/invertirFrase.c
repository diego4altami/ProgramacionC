/*
    @file  Invertir frase.c
    @brief: Se tiene una frase guardada en un archivo de texto frase.txt; la frase dice:
            La educación no es algo que tú puedes terminar
            Haga un programa en C que utilice Listas Simples Lineales y con la ayuda de estas, invierta la frase; la frase debe de quedar así:
            terminar puedes tú que algo es no educación La
            Imprima en pantalla la frase invertida con la ayuda de Listas Lineales Simples; guarde la frase invertida en el archivo de salida invertida.txt.
    @author Diego Altamirano Tovar
    @date 25/09/23
*/

#include "tipos.h"

void guardarInvert(nodo *pt);
nodo *capturarArch(char archNom[]);

int main(int argc, char *argv[])
{
    nodo *inicio;
    char archNom[80];

    inicio = NULL;

    strcpy( archNom,argv[1]);

    inicio = capturarArch(archNom);

    guardarInvert(inicio);

    return 0;
}


