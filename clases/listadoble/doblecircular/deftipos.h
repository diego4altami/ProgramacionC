#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno 
     {
        char nombre[40];
        int cuenta;
        float promedio;
     };
typedef struct alumno alum;

struct elemento
    {
        alum datos;
        struct elemento *izq, *der;
        
    };
typedef struct elemento nodo;

struct referencias
    {
        nodo *inicio, *fin, *aux;
    };
typedef struct referencias refs;