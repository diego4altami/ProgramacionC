#include <gtk-2.0/gtk/gtk.h>

struct mascotas
{
    char raza[80];
    float peso;
    int cliente;
};
typedef struct mascotas tipoMascota;

struct elemnto
{
    tipoMascota datos;
    struct elemnto *izq, *der;
};
typedef struct elemnto nodo;

struct appGTK
{
    nodo *inicio, *fin, *aux;
    GtkWidget *clienteLbl, *razaLbl, *pesoLbl;
    GtkWidget *botonIzq, *botonDer, *insertarNodo;
    GtkWidget *inCliente, *inRaza, *inPeso;
};
typedef struct appGTK refsApp;