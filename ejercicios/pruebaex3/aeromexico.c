/*
@file: arboEnteros.c
@brief: 
@author Diego Altamirano Tovar
@date 17/10/2023
 */

#include "deftipos.h"

void insertarCola(refs *nav, alum dat);
void imprimirListaDoble(refs nav);
void insertarColaOrdenada(refs *filaO, alum dat);

int main(int argc, char *argv[])
{
   refs cola;
   FILE *fp;
   alum datos;

   cola.inicio = NULL;
   cola.aux = NULL;
   cola.fin = NULL;

   fp = fopen(argv[1], "r");
   if(fp == NULL)
   {
      printf("\nArchvio no disponible");
      exit(1);
   } 
   while(fscanf(fp, "%d\t %[^\t] %f\n", &datos.cuenta, datos.nombre, &datos.promedio)==3)
   {
      insertarCola(&cola,datos);
   }

   fclose(fp);
   imprimirListaDoble(cola);

   return 0;
}