#include "misInluidos.h"

/*
@brief Esta función cuentas las palabras que hay en un archvio de texto y devuelve el número 
       de palabras.

*/
 

extern int contarPalbras(char archivo[])
{
    int numPalabras = 0;
    char palabra[50];
    FILE *fp;

    fp = fopen(archivo,"r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible");
        exit(1);
    }
    while(fscanf(fp, "%s", palabra)==1)
    {
        numPalabras += 1;
    } 
    fclose(fp);

    return numPalabras;
}