/* 
@file palabras.c
@brief Este programa permite escribir una frase en el archivo de frase.txt
       Una vez que la frase quedó escrita, el programa cuenta cuántas palabras
       fueron escritas.
       A) Permita que el usuario ingrese el nombre del archivo desde la 
          línea de comandos.
          $./palabras.exe miFrase.txt
@author Diego Altamirano 
@date 07/sep/2023
*/
#include "misInluidos.h"

int contarPalbras(char archivo[]);

int main(int argc, char *argv[])
{
    FILE *fp;
    char frase[250];
    int  numPalabras;

    fp = fopen(argv[1],"w");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible");
        exit(1);
    }
    printf("\nDame la frase: ");
    scanf("%[^\n]", frase);
    fprintf(fp,"%s", frase);
    fclose(fp);
    numPalabras = contarPalbras(argv[1]);
    printf("\nTu frase contiene %i palabras.\n",numPalabras);

    return 0;
}