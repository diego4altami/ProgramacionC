#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct carrozas
    {   char marca[80];
        char modelo[80];
        char placa[7];
        int anio;
    };

typedef struct carrozas tipocoche;

struct elemento
{
    tipocoche carro;
    struct elemento *next;
};

typedef struct elemento nodo;
