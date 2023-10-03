#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct elemento
{
    int prioridad;
    char nombre[40];
    struct elemento *next;
};

typedef struct elemento nodo;