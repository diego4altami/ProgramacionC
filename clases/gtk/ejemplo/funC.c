#include "deftipos.h"

void insertarCola(tipoMascotas dat, refsApp *pMiApp);

extern void crearListaDoble(char nomArch[], refsApp *pMiApp)
{
    FILE *fp;
    tipoMascotas datos;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponoble. \n");
        exit(1);
    }
    
    while(fscanf(fp, " %[^\t] %f\t %d \n", datos.raza, &datos.peso, &datos.cliente)==3)
    {
        insertarCola(datos, pMiApp);
    }

    fclose(fp);

}

void insertarCola(tipoMascotas dat, refsApp *pMiApp)
{
    nodo *nuevo;
    
    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1);
    }
    nuevo->datos = dat;
    if((pMiApp->inicio == NULL) && (pMiApp->fin == NULL))
    {
        nuevo->der = nuevo;
        nuevo->izq = nuevo;
        pMiApp->inicio = nuevo;
        pMiApp->fin = nuevo;
    }
    else{
        nuevo->izq = pMiApp->fin;
        nuevo->der = pMiApp->inicio;
        pMiApp->fin->der = nuevo;
        pMiApp->inicio->izq = nuevo;
        pMiApp->fin = nuevo;
    }

    return;
}
