#include "tiposGTK.h"

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