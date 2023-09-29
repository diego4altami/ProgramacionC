#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct elemento
{
    char palabra[40];
    struct elemento *next;
};

typedef struct elemento nodo;