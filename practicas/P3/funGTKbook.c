#include "tiposGTK.h"

#define MAX_CHARS 1800
#define MAX_CHARS_PER_LINE 60

void instertarTodo(char tituloLibro[], int numeroSeccion, refsApp *refs);
void imprimirRepisa(refsApp refs);
void sigeSec(char tituloSeccion[], rep *nRefs);

extern gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data)
{
    gtk_main_quit();

    return(FALSE); // false propaga el evento
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

extern void visualizarVentanaCrear(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botAlta));
    gtk_widget_show_all(pVentana);

    return;
}

extern void visualizarVentanaEditar(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botAlta));
    gtk_widget_show_all(pVentana);

    return;
}

extern void visualizarVentanaAviso(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botAlta));
    gtk_widget_show_all(pVentana);

    return;
}

extern void visualizarVentanaSecc(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botAlta));
    gtk_widget_show_all(pVentana);

    return;
}

extern void visualizarVentanaEscribir(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_hide(gtk_widget_get_toplevel(botAlta));
    gtk_widget_show_all(pVentana);

    return;
}

extern void crearTodo(GtkWidget *n, gpointer *pmiApp){
    refsApp *refs;
    
    refs = (refsApp *)pmiApp;

    int numeroSeccion;
    char tituloLibro[40];

    strcpy(tituloLibro, gtk_entry_get_text(GTK_ENTRY(refs->titulo)));
    sscanf(gtk_entry_get_text(GTK_ENTRY(refs->numSecc)), "%d", &numeroSeccion);

    instertarTodo(tituloLibro, numeroSeccion, refs);

    imprimirRepisa(*refs);

    return;
}

extern void nombrarSeccion(GtkWidget *n, gpointer data)
{
    secc *seccionActual = (secc *)data; // Asegúrate de que data sea de tipo secc *

    if (seccionActual != NULL) {
        const char *nombreSeccion = gtk_entry_get_text(GTK_ENTRY(n));
        strncpy(seccionActual->titSeccion, nombreSeccion, sizeof(seccionActual->titSeccion) - 1);
        seccionActual->titSeccion[sizeof(seccionActual->titSeccion) - 1] = '\0';
    }
}


extern void navegarYNombrarSeccion(GtkWidget *widget, gpointer data)
{
    refsApp *app = (refsApp *)data;
    secc *seccActual;
    seccActual = (secc *)(app->aux);

    // Navegación: Supongamos que usamos botones para navegar
    if (widget == app->botSigSecc) {
        if (app->aux && app->aux->der) {
            app->aux = app->aux->der;
        }
    } else if (widget == app->botReg) {
        if (app->aux && app->aux->izq) {
            app->aux = app->aux->izq;
        }
    }

    // Actualizar la interfaz con la información de la sección actual
    if (app->aux) 
    {
        gtk_label_set_text(GTK_LABEL(app->seccNum), g_strdup_printf("%d", app->aux->numSeccs));
        gtk_entry_set_text(GTK_ENTRY(app->nomSecc), seccActual->titSeccion);
    }
}

extern void on_insert_text(GtkTextBuffer *buffer, GtkTextIter *location, gchar *text, gint len, gpointer data) 
{
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    gchar *current_text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

    if (strlen(current_text) + len > MAX_CHARS) {
        g_signal_stop_emission_by_name(buffer, "insert-text");
    }

    g_free(current_text);

    // Check for line length
    GtkTextIter line_start = *location;
    gtk_text_iter_set_line_offset(&line_start, 0);
    gchar *line_text = gtk_text_buffer_get_text(buffer, &line_start, location, FALSE);

    if (strlen(line_text) + len > MAX_CHARS_PER_LINE) {
        g_signal_stop_emission_by_name(buffer, "insert-text");
    }

    g_free(line_text);
}

extern void print_and_quit(GtkButton *was_clicked, gpointer user_data);
gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data);

void print_and_quit(GtkButton *was_clicked, gpointer user_data)
{
    g_print("Gracias por usarme\n");
    gtk_main_quit();
    return;
}