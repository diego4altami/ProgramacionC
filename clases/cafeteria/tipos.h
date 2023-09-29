#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct pedido
    {   char nombre[80];
        char cafe[40];
        float precio;
    };

typedef struct pedido cliente;

struct elemento
{
    cliente ticket;
    struct elemento *next;
};

typedef struct elemento nodo;
