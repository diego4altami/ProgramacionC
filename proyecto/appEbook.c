/*
@file appEbook.c
@brief  El programa es una aplicación de interfaz gráfica construida con GTK en C para la creación y edición de libros electrónicos (ebooks). 
        A través de varias ventanas y botones, el usuario puede realizar acciones como crear un nuevo libro, editar un libro existente, nombrar secciones, 
        escribir contenido, y guardar el libro en formatos binarios y de texto. La aplicación utiliza callbacks para manejar eventos de botones y 
        realiza diversas funciones relacionadas con la manipulación y gestión de libros electrónicos.
@author Alberto Parera Méndez, Diego Altamirano Tovar Y Ariadna Berenice Pedraza Rodriguez.
@date 28/11/2023
*/
#include "tiposGTK.h"

gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data);
void closeTheApp(GtkWidget *botSalir, gpointer data);
void regresarAVentanaAnterior(GtkWidget *botRegresar, gpointer pVentana);
void visualizarVentanaSiguiente(GtkWidget *botCrear, gpointer pVentana);
void tomarTexto(GtkButton *was_clicked, gpointer *pmiApp);
void tomarTexto2(GtkButton *was_clicked, gpointer *pmiApp);
void crearTodo(GtkWidget *n, gpointer *pmiApp);
void nombrarSecciones(GtkWidget *n, gpointer *pmiApp);
void guardarEnBin(GtkWidget *was_clicked, gpointer *pmiApp);
void guardarEnTxt(GtkWidget *was_clicked, gpointer *pmiApp);
void siguientePagina(GtkWidget *was_clicked, gpointer *pmiApp);
void moverSeccion(GtkWidget *was_clicked, gpointer *pmiApp);
void revisar(GtkWidget *was_clicked, gpointer *pmiApp);
void cargarTodosLosbinarios(refsApp *refs);
void cargarLectura(refsApp *refs);
void imprimirLibro(refsApp refs);
void tocoYmeMuevo(GtkWidget *was_clicked, gpointer *pmiApp);
void cargar_y_mostrar(GtkWidget *widget, gpointer *pmiApp);
void moverIzq(GtkWidget *btnAnterior, gpointer *pMiApp);
void moverDer(GtkWidget *btnSiguiente, gpointer *pMiApp);
void leerMoverPagIzq(GtkWidget *botIzq, gpointer *pMiApp);
void leerMoverPagDer(GtkWidget *botDer, gpointer *pMiApp);
void marcarMarcadorMarcado(GtkWidget *botMarcar, gpointer *pMiApp);
void continuarLeyendo(GtkWidget *btnContinuar, gpointer *pMiApp);
void empezarAleer(GtkWidget *btnEmpezar, gpointer *pMiApp);
void anexarIndice(GtkWidget *botAnexar, gpointer *pMiApp);
void guardarArbolTxt(GtkWidget *botsalyGuar, gpointer *pMiApp);
void guardarMarcadores(GtkWidget *botsalyGuar, gpointer *pMiApp);

int main(int argc, char *argv[])
{
    refsApp miApp;
    char leerNumPag[10];
    GtkWidget *window1, *window2, *window3, *window4;
    GtkWidget *window5, *window6, *window7, *window8, *window9, *window10, *window11;
    GtkWidget *bienvenidoLbl, *introLbl;
    GtkWidget *botEditar, *botCrear, *botSalir, *botLeer;
    GtkWidget *hBox1, *vBox1;    
    GtkWidget *hBox21, *hBox22, *hBox23, *vBox2;    
    GtkWidget *numSeccLbl, *titLbl;
    GtkWidget *hBox31, *hBox32, *hBox33, *hBox34, *vBox3;    
    GtkWidget *numSeccLbl2, *titLbl2, *pagLbl;
    GtkWidget *hBox41, *vBox4;    
    GtkWidget *hBox101, *vBox10;    
    GtkWidget *hBox111, *vBox11;    
    GtkWidget *avisoLbl, *texto1Lbl, *texto2Lbl;
    GtkWidget *avisoLbl2, *texto1Lbl2, *texto2Lbl2;
    GtkWidget *avisoLbl3, *texto1Lbl3, *texto2Lbl3;
    GtkWidget *seccLbl, *preguntaLbl;
    GtkWidget *hBox51, *hBox52, *hBox53, *vBox5; 
    GtkWidget *scrollWin, *separator;
    GtkWidget *capLbl, *hojaLbl;
    GtkWidget *hBox61, *hBox62, *hBox63, *vBox6; 
    GtkWidget *vBox7, *hBox7, *editLbl;
    GtkWidget *scrollWin2, *separator2;
    GtkWidget *hBox81, *hBox82, *hBox83, *hBox84, *vBox8;
    GtkWidget *hBox91, *hBox92, *hBox93, *vBox9;

    miApp.inicio = NULL;
    miApp.fin = NULL;
    miApp.aux = NULL;

    miApp.inicioLeer = NULL;
    miApp.finLeer = NULL;
    miApp.auxLeer = NULL;

    miApp.libroActual = NULL;

    cargarTodosLosbinarios(&miApp);
    cargarLectura(&miApp);

    sprintf(leerNumPag, "%d", miApp.auxLeer->aux->numero);
    
    //1. inicializar entorno
    gtk_init(&argc, &argv);

    //2. crear los widgets
    window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox1 = gtk_hbox_new(FALSE, 10);
    vBox1 = gtk_vbox_new(FALSE, 10);
    botEditar = gtk_button_new_with_label("Editar Libro");
    botCrear = gtk_button_new_with_label("Crear Libro");
    botLeer = gtk_button_new_with_label("Leer Libro");
    botSalir = gtk_button_new_with_label("Salir");
    bienvenidoLbl = gtk_label_new("Bienvenido");
    introLbl = gtk_label_new("Con esta app puedes leer, crear o editar un libro.");

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
    numSeccLbl2 = gtk_label_new("Título de sección:");
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
    texto1Lbl = gtk_label_new("Escriba con libertad y cuando guste cambiar de línea presiones Enter\nUse los botones a su gusto\nSiguiente página crea una página nueva\nSiguiente sección te pedira nombrar la siguiente sección");
    texto2Lbl = gtk_label_new("Es importante nombrar todas las secciones antes de guardar los cambios no guardados de verán perdidos.");
    miApp.avBotReg = gtk_button_new_with_label("Regresar");
    miApp.avBotSig = gtk_button_new_with_label("Siguiente");

    window10 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox101 = gtk_hbox_new(FALSE, 10);
    vBox10 = gtk_vbox_new(FALSE, 10);
    avisoLbl2 = gtk_label_new("AVISO");
    texto1Lbl2 = gtk_label_new("Escoja el libro de su preferencia y lealo sin restricciones \n Use los botones con libertad\n Solo se puede colocar una marca por libro\n Los nombres de los libros tendrán .bin al final ");
    texto2Lbl2 = gtk_label_new("Debe guardar los cambios antes de salir\nDe lo contrario de borrarán");
    miApp.avBotReg2 = gtk_button_new_with_label("Regresar");
    miApp.avBotSig2 = gtk_button_new_with_label("Siguiente");

    window11 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox111 = gtk_hbox_new(FALSE, 10);
    vBox11 = gtk_vbox_new(FALSE, 10);
    avisoLbl3 = gtk_label_new("AVISO");
    texto1Lbl3 = gtk_label_new("Escriba con libertad y cuando guste cambiar de línea presiones Enter\nUse los botones a su gusto\nSiguiente página crea una página nueva\nSiguiente sección te pedira nombrar la siguiente sección");
    texto2Lbl3 = gtk_label_new("Es importante nombrar todas las secciones antes de guardar\nLos cambios no guardados de verán perdidos.");
    miApp.avBotReg3 = gtk_button_new_with_label("Regresar");
    miApp.avBotSig3 = gtk_button_new_with_label("Siguiente");

    window5 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox51 = gtk_hbox_new(FALSE, 10);
    hBox52 = gtk_hbox_new(FALSE, 10);
    hBox53 = gtk_hbox_new(FALSE, 10);
    vBox5 = gtk_vbox_new(FALSE, 10);
    seccLbl = gtk_label_new("Sección:");
    miApp.seccNum = gtk_label_new("1");
    preguntaLbl = gtk_label_new("¿Cuál es el título de esta sección?");
    miApp.nomSecc = gtk_entry_new();
    miApp.botSeccReg = gtk_button_new_with_label("Regresar");
    miApp.btoSeccSig = gtk_button_new_with_label("Siguiente");

    window6 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox61 = gtk_hbox_new(FALSE, 10);
    hBox62 = gtk_hbox_new(FALSE, 10);
    hBox63 = gtk_hbox_new(FALSE, 10);
    vBox6 = gtk_vbox_new(FALSE, 10);
    capLbl = gtk_label_new("Capítulo: ");
    hojaLbl = gtk_label_new("Hoja: ");
    miApp.capNom = gtk_label_new("1");
    miApp.numHoj = gtk_label_new("1");
    miApp.texto = gtk_text_view_new();
    gtk_widget_set_size_request(miApp.texto, 550, 425);
    scrollWin = gtk_scrolled_window_new(NULL, NULL);
    separator = gtk_hseparator_new();
    miApp.botSigPag = gtk_button_new_with_label("Siguiente página");
    miApp.botReg = gtk_button_new_with_label("Regresar");
    miApp.botSigSecc = gtk_button_new_with_label("Siguiente sección");
    miApp.botGurdaryVer = gtk_button_new_with_label("Guardar y ver");

    window7 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    vBox7 = gtk_vbox_new(FALSE, 10);
    hBox7 = gtk_hbox_new(FALSE, 10);
    editLbl =gtk_label_new("Edición de página");
    miApp.texto2 = gtk_text_view_new();
    gtk_widget_set_size_request(miApp.texto2, 550, 425);
    scrollWin2 = gtk_scrolled_window_new(NULL, NULL);
    separator2 = gtk_hseparator_new();
    miApp.boteditsave=gtk_button_new_with_label("Guardar cambios");
    miApp.editBotreg=gtk_button_new_with_label("Regresar");


    window8 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox81 = gtk_hbox_new(FALSE, 10);
    hBox82 = gtk_hbox_new(FALSE, 10);
    hBox83 = gtk_hbox_new(FALSE, 10);
    hBox84 = gtk_hbox_new(FALSE, 10);
    vBox8 = gtk_vbox_new(FALSE, 10);
    miApp.titLbl = gtk_label_new(miApp.auxLeer->aux->titulo);
    miApp.seccLbl = gtk_label_new(miApp.auxLeer->aux->titSeccion);
    miApp.lblTexto = gtk_label_new(miApp.auxLeer->aux->texto);
    miApp.pagLbl = gtk_label_new(leerNumPag);
    miApp.entryAnexar = gtk_entry_new();
    miApp.botMarcar = gtk_button_new_with_label("Marcar");
    miApp.botsalyGuar = gtk_button_new_with_label("Salir y Guardar");
    miApp.botAnexar = gtk_button_new_with_label("Anexar en índice");
    miApp.botIzq = gtk_button_new_with_label("<-");
    miApp.botDer = gtk_button_new_with_label("->");
    miApp.butReg = gtk_button_new_with_label("Regresar");

    window9 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox91 = gtk_hbox_new(FALSE, 10);
    hBox92 = gtk_hbox_new(FALSE, 10);
    hBox93 = gtk_hbox_new(FALSE, 10);
    vBox9 = gtk_vbox_new(FALSE, 10);
    miApp.labelTitulo = gtk_label_new(miApp.inicioLeer->titulo);
    miApp.btnSiguiente = gtk_button_new_with_label("->");
    miApp.btnAnterior = gtk_button_new_with_label("<-");
    miApp.btnContinuar = gtk_button_new_with_label("Continuar Lectura");
    miApp.btnEmpezar = gtk_button_new_with_label("Empezar Lectura");
    miApp.btnRegresar = gtk_button_new_with_label("Regresar");

    gtk_window_set_title(GTK_WINDOW(window1), "app Ebook");
    gtk_container_set_border_width(GTK_CONTAINER(window1), 100);

    gtk_window_set_title(GTK_WINDOW(window2), "Crear Ebook");
    gtk_container_set_border_width(GTK_CONTAINER(window2), 100);

    gtk_window_set_title(GTK_WINDOW(window3), "Editar Ebook");
    gtk_container_set_border_width(GTK_CONTAINER(window3), 100);

    gtk_window_set_title(GTK_WINDOW(window4), "AVISO");
    gtk_container_set_border_width(GTK_CONTAINER(window4), 100);

    gtk_window_set_title(GTK_WINDOW(window10), "AVISO");
    gtk_container_set_border_width(GTK_CONTAINER(window10), 100);

    gtk_window_set_title(GTK_WINDOW(window11), "AVISO");
    gtk_container_set_border_width(GTK_CONTAINER(window11), 100);

    gtk_window_set_title(GTK_WINDOW(window5), "Nombrar secciones");
    gtk_container_set_border_width(GTK_CONTAINER(window5), 100);

    gtk_window_set_title(GTK_WINDOW(window6), "Escribir Ebook");
    gtk_container_set_border_width(GTK_CONTAINER(window6), 100);

    gtk_window_set_title(GTK_WINDOW(window7), "Editar página");
    gtk_container_set_border_width(GTK_CONTAINER(window7), 100);

    gtk_window_set_title(GTK_WINDOW(window8), "Lector de Libro");
    gtk_container_set_border_width(GTK_CONTAINER(window8), 100);

    gtk_window_set_title(GTK_WINDOW(window9), "Selector de Libros");
    gtk_container_set_border_width(GTK_CONTAINER(window9), 100);

    //3. Registro de callbacks

    //callbacks primera ventana
    g_signal_connect(G_OBJECT(window1), "delete_event", G_CALLBACK(delete_event_handler), NULL);
    g_signal_connect(G_OBJECT(botSalir), "clicked", GTK_SIGNAL_FUNC(closeTheApp), NULL);
    g_signal_connect(G_OBJECT(botCrear), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaSiguiente), window2);
    g_signal_connect(G_OBJECT(botEditar), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaSiguiente), window10);
    g_signal_connect(G_OBJECT(botLeer), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaSiguiente), window11);

    //callbacks segunda ventana
    g_signal_connect(G_OBJECT(miApp.botRegresar), "clicked", G_CALLBACK(regresarAVentanaAnterior), window1);
    g_signal_connect(G_OBJECT(miApp.botCrear), "clicked", G_CALLBACK(crearTodo), &miApp);
    g_signal_connect(G_OBJECT(miApp.botCrear), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaSiguiente), window4);

    //callbacks tercera ventana
    g_signal_connect(G_OBJECT(miApp.edBotReg), "clicked", G_CALLBACK(regresarAVentanaAnterior), window1);
    g_signal_connect(G_OBJECT(miApp.edBotEdit), "clicked", GTK_SIGNAL_FUNC(tocoYmeMuevo), &miApp);
    g_signal_connect(G_OBJECT(miApp.edBotEdit), "clicked", GTK_SIGNAL_FUNC(cargar_y_mostrar), &miApp);
    g_signal_connect(G_OBJECT(miApp.edBotEdit), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaSiguiente), window7);

    //callbacks cuarta ventana
    g_signal_connect(G_OBJECT(miApp.avBotReg), "clicked", G_CALLBACK(regresarAVentanaAnterior), window2);
    g_signal_connect(G_OBJECT(miApp.avBotSig), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaSiguiente), window5);

    //callbacks décima ventana
    g_signal_connect(G_OBJECT(miApp.avBotReg2), "clicked", G_CALLBACK(regresarAVentanaAnterior), window1);
    g_signal_connect(G_OBJECT(miApp.avBotSig2), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaSiguiente), window3);

    //callbacks onceava ventana
    g_signal_connect(G_OBJECT(miApp.avBotReg3), "clicked", G_CALLBACK(regresarAVentanaAnterior), window1);
    g_signal_connect(G_OBJECT(miApp.avBotSig3), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaSiguiente), window9);

    //callbacks quinta ventana 
    g_signal_connect(G_OBJECT(miApp.botSeccReg), "clicked", G_CALLBACK(regresarAVentanaAnterior), window4);
    g_signal_connect(G_OBJECT(miApp.btoSeccSig), "clicked", G_CALLBACK(nombrarSecciones), &miApp);
    g_signal_connect(G_OBJECT(miApp.btoSeccSig), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaSiguiente), window6);

    //callbacks sexta ventana
    g_signal_connect(G_OBJECT(miApp.botReg), "clicked", G_CALLBACK(regresarAVentanaAnterior), window1);
    g_signal_connect(G_OBJECT(miApp.botSigPag), "clicked", G_CALLBACK(revisar), &miApp);
    g_signal_connect(G_OBJECT(miApp.botSigPag), "clicked", G_CALLBACK(tomarTexto), &miApp);
    g_signal_connect(G_OBJECT(miApp.botSigPag), "clicked", G_CALLBACK(siguientePagina), &miApp);
    g_signal_connect(G_OBJECT(miApp.botSigPag), "clicked", G_CALLBACK(visualizarVentanaSiguiente), window6);    
    g_signal_connect(G_OBJECT(miApp.botGurdaryVer), "clicked", G_CALLBACK(revisar), &miApp);    
    g_signal_connect(G_OBJECT(miApp.botGurdaryVer), "clicked", G_CALLBACK(tomarTexto), &miApp);
    g_signal_connect(G_OBJECT(miApp.botGurdaryVer), "clicked", G_CALLBACK(guardarEnBin), &miApp);
    g_signal_connect(G_OBJECT(miApp.botGurdaryVer), "clicked", G_CALLBACK(guardarEnTxt), &miApp);
    g_signal_connect(G_OBJECT(miApp.botGurdaryVer), "clicked", G_CALLBACK(visualizarVentanaSiguiente), window1);    
    g_signal_connect(G_OBJECT(miApp.botSigSecc), "clicked", G_CALLBACK(revisar), &miApp);
    g_signal_connect(G_OBJECT(miApp.botSigSecc), "clicked", G_CALLBACK(tomarTexto), &miApp);
    g_signal_connect(G_OBJECT(miApp.botSigSecc), "clicked", G_CALLBACK(moverSeccion), &miApp);
    g_signal_connect(G_OBJECT(miApp.botSigSecc), "clicked", G_CALLBACK(visualizarVentanaSiguiente), window5);

    //callbacks septima ventana
    g_signal_connect(G_OBJECT(miApp.editBotreg), "clicked", G_CALLBACK(regresarAVentanaAnterior), window3);
    g_signal_connect(G_OBJECT(miApp.boteditsave), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaSiguiente), window1);
    g_signal_connect(G_OBJECT(miApp.boteditsave), "clicked", GTK_SIGNAL_FUNC(tomarTexto2), &miApp);
    g_signal_connect(G_OBJECT(miApp.boteditsave), "clicked", GTK_SIGNAL_FUNC(guardarEnBin), &miApp);
    g_signal_connect(G_OBJECT(miApp.boteditsave), "clicked", GTK_SIGNAL_FUNC(guardarEnTxt), &miApp);

    //callbacks novena ventana
    g_signal_connect(G_OBJECT(miApp.btnContinuar), "clicked", G_CALLBACK(regresarAVentanaAnterior), window8);
    g_signal_connect(G_OBJECT(miApp.btnEmpezar), "clicked", G_CALLBACK(regresarAVentanaAnterior), window8);
    g_signal_connect(G_OBJECT(miApp.btnEmpezar), "clicked", G_CALLBACK(empezarAleer), &miApp);
    g_signal_connect(G_OBJECT(miApp.btnRegresar), "clicked", GTK_SIGNAL_FUNC(visualizarVentanaSiguiente), window1);
    g_signal_connect(G_OBJECT(miApp.btnAnterior), "clicked", G_CALLBACK(moverIzq), &miApp);
    g_signal_connect(G_OBJECT(miApp.btnSiguiente), "clicked", G_CALLBACK(moverDer), &miApp);
    g_signal_connect(G_OBJECT(miApp.btnContinuar), "clicked", G_CALLBACK(continuarLeyendo), &miApp);

    //callbacks octava ventana
    g_signal_connect(G_OBJECT(miApp.butReg), "clicked", G_CALLBACK(regresarAVentanaAnterior), window9);
    g_signal_connect(G_OBJECT(miApp.botIzq), "clicked", G_CALLBACK(leerMoverPagIzq), &miApp);
    g_signal_connect(G_OBJECT(miApp.botDer), "clicked", G_CALLBACK(leerMoverPagDer), &miApp);
    g_signal_connect(G_OBJECT(miApp.botMarcar), "clicked", G_CALLBACK(marcarMarcadorMarcado), &miApp);
    g_signal_connect(G_OBJECT(miApp.botAnexar), "clicked", G_CALLBACK(anexarIndice), &miApp);
    g_signal_connect(G_OBJECT(miApp.botsalyGuar), "clicked", G_CALLBACK(guardarArbolTxt), &miApp);

    //4. Definiendo jerarquias
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), bienvenidoLbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), introLbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), botLeer);
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

    gtk_box_pack_start_defaults(GTK_BOX(vBox10), avisoLbl2);
    gtk_box_pack_start_defaults(GTK_BOX(vBox10), texto1Lbl2);
    gtk_box_pack_start_defaults(GTK_BOX(vBox10), texto2Lbl2);
    gtk_box_pack_start_defaults(GTK_BOX(hBox101), miApp.avBotReg2);
    gtk_box_pack_start_defaults(GTK_BOX(hBox101), miApp.avBotSig2);
    gtk_box_pack_start_defaults(GTK_BOX(vBox10), hBox101);
    gtk_container_add(GTK_CONTAINER(window10), vBox10);

    gtk_box_pack_start_defaults(GTK_BOX(vBox11), avisoLbl3);
    gtk_box_pack_start_defaults(GTK_BOX(vBox11), texto1Lbl3);
    gtk_box_pack_start_defaults(GTK_BOX(vBox11), texto2Lbl3);
    gtk_box_pack_start_defaults(GTK_BOX(hBox111), miApp.avBotReg3);
    gtk_box_pack_start_defaults(GTK_BOX(hBox111), miApp.avBotSig3);
    gtk_box_pack_start_defaults(GTK_BOX(vBox11), hBox111);
    gtk_container_add(GTK_CONTAINER(window11), vBox11);

    gtk_box_pack_start_defaults(GTK_BOX(hBox51), seccLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox51), miApp.seccNum);
    gtk_box_pack_start_defaults(GTK_BOX(vBox5), hBox51);
    gtk_box_pack_start_defaults(GTK_BOX(vBox5), preguntaLbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox5), miApp.nomSecc);
    gtk_box_pack_start_defaults(GTK_BOX(hBox53), miApp.botSeccReg);
    gtk_box_pack_start_defaults(GTK_BOX(hBox53), miApp.btoSeccSig);
    gtk_box_pack_start_defaults(GTK_BOX(vBox5), hBox53);
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
    gtk_box_pack_start_defaults(GTK_BOX(vBox6), miApp.botGurdaryVer);
    gtk_container_add(GTK_CONTAINER(window6), vBox6);

    gtk_box_pack_start_defaults(GTK_BOX(vBox7), editLbl);
    gtk_container_add(GTK_CONTAINER(scrollWin2), miApp.texto2);
    gtk_box_pack_start_defaults(GTK_BOX(vBox7), scrollWin2);
    gtk_box_pack_start_defaults(GTK_BOX(vBox7), separator2);
    gtk_box_pack_start_defaults(GTK_BOX(hBox7), miApp.editBotreg);
    gtk_box_pack_start_defaults(GTK_BOX(hBox7), miApp.boteditsave);
    gtk_box_pack_start_defaults(GTK_BOX(vBox7), hBox7);
    gtk_container_add(GTK_CONTAINER(window7), vBox7);

    //leer 
    gtk_box_pack_start_defaults(GTK_BOX(hBox81), miApp.titLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox81), miApp.seccLbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox8), hBox81);
    gtk_label_set_line_wrap(GTK_LABEL(miApp.lblTexto), TRUE);
    gtk_label_set_line_wrap_mode(GTK_LABEL(miApp.lblTexto), PANGO_WRAP_WORD);
    gtk_widget_set_size_request(miApp.lblTexto, 425, 350); 
    gtk_box_pack_start(GTK_BOX(vBox8), miApp.lblTexto, FALSE, FALSE, 0);
    gtk_box_pack_start_defaults(GTK_BOX(vBox8), miApp.pagLbl);
    gtk_box_pack_start_defaults(GTK_BOX(hBox82), miApp.botIzq);
    gtk_box_pack_start_defaults(GTK_BOX(hBox82), miApp.botDer);
    gtk_box_pack_start_defaults(GTK_BOX(vBox8), hBox82);
    gtk_box_pack_start_defaults(GTK_BOX(hBox83), miApp.entryAnexar);
    gtk_box_pack_start_defaults(GTK_BOX(hBox83), miApp.botAnexar);
    gtk_box_pack_start_defaults(GTK_BOX(vBox8), hBox83);
    gtk_box_pack_start_defaults(GTK_BOX(hBox84), miApp.butReg);
    gtk_box_pack_start_defaults(GTK_BOX(hBox84), miApp.botMarcar);
    gtk_box_pack_start_defaults(GTK_BOX(hBox84), miApp.botsalyGuar);
    gtk_box_pack_start_defaults(GTK_BOX(vBox8), hBox84);
    gtk_container_add(GTK_CONTAINER(window8), vBox8);

    //repisa de libros
    gtk_box_pack_start_defaults(GTK_BOX(vBox9), miApp.labelTitulo);
    gtk_box_pack_start_defaults(GTK_BOX(hBox91), miApp.btnAnterior);
    gtk_box_pack_start_defaults(GTK_BOX(hBox91), miApp.btnSiguiente);
    gtk_box_pack_start_defaults(GTK_BOX(vBox9), hBox91);
    gtk_box_pack_start_defaults(GTK_BOX(vBox9), miApp.btnEmpezar);
    gtk_box_pack_start_defaults(GTK_BOX(vBox9), miApp.btnContinuar);
    gtk_box_pack_start_defaults(GTK_BOX(vBox9), miApp.btnRegresar);
    gtk_container_add(GTK_CONTAINER(window9), vBox9);

    //5. Mostrar los widgets
    gtk_widget_show_all(window1);

    //6. El programa se queda en loop
    gtk_main();

    return 0; 
}