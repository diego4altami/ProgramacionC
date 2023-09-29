#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

typedef struct alumno tipoAlumno;
