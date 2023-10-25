/*
@file listaDobleCirc.c
@brief Este programa permite crear una lista doble circular con 
       los datos de alumnos.txt
       1) Haga una función que cree una lista doble enlazada
       2) Verifique con otra función la integridad de la lista creada
       3) Haga una segunda lista doble circular que quede ordenada en 
          orden ascendente por el número de cuenta. 
@author Diego Altamirano
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
      insertarColaOrdenada(&cola,datos);
   }
   // while(fscanf(fp, "%d\t %[^\t] %f\n", &datos.cuenta, datos.nombre, &datos.promedio)==3)
   // {
   //    insertarCola(&cola,datos);
   // }

   fclose(fp);
   imprimirListaDoble(cola);

   return 0;
}