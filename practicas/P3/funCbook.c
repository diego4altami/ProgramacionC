#include "tiposGTK.h"

extern void instertarTodo(char tituloLibro[], int numeroSeccion, refsApp *refs)
{
    if (numeroSeccion <= 0) 
    {
        printf("Número de secciones debe ser mayor a 0.\n");
        return;
    }

    rep *newLibro = (rep *)malloc(sizeof(rep));
    if (newLibro == NULL)
    {
        printf("\nNo hay memoria suficiente para el libro\n");
        return;
    }

    // Inicialización de la estructura rep
    newLibro->inicio = NULL;
    newLibro->fin = NULL;
    newLibro->aux = NULL;
    newLibro->aux = newLibro->fin;
    strcpy(newLibro->titulo, tituloLibro);
    newLibro->numSeccs = numeroSeccion;

    for (int cont = 1; cont <= numeroSeccion; cont++) 
    {
        secc *newSecc = (secc *)malloc(sizeof(secc));
        if (newSecc == NULL) {
            printf("\nNo hay memoria suficiente para la sección\n");
            return;
        }

        // Inicialización de la estructura secc
        newSecc->izq = NULL;
        newSecc->der = NULL;
        newSecc->primPag = NULL;
        newSecc->ultPag = NULL;
        newSecc->numSecc = cont;

        // Crear y inicializar la primera página
        hoja *newPag = (hoja *)malloc(sizeof(hoja));
        if (newPag == NULL) 
        {
            printf("\nNo hay memoria suficiente para la página\n");
            return;
        }
        newPag->next = NULL;
        strcpy(newPag->titSeccion,newSecc->titSeccion);
        strcpy(newPag->titSeccion,newSecc->titSeccion);
        newPag->numSecc = newSecc->numSecc;
        strcpy(newPag->titulo, newLibro->titulo);
        newPag->numero = 1;

        newSecc->primPag = newPag;
        newSecc->ultPag = newPag;

        // Enlazar la nueva sección en el libro
        if (newLibro->inicio == NULL) 
        {
            newLibro->inicio = newSecc;
            newLibro->fin = newSecc;
        } 
        else 
        {
            newLibro->fin->der = newSecc;
            newSecc->izq = newLibro->fin;
            newLibro->fin = newSecc;
        }
    }

    // Enlazar el nuevo libro en la repisa
    if (refs->inicio == NULL) 
    {
        refs->inicio = newLibro;
        refs->fin = newLibro;
        newLibro->izq = newLibro;
        newLibro->der = newLibro;
    } 
    else
    {
        newLibro->izq = refs->fin;
        refs->fin->der = newLibro;
        newLibro->der = refs->inicio;
        refs->inicio->izq = newLibro;
        refs->fin = newLibro;
    }
}

void imprimirLibro(rep refs)
{
    refs.aux = refs.inicio;

    while(refs.aux != NULL)
    {
        printf("\nNombre de sección: %s\t", refs.aux->titSeccion);
        printf("Número de sección: %d\n", refs.aux->numSecc);
        refs.aux = refs.aux->der;
    }
    if((refs.inicio == NULL) && (refs.fin == NULL))
    {
        printf("\nLista vacía.\n");
    }

    return;
}

extern void imprimirRepisa(refsApp refs)
{
    refs.aux = refs.inicio;

    if((refs.inicio == NULL) && (refs.fin == NULL))
    {
        printf("\nNo puedo imprimir una repisa vacía.\n");
    }
    else
    {
        do
       {
            printf("\nTítulo del libro: %s", refs.aux->titulo);
            printf("\tNúmero de secciones: %d\n", refs.aux->numSeccs);
            imprimirLibro(*(refs.aux));
            refs.aux = refs.aux->der;
       }while(refs.aux != refs.inicio); 
    }

    return;
}