#include "tiposGTK.h"

gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data);
void closeTheApp(GtkWidget *botSalir, gpointer data);
void regresarAVentanaAnterior(GtkWidget *botRegresar, gpointer pVentana);
void visualizarVentanaCrear(GtkWidget *botCrear, gpointer pVentana);
void visualizarVentanaEditar(GtkWidget *botEditar, gpointer pVentana);
void visualizarVentanaAviso(GtkWidget *botEditar, gpointer pVentana);
void visualizarVentanaSecc(GtkWidget *botEditar, gpointer pVentana);
void visualizarVentanaEscribir(GtkWidget *botEditar, gpointer pVentana);

void crearTodo(GtkWidget *n, gpointer *pmiApp);
void nombrarSeccion(GtkWidget *widget, gpointer *pmiApp);
void navegarYNombrarSeccion(GtkWidget *widget, gpointer data);

/*
void print_and_quit(GtkButton *was_clicked, gpointer user_data);
void on_insert_text(GtkTextBuffer *buffer, GtkTextIter *location, gchar *text, gint len, gpointer data);
*/

int main(int argc, char *argv[]) 
{
    refsApp miApp;
    char NumSecc[100];
    GtkWidget *window1, *window2, *window3, *window4, *window5, *window6;
    GtkWidget *bienvenidoLbl, *introLbl;
    GtkWidget *botEditar, *botCrear, *botSalir;
    GtkWidget *hBox1, *vBox1;    
    GtkWidget *hBox21, *hBox22, *hBox23, *vBox2;    
    GtkWidget *numSeccLbl, *titLbl;
    GtkWidget *hBox31, *hBox32, *hBox33, *hBox34, *vBox3;    
    GtkWidget *numSeccLbl2, *titLbl2, *pagLbl;
    GtkWidget *hBox41, *vBox4;    
    GtkWidget *avisoLbl, *texto1Lbl, *texto2Lbl;
    GtkWidget *seccLbl, *preguntaLbl;
    GtkWidget *hBox51, *hBox52, *vBox5; 
    GtkWidget *scrollWin, *separator;
    GtkWidget *capLbl, *hojaLbl;
    GtkWidget *hBox61, *hBox62, *hBox63, *vBox6; 

    miApp.inicio = NULL;
    miApp.fin = NULL;
    miApp.aux = NULL;

    sprintf(NumSecc, "%d", miApp.aux->aux->numSecc);

    //1. inicializar entorno
    gtk_init(&argc, &argv);

    //2. crear los widgets
    window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox1 = gtk_hbox_new(FALSE, 10);
    vBox1 = gtk_vbox_new(FALSE, 10);
    botEditar = gtk_button_new_with_label("Editar Libro");
    botCrear = gtk_button_new_with_label("Crear Libro");
    botSalir = gtk_button_new_with_label("Salir");
    bienvenidoLbl = gtk_label_new("Bienvenido");
    introLbl = gtk_label_new("Con esta app puedes crear un libro o editar un libro existente");

    window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox21 = gtk_hbox_new(FALSE, 10);
    hBox22 = gtk_hbox_new(FALSE, 10);
    hBox23 = gtk_hbox_new(FALSE, 10);
    vBox2 = gtk_vbox_new(FALSE, 10);
    titLbl = gtk_label_new("Título de libro:");
    numSeccLbl = gtk_label_new("Número de secciones:");
    miApp.titulo = gtk_entry_new();
    miApp.numSecc = gtk_entry_new();
    miApp.botRegresar = gtk_button_new_with_label("Regresar");
    miApp.botCrear = gtk_button_new_with_label("Crear");

    window3 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox31 = gtk_hbox_new(FALSE, 10);
    hBox32 = gtk_hbox_new(FALSE, 10);
    hBox33 = gtk_hbox_new(FALSE, 10);
    hBox34 = gtk_hbox_new(FALSE, 10);
    vBox3 = gtk_vbox_new(FALSE, 10);
    titLbl2 = gtk_label_new("Título de libro:");
    numSeccLbl2 = gtk_label_new("Número de sección:");
    pagLbl = gtk_label_new("Número de página:");
    miApp.edTitLbl = gtk_entry_new();
    miApp.edSeccLbl = gtk_entry_new();
    miApp.edPagLbl = gtk_entry_new();
    miApp.edBotReg = gtk_button_new_with_label("Regresar");
    miApp.edBotEdit = gtk_button_new_with_label("Editar");

    window4 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox41 = gtk_hbox_new(FALSE, 10);
    vBox4 = gtk_vbox_new(FALSE, 10);
    avisoLbl = gtk_label_new("AVISO");
    texto1Lbl = gtk_label_new("insetar instrucciones 1");
    texto2Lbl = gtk_label_new("insertar instrucciones 2");
    miApp.avBotReg = gtk_button_new_with_label("Regresar");
    miApp.avBotSig = gtk_button_new_with_label("Siguiente");

    window5 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox51 = gtk_hbox_new(FALSE, 10);
    hBox52 = gtk_hbox_new(FALSE, 10);
    vBox5 = gtk_vbox_new(FALSE, 10);
    seccLbl = gtk_label_new("Sección:");
    preguntaLbl = gtk_label_new("¿Cuál es el título de esta sección?");
    miApp.nomSecc = gtk_entry_new();
    miApp.seccNum = gtk_label_new(NumSecc);
    miApp.botSeccReg = gtk_button_new_with_label("Regresar");
    miApp.btoSeccSig = gtk_button_new_with_label("Siguiente");

    window6 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox61 = gtk_hbox_new(FALSE, 10);
    hBox62 = gtk_hbox_new(FALSE, 10);
    hBox63 = gtk_hbox_new(FALSE, 10);
    vBox6 = gtk_vbox_new(FALSE, 10);
    capLbl = gtk_label_new("Capítulo: ");
    hojaLbl = gtk_label_new("Hoja: ");
    miApp.texto = gtk_text_view_new();
    gtk_widget_set_size_request(miApp.texto, 400, 300);
    scrollWin = gtk_scrolled_window_new(NULL, NULL);
    separator = gtk_hseparator_new();
    miApp.capNom = gtk_label_new("1");
    miApp.numHoj = gtk_label_new("1");
    miApp.botSigPag = gtk_button_new_with_label("Siguiente página");
    miApp.botReg = gtk_button_new_with_label("Regresar");
    miApp.botSigSecc = gtk_button_new_with_label("Siguiente sección");
    miApp.botInsertarImg = gtk_button_new_with_label("Insertar imagen");
    miApp.botGurdaryVer = gtk_button_new_with_label("Guardar y ver");

    gtk_window_set_title(GTK_WINDOW(window1), "app Ebook");
    gtk_container_set_border_width(GTK_CONTAINER(window1), 100);

    gtk_window_set_title(GTK_WINDOW(window2), "Crear Ebook");
    gtk_container_set_border_width(GTK_CONTAINER(window2), 100);

    gtk_window_set_title(GTK_WINDOW(window3), "Editar Ebook");
    gtk_container_set_border_width(GTK_CONTAINER(window3), 100);

    gtk_window_set_title(GTK_WINDOW(window4), "AVISO");
    gtk_container_set_border_width(GTK_CONTAINER(window4), 100);

    gtk_window_set_title(GTK_WINDOW(window5), "Sección");
    gtk_container_set_border_width(GTK_CONTAINER(window5), 100);

    gtk_window_set_title(GTK_WINDOW(window6), "Sección");
    gtk_container_set_border_width(GTK_CONTAINER(window6), 100);

    //3. Registro de callbacks
    g_signal_connect(G_OBJECT(window1), "delete_event", G_CALLBACK(delete_event_handler), NULL);
    g_signal_connect(G_OBJECT(botSalir), "clicked", GTK_SIGNAL_FUNC(closeTheApp), NULL);

    g_signal_connect(G_OBJECT(botCrear), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaCrear), window2);
    g_signal_connect(G_OBJECT(miApp.botRegresar), "clicked", G_CALLBACK(regresarAVentanaAnterior), window1);
    g_signal_connect(G_OBJECT(miApp.botCrear), "clicked", G_CALLBACK(crearTodo), &miApp);

    g_signal_connect(G_OBJECT(botEditar), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaEditar), window3);
    g_signal_connect(G_OBJECT(miApp.edBotReg), "clicked", G_CALLBACK(regresarAVentanaAnterior), window1);

    g_signal_connect(G_OBJECT(miApp.botCrear), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaAviso), window4);
    g_signal_connect(G_OBJECT(miApp.avBotReg), "clicked", G_CALLBACK(regresarAVentanaAnterior), window2);

    g_signal_connect(G_OBJECT(miApp.avBotSig), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaSecc), window5);
    g_signal_connect(G_OBJECT(miApp.botSeccReg), "clicked", G_CALLBACK(regresarAVentanaAnterior), window4);
    g_signal_connect(G_OBJECT(miApp.btoSeccSig), "clicked", G_CALLBACK(nombrarSeccion), &miApp);

    g_signal_connect(G_OBJECT(miApp.btoSeccSig), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaEscribir), window6);
    g_signal_connect(G_OBJECT(miApp.edBotEdit), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaEscribir), window6);
    g_signal_connect(G_OBJECT(miApp.botReg), "clicked", G_CALLBACK(regresarAVentanaAnterior), window1);
    g_signal_connect(G_OBJECT(miApp.botSigSecc), "clicked", G_CALLBACK(navegarYNombrarSeccion), &miApp);
    g_signal_connect(G_OBJECT(miApp.avBotSig), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaSecc), window5);
    g_signal_connect(G_OBJECT(miApp.btoSeccSig), "clicked", G_CALLBACK(nombrarSeccion), &miApp);
    g_signal_connect(G_OBJECT(miApp.botSeccReg), "clicked", G_CALLBACK(regresarAVentanaAnterior), window6);

    //4. Definiendo jerarquias
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), bienvenidoLbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), introLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox1), botEditar);
    gtk_box_pack_start_defaults(GTK_BOX(hBox1), botCrear);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), hBox1);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), botSalir);
    gtk_container_add(GTK_CONTAINER(window1), vBox1);

    gtk_box_pack_start_defaults(GTK_BOX(hBox21), titLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox21), miApp.titulo);
    gtk_box_pack_start_defaults(GTK_BOX(hBox22), numSeccLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox22), miApp.numSecc);
    gtk_box_pack_start_defaults(GTK_BOX(hBox23), miApp.botRegresar);
    gtk_box_pack_start_defaults(GTK_BOX(hBox23), miApp.botCrear);
    gtk_box_pack_start_defaults(GTK_BOX(vBox2), hBox21);
    gtk_box_pack_start_defaults(GTK_BOX(vBox2), hBox22);
    gtk_box_pack_start_defaults(GTK_BOX(vBox2), hBox23);
    gtk_container_add(GTK_CONTAINER(window2), vBox2);

    gtk_box_pack_start_defaults(GTK_BOX(hBox31), titLbl2);
    gtk_box_pack_start_defaults(GTK_BOX(hBox31), miApp.edTitLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox32), numSeccLbl2);
    gtk_box_pack_start_defaults(GTK_BOX(hBox32), miApp.edSeccLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox33), pagLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox33), miApp.edPagLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox34), miApp.edBotReg);
    gtk_box_pack_start_defaults(GTK_BOX(hBox34), miApp.edBotEdit);
    gtk_box_pack_start_defaults(GTK_BOX(vBox3), hBox31);
    gtk_box_pack_start_defaults(GTK_BOX(vBox3), hBox32);
    gtk_box_pack_start_defaults(GTK_BOX(vBox3), hBox33);
    gtk_box_pack_start_defaults(GTK_BOX(vBox3), hBox34);
    gtk_container_add(GTK_CONTAINER(window3), vBox3);

    gtk_box_pack_start_defaults(GTK_BOX(vBox4), avisoLbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox4), texto1Lbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox4), texto2Lbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox41), miApp.avBotReg);
    gtk_box_pack_start_defaults(GTK_BOX(hBox41), miApp.avBotSig);
    gtk_box_pack_start_defaults(GTK_BOX(vBox4), hBox41);
    gtk_container_add(GTK_CONTAINER(window4), vBox4);

    gtk_box_pack_start_defaults(GTK_BOX(hBox51), seccLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox51), miApp.seccNum);
    gtk_box_pack_start_defaults(GTK_BOX(vBox5), hBox51);
    gtk_box_pack_start_defaults(GTK_BOX(vBox5), preguntaLbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox5), miApp.nomSecc);
    gtk_box_pack_start_defaults(GTK_BOX(hBox52), miApp.botSeccReg);
    gtk_box_pack_start_defaults(GTK_BOX(hBox52), miApp.btoSeccSig);
    gtk_box_pack_start_defaults(GTK_BOX(vBox5), hBox52);
    gtk_container_add(GTK_CONTAINER(window5), vBox5);

    gtk_box_pack_start_defaults(GTK_BOX(hBox61), capLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox61), miApp.capNom);
    gtk_box_pack_start_defaults(GTK_BOX(hBox61), hojaLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox61), miApp.numHoj);
    gtk_box_pack_start_defaults(GTK_BOX(vBox6), hBox61);
    gtk_container_add(GTK_CONTAINER(scrollWin), miApp.texto);
    gtk_box_pack_start_defaults(GTK_BOX(vBox6), scrollWin);
    gtk_box_pack_start_defaults(GTK_BOX(vBox6), separator);
    gtk_box_pack_start_defaults(GTK_BOX(vBox6), miApp.botSigPag);
    gtk_box_pack_start_defaults(GTK_BOX(hBox62), miApp.botReg);
    gtk_box_pack_start_defaults(GTK_BOX(hBox62), miApp.botSigSecc);
    gtk_box_pack_start_defaults(GTK_BOX(vBox6), hBox62);
    gtk_box_pack_start_defaults(GTK_BOX(hBox63), miApp.botInsertarImg);
    gtk_box_pack_start_defaults(GTK_BOX(hBox63), miApp.botGurdaryVer);
    gtk_box_pack_start_defaults(GTK_BOX(vBox6), hBox63);
    gtk_container_add(GTK_CONTAINER(window6), vBox6);

    //5. Mostrar los widgets
    gtk_widget_show_all(window1);

    //6. El programa se queda en loop
    gtk_main();

    return 0; 
}