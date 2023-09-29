/* 
@file darResultados.c
@brief  Ese archivo tiene  las funciones externas que son
        utilizadas por el programa invertirFrase.c
@author Diego Altamirano 
@date 23/sept/2023
*/

#include "tipos.h"
extern nodo *push(char pal[], nodo *pt);



/* 
@brief Esta función crea un archivo txt a partir de una lista LIFO 
@author Diego Altamirano Tovar
@date 23/sept/2023
@param  *pt es un apuntador del tipo nodo.
*/
extern void guardarInvert(nodo *pt)
{
    FILE *fp;

    fp = fopen("invertida.txt","w");

    if(pt != NULL)
    {
        while(pt != NULL)
        {
            fprintf(fp,"%s\t", pt->palabra);
            pt = pt->next;
        }
    }
    else
    {
        printf("\nlista vacía\n");
    }

    fclose(fp);

    return;

}


/* 
@brief Esta función copia lo que se encuentra en un archivo de texto
       y lo coloca en una lista lifo
@author Diego Altamirano Tovar
@date 23/sept/2023
@param archNom es una cadena de char que contiene el nombre del archivo
@return *pt es apuntador de tipo nodo que devuelve el 
        el nuevo inico de la lista
*/
extern nodo *capturarArch(char archNom[])
{
    nodo *pt;
    FILE *fp;
    char pal[40];

    fp = fopen(archNom,"r");

    if(fp==NULL)
    {
        printf("archivo no disponible\n");
        exit(1);
    }

    pt = NULL;

    while(fscanf(fp,"%s",pal)==1)
    {
        pt = push(pal,pt);
        
    }
    fclose(fp);

    return pt;
}