/*
@file listaDoble.c
@brief Este es un ejemplo para construir una lista doblemente enlazada
       simple.
       A) Haga un programa que agregue datos de alumnos que están en un
          archivo de texto alumnos.txt y los integre a la lista en orden
          del apuntador der (derecha). Inserta conforme están capturados
          en el archivo.
          A.1) Imprima la lista 
       B) Haga una función que borre/atienda el nodo del inicio de la lista
          sin romper la integridad.
          B.1) Borre la lista completa.
          B.2) Haga un modulo/función que permita borrar un neodo que tenga
               el número de cuenta que indique el usuario.
       C) Cree una lista completa  que inserte los nodos en orden acendente
          de la cuenta único del usuario.
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 12/10/2023
*/

#include "tiposDoble.h"

void insertarListaDoble(refs *nav, alum dat);
void imprimirListaDoble(refs nav);
void borrarNodo(refs *nav);
void borrarTodos(refs *nav);
nodo *buscarAlumno(refs nav,int cta);
void borrarNodoCuenta(refs *nav, nodo *borra);

int main(int argc,char *argv[])
{
    FILE *fp;
    alum datos;
    refs navegador;
    int cuenta;
    nodo *nodoEntoncontrado;

    navegador.inicio = NULL;
    navegador.fin = NULL;
    navegador.aux = NULL;

    fp =fopen(argv[1],"r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fscanf(fp, "%d\t %[^\t] %f\n", &datos.cuenta, datos.nombre, &datos.promedio)==3)
    {
        insertarListaDoble(&navegador,datos);
    }
    fclose(fp);
    imprimirListaDoble(navegador);
    // printf("\nSe borrará un nodo: \n");
    // borrarNodo(&navegador);
    // imprimirListaDoble(navegador);
    // borrarTodos(&navegador);
    // imprimirListaDoble(navegador);
    printf("\nDame un número de cuenta para buscar un alumno: \n");
    scanf(" %d", &cuenta);
    nodoEntoncontrado = buscarAlumno(navegador,cuenta);
    if(nodoEntoncontrado == NULL)
    {
        printf("\nEl alumno no existe en el catálogo.\n");
    }
    else
    {
        printf("\nLa cuenta : %d le pertenece a %s, ",cuenta, nodoEntoncontrado->datos.nombre);
        printf("que tiene el promedio: %f y está en la dirección de memoria: %p\n", nodoEntoncontrado->datos.promedio, nodoEntoncontrado);
    }
    printf("\nDame un número de cuenta para borrar el nodo de un alumno: \n");
    scanf("%d",&cuenta);
    nodoEntoncontrado = buscarAlumno(navegador,cuenta);
    if(nodoEntoncontrado == NULL)
    {
        printf("\nEl alumno no existe en el catálogo.\n");
    }
    else
    {
        borrarNodoCuenta(&navegador, nodoEntoncontrado);
        imprimirListaDoble(navegador);
    }


    return 0;
}