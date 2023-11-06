#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct categoria1 
     {
        int clave;
        char categoria[40];
        char producto[40];
        float precio;
        int inventario;
     };
typedef struct categoria1 cat1;

struct categoria2 
     {
        int clave;
        char categoria[40];
        char producto[40];
        float precio;
        int inventario;
     };
typedef struct categoria2 cat2;

struct porcomprar
    {
        char categoria[40];
        char producto[40];
        float precio;
        int cantidad;
    };
typedef struct porcomprar datcar;

struct elemento
    {
        cat1 datos1;
        cat2 datos2;
        struct elemento *izq, *der;
        
    };
typedef struct elemento nodo;

struct elementotipocarro
    {
        datcar datos;
        struct elementotipocarro *next;
    };
typedef struct elementotipocarro nodocar;

struct referencias
    {
        nodo *inicio, *fin, *aux;
    };
typedef struct referencias refs;

struct navegacion
    {
        refs *refscirc, *refslin;
        nodocar *iniciocar;
    };
typedef struct navegacion nav;

