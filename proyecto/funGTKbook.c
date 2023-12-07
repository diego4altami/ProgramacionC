#include "tiposGTK.h"

void instertarTodo(char tituloLibro[], int numeroSeccion, refsApp *refs);
void imprimirLibro(refsApp refs);
void modificarNomSeccion(rep *libro, char nomSecc[]);
void guardarLibroEnBin(rep *libro);
void guardarLibroEnTxt(rep *libro);
void moverPagina(rep *libro);
void siguienteSec(rep *libro);
void buscandoAnemo(char tit[], char sec[], int pagNum, refsApp refs);

extern gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data)
{
    gtk_main_quit();

    return(FALSE); 
}

extern void closeTheApp(GtkWidget *botSalir, gpointer data)
{
    gtk_main_quit();

    return;
}

extern void regresarAVentanaAnterior(GtkWidget *botRegresar, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botRegresar)); 
    gtk_widget_show_all(pVentana); 
}

extern void visualizarVentanaSiguiente(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botAlta));
    gtk_widget_show_all(pVentana);

    return;
}

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

void moverSeccion(GtkWidget *was_clicked, gpointer *pmiApp)
{
    refsApp *refs;
    refs = (refsApp *)pmiApp;

    siguienteSec(refs->libroActual);

    return;
}

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

extern void siguientePagina(GtkWidget *was_clicked, gpointer *pmiApp)
{   
    refsApp *refs;
    refs = (refsApp *)pmiApp;

    moverPagina(refs->libroActual);

    return;
}

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
    //imprimirRepisa(*refs);
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

    buscandoAnemo(buscTit, buscNomSecc, buscPagNum, *refs);

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

    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(refs->texto));
    gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(buffer), &inicio, &fin);
    textoEnVentana = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer), &inicio, &fin, FALSE); 

    strncpy(paginaActual->texto, textoEnVentana, sizeof(paginaActual->texto) - 1);
    paginaActual->texto[sizeof(paginaActual->texto) - 1] = '\0';

    gtk_text_buffer_set_text(buffer, "", -1);
}