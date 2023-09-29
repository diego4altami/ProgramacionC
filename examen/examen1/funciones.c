/*
    @file funcones.c
    @brief este archivo contiene las funciones que son llamadas
           desde autos.c, permite añadir nodos a una lista LIFO, 
           leer los datos de un archivo de texto y añadirlos a una lista LIFO, 
           comprobar que la lista se haya guardado correctamente, guardar la lista invertida en un .txt, 
           imprimir los mese de verificación de los autos y 
           crear un reporte por el cuál el usuario se puede mover a través de la lista. 
    @author Diego Altamirano Tovar
    @date 29/09/23
*/

#include "tipos.h"


/*
    @brief esta función agrega un nodo al inicio de la lista con la función
           push en una lista LIFO
    @author Diego Altamirano Tovar
    @date 29/09/23
    @param carro es un struct tipocoche, contiene la marca, el modelo, la placa y el año
    @param *pt es un apuntador del tipo nodo del inicio de la lista
    @return *pt es un apuntador que devuelve en nuevo inicio de la lista
*/


extern nodo *push(tipocoche carro, nodo *pt)
{
    nodo *nuevo;

    nuevo = (nodo*)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1); 
    }
    nuevo->carro = carro;
    nuevo->next=pt;
    pt = nuevo;

    return pt;
}

/*
    @brief esta función lee un archivo que contiene datos tipocoche y los añade a una lista LIFO
           push en una lista LIFO
    @author Diego Altamirano Tovar
    @date 29/09/23
    @param nomArch es una cadena que contiene el nombre del archvio que se va a leer
    @return *pt es un apuntador que devuelve en nuevo inicio de la lista creada a partir de los datos del archivo
*/

extern nodo *leerDatos(char nomArch[])
{
    FILE *fp;
    nodo *pt;
    tipocoche carritos;

    pt=NULL;

    fp = fopen(nomArch,"r");
    if(fp ==NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fscanf(fp,"%s\t%s\t%s\t%i\n",carritos.marca,carritos.modelo,carritos.placa,&carritos.anio)==4)
    {
        pt = push(carritos,pt);
    }

    fclose(fp);

    return pt;
}

/*
    @brief esta función comprueba una lista imprimiendola en pantalla
    @author Diego Altamirano Tovar
    @date 29/09/23
    @param *pt es un apuntador del tipo nodo del inicio de la lista
*/
extern void comprobarLista(nodo *pt)
{
    printf("\nComprobando que la lista esta completa:\n");
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            printf("%s\t%s\t%s\t%i\n",pt->carro.marca,pt->carro.modelo,pt->carro.placa,pt->carro.anio);
            pt = pt->next;
        }
        printf("\n");
    }
    else
    {
        printf("\nLista vacia.\n");
    }
    
    return;
}

/*
    @brief esta función imrpime una lista LIFO invertida en un archvio de texto llamado invertida.txt
    @author Diego Altamirano Tovar
    @date 29/09/23
    @param *pt es un apuntador del tipo nodo del inicio de la lista
    @return *pt es un apuntador que devuelve en nuevo inicio de la lista
*/
extern void guardarInvertida(nodo *pt)
{
    FILE *fp;

    fp = fopen("invertida.txt", "w");
    if(fp ==NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            fprintf(fp,"%s\t%s\t%s\t%i\n",pt->carro.marca,pt->carro.modelo,pt->carro.placa,pt->carro.anio);
            pt = pt->next;
        }
    }
    else
    {
        printf("\nLista vacía\n");
    }
    fclose(fp);
    return;
}

/*
    @brief esta función agrega un nodo al inicio de la lista con la función
           push en una lista LIFO
    @author Diego Altamirano Tovar
    @date 29/09/23
    @param pal[] es una cadena de char
    @param *pt es un apuntador del tipo nodo del inicio de la lista
    @return *pt es un apuntador que devuelve en nuevo inicio de la lista
*/
extern void verificacion(nodo *pt)
{

    printf("\nReporte de mesese en que se deben de verificar los autos: \n");

    while( pt != NULL)
    {
        if(pt->carro.placa[5]==49 || pt->carro.placa[5]==50)
        {
            printf("\nEl %s %s con placa %s se debe verificar entre julio y agosto\n",pt->carro.marca,pt->carro.modelo,pt->carro.placa);
        }
        if(pt->carro.placa[5]==51 || pt->carro.placa[5]==52)
        {
            printf("\nEl %s %s con placa %s se debe verificar entre agosto y septiembre\n",pt->carro.marca,pt->carro.modelo,pt->carro.placa);
        }
        if(pt->carro.placa[5]==53 || pt->carro.placa[5]==54)
        {
            printf("\nEl %s %s con placa %s se debe verificar entre septiembre y octubre\n",pt->carro.marca,pt->carro.modelo,pt->carro.placa);
        }
        if(pt->carro.placa[5]==55 || pt->carro.placa[5]==56)
        {
            printf("\nEl %s %s con placa %s se debe verificar entre octubre y noviembre\n",pt->carro.marca,pt->carro.modelo,pt->carro.placa);
        }
        if(pt->carro.placa[5]==57 || pt->carro.placa[5]==48)
        {
            printf("\nEl %s %s con placa %s se debe verificar entre noviembre y diciembre\n",pt->carro.marca,pt->carro.modelo,pt->carro.placa);
        }
        pt = pt->next;
    }
    return;
}

/*
    @brief esta función crea un reporte de autos que estan guardados en una lista LIFO,
           la función imprime el contenido de los nodos y pide el input del usuario,
           si el usuario pide s avanza en la lista hasta que se acaba, si el usuario pide n el programa termina
    @author Diego Altamirano Tovar
    @date 29/09/23
    @param *pt es un apuntador del tipo nodo del inicio de la lista
*/
extern void reporte(nodo *pt)
{
    char aux[20];

    printf("\nInforme de los autos en la lista\n");
    while(pt != NULL)
    {
        printf("\nDesea avanzar al siguiente nodo?, <s|n>:\n");
        scanf("%s",aux);
        if(strcmp(aux,"s")==0)
        {
            printf("\nEl auto actual es: %s %s %i\n",pt->carro.marca,pt->carro.modelo,pt->carro.anio);    
        }
        if(strcmp(aux,"n")==0)
        {
            exit(1);
        }
        pt=pt->next;
    }
    printf("\nNo hay más autos por mostrar\n");
    return;
}