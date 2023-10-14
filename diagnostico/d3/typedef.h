#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mascotas
{
  char raza[80];
  float peso;
  int edad;
};
typedef struct mascotas tipoMascota;

struct elemento
    {
        tipoMascota datos;
        struct elemento *izq, *der;
    };
typedef struct elemento nodo;

struct referencias
    {
        nodo *inicio, *fin, *aux;
    };
typedef struct referencias refs;