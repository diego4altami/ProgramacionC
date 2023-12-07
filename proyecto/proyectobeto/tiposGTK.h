#include <gtk-2.0/gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

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

struct appGTK
{
  rep *inicio, *fin, *aux;
  rep *libroActual;
  GtkWidget *titulo, *numSecc, *botRegresar, *botCrear;
  GtkWidget *avBotReg, *avBotSig;
  GtkWidget *edTitLbl, *edSeccLbl, *edPagLbl, *edBotReg, *edBotEdit;
  GtkWidget *btoSeccSig, *botSeccReg, *nomSecc, *seccNum, *botSigSeccNom;
  GtkWidget *botSigPag, *botReg, *botInsertarImg, *botGurdaryVer, *botSigSecc, *texto;
  GtkWidget *capNom, *numHoj;
  GtkWidget *texto2;
  GtkWidget *editBotreg, *boteditsave;
};
typedef struct appGTK refsApp;