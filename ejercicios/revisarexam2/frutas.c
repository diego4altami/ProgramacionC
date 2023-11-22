/*
@file frutas.c
@brief Este programa toma los datos de un archivo de 
       texto que contiene la información 
       sobre los productos que tiene una frutería.
       El programa inserta estos datos en una lista doble, los inserta 
       por orden alfabético. Después imprime la lista creada para 
       confirmar su integridad. 
       Una vez que la lista esta creada el programa hace una revisión de inventarios
       e imprime en pantalla cuánto dinero hay por cada fruta y cuál es el valor 
       total.
       Por último, el programa le pide al usuario un porcentaje con el cuál aumentar los precios
       El programa aumenta los precios recorriendo la lista y muestra un informe en pantalla
@author Diego Altamirano Tovar
@date 27/10/2023
*/

#include "deftipos.h"

void insertarListaDobleOrdenada(refs *nav, frut dat);
void imprimirListaDoble(refs nav);
void revisarInventario(refs nav);
void actualizarPrecios(refs *nav);

int main(int argc,char *argv[])
{
    FILE *fp;
    frut datos;
    refs navegador;
    nodo *nodoEntoncontrado;
    char sn[1]; 
    char res[1];

    navegador.inicio = NULL;
    navegador.fin = NULL;
    navegador.aux = NULL;

    fp =fopen(argv[1],"r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fscanf(fp, "%[^\t] %f\t %i\n", datos.nombre, &datos.precio, &datos.inventario)==3)
    {
        insertarListaDobleOrdenada(&navegador,datos);
    }
    fclose(fp);

    printf("\nBienvenido al software especializado para frutería\n");
    printf("\n¿Desea ver un un informe con las frutas que contiene toda la frutería?: s|n \n");
    scanf("%s",sn);
    if(strcmp(sn, "s")==0)imprimirListaDoble(navegador);
    printf("\n----------------MENU--------------\n");
    printf("\nBienvenido al menú, ¿Qué desea hacer?\n");
    printf("\n f : revisar frutas\n");
    printf("\n i : revisar inventario\n");
    printf("\n a : Actualizar precios\n");
    printf("\n x : salir\n");
    scanf(" %s", res);
    while(strcmp(res,"x") != 0)
    {
        if(strcmp(res,"f")==0)
        {
            imprimirListaDoble(navegador);
        }
        if(strcmp(res,"i")==0)
        {
            revisarInventario(navegador);
        }
        if(strcmp(res,"a")==0)
        {
            actualizarPrecios(&navegador);
            printf("\nEl inventario con los nuevos precios es el siguiente: \n");
            revisarInventario(navegador);
        }
        printf("\n¿Qué desea hacer ahora?:\n");
        printf("\n f : revisar frutas\n");
        printf("\n i : revisar inventario\n");
        printf("\n a : Actualizar precios\n");
        printf("\n x : salir\n");
        scanf("\n%s", res);
    }
    return 0;
}