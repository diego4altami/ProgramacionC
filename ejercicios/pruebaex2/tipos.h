#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct alumno
    {   char nombre[80];
        float calCalc;
        float calFis;
        float calProg;
    };

typedef struct alumno tipoAlumno;

struct elemento
{
    tipoAlumno alumno[40];
    struct elemento *next;
};

typedef struct elemento nodo;