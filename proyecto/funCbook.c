/*
@file funCbook.c
@brief El codigo utiliza la biblioteca GTK para construir una interfaz gráfica que facilita la creación y edición de libros
       electrónicos, guiando al usuario a través de diferentes etapas del proceso.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
*/
#include "tiposGTK.h"

/*
@brief Esta función crea una estructura de datos jerárquica para representar libros con secciones y páginas, 
       manejando la asignación de memoria y la conexión de estructuras en un sistema de lista circular doblemente enlazada.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param char tituloLibro[]: Un arreglo de caracteres que representa el título del libro que se va a insertar
@param int numeroSeccion: Un entero que indica el número de secciones que se deben crear en el libro.
@param refsApp *refs: Un puntero a una estructura refsApp, que contiene referencias a libros. 
*/

extern void instertarTodo(char tituloLibro[], int numeroSeccion, refsApp *refs)
{
  secc *newSecc;
  int cont;
  rep *newLibro;
  hoja *newPag;
  
    if (numeroSeccion <= 0) 
    {
        printf("Número de secciones debe ser mayor a 0.\n");
	//el usuario aqui no se entero de nada
        return;
    }

    newLibro = (rep *)malloc(sizeof(rep));
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

    for (cont = 1; cont <= numeroSeccion; cont++) 
    {
        newSecc = (secc *)malloc(sizeof(secc));
	
        if (newSecc == NULL) {
            printf("\nNo hay memoria suficiente para la sección\n");
            return;
        }

        newSecc->izq = NULL;      
        newSecc->der = NULL;
        newSecc->primPag = NULL;
        newSecc->ultPag = NULL;
        newSecc->numSecc = cont;
        strcpy(newSecc->titSeccion, "Titulo por defecto"); // Añadir un título por defecto

        // Crear e inicializar la primera página
        newPag = (hoja *)malloc(sizeof(hoja));
        if (newPag == NULL) 
        {
            printf("\nNo hay memoria suficiente para la página\n");
            return;
        }
        newPag->next = NULL;
        newPag->numSecc = newSecc->numSecc;
        strcpy(newPag->titulo, newLibro->titulo);
        strcpy(newPag->titSeccion, newSecc->titSeccion); // Copiar el título de la sección
        strcpy(newPag->texto, "Texto por defecto"); // Añadir un texto por defecto
        newPag->numero = 1; // Establecer el número de la página

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
    refs->aux = newLibro;
    refs->aux->aux = newSecc;
    // Asignar el nuevo libro al puntero libroActual
    refs->libroActual = newLibro;
}

/*
@brief La función esencialmente recorre las secciones del libro e imprime el nombre y el número de cada sección. 
       Si la lista de secciones está vacía, también imprime un mensaje indicando que la lista está vacía.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param rep refs: Un parámetro de tipo rep, que representa un libro. 
       La función utiliza esta estructura para acceder a la información sobre las secciones del libro que se imprimirán.
@param 
*/

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

/*
@brief La función imprimirRepisa itera a través de la lista circular doblemente enlazada de libros e imprime información sobre cada libro, incluyendo su título, el número de secciones y la información detallada de las secciones a través de la llamada a la función imprimirLibro. También maneja el caso en que la repisa está vacía.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param refsApp refs: Un parámetro de tipo refsApp, que es una estructura que contiene referencias a libros. 
       La función utiliza esta estructura para acceder a la información sobre la lista de libros que se imprimirán en la repisa.
*/

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

/*
@brief La función intenta modificar el nombre de la primera sección de un libro con el nombre proporcionado (nomSecc). 
       Si el libro o el nombre de la sección son nulos o si no hay secciones en el libro, la función imprime un mensaje de error 
       y no realiza ninguna modificación.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param rep *libro: Un puntero a una estructura rep que representa un libro. 
       Este puntero permite a la función acceder y modificar la información del libro.
@param char nomSecc[]: Un arreglo de caracteres que representa el nuevo nombre que se desea asignar a la primera sección del libro.
*/

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
        strcpy(seccionActual->ultPag->titSeccion, seccionActual->titSeccion);
    }
}

/*
@brief la función avanza al usuario a la siguiente sección en un libro, siempre que haya una sección siguiente. 
       Si el libro es nulo o está vacío o si ya está en la última sección, se imprime un mensaje de error o informativo.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param rep *libro: Un puntero a una estructura rep que representa un libro. 
       Este puntero permite a la función acceder y modificar la información del libro.
*/

extern void siguienteSec(rep *libro) 
{
    secc *seccionActual;

    if (libro == NULL || libro->aux == NULL) 
    {
        printf("Libro no válido o vacío.\n");
        return;
    }

    seccionActual = libro->aux;
    if (seccionActual->der != NULL) 
    {
        libro->aux = seccionActual->der;
    } 
    else 
    {
        printf("Ya estás en la última sección.\n");
    }
}

/*
@brief La función agrega una nueva página al final de la sección actual de un libro, asignando automáticamente 
       el número siguiente y copiando información relevante del libro y la sección actual a la nueva página.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param rep *libro: Un puntero a una estructura rep que representa un libro. 
       Este puntero permite a la función acceder y modificar la información del libro sobre el cual se realizará 
       la acción de agregar una nueva página.
*/

extern void moverPagina(rep *libro)
{
    secc *seccionActual;
    hoja *nuevaPagina;

    seccionActual = libro->aux;
    nuevaPagina = (hoja *)malloc(sizeof(hoja));

    if (libro == NULL || libro->aux == NULL) 
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

/*
@brief la función guarda la información del libro (títulos de libro y sección, número de página, y texto de la página) en un archivo binario. 
       El nombre del archivo se construye a partir del título del libro, y la información se almacena de manera estructurada.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param rep *libro: Un puntero a una estructura rep que representa un libro. Este puntero permite a la función acceder y leer la información del libro que se guardará en el archivo binario.
*/

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

    sprintf(nombreArchivo, "%s.bin", libro->titulo);
    archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
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

/*
@brief la función crea un archivo de texto con el nombre del libro y escribe en él la información estructurada del libro, incluyendo título, secciones, números de página y texto de las páginas.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param rep *libro: Este parámetro es un puntero a una estructura que representa un libro. La estructura rep  contiene información sobre el libro, como su título y referencias a las secciones y páginas del mismo. La función utiliza esta información para escribir en un archivo de texto.
*/

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

    sprintf(nombreArchivo, "%s.txt", libro->titulo);
    archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return;
    }

    seccionActual = libro->inicio;
    while (seccionActual != NULL) 
    {
        paginaActual = seccionActual->primPag;
        while (paginaActual != NULL) 
        {
            fprintf(archivo, "Título: %s\n", paginaActual->titulo);
            fprintf(archivo, "Sección: %s\n", paginaActual->titSeccion);
            fprintf(archivo, "Número de página: %d\n", paginaActual->numero);
            fprintf(archivo, "Texto: %s\n\n", paginaActual->texto);
            paginaActual = paginaActual->next;
        }
        seccionActual = seccionActual->der;
    }
    fclose(archivo);
}
