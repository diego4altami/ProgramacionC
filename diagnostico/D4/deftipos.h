#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento
    {
        int dato;
        struct elemento *izq, *der;
    };

typedef struct elemento nodo;

struct posicones
{
    nodo *inicio, *fin, *actaul;
};
typedef struct posiciones referencia; 