/* 
@file actualizarDatos.c
@brief Este programa permite manipular el archivo binario lista.bin utilizando otras funciones;
       permite actualizar los datos.
       1)En
@author Diego Altamirano 
@date 05/sept/2023
*/

#include "defTipos.h"
int imprimirEnPantallaBinario(char nomArch[]);
void actualizarAlumno(int pos,char nomArch[]);

int main(void)
{
    int pos;
    
    imprimirEnPantallaBinario("lista.bin");
    printf("\nDame la posición del alumno que deseas modificar\n");
    scanf(" %i",&pos);
    actualizarAlumno(pos,"lista.bin");

    return 0;
}