#include "deftipos.h"

void insertarCola(tipoMascotas dat, refsApp *pMiApp);
void imprimirListaDobleCirc(refsApp pMiApp);
void moverIzq(refsApp *pRefs);

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

extern void visualizarVentanaAlta(GtkWidget *botAlta, gpointer pVentana)
{
    gtk_widget_show_all(pVentana);

    return;
}

extern void darAltaMascota(GtkWidget *facilito, gpointer *pMiApp)
{
    tipoMascotas datos;
    refsApp *referencias;

    referencias = (refsApp *)pMiApp;

    strcpy(datos.raza, gtk_entry_get_text(GTK_ENTRY(referencias->inRaza)));
    sscanf(gtk_entry_get_text(GTK_ENTRY(referencias->inCliente)), "%d", &datos.cliente);
    sscanf(gtk_entry_get_text(GTK_ENTRY(referencias->inCliente)), "%f", &datos.peso);

    insertarCola(datos, referencias);
    system("clear");
    imprimirListaDobleCirc(*referencias);

    return;
}

extern void recorrerIzq(GtkWidget *pBotIzq, gpointer pMiApp)
{
    refsApp *referencias;
    char cliente[10];
    char peso[10];

    referencias = (refsApp *)pMiApp;

    sprintf(cliente,"%d", referencias->aux->datos.cliente);
    gtk_label_set_text(GTK_LABEL(referencias->clienteLbl), cliente);
    gtk_label_set_text(GTK_LABEL(referencias->razalbl), referencias->aux->datos.raza);
    sprintf(peso,"%d", referencias->aux->datos.peso);
    gtk_label_set_text(GTK_LABEL(referencias->pesolbl), peso);
    moverIzq(referencias);
    sprintf(cliente,"%d", referencias->aux->datos.cliente);
    gtk_label_set_text(GTK_LABEL(referencias->clienteLbl), cliente);
    gtk_label_set_text(GTK_LABEL(referencias->razalbl), referencias->aux->datos.raza);
    sprintf(peso,"%d", referencias->aux->datos.peso);
    gtk_label_set_text(GTK_LABEL(referencias->pesolbl), peso);

    return;
}