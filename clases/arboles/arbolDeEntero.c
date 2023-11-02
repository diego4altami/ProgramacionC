/*
 * @file: arboEnteros.c
 * @brief: Ejemplo de creación de árboles binarios
 *
 * A partir de una secuencia de números enteros, este programa genera una estructura de datos de árbol binario
 * jerárquico (su búsqueda podrá ser ascendente o descendente).
 * 
 * 1) Definir el tipo de dato nodo, que permita crear un árbol binario ascendente; defina un struct que tenga un entero y
 *    dos direcciones del tipo nodo (izq y der).
 * 2) La secuencia de datos a ordenar será compilada/leída de un archivo de texto.
 * 3) Reglas del algoritmo para nodo raíz:
 *    a) El primer dato que se lea, será la raíz del árbol.
 *    b) Crear un nodo nuevo (asignación del archivo), apuntas a NULL (izq y der) y lo apuntas con raíz.
 * 4) Los datos subsiguientes serán evaluados. Cada vez que lea un dato nuevo debo: comparar con el raíz:
 *    a) IZQUIERDA Si es menor o igual, debo verificar a la izq si es NULL,
 *       si es NULL creo un nuevo nodo, asigno el dato y coloco el nodo. Ni no es NULL vuelo a evaluar.
 *    b) DERECHA Si es mayor, debo verificar a la de si es NULL,
 *       si es NULL creo un nuevo nodo, asigno el dato y coloco el nodo. Ni no es NULL vuelo a evaluar.
 */

#include "deftipos.h"

nodo *insertarNodArbol(nodo *pt, int num);
void recorrer(nodo *pt);
void imprimirOrdenados(nodo *pt, FILE *fp);
nodo *buscarDirecto(int busca,nodo *pt);

int main(int argc, char *argv[])
{
   nodo *raiz, *temp;
   int numero, resultado;
   FILE *fp;

   raiz = NULL;
   fp = fopen(argv[1], "r");
   if(fp == NULL)
   {
      printf("Archivo no disponible.");
      exit(1);
   }

   while(fscanf(fp, "%i", &numero) == 1)
   {
      raiz = insertarNodArbol(raiz, numero);
   }

   fclose(fp);

   recorrer(raiz);

   fp = fopen("numOrdenados.txt", "w");
   if(fp == NULL)
   {
      printf("Archivo no disponible.");
      exit(1);
   }
   imprimirOrdenados(raiz, fp);
   fclose(fp);

   printf("\nDame el número que desea buscar: \n");
   scanf("%d", &numero);
   temp = buscarDirecto(numero, raiz);
   if(temp == NULL)
   {
      printf("\nBusqueda sin éxito, el dato no está en el árbol\n");
   }
   else
   {
      printf("\nEn la dirección %p está %d\n", temp, temp->num);
   }
   return 0;
}