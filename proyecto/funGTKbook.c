/*
@file funGTKbook.c
@brief El código se integra con la interfaz gráfica creada con GTK y realiza operaciones específicas en respuesta a eventos del usuario.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
*/

#include "tiposGTK.h"

void instertarTodo(char tituloLibro[], int numeroSeccion, refsApp *refs);
void imprimirRepisa(refsApp refs);
void modificarNomSeccion(rep *libro, char nomSecc[]);
void guardarLibroEnBin(rep *libro);
void guardarLibroEnTxt(rep *libro);
void moverPagina(rep *libro);
void siguienteSec(rep *libro);
void imprimirLibro(refsApp refs);
void buscandoAnemo(char tit[], char sec[], int pagNum, refsApp *refs);
void moverIzquierda(refsApp *refs);
void moverDerecha(refsApp *refs);
void moverPagDer(refsApp *refs);
void moverPagIzq(refsApp *refs);
void seMarcarMarcadorMarcadoMarcadisimoMuyMarcado(refsApp *refs);
void buscarMarcador(refsApp *refs);
arbolote *insetarEnArbol(char indice[], int numPag, arbolote *root);
void imprimirEnTxt(arbolote *aux, FILE *fp);
void crearMarcadoresBin(refsApp *refs);

/*
@brief la función se encarga de cerrar la aplicación correctamente cuando el usuario intenta cerrar la ventana principal.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param GtkWidget *widget: Es un puntero al widget al que está asociado el manejador de eventos. En este caso, sería un puntero a la ventana principal de la aplicación.
@return gboolean: Es un tipo de datos específico de GTK que representa un valor booleano.
@return return(FALSE): La función devuelve FALSE para indicar que el evento no debe propagarse más allá de este manejador.
*/

extern gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data)
{
    gtk_main_quit();

    return(FALSE); 
}

/*
@brief cuando esta función es llamada, se espera que cierre la aplicación GTK al invocar gtk_main_quit(). Esto es útil para gestionar la acción de cerrar la aplicación cuando se hace clic en el botón "Salir".
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param GtkWidget *botSalir: Es un puntero al widget que activó la función. En este contexto, se espera que sea el botón "Salir" de la interfaz gráfica.
@param gpointer data: Es un puntero que puede contener datos adicionales pasados por el usuario.
*/

extern void closeTheApp(GtkWidget *botSalir, gpointer data)
{
    gtk_main_quit();

    return;
}

/*
@brief esta función facilita la transición entre ventanas en una interfaz gráfica al ocultar la ventana actual y mostrar la ventana previamente especificada.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param GtkWidget *botRegresar: Es un puntero al botón que activó la función. Este parámetro se utiliza para identificar qué botón ha sido presionado y, por lo tanto, cuál es la acción a realizar.
@param gpointer pVentana: Es un puntero genérico que apunta a la ventana que se mostrará después de ocultar la ventana actual. Este parámetro proporciona la flexibilidad de trabajar con diferentes tipos de ventanas y permite que la función sea utilizada de manera más general en un entorno de interfaz gráfica.
*/

extern void regresarAVentanaAnterior(GtkWidget *botRegresar, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botRegresar)); 
    gtk_widget_show_all(pVentana); 
}

/*
@brief La función visualizarVentanaSiguiente se encarga de ocultar la ventana que contiene el botón botAlta y mostrar la ventana identificada por el puntero pVentana.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param GtkWidget *botAlta: Este es un puntero al widget que activó la función, en este caso, el botón botAlta.
@param gpointer pVentana: Este es un puntero genérico que apunta a la ventana que se va a mostrar (pVentana). Se utiliza para identificar la ventana que se debe mostrar al ocultar la ventana asociada al botón botAlta.
*/

extern void visualizarVentanaSiguiente(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botAlta));
    gtk_widget_show_all(pVentana);

    return;
}

/*
@brief  la función se utiliza para iniciar el proceso de creación de un libro en la aplicación GUI, tomando la información del título y el número de secciones ingresados por el usuario en la interfaz gráfica.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param *n (GtkWidget)**: Puntero al widget que activó la función. En este contexto, se espera que sea un botón u otro elemento de la interfaz gráfica que desencadene la acción de crear un libro.
@param *pmiApp (gpointer)**: Puntero genérico que apunta a la estructura refsApp. La estructura refsApp contiene información y referencias necesarias para las acciones relacionadas con la creación de libros en la aplicación.
*/

extern void crearTodo(GtkWidget *n, gpointer *pmiApp)
{
    refsApp *refs;
    
    refs = (refsApp *)pmiApp;

    int numeroSeccion;
    char tituloLibro[40];

    strcpy(tituloLibro, gtk_entry_get_text(GTK_ENTRY(refs->titulo)));
    sscanf(gtk_entry_get_text(GTK_ENTRY(refs->numSecc)), "%d", &numeroSeccion);

    instertarTodo(tituloLibro, numeroSeccion, refs);
    gtk_entry_set_text(GTK_ENTRY(refs->titulo), "");
    gtk_entry_set_text(GTK_ENTRY(refs->numSecc), "");

    //imprimirRepisa(*refs);

    return;
}

/*
@brief La función nombrarSecciones es un controlador de eventos que se activa al hacer clic en un botón u otro elemento de la interfaz gráfica. 
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param GtkWidget *n: Es un puntero al widget que activó el evento. En este contexto, se espera que este parámetro represente el botón u elemento de la interfaz gráfica que desencadenó la acción.
@param gpointer *pmiApp: Es un puntero genérico que se utiliza para pasar un puntero a la estructura refsApp, que probablemente contiene información sobre la aplicación y el estado actual.
*/

extern void nombrarSecciones(GtkWidget *n, gpointer *pmiApp)
{   
    refsApp *refs;
    char newNomSecc[40];

    refs = (refsApp *)pmiApp;

    strcpy(newNomSecc, gtk_entry_get_text(GTK_ENTRY(refs->nomSecc)));        

    modificarNomSeccion(refs->libroActual, newNomSecc);

    gtk_entry_set_text(GTK_ENTRY(refs->nomSecc), "");


    return;
} 

/*
@brief la función se encarga de obtener el nombre de una sección de la interfaz gráfica y luego modificar esa sección en la estructura del libro actual de la aplicación.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param GtkWidget *n: Este parámetro representa el widget que activó el evento asociado a esta función. En el contexto de la aplicación GTK, podría ser un botón u otro tipo de widget interactivo.
@param gpointer *pmiApp: Este parámetro es un puntero genérico que se utiliza para pasar un puntero a la estructura refsApp.
*/

void moverSeccion(GtkWidget *was_clicked, gpointer *pmiApp)
{
    refsApp *refs;
    refs = (refsApp *)pmiApp;

    siguienteSec(refs->libroActual);

    return;
}

/*
@brief la función se encarga de tomar el texto introducido en un GtkTextView y guardarlo en la estructura de datos de la aplicación, específicamente en la última página de la sección actual del libro en edición.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param GtkWidget *was_clicked: Este parámetro representa el widget que activó el evento asociado a esta función.
@param gpointer *pmiApp: Este parámetro es un puntero genérico que se utiliza para pasar un puntero a la estructura refsApp.
*/

extern void tomarTexto(GtkWidget *was_clicked, gpointer *pmiApp)
{
    refsApp *refs;
    GtkTextBuffer *buffer; 
    GtkTextIter inicio, fin; 
    const gchar *textoEnVentana;
    secc *seccionActual;
    hoja *paginaActual;

    refs = (refsApp *)pmiApp;

    if(refs->libroActual == NULL)
    {
        printf("\nNo hay un libro actualmente en edición\n");
        //hay que cambiar cosas aqui porque el usuario no se entera de nada
        return;
    }

    seccionActual = refs->libroActual->aux;
    if (seccionActual == NULL) {
        printf("\nNo hay secciones en el libro actual\n");
        return;
    }

    paginaActual = seccionActual->ultPag;
    if (paginaActual == NULL) {
        printf("\nNo hay páginas en la sección actual\n");
        return;
    }

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(refs->texto));
    gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(buffer), &inicio, &fin);
    textoEnVentana = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer), &inicio, &fin, FALSE); 

    strncpy(paginaActual->texto, textoEnVentana, sizeof(paginaActual->texto) - 1);
    paginaActual->texto[sizeof(paginaActual->texto) - 1] = '\0';

    gtk_text_buffer_set_text(buffer, "", -1);
}

/*
@brief La función tiene como objetivo verificar si hay un libro en edición y, en caso afirmativo, llamar a la función guardarLibroEnBin para almacenar dicho libro en formato binario. Si no hay un libro en edición, la función imprime un mensaje en la consola indicando que no existe un libro actualmente en proceso de edición.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param GtkWidget *was_clicked: Un puntero al widget que activó el evento, aunque en esta función no se utiliza directamente.
@param gpointer *pmiApp: Un puntero a datos genéricos que se utiliza para pasar información específica de la aplicación. En este caso, se espera que sea un puntero a la estructura refsApp, que contiene información sobre la aplicación y el libro actual en edición.
*/

extern void guardarEnBin(GtkWidget *was_clicked, gpointer *pmiApp)
{
    refsApp *refs;
    refs = (refsApp *)pmiApp;

    if(refs->libroActual == NULL)
    {
        printf("\no un un libro actualmente en edición\n");
        return;
    }

    guardarLibroEnBin(refs->libroActual);
}

/*
@brief la función se encarga de verificar si hay un libro en edición y, en caso afirmativo, guarda ese libro en un archivo de texto.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param GtkWidget *was_clicked: Un puntero al widget que activó el evento. En este caso, no se utiliza directamente en la función, pero es común incluirlo en la firma de la función para manejar eventos de widgets en GTK.
@param gpointer *pmiApp: Un puntero genérico a datos que se utiliza para pasar información específica de la aplicación. En este contexto, se espera que sea un puntero a la estructura refsApp, que contiene información sobre la aplicación y el libro actual en edición. Este puntero se utiliza para acceder a los datos relevantes para realizar la acción de guardar en texto.
*/

extern void guardarEnTxt(GtkWidget *was_clicked, gpointer *pmiApp)
{
    refsApp *refs;
    refs = (refsApp *)pmiApp;

    if(refs->libroActual == NULL)
    {
        printf("\no un un libro actualmente en edición\n");
        return;
    }

    guardarLibroEnTxt(refs->libroActual);
}

/*
@brief La función siguientePagina se encarga de avanzar a la siguiente página en el libro actualmente en edición de la aplicación GTK. 
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
@param GtkWidget *was_clicked: Este parámetro es un puntero al widget que activó el evento. En este caso, se llama was_clicked y es de tipo GtkWidget *.
@param gpointer *pmiApp: Se utiliza para pasar información y acceder a los elementos necesarios para realizar la funcionalidad de la función.
*/

extern void siguientePagina(GtkWidget *was_clicked, gpointer *pmiApp)
{   
    refsApp *refs;
    refs = (refsApp *)pmiApp;

    moverPagina(refs->libroActual);

    return;
}

extern void revisar(GtkWidget *was_clicked, gpointer *pmiApp)
{
    refsApp *refs;
    refs = (refsApp *)pmiApp;

    imprimirLibro(*refs);

    return;
}

extern void tocoYmeMuevo(GtkWidget *was_clicked, gpointer *pmiApp)
{
    refsApp *refs;
    char buscTit[40];
    char buscNomSecc[40];
    int buscPagNum;
    
    refs = (refsApp *)pmiApp;

    strcpy(buscTit, gtk_entry_get_text(GTK_ENTRY(refs->edTitLbl)));
    strcpy(buscNomSecc, gtk_entry_get_text(GTK_ENTRY(refs->edSeccLbl)));  
    sscanf(gtk_entry_get_text(GTK_ENTRY(refs->edPagLbl)), "%d", &buscPagNum);      

    printf("prueba");

    buscandoAnemo(buscTit, buscNomSecc, buscPagNum, refs);

    return;
}

extern void tomarTexto2(GtkWidget *was_clicked, gpointer *pmiApp)
{
    refsApp *refs;
    GtkTextBuffer *buffer; 
    GtkTextIter inicio, fin; 
    const gchar *textoEnVentana;
    secc *seccionActual;
    hoja *paginaActual;

    refs = (refsApp *)pmiApp;

    if(refs->libroActual == NULL)
    {
        printf("\nNo hay un libro actualmente en edición\n");
        //hay que cambiar cosas aqui porque el usuario no se entera de nada
        return;
    }

    seccionActual = refs->libroActual->aux;
    if (seccionActual == NULL) {
        printf("\nNo hay secciones en el libro actual\n");
        return;
    }

    paginaActual = seccionActual->primPag;
    if (paginaActual == NULL) {
        printf("\nNo hay páginas en la sección actual\n");
        return;
    }

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(refs->texto2));
    gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(buffer), &inicio, &fin);
    textoEnVentana = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer), &inicio, &fin, FALSE); 

    strncpy(paginaActual->texto, textoEnVentana, sizeof(paginaActual->texto) - 1);
    paginaActual->texto[sizeof(paginaActual->texto) - 1] = '\0';

    gtk_text_buffer_set_text(buffer, "", -1);
}

void cargar_y_mostrar(GtkWidget *widget, gpointer *pmiApp) 
{

    refsApp *refs;
    refs = (refsApp *)pmiApp;

    GtkTextBuffer *buffer;
    system("clear");

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(refs->texto2));
    gtk_text_buffer_set_text(buffer, refs->libroActual->aux->primPag->texto, -1);
}

extern void moverIzq(GtkWidget *btnAnterior, gpointer pMiApp)
{
    refsApp *refs; 
    refs = (refsApp *)pMiApp;

    moverIzquierda(refs);

    gtk_label_set_text(GTK_LABEL(refs->labelTitulo), refs->auxLeer->titulo);

    return;
}

extern void moverDer(GtkWidget *btnSiguiente, gpointer pMiApp)
{
    refsApp *refs; 

    refs = (refsApp *)pMiApp;

    moverDerecha(refs);

    gtk_label_set_text(GTK_LABEL(refs->labelTitulo), refs->auxLeer->titulo);

    return;
}

void leerMoverPagIzq(GtkWidget *botIzq, gpointer *pMiApp)
{
    refsApp *refs; 
    refs = (refsApp *)pMiApp;
    char leerNumPag[10];

    moverPagIzq(refs);

    gtk_label_set_text(GTK_LABEL(refs->titLbl), refs->auxLeer->aux->titulo);
    gtk_label_set_text(GTK_LABEL(refs->seccLbl), refs->auxLeer->aux->titSeccion);
    gtk_label_set_text(GTK_LABEL(refs->lblTexto), refs->auxLeer->aux->texto);
    sprintf(leerNumPag, "%d", refs->auxLeer->aux->numero);
    gtk_label_set_text(GTK_LABEL(refs->pagLbl), leerNumPag);

    return;
}

void leerMoverPagDer(GtkWidget *botDer, gpointer *pMiApp)
{
    refsApp *refs; 
    refs = (refsApp *)pMiApp;
    char leerNumPag[10];
    
    moverPagDer(refs);

    gtk_label_set_text(GTK_LABEL(refs->titLbl), refs->auxLeer->aux->titulo);
    gtk_label_set_text(GTK_LABEL(refs->seccLbl), refs->auxLeer->aux->titSeccion);
    gtk_label_set_text(GTK_LABEL(refs->lblTexto), refs->auxLeer->aux->texto);
    sprintf(leerNumPag, "%d", refs->auxLeer->aux->numero);
    gtk_label_set_text(GTK_LABEL(refs->pagLbl), leerNumPag);

    return;
}

void marcarMarcadorMarcado(GtkWidget *botMarcar, gpointer *pMiApp)
{
    refsApp *refs; 
    refs = (refsApp *)pMiApp;

    seMarcarMarcadorMarcadoMarcadisimoMuyMarcado(refs);

    return;
}

void continuarLeyendo(GtkWidget *btnContinuar, gpointer *pMiApp)
{
    refsApp *refs; 
    char leerNumPag[10];

    refs = (refsApp *)pMiApp;

    buscarMarcador(refs);

    gtk_label_set_text(GTK_LABEL(refs->titLbl), refs->auxLeer->aux->titulo);
    gtk_label_set_text(GTK_LABEL(refs->seccLbl), refs->auxLeer->aux->titSeccion);
    gtk_label_set_text(GTK_LABEL(refs->lblTexto), refs->auxLeer->aux->texto);
    sprintf(leerNumPag, "%d", refs->auxLeer->aux->numero);
    gtk_label_set_text(GTK_LABEL(refs->pagLbl), leerNumPag);

    return;
}

void empezarAleer(GtkWidget *btnEmpezar, gpointer *pMiApp)
{
    refsApp *refs; 
    refs = (refsApp *)pMiApp;
    char leerNumPag[10];

    sprintf(leerNumPag, "%d", refs->auxLeer->inicio->numero);

    gtk_label_set_text(GTK_LABEL(refs->titLbl), refs->auxLeer->inicio->titulo);
    gtk_label_set_text(GTK_LABEL(refs->seccLbl), refs->auxLeer->inicio->titSeccion);
    gtk_label_set_text(GTK_LABEL(refs->lblTexto), refs->auxLeer->inicio->texto);
    sprintf(leerNumPag, "%d", refs->auxLeer->inicio->numero);
    gtk_label_set_text(GTK_LABEL(refs->pagLbl), leerNumPag);

    return;
}

void anexarIndice(GtkWidget *botAnexar, gpointer *pMiApp)
{
    refsApp *refs; 
    char indice[100];

    refs = (refsApp *)pMiApp;

    strcpy(indice, gtk_entry_get_text(GTK_ENTRY(refs->entryAnexar)));

    refs->raiz = insetarEnArbol(indice, refs->auxLeer->aux->numero, refs->raiz);

    gtk_entry_set_text(GTK_ENTRY(refs->entryAnexar), "");

    return;
}

void guardarArbolTxt(GtkWidget *botsalyGuar, gpointer *pMiApp)
{
    refsApp *refs; 
    FILE *fp;
    refs = (refsApp *)pMiApp;

    
    fp = fopen("índices.txt", "w");
    if(fp == NULL)
    {
        printf("Archivo no disponible\n");
        exit(1);
    }
    fprintf(fp,"Índice de referencias\n");
    imprimirEnTxt(refs->raiz, fp);
    fclose(fp);

    return;
}