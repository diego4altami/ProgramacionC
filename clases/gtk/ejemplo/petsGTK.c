#include "deftipos.h"

int main(int argc, char *argv[])
{
    refsApp miApp;
    GtkWidget *window1, *window2, *botAlta, *botSalir;
    GtkWidget *hbox1, *vbox1;
    GtkWidget *clienteLbl2, *razaLbl2, *pesoLbl2, *inClliente, *inRaza, *inPeso;
    GtkWidget *hbox21,*hbox22,*hbox23,*vbox2;

    miApp.inicio = NULL;
    miApp.fin = NULL;
    miApp.aux = NULL;

    /* 1. Se inicializa el entorno */
    gtk_init(&argc, &argv);

    /* 2. Crea los widgets*/
    window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hbox1 = gtk_hbox_new(FALSE, 10);
    vbox1 = gtk_vbox_new(FALSE, 10);
    botSalir = gtk_button_new_with_label("Salir");
    botAlta = gtk_button_new_with_label("Alta de mascotas");
    miApp.clienteLbl = gtk_label_new("Aqui va el cliente");
    miApp.razalbl = gtk_label_new("Aqui va la raza");
    miApp.pesolbl = gtk_label_new("Aqui va el peso");
    miApp.botIzq = gtk_button_new_with_label("<-");
    miApp.botDer = gtk_button_new_with_label("->");

    window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hbox21 = gtk_hbox_new(FALSE, 10);
    hbox22 = gtk_hbox_new(FALSE, 10);
    hbox23 = gtk_hbox_new(FALSE, 10);
    vbox2 = gtk_vbox_new(FALSE, 10);
    clienteLbl2 = gtk_label_new("Cliente: ");
    razaLbl2 = gtk_label_new("Raza: ");
    pesoLbl2 = gtk_label_new("Peso: ");
    miApp.inCliente = gtk_entry_new();
    miApp.inRaza = gtk_entry_new();
    miApp.inPeso = gtk_entry_new();
    miApp.insertarNodo = gtk_button_new_with_label("Insertar mascota");

    gtk_window_set_title(GTK_WINDOW(window1), "Masctoas");
    gtk_container_set_border_width(GTK_CONTAINER(window1),100);
    gtk_window_set_title(GTK_WINDOW(window2), "Alta de mascotas");
    gtk_container_set_border_width(GTK_CONTAINER(window2),100);

    /* 3. Registro de Callbakcs*/

    /* 4. Define jerarquía de instancias (pack de widgets)*/

    gtk_box_pack_start_defaults(GTK_BOX(vbox1), miApp.clienteLbl);
    gtk_box_pack_start_defaults(GTK_BOX(vbox1), miApp.razalbl);
    gtk_box_pack_start_defaults(GTK_BOX(vbox1), miApp.pesolbl);
    gtk_box_pack_start_defaults(GTK_BOX(vbox1), botAlta);
    gtk_box_pack_start_defaults(GTK_BOX(hbox1), miApp.botIzq);
    gtk_box_pack_start_defaults(GTK_BOX(hbox1), botSalir);
    gtk_box_pack_start_defaults(GTK_BOX(hbox1), miApp.botDer);
    gtk_box_pack_start_defaults(GTK_BOX(vbox1), hbox1);
    gtk_container_add(GTK_CONTAINER(window1), vbox1);


    gtk_box_pack_start_defaults(GTK_BOX(hbox21), clienteLbl2);
    gtk_box_pack_start_defaults(GTK_BOX(hbox21), miApp.inCliente);
    gtk_box_pack_start_defaults(GTK_BOX(hbox22), razaLbl2);
    gtk_box_pack_start_defaults(GTK_BOX(hbox22), miApp.inRaza);
    gtk_box_pack_start_defaults(GTK_BOX(hbox23), pesoLbl2);
    gtk_box_pack_start_defaults(GTK_BOX(hbox23), miApp.inPeso);
    gtk_box_pack_start_defaults(GTK_BOX(vbox2), hbox21);  // Cambiado a vbox2
    gtk_box_pack_start_defaults(GTK_BOX(vbox2), hbox22);  // Cambiado a vbox2
    gtk_box_pack_start_defaults(GTK_BOX(vbox2), hbox23);  // Cambiado a vbox2
    gtk_box_pack_start_defaults(GTK_BOX(vbox2), miApp.insertarNodo);
    gtk_container_add(GTK_CONTAINER(window2), vbox2);

    /* 5. Mostrar los widgets */
    gtk_widget_show_all(window1);
    gtk_widget_show_all(window2);

    /* 6. El programa se queda en loop*/
    gtk_main();
    
    return 0;
}