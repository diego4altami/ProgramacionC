/*
    @file funcones.c
    @brief Este archivo contien la información de autos que se desean verificar. 
           Los datos se catalogaron en una structura y se generan informes en pantalla y en archivo.
            a)Se tiene un archivo llamado autos.txt del cuál se obtienen los datos para hacer una lista LIFO, 
            se imprime esta lista en pantalla y se crea un archivo .txt donde se guarden los datos invertidos.
            b)También se imprimen en pantalla los autos con la fecha correspondiente a la fecha en la que deben verificarse, 
            este reporte se muestra en pantalla.
            c)Por último, el programa crea un reporte donde aparezcan en pantalla el auto actual de la lista y 
            con la voluntad del usuario avance en la lista o termine el programa.
    @author Diego Altamirano Tovar
    @date 29/09/23
*/

#include "tipos.h"

nodo *push(tipocoche carro, nodo *pt);
nodo *leerDatos(char nomArch[]);
void comprobarLista(nodo *pt);
void guardarInvertida(nodo *pt);
void verificacion(nodo *pt);
void reporte(nodo *pt);

int main(int argc, char *argv[])
{   
    FILE *fp;
    nodo *inicio;

    inicio = NULL;

    inicio=leerDatos(argv[1]);
    comprobarLista(inicio);
    guardarInvertida(inicio);
    verificacion(inicio);
    reporte(inicio);
    return 0;
}