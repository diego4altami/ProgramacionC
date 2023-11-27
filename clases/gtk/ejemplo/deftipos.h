#include <gtk-2.0/gtk/gtk.h>

struct mascotas
{
    char raza[80];
    float peso;
    int cliente;
};

typedef struct mascotas tipoMascotas;

struct elemento
{
    tipoMascotas datos;
    struct elemento *izq, *der;
};
typedef struct elemento nodo;

struct appGTK
{
    nodo *inicio, *fin, *aux;
    GtkWidget *clienteLbl, *razalbl, *pesolbl, *imagenPet;
    GtkWidget *botIzq, *botDer, *insertarNodo;
    GtkWidget *inCliente, *inRaza, *inPeso;
};
typedef struct appGTK refsApp;