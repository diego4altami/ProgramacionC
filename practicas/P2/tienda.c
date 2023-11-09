#include "tiposTienda.h"

void leerTxt(char *nomArch, nav *nav);
void leerBin(char *nomArch, nav *nav);
void imprimirListaDobleCirc(refs refcirc);
void imprimirListaDoble(refs reflin);
void navegar(nav *nav);

int main (int argc, char *argv[])
{
    nav *navegador;
    
    navegador = (nav *)malloc(sizeof(nav));
    if (navegador == NULL) 
    {
        printf("No hay memoria suficiente\n");
        exit(1);
    }
    navegador->refscirc = (refs *)malloc(sizeof(refs));
    if (navegador == NULL) 
    {
        printf("No hay memoria suficiente\n");
        exit(1);
    } 
    navegador->refslin = (refs *)malloc(sizeof(refs));
    if (navegador == NULL) 
    {
        printf("No hay memoria suficiente\n");
        exit(1);
    }

    navegador->refscirc->inicio = NULL;
    navegador->refscirc->fin = NULL;
    navegador->refscirc->aux = NULL;

    navegador->refslin->inicio = NULL;
    navegador->refslin->fin = NULL;
    navegador->refslin->aux = NULL;

    navegador->iniciocar = NULL;
    navegador->fincar = NULL;

    if(argc != 3) 
    {
        printf("Uso: %s <nombre_archivo> -t|-b\n", argv[0]);
        exit(1);
    }
    if(strcmp(argv[2], "-t") == 0)
    {
        leerTxt(argv[1], navegador);
    }
    else if(strcmp(argv[2], "-b") == 0)
    {
        leerBin(argv[1], navegador);
    }
    else 
    {
        printf("Opción no reconocida: %s\n", argv[2]);
        exit(1);
    }
    printf("---------- PRODUCTOS --------\n\n");
    printf("\nImpresión de la cola (categoría 1): \n\n");
    imprimirListaDobleCirc(*(navegador->refscirc));
    printf("\nImpresión de la lista (categoría 2): \n\n");
    imprimirListaDoble(*(navegador->refslin));

    navegar(navegador);

    return 0;
}