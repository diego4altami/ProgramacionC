/*
@file canes.c
@brief Este programa lee un archivo de texto que contiene 
       datos de mascotas y genera de manera alterna 1 lista 
       de las mascotas doble lineal. E valor de retorno
       de la función regresa el promedio de edad que tienen 
       los canes dados de alta en la lista. Comprueba la 
       integridad de la lista imprimiendo en pantalla los 
       resultados: canes catalogados y el promedio de edad.

       Tiene una función que revisa en la lista las razas 
       que inicien con las letras de la ‘a’ a la ‘h’; 
       imprime y comprueba en pantalla los canes 
       catalogas de esa coincidencia.
@author Diego Altamirano Tovar
@date 14/10/2023
*/

#include "deftipos.h"

float insertarListaDoble(char archNom[], refs *nav);
void imprimirListaDoble(refs nav, float prom);
void buscarRazas(refs nav);

int main(int argc,char *argv[])
{
    refs navegador;
    float promedio;

    navegador.inicio = NULL;
    navegador.fin = NULL;
    navegador.aux = NULL;

    promedio = insertarListaDoble(argv[1], &navegador);
    imprimirListaDoble(navegador, promedio);
    buscarRazas(navegador);

    return 0;
}