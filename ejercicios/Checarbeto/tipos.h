#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

struct clientes 
{
    char nombre[80];
    char curp[80];
    int cp;
    float limcred;
};

typedef struct clientes tipoclientes;

struct elemento
{
    tipoclientes clientes;
    struct elemento *next;
};

typedef struct elemento nodo;