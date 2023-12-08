#include <gtk-2.0/gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

struct arbol
{
   int arbNumPag;
   char indice[100];
   struct arbol *izq, *der;
};
typedef struct arbol arbolote;

struct element
{
    char titulo[40];
    char titSeccion[40];
    int numero;
    char texto[1800];
    int marcador;
    struct element *izq, *der;
};
typedef struct element dubCircPag;

struct elemento
{
    char titulo[40];
    char titSeccion[40];
    int numero;
    char texto[1800];
};
typedef struct elemento tipohoja;

struct elemnto 
{
  char titulo[40];
  char titSeccion[40];
  int numero;
  char texto[1800];
  struct elemnto *next; //chance quitar esto para la lectura correcta del binario
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
  int numSeccs;
  secc *inicio, *fin, *aux;
  struct repisa *izq, *der;
};
typedef struct repisa rep;

struct otroLibro
{
    char titulo[40];
    dubCircPag *inicio, *fin, *aux;
    struct otroLibro *izq, *der;
    //falta agregar la referencia a la raìz del àrbol 
};
typedef struct otroLibro libroLeer;

struct appGTK
{
  rep *inicio, *fin, *aux;
  rep *libroActual;
  libroLeer *inicioLeer, *finLeer, *auxLeer;
  libroLeer *lectura;
  arbolote *raiz;
  GtkWidget *titulo, *numSecc, *botRegresar, *botCrear;
  GtkWidget *avBotReg, *avBotSig;
  GtkWidget *avBotReg2, *avBotSig2;
  GtkWidget *avBotReg3, *avBotSig3;
  GtkWidget *edTitLbl, *edSeccLbl, *edPagLbl, *edBotReg, *edBotEdit;
  GtkWidget *btoSeccSig, *botSeccReg, *nomSecc, *seccNum, *botSigSeccNom;
  GtkWidget *botSigPag, *botReg, *botInsertarImg, *botGurdaryVer, *botSigSecc, *texto;
  GtkWidget *capNom, *numHoj;
  GtkWidget *texto2;
  GtkWidget *editBotreg, *boteditsave;
  GtkWidget *botMarcar, *botsalyGuar, *botAnexar, *botDer, *botIzq;
  GtkWidget *entryAnexar, *lblTexto, *butReg, *titLbl, *seccLbl, *pagLbl;
  GtkWidget *labelTitulo, *btnSiguiente, *btnAnterior, *btnContinuar, *btnEmpezar, *btnRegresar;
};
typedef struct appGTK refsApp;