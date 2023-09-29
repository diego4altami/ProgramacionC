/*
 * @file  ordenarNombres.c
 * @brief Haga un programa que reciba como argumentos de la línea de comandos 3 nombres. El programa debe de mostrar en pantalla los 3 nombres ordenados (a-z) en orden alfabético como lo muestra el ejemplo:
          $./ordenarNombres.exe oso kiwi loro Los nombres ordenados:
          kiwi
          loro
          oso
 *@aunthor Diego Altamirano Tovar, Alberto Parera, Ariadna Pedraza
 *@date 25/agosto/2023
 *
 */

#include "inclusiones.h"

void OrdenaNom(char *nombres[]);

int main(int argc, char *argv[]) {
    if (argc != 4) 
    {
        printf(" %s, nombre1, nombre2, nombre3\n", argv[0]);
        
    }

    char *nombres[3] = {argv[1], argv[2], argv[3]};

    OrdenaNom(nombres);

    printf("Nombres ordenados:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, nombres[i]);
    }

    return 0;
}