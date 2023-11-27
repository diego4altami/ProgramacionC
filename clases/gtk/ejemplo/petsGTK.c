#include "deftipos.h"

//Funciones de GTK, callbacks

gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data);
void closeTheApp(GtkWidget *botSalir, gpointer data);
void visualizarVentanaAlta(GtkWidget *botAlta, gpointer pVentana);
void darAltaMascota(GtkWidget *facilito, gpointer *pMiApp);
void recorrerIzq(GtkWidget *pBotIzq, gpointer pMiApp);
void recorrerDer(GtkWidget *pBotDer, gpointer pMiApp);

//Funciones de C

void imprimirListaDobleCirc(refsApp pMiApp);
void crearListaDoble(char nomArch[], refsApp *pMiApp);

int main(int argc, char *argv[])
{
    refsApp miApp;
    GtkWidget *window1, *window2, *botAlta, *botSalir, *hBox1, *vBox1;
    GtkWidget *clienteLbl2, *razaLbl2, *pesoLbl2, *inCliente, *inRaza, *inPeso;
    GtkWidget *hBox21, *hBox22, *hBox23, *vBox2;

    char cadPeso[10], cadCliente[10];

    miApp.inicio = NULL;
    miApp.fin = NULL;
    miApp.aux = NULL;

    crearListaDoble(argv[1], &miApp);
    miApp.aux = miApp.inicio; //ya puse aux en el inicio
    imprimirListaDobleCirc(miApp);

    sprintf(cadCliente, "%d", miApp.aux->datos.cliente);
    sprintf(cadPeso, "%f", miApp.aux->datos.peso);

    // 1. Se inicializa el entorno
    gtk_init(&argc, &argv);

    // 2. Crea los widgets
    window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox1 = gtk_hbox_new(FALSE, 10);
    vBox1 = gtk_vbox_new(FALSE, 10);
    botSalir = gtk_button_new_with_label("Salir");
    botAlta = gtk_button_new_with_label("Alta de mascota");
    miApp.clienteLbl = gtk_label_new(cadCliente);
    miApp.razalbl = gtk_label_new(miApp.aux->datos.raza);
    miApp.pesolbl = gtk_label_new(cadPeso);
    miApp.botDer = gtk_button_new_with_label("->");
    miApp.botIzq = gtk_button_new_with_label("<-");
    miApp.imagenPet = gtk_image_new_from_file(miApp.aux->datos.raza);

    window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox21 = gtk_hbox_new(FALSE, 10);
    hBox22 = gtk_hbox_new(FALSE, 10);
    hBox23 = gtk_hbox_new(FALSE, 10);
    vBox2 = gtk_vbox_new(FALSE, 10);
    clienteLbl2 = gtk_label_new("Cliente.");
    razaLbl2 = gtk_label_new("Raza.");
    pesoLbl2 = gtk_label_new("Peso.");
    miApp.inCliente = gtk_entry_new();
    miApp.inRaza = gtk_entry_new();
    miApp.inPeso = gtk_entry_new();
    miApp.insertarNodo = gtk_button_new_with_label("Insertar mascota");

    gtk_window_set_title(GTK_WINDOW(window1), "Mascotas");
    //gtk_container_set_border_width(GTK_CONTAINER(window1), 100);
    gtk_window_set_title(GTK_WINDOW(window2), "Alta de mascotas");
    //gtk_container_set_border_width(GTK_CONTAINER(window2), 100);
    //gtk_window_set_default_size(GTK_WINDOW(window1), 300, 200);

    // 3. Registro de callbacks
    g_signal_connect(G_OBJECT(window1), "delete_event", G_CALLBACK(delete_event_handler), NULL);
    g_signal_connect(G_OBJECT(window2), "delete_event", G_CALLBACK(delete_event_handler), NULL);
    g_signal_connect(G_OBJECT(botSalir), "clicked", GTK_SIGNAL_FUNC(closeTheApp), NULL);
    g_signal_connect(G_OBJECT(botAlta), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaAlta), window2);
    g_signal_connect(G_OBJECT(miApp.insertarNodo), "clicked", GTK_SIGNAL_FUNC(darAltaMascota), &miApp);
    g_signal_connect(G_OBJECT(miApp.botIzq), "clicked", GTK_SIGNAL_FUNC(recorrerIzq), &miApp);
    g_signal_connect(G_OBJECT(miApp.botDer), "clicked", GTK_SIGNAL_FUNC(recorrerDer), &miApp);

    // 4. Define jerarquía de instancias (pack de widgets)

    gtk_box_pack_start_defaults(GTK_BOX(vBox1), miApp.imagenPet);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), miApp.clienteLbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), miApp.razalbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), miApp.pesolbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), botAlta);
    gtk_box_pack_start_defaults(GTK_BOX(hBox1), miApp.botIzq);
    gtk_box_pack_start_defaults(GTK_BOX(hBox1), botSalir);
    gtk_box_pack_start_defaults(GTK_BOX(hBox1), miApp.botDer);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), hBox1);
    gtk_container_add(GTK_CONTAINER(window1), vBox1);
    
    gtk_box_pack_start_defaults(GTK_BOX(hBox21), clienteLbl2);
    gtk_box_pack_start_defaults(GTK_BOX(hBox21), miApp.inCliente);
    gtk_box_pack_start_defaults(GTK_BOX(hBox22), razaLbl2);
    gtk_box_pack_start_defaults(GTK_BOX(hBox22), miApp.inRaza);
    gtk_box_pack_start_defaults(GTK_BOX(hBox23), pesoLbl2);
    gtk_box_pack_start_defaults(GTK_BOX(hBox23), miApp.inPeso);
    gtk_box_pack_start_defaults(GTK_BOX(vBox2), hBox21);
    gtk_box_pack_start_defaults(GTK_BOX(vBox2), hBox22);
    gtk_box_pack_start_defaults(GTK_BOX(vBox2), hBox23);
    gtk_box_pack_start_defaults(GTK_BOX(vBox2), miApp.insertarNodo);

    gtk_container_add(GTK_CONTAINER(window2), vBox2);

    // 5. Mostrar los widgets
    gtk_widget_show_all(window1);

    // 6. El programa se queda en loop
    gtk_main();

    return 0;
}