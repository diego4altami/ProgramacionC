/*
@file banco.c
@brief Este programa permita administrar un catálogo de clientes de una 
       institución bancaria.
       1) El programa crea una lista LIFO de clientes: desde la línea de 
          comandos:
                            $./banco.exe clientes.txt
       2) El programa guarda un informe en un archivo binario de personas 
          que pertenecen a un cierto rango de edad.
       3) Incrementar 10,000 pesos el límite de crédito (mientras este sea 
          menor a 30,000 pesos) de un determinado código postal.
       4) El programa elimina de la lista un cliente y actualizar el archivo 
          clientes.
@authors
@date 02/10/2023
*/

#include "tipos.h"

nodo *leerDatos(char nomArch[]);
void imprimirLista(nodo *pt);
void guardarenTexto(nodo *pt);
void edadBinario(nodo *pt, int edad);
void incrementoDeCredito(nodo *pt, int cp);
void borrarCliente(nodo **pt, char nombre[80]);
void actualizarArchivo(nodo *pt, char nomArch[]);

int main(int arc, char *argv[])
{   
    nodo* inicio;
    int opmenu = 1;
    inicio = NULL;
    int edad, cp;
    char nombre[80];

    inicio = leerDatos(argv[1]);
        
    system("clear");
    printf("\n\nBienvenido a este programa, a continuación se le mostraran las opciones del menú.\n\n");
    printf("Ingrese la tecla <enter> para continuar\n\n");
    getchar();
    system("clear");

    while((opmenu == 1) || (opmenu == 2) || (opmenu == 3))
    {
        imprimirLista(inicio);
        printf("\n\n------------------------------------Menú------------------------------------\n\n");
        printf("\nEscriba [1] si quiere guardar un informe en un archivo binario de personas que pertenecen a un rango de edad.\n");
        printf("\nEscriba [2] si quiere incrementar el límite de crédito de un determinado código postal.\n");
        printf("\nEscriba [3] si quiere eliminar de la lista un cliente y actualizar el archivo.\n");
        printf("\nEscriba [4] si quiere finalizar el programa.\n\n");
        scanf("%d", &opmenu);
        if(opmenu == 1)
        {
            system("clear");
            printf("\nDame una edad: ");
            scanf("%i",&edad);
            edadBinario(inicio, edad);
            getchar();
            printf("\n\nIngrese la tecla <enter> para regresar al menú.\n\n");
            getchar();
        }
        if(opmenu == 2)
        {
            system("clear");
            printf("\nDame un código postal: ");
            scanf("%i",&cp);
            incrementoDeCredito(inicio, cp);
            getchar();
            printf("\n\nIngrese la tecla <enter> para regresar al menú.\n\n");
            getchar();
        }
        if(opmenu == 3)
        {
            system("clear");
            printf("\nDame el nombre del cliente que quieres borrar: ");
            scanf(" %[^\n]", nombre);
            borrarCliente(&inicio, nombre);
            actualizarArchivo(inicio, argv[1]);
            getchar();
            printf("\n\nIngrese la tecla <enter> para regresar al menú.\n\n");
            getchar();
        }
    }

    return 0;
}