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
    rep *newLibro;
  
    if(numeroSeccion <= 0) 
    {
        printf("Número de secciones debe ser mayor a 0.\n");
	//el usuario aqui no se entero de nada
        return;
    }

    newLibro = (rep *)malloc(sizeof(rep));
    if(newLibro == NULL)
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

    for(int cont = 1; cont <= numeroSeccion; cont++) 
    {
        secc *newSecc;
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
        hoja *newPag;
        newPag = (hoja *)malloc(sizeof(hoja));
        if (newPag == NULL) 
        {
            printf("\nNo hay memoria suficiente para la página\n");
            return;
        }

        newPag->next = NULL;
        strcpy(newPag->titulo, newLibro->titulo);
        strcpy(newPag->titSeccion, newSecc->titSeccion); // Copiar el título de la sección
        strcpy(newPag->texto, "Texto por defecto"); // Añadir un texto por defecto
        newPag->numero = 1; // Establecer el número de la página

        newSecc->primPag = newPag;
        newSecc->ultPag = newPag;

        // Enlazar la nueva sección en el libro
        if(newLibro->inicio == NULL) 
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

    if(refs->inicio == NULL) 
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
    refs->aux->aux = newLibro->inicio;
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
void imprimirPags(secc refs)
{
    while(refs.primPag != NULL)
    {
        printf("\nTítulo del libro: %s",refs.primPag->titulo);
        printf("\tTítulo de la sección: %s",refs.primPag->titSeccion);  
        printf("\tNúmero de página %i",refs.primPag->numero);
        printf("\tEl texto guardado: %s\n\n\n",refs.primPag->texto);
        refs.primPag = refs.primPag->next;
    }
    return;
}

void imprimirSecc(rep refs)
{
    refs.aux = refs.inicio;

    while(refs.aux != NULL)
    {
        printf("\nNombre de sección: %s\t", refs.aux->titSeccion);
        printf("Número de sección: %d\n\n", refs.aux->numSecc);
        imprimirPags(*(refs.aux));
        refs.aux = refs.aux->der;
    }
    if((refs.inicio == NULL) && (refs.fin == NULL))
    {
        printf("\nLista vacía.\n");
    }

    return;
}


extern void imprimirLibro(refsApp refs)
{
    system("clear");
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
            printf("\tNúmero de secciones: %d\n\n", refs.aux->numSeccs);
            imprimirSecc(*(refs.aux));
            refs.aux = refs.aux->der;
       }while(refs.aux != refs.inicio); 
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

    secc *seccionActual;
    hoja *paginaActual;

    refs.aux = refs.inicio;
 
    do
    {
        printf("\nTítulo del libro: %s", refs.aux->titulo);
        printf("\nTítulo de la sección: %s", refs.aux->aux->titSeccion);
        //printf("\nNúmero de página: %d", refs.aux->aux->);
        seccionActual = refs.aux->aux;
        while (seccionActual != NULL) 
        {
            paginaActual = seccionActual->primPag;
            while (paginaActual != NULL) 
            {
                printf("\nTítulo del libro: %s", refs.aux->titulo);
                printf("\nTítulo de la sección: %s", seccionActual->titSeccion);
                printf("\nNúmero de página: %d", paginaActual->numero);
                printf("\nTexto: %s\n\n", paginaActual->texto);
                paginaActual = paginaActual->next;
            }
            seccionActual = seccionActual->der;
        }
        refs.aux = refs.aux->der;
    }while(refs.aux != refs.inicio); 

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

    if (libro == NULL || libro->aux == NULL) 
    {
        printf("Libro no válido o vacío.\n");
        return;
    }

    if(libro->aux->der != NULL) 
    {
        libro->aux = libro->aux->der;
    } 
    else 
    {
        //El usuario no se entera de que ya es la última sección
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
    memset(nuevaPagina->texto, 0, sizeof(nuevaPagina->texto)); // Inicializar el texto con una cadena vacía

    // Agregar la nueva página al final de la lista de páginas
    if (seccionActual->ultPag == NULL) 
    {
        seccionActual->primPag = nuevaPagina;
    } 
    else 
    {
        seccionActual->ultPag->next = nuevaPagina;
        seccionActual->ultPag = nuevaPagina;
    }
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
            fwrite(paginaActual->titulo, sizeof(paginaActual->titulo), 1, archivo);
            fwrite(paginaActual->titSeccion, sizeof(paginaActual->titSeccion), 1, archivo);
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

extern void cargarTodosLosbinarios(refsApp *refs) 
{
    DIR *d;
    struct dirent *dir;
    char filepath[512];
    
    d = opendir(".");
    if (d == NULL) {
        perror("Error al abrir el directorio");
        // Opcional: crear el directorio si no existe
        return;
    }

    while ((dir = readdir(d)) != NULL) {
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) 
            continue;

        if (dir->d_type == DT_REG && strstr(dir->d_name, ".bin") != NULL) {
            snprintf(filepath, sizeof(filepath), "%s", dir->d_name);
            FILE *file = fopen(filepath, "rb");
            if (file == NULL) {
                perror("Error al abrir el archivo");
                continue;
            }

            rep *newLibro = (rep *)malloc(sizeof(rep));
            if (newLibro == NULL) {
                fclose(file);
                continue; // Manejo de error
            }
            // Inicializar newLibro aquí...
            newLibro->inicio = NULL;
            newLibro->fin = NULL;
            newLibro->aux = NULL;
            newLibro->izq = NULL;
            newLibro->der = NULL;
            strcpy(newLibro->titulo, dir->d_name); // Usando el nombre del archivo como título del libro

            secc *ultimaSeccion = NULL;
            tipohoja tempHoja;

            while(fread(&tempHoja, sizeof(tipohoja), 1, file) == 1) {
                if (ultimaSeccion == NULL || strcmp(ultimaSeccion->titSeccion, tempHoja.titSeccion) != 0) {
                    // Crear una nueva sección
                    secc *nuevaSeccion = (secc *)malloc(sizeof(secc));
                    if (nuevaSeccion == NULL) {
                        // Manejar error de memoria
                        break;
                    }
                    strcpy(nuevaSeccion->titSeccion, tempHoja.titSeccion);
                    nuevaSeccion->izq = ultimaSeccion;
                    nuevaSeccion->der = NULL;
                    nuevaSeccion->primPag = NULL;
                    nuevaSeccion->ultPag = NULL;
                    
                    if (ultimaSeccion != NULL) {
                        ultimaSeccion->der = nuevaSeccion;
                    }

                    if (newLibro->inicio == NULL) {
                        newLibro->inicio = nuevaSeccion;
                    }
                    newLibro->fin = nuevaSeccion;
                    ultimaSeccion = nuevaSeccion;
                }

                // Agregar la página a la última sección
                hoja *nuevaPagina = (hoja *)malloc(sizeof(hoja));
                if (nuevaPagina == NULL) {
                    // Manejar error de memoria
                    break;
                }
                strcpy(nuevaPagina->titulo, tempHoja.titulo); // Copiar la información
                strcpy(nuevaPagina->titSeccion, tempHoja.titSeccion); // Copiar la información
                nuevaPagina->numero = tempHoja.numero; // Copiar la información
                strcpy(nuevaPagina->texto, tempHoja.texto); // Copiar la información
                nuevaPagina->next = NULL;

                if (ultimaSeccion->primPag == NULL) {
                    ultimaSeccion->primPag = nuevaPagina;
                } else {
                    ultimaSeccion->ultPag->next = nuevaPagina;
                }
                ultimaSeccion->ultPag = nuevaPagina;
            }

            fclose(file); // Cierra el archivo

            // Enlazar el nuevo libro en refs
            if (refs->inicio == NULL) {
                refs->inicio = newLibro;
                refs->fin = newLibro;
                newLibro->izq = newLibro;
                newLibro->der = newLibro;
            } else {
                refs->fin->der = newLibro;
                newLibro->izq = refs->fin;
                refs->inicio->izq = newLibro;
                newLibro->der = refs->inicio;
                refs->fin = newLibro;
            }
        }
    }
    closedir(d); // Cierra el directorio
}

extern void buscandoAnemo(char tit[], char sec[], int pagNum, refsApp *refs)
{       
    refs->aux = refs->inicio;
    printf("prueba1");
    
    if(refs->aux == NULL)
    {
        printf("\nNO NEMO\n.");
    }
    else
    {
        do
        {
            if(strcmp(tit, refs->aux->titulo) == 0)
            {
                refs->libroActual = refs->aux;
                refs->libroActual->aux = refs->libroActual->inicio; 
                if(refs->libroActual->aux == NULL)
                {
                    printf("\nNO DORY\n.");
                }
                else
                {
                    while(refs->libroActual->aux != NULL)
                    {
                        if (strcmp(sec, refs->libroActual->aux->titSeccion) == 0)
                        {
                            while(refs->libroActual->aux->primPag != NULL)
                            {
                                if(refs->libroActual->aux->primPag->numero == pagNum)
                                {
                                    printf("Se ha encontrado el libro, la sección y la página\n");
                                    printf("Nombre de la sección que se encontró: %s", refs->libroActual->aux->titSeccion);
                                    return;
                                }
                                else
                                {
                                    refs->libroActual->aux->primPag = refs->libroActual->aux->primPag->next;
                                }
                                printf("prueba2");

                            }
                        }
                        else
                        {
                            refs->libroActual->aux = refs->libroActual->aux->der;
                        }
                        printf("prueba3"); 
                    }
                }
            }
            else
            {
                refs->aux = refs->aux->der;
            }
            printf("prueba4"); 
        }while(refs->aux != refs->inicio);
    }

    return;
}

extern void cargarLectura(refsApp *refs) 
{
    struct dirent *dir;
    char filepath[512];
    int cont;

    if (refs == NULL) {
        fprintf(stderr, "Error: refsApp es NULL.\n");
        return;
    }

    DIR *d = opendir(".");
    if (d == NULL) {
        perror("Error al abrir el directorio");
        return;
    }

    while ((dir = readdir(d)) != NULL) 
    {
        cont =1;
        if (dir->d_type == DT_REG && strstr(dir->d_name, ".bin") != NULL) 
        {
            snprintf(filepath, sizeof(filepath), "%s", dir->d_name);
            FILE *file = fopen(filepath, "rb");
            
            if (file == NULL) 
            {
                perror("Error al abrir el archivo");
                continue;
            }

            libroLeer *newLibro = malloc(sizeof(libroLeer));
            if (newLibro == NULL) 
            {
                fclose(file);
                continue;
            }

            // Inicialización de newLibro
            memset(newLibro, 0, sizeof(libroLeer));
            strncpy(newLibro->titulo, dir->d_name, sizeof(newLibro->titulo) - 1);

            tipohoja tempHoja;
            while(fread(&tempHoja, sizeof(tipohoja), 1, file) == 1) 
            {
                dubCircPag *nuevaPagina = malloc(sizeof(dubCircPag));
                if (nuevaPagina == NULL) 
                {
                    fclose(file);
                    free(newLibro);
                    break;
                }

                // Inicialización de nuevaPagina
                memset(nuevaPagina, 0, sizeof(dubCircPag));
                strncpy(nuevaPagina->titulo, tempHoja.titulo, sizeof(nuevaPagina->titulo) - 1);
                strncpy(nuevaPagina->titSeccion, tempHoja.titSeccion, sizeof(nuevaPagina->titSeccion) - 1);
                nuevaPagina->numero = cont++;
                strncpy(nuevaPagina->texto, tempHoja.texto, sizeof(nuevaPagina->texto) - 1);
                nuevaPagina->marcador = 0;

                // Manejo de la lista
                if ((newLibro->inicio == NULL) && (newLibro->fin == NULL))
                 {
                    nuevaPagina->izq = nuevaPagina;
                    nuevaPagina->der = nuevaPagina; // Para manejar la lista como circular
                    newLibro->inicio = nuevaPagina;
                    newLibro->fin = nuevaPagina;
                } 
                else 
                {
                    nuevaPagina->izq = newLibro->fin;
                    nuevaPagina->der = newLibro->inicio; // Enlazar con el inicio para la lista circular
                    newLibro->fin->der = nuevaPagina;
                    newLibro->inicio->izq = nuevaPagina;
                    newLibro->fin = nuevaPagina;
                }
                newLibro->aux = newLibro->inicio;
            }
            fclose(file);

            // Enlace del nuevo libro con refs
            if ((refs->inicioLeer == NULL)&&(refs->finLeer ==NULL)) 
            {
                newLibro->der = newLibro;
                newLibro->izq = newLibro;
                refs->inicioLeer = newLibro;
                refs->finLeer = newLibro;
            } 
            else 
            {
                newLibro->izq = refs->finLeer;
                newLibro->der = refs->inicioLeer; // Enlazar con el inicioLeer para la lista circular
                refs->finLeer->der = newLibro;
                refs->inicioLeer->izq = newLibro;
                refs->finLeer = newLibro;
            }
            refs->auxLeer = refs->inicioLeer;
        }
    }
    closedir(d);
}

extern void moverIzquierda(refsApp *refs)
{
    refs->auxLeer =refs->auxLeer->izq;

    return;
}

extern void moverDerecha(refsApp *refs)
{
    refs->auxLeer = refs->auxLeer->der;

    return;
}

void moverPagDer(refsApp *refs)
{
    refs->auxLeer->aux = refs->auxLeer->aux->der;

    return;
}

void moverPagIzq(refsApp *refs)
{
    refs->auxLeer->aux = refs->auxLeer->aux->izq;

    return;
}

extern void seMarcarMarcadorMarcadoMarcadisimoMuyMarcado(refsApp *refs)
{
    dubCircPag *laux;
    laux = malloc(sizeof(dubCircPag));

    laux = refs->auxLeer->inicio;

    do    
    {
        if(laux->marcador == 1)
        {
            laux->marcador = 0;
        }
        else
        {
            laux = laux->der;
        }

    }while(laux != refs->auxLeer->inicio);

    refs->auxLeer->aux->marcador = 1;

    return;
}

void buscarMarcador(refsApp *refs)
{
    refs->auxLeer->aux = refs->auxLeer->inicio;

    do    
    {
        if(refs->auxLeer->aux->marcador == 1)
        {
            return;
        }
        else
        {
            refs->auxLeer->aux = refs->auxLeer->aux->der;
        }

    }while(refs->auxLeer->aux != refs->auxLeer->inicio);
}

extern arbolote *insetarEnArbol(char indice[], int numPag, arbolote *root)
{
    arbolote *nuevo, *aux;
    nuevo = (arbolote *)malloc(sizeof(arbolote));
    
    aux = root;

    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.");
        exit(1);
    }
    nuevo->arbNumPag = numPag;
    strcpy(nuevo->indice, indice);
    nuevo->izq = NULL;
    nuevo->der = NULL;

    if(aux == NULL)
    {
        aux = nuevo;
        return aux;  
    }
    printf("\nAqui se tiene que ver lo que escribí en el índice %s\n", nuevo->indice);
    printf("\nAqui se tiene que ver la página del índice %i\n", nuevo->arbNumPag);
    if(strcmp(indice, nuevo->indice) < 0) 
    {   
        printf("prueba");
        aux->der = insetarEnArbol(indice, numPag, aux->der);
    } 
    else if (strcmp(indice, nuevo->indice) > 0)
    {
        printf("prueba2");
        aux->izq = insetarEnArbol(indice, numPag, aux->izq);
    }
    
    return aux;
}

extern void imprimirEnTxt(arbolote *aux, FILE *fp)
{
    if(aux != NULL)
    {
        imprimirEnTxt(aux->izq, fp);  
        fprintf(fp, "%s\t %d\n", aux->indice, aux->arbNumPag);
        imprimirEnTxt(aux->der, fp);  
    }
    return;
}