/*
@file funciones.c
@brief Este  archivo contiene las funciones que son llamadas desde
       banco.c. 
@author Alberto Parera Méndez
@date 01/10/2023
*/

#include "tipos.h"

/*
@brief Esta función agrega un nodo al inicio de la lista con la operación
       en banco.c.
@author Alberto Parera Méndez
@date 01/10/2023
@param clientes estructura de tipoclientes.
@param *pt es un apuntador del tipo nodo.
@return *pt es un apuntador de tipo nodo que devuelve el nuevo inicio de
        la lista.
*/
extern nodo *push(tipoclientes clientes, nodo *pt)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }
    nuevo->clientes = clientes;
    nuevo->next = pt;
    pt = nuevo;

    return pt;
}

/*
@brief Esta función copia lo que se encuentra en el acrhivo de texto y lo
       coloca en una lista LIFO.
@author Alberto Parera Méndez
@date 01/10/2023
@param nomarch[] es una cadena de chars que contiene el nombre del archivo de
       texto.
@param *pt es un apuntador del tipo nodo.
@return *pt es un apiuntador de tipo nodo que devuelve el nuevo inicio de
        la lista.
*/
extern nodo *leerDatos(char nomArch[])
{
    FILE *fp;
    nodo *pt;
    tipoclientes clientes;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }

    pt = NULL;
    
    while(fscanf(fp, " %[^\t]\t%s\t%i\t%f\n", clientes.nombre, clientes.curp, &clientes.cp, &clientes.limcred) == 4)
    {
        pt = push(clientes, pt);
    }
    fclose(fp);

    return pt;
}

/*
@brief Esta función imprime en pantalla lo que se encuentra en la lista 
       LIFO.
@author Alberto Parera Méndez
@date 01/10/2023
@param *pt es un apuntador del tipo nodo.
*/
extern void imprimirLista(nodo *pt)
{
    printf("\nLos datos en el archivo son:\n");
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            printf("\n%s\t%s\t%i\t%f\n", pt->clientes.nombre,pt->clientes.curp, pt->clientes.cp, pt->clientes.limcred);
            pt = pt->next;
        }
    }
    else
    {
        printf("\nLista vacía\n");
    }
    return;
}

/*
@brief Esta función imprime en pantalla lo que se encuentra en el archivo
       binario.
@author Diego Alramirano Tovar
@date 02/10/2023
@param nomArch[] es un arreglo que contiene el nombre del archivo ingresado
       en la linea de comandos.
*/
extern int imprimirEnPantallaBin(char nomArch[])
{
    tipoclientes cliente, *ptcliente;
    FILE *fp;
    int numClientes = 0;

    fp = fopen(nomArch, "r+b");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    printf("\nImprimiendo los datos del archivo binario\n");
    while(fread(&cliente, sizeof(tipoclientes), 1, fp) == 1)
    {
        ptcliente = &cliente;
        printf("\nNombre: %s\nCURP: %s\nCP: %i\n", ptcliente->nombre, ptcliente->curp, ptcliente->cp);
        printf("Crédito: %f\n", ptcliente->limcred);
        numClientes++;
    }
    printf("\nEl archivo contiene %d clientes.\n", numClientes);
    fclose(fp);

    return numClientes;
}

/*
@brief Esta función crea un archivo binario con los clientes que tenga un 
       cierto rango de edad. Este rango de edad es ingresado por el cliente.
       La función clacula la edad de los clientes con su CURP y despues
       hace una serie de comparaciones para filtrar los clientes con cierta
       edad y guarda estos en un archivo binario y los despliega en pantalla
       también.
@author Diego Alramirano Tovar
@date 02/10/2023
@param *pt es un apuntador del tipo nodo.
@param edad es una variable de tipo entero, su valor es ingreasado por el 
       usuario y es la edad con la que se harán las comparaciones.
*/
extern void edadBinario(nodo *pt, int edad)
{
    char anios[3];
    int aniosJuntos;
    int cumpl;
    FILE *fp;

    char nomArch[100];
    sprintf(nomArch, "mayoresDe%i",edad);
    fp = fopen(nomArch, "w+b");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            anios[0]=pt->clientes.curp[4];
            anios[1]=pt->clientes.curp[5];
            anios[2] = '\0';

            aniosJuntos = atoi(anios);

            if(aniosJuntos <= 99)
            {
                aniosJuntos = aniosJuntos + 1900;
            }
            else
            {
                aniosJuntos = aniosJuntos + 2000;
            }

            cumpl = 2023 - aniosJuntos;

            if(cumpl >= edad)
            {
                fwrite(&pt->clientes,sizeof(tipoclientes),1,fp);
            }
            pt = pt->next;
        }
    }
    else
    {
        printf("\nLista vacía\n");
    }
    fclose(fp);
    printf("\nLista de clientes en el rango de %i años de edad o mayores:\n",edad);
    imprimirEnPantallaBin(nomArch);
}

/*
@brief Esta función incrementa el límite de crédito de un cliente dependiendo
       de su código postal.
@author Alberto Parera Méndez
@date 02/10/2023
@param *pt es un apuntador del tipo nodo.
@param cp es una variable de tipo entero, su valor es ingreasado por el 
       usuario y es el código postal con la que se harán las comparaciones.
*/
extern void incrementoDeCredito(nodo *pt, int cp)
{
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            if(cp == pt->clientes.cp)
            {
                if(pt->clientes.limcred <= 30000.00)
                {
                    pt->clientes.limcred += 10000.00;
                }
                else
                {
                    printf("\nEl cliente cuenta con una línea de crédito mayo a 30,000.00 pesos, por lo tanto no se le puede incrementar más.\n");
                }
            }
            else
            {
                printf("\nEse código postal no se encuentra en la lista\n");

            }
            pt = pt->next;
        }
    }
    else
    {
        printf("\nLista vacía\n");
    }

    return;
}

/*
@brief Esta función elimina un cliente específico de la lista LIFO de 
       clientes representada por el puntero nodo **pt.
@author Alberto Parera Méndez
@date 02/10/2023
@param **pt es un doble apuntador del tipo nodo.
@param nombre es una cadena de caracteres ingresada por el usuario que
       contiene el nombre del cliente que se desea eliminar de la lista.
*/
extern void borrarCliente(nodo **pt, char nombre[80])
{
    if (*pt != NULL)
    {
        if (strcmp((*pt)->clientes.nombre, nombre) == 0)
        {
            nodo *borra = *pt;
            *pt = (*pt)->next;
            free(borra);
            return;
        }
        else
        {
            printf("\nEse nombre no se encuentra en la lista\n");
        }

        nodo *anterior = *pt;
        nodo *actual = (*pt)->next;

        while (actual != NULL)
        {
            if (strcmp(actual->clientes.nombre, nombre) == 0)
            {
                anterior->next = actual->next;
                free(actual);
                return;
            }
            else
            {
                printf("\nEse nombre no se encuentra en la lista\n");
            }
            anterior = actual;
            actual = actual->next;
        }
    }
    else
    {
        printf("\nLista vacía\n");
    }
}

/*
@brief Esta función actualiza el archivo de texto clientes.
@author Alberto Parera Méndez
@date 02/10/2023
@param *pt es un apuntador del tipo nodo.
@param nomarch[] es una cadena de chars que contiene el nombre del archivo de
       texto.
*/
extern void actualizarArchivo(nodo *pt, char nomArch[])
{
    FILE *fp;

    fp = fopen(nomArch, "w");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible\n");
        exit(1);
    }
    
    while(pt != NULL)
    {
        fprintf(fp, "%s\t%s\t%i\t%f\n", pt->clientes.nombre,pt->clientes.curp, pt->clientes.cp, pt->clientes.limcred);
        pt = pt->next;
    }
    fclose(fp);

    return;
}