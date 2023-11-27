#include <gtk-2.0/gtk/gtk.h>

struct elemnto 
     {
        char texto[1800];
        int numero;
        struct elemnto *next;
     };
typedef struct elemnto hoja;

struct seccion 
     {
        char titSeccion[40];
        int numSecc;
        hoja *primPag, *ultPag;
        struct seccion *izq, *der;
     };
typedef struct seccion secc;

struct repisa 
     {
        char titulo[40];
        secc *inicio, *fin, *aux;
     };
typedef struct repisa rep;

struct referencias
    {
        rep *inicio, *fin, *aux;
    };
typedef struct referencias nomad;

struct appGTK
{
    nomad *inicio, *fin, *aux;
    GtkWidget *titulo, *numSecc, *botRegresar, *botCrear;
    GtkWidget *avBotReg, *avBotSig;
    GtkWidget *edTitLbl, *edSeccLbl, *edPagLbl, *edBotReg, *edBotEdit;
    GtkWidget *btoSeccSig, *botSeccReg, *nomSecc, *seccNum;
    GtkWidget *botSigPag, *botReg, *botInsertarImg, *botGurdaryVer, *botSigSecc;
    GtkWidget *capNom, *numHoj;
};
typedef struct appGTK refsApp;