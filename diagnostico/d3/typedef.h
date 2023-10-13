#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mascotas
     {
        char raza[80];
        int edad;
        float peso;
     };
typedef struct mascotas tipoMascota;

struct elemento
    {
        tipoMascota datos;
        struct elemento *next;
        
    };
typedef struct elemento nodoPet;