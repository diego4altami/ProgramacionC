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
    newLibro->der = NULL;
    newLibro->izq = NULL;
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
    refs->aux=refs->inicio;
    refs->aux->aux=refs->inicio->inicio;
    // Asignar el nuevo libro al puntero libroActual
    refs->libroActual = newLibro;
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

extern void modificarNomSeccion(rep *libro, char nomSecc[]) 
{
    secc *seccionActual;
    
    if (libro == NULL || nomSecc == NULL) 
    {
        printf("Error: libro o nombre de sección no válido.\n");
        return;
    }

    seccionActual = libro->aux;
    if (seccionActual != NULL) 
    {
        strcpy(seccionActual->titSeccion, nomSecc);
    }
}

extern void siguienteSec(rep *libro) 
{
    secc *seccionActual;

    if (libro == NULL || libro->inicio == NULL) 
    {
        printf("Libro no válido o vacío.\n");
        return;
    }

    seccionActual = libro->inicio;
    if (seccionActual->der != NULL) 
    {
        libro->inicio = seccionActual->der;
    } 
    else 
    {
        printf("Ya estás en la última sección.\n");
    }
}

extern void moverPagina(rep *libro)
{
    secc *seccionActual;
    hoja *nuevaPagina;

    seccionActual = libro->inicio;
    nuevaPagina = (hoja *)malloc(sizeof(hoja));

    if (libro == NULL || libro->inicio == NULL) 
    {
        printf("Libro no válido o vacío.\n");
        return;
    }

    if (nuevaPagina == NULL) 
    {
        printf("No se pudo asignar memoria para una nueva página.\n");
        return;
    }

    // Inicializar la nueva página
    nuevaPagina->next = NULL;
    nuevaPagina->numero = seccionActual->ultPag->numero + 1;
    strcpy(nuevaPagina->titulo, libro->titulo);
    strcpy(nuevaPagina->titSeccion, seccionActual->titSeccion);
    nuevaPagina->numSecc = seccionActual->numSecc;
    memset(nuevaPagina->texto, 0, sizeof(nuevaPagina->texto)); // Inicializar el texto con una cadena vacía

    // Agregar la nueva página al final de la lista de páginas
    if (seccionActual->ultPag == NULL) 
    {
        seccionActual->primPag = nuevaPagina;
    } 
    else 
    {
        seccionActual->ultPag->next = nuevaPagina;
    }
    seccionActual->ultPag = nuevaPagina;
}

extern void guardarLibroEnBin(rep *libro) 
{
    FILE *archivo;
    secc *seccionActual;
    hoja *paginaActual;
    char nombreArchivo[45];
    
    if (libro == NULL || nombreArchivo == NULL) 
    {
        printf("Error: libro o nombre de archivo no válido.\n");
        return;
    }

    snprintf(nombreArchivo, sizeof(nombreArchivo), "%s.bin", libro->titulo);
    archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    seccionActual = libro->inicio;
    while (seccionActual != NULL) 
    {
        paginaActual = seccionActual->primPag;
        while (paginaActual != NULL) 
        {
            fwrite(libro->titulo, sizeof(libro->titulo), 1, archivo);
            fwrite(seccionActual->titSeccion, sizeof(seccionActual->titSeccion), 1, archivo);
            fwrite(&(paginaActual->numero), sizeof(paginaActual->numero), 1, archivo);
            fwrite(paginaActual->texto, sizeof(paginaActual->texto), 1, archivo);
            paginaActual = paginaActual->next;
        }
        seccionActual = seccionActual->der;
    }
    fclose(archivo);
}

extern void guardarLibroEnTxt(rep *libro) 
{
    FILE *archivo;
    secc *seccionActual;
    hoja *paginaActual;
    char nombreArchivo[45]; 
    
    if (libro == NULL || nombreArchivo == NULL) 
    {
        printf("Error: libro o nombre de archivo no válido.\n");
        return;
    }

    snprintf(nombreArchivo, sizeof(nombreArchivo), "%s.txt", libro->titulo);
    archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    seccionActual = libro->inicio;
    while (seccionActual != NULL) 
    {
        paginaActual = seccionActual->primPag;
        while (paginaActual != NULL) 
        {
            fprintf(archivo, "Título: %s\n", libro->titulo);
            fprintf(archivo, "Sección: %s\n", seccionActual->titSeccion);
            fprintf(archivo, "Número de página: %d\n", paginaActual->numero);
            fprintf(archivo, "Texto: %s\n", paginaActual->texto);
            paginaActual = paginaActual->next;
        }
        seccionActual = seccionActual->der;
    }
    fclose(archivo);
}