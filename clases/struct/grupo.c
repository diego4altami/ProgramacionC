/* 
@file darResultados.c
@brief  Este programa es un ejemplo para crear una lista
        de n alumnos con los siguientes datos: #cuenta,
        nombre, carrera, fecha de nacimiento y promedio
@author Diego Altamirano 
@date 05/sep/2023
*/

#include "defTipos.h"

struct nacimiento
    {
        int dia;
        int mes;
        int anio;
    };

struct alumno
    {   int numCta;
        char nombre[80];
        char carrera[80];
        struct nacimiento fecha;
        float promedio;
    };

int main(void)
{
    struct alumno unAlumno;

    printf("\nDame el nombre: \n");
    scanf("%[^\n]", unAlumno.nombre);
    printf("\nDame el promedio: ");
    scanf(" %f", &unAlumno.promedio);
    printf("\nDame el mes: ");
    scanf(" %d", &unAlumno.fecha.mes);
    return 0;
}