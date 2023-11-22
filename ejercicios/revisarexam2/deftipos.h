#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fruta
     {
        char nombre[80];
        float precio;
        int inventario;
     };
typedef struct fruta frut;

struct elemento
    {
        frut datos;
        struct elemento *izq, *der;
        
    };
typedef struct elemento nodo;

struct referencias
    {
        nodo *inicio, *fin, *aux;
    };
typedef struct referencias refs;