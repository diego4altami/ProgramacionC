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
int retotnatValor(char nomArch[]);

int main(void)
{
    int pos, numAlumnos;
    
    numAlumnos = retotnatValor("lista.bin");
    printf("\nEn el archivo lista.bin hay %d alumnos.\n", retotnatValor("lista.bin"));
    imprimirEnPantallaBinario("lista.bin");
    printf("\nDame la posición del alumno que deseas modificar\n");
    scanf(" %i",&pos);
    if(pos > numAlumnos)
    {
        printf("\nCálculo fuera del rango del número de alumnos. \n");
    }
    else
    {
        actualizarAlumno(pos,"lista.bin");
        imprimirEnPantallaBinario("lista.bin");
    }
    return 0;
}