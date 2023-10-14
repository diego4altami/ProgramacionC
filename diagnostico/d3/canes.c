/*
@file canes.c
@brief Este programa que lea un archivo de texto que contiene datos de 
       mascotas.
       1) Se genera de manera alterna 1 lista de las mascotas doble lineal. 
          El valor de retorno de la función regrese el promedio de edad que 
          tienen los canes dados de alta en la lista. Se comprueba la 
          integridad de la lista imprimiendo en pantalla los resultados: 
          canes catalogados y el promedio de edad.
        2) Se genera función que revise en la lista las razas que inicien 
           con las letras de la ‘a’ a la ‘h’; imprime y comprueba en 
           pantalla los canes catalogas de esa coincidencia..
@author Alberto Parera Méndez en la clase de Guillermo Gómez
@date 13/10/2023
*/

#include "typedef.h"

float insertarListaDoble(char nomArch[], refs *nav);
void imprimirListaDoble(refs nav);
void imprimirCanesPorRazas(ListaMascotas *lista) 

int main (int argc, char *argv[])
{
    FILE *fp;
    refs navegador;
    float promedio;

    navegador.inicio = NULL;
    navegador.fin = NULL;
    navegador.aux = NULL;



    return 0;
}