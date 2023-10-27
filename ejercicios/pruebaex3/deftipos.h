#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento
    {
        char nombre[40];
        int zona;
        struct elemento *izq, *der;
    };

typedef struct elemento nodo;

struct referencias
    {
        char nombre[40];
        int zona;
        struct referencias *refsinicio, *aux;
    };

typedef struct elemento nav;