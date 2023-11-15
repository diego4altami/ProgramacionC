#include "defTiposGTK.h"

int main(int argc, char *argv[])
{
    refsApp miApp;
    GtkWidget *window1, *window2, *botAlta, *botSalir, *hBox1, *vBox1;
    GtkWidget *clienteLbl2, *razaLbl2, *pesoLbl2, *inCliente, *inRaza, *inPeso;
    GtkWidget *hBox21, *hBox22, *hBox23, *vBox2;

    miApp.inicio = NULL;
    miApp.fin = NULL;
    miApp.aux = NULL;

    // 1. Se inicializa el entorno
    gtk_init(&argc, &argv);

    // 2. Crea los widgets
    window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox1 = gtk_hbox_new(FALSE, 10);
    vBox1 = gtk_vbox_new(FALSE, 10);
    botSalir = gtk_button_new_with_label("Salir");
    botAlta = gtk_button_new_with_label("Alta de mascota");
    miApp.clienteLbl = gtk_label_new("Aquí va el cliente.");
    miApp.razaLbl = gtk_label_new("Aquí va la raza.");
    miApp.pesoLbl = gtk_label_new("Aquí va el peso.");
    miApp.botonDer = gtk_button_new_with_label("->");
    miApp.botonIzq = gtk_button_new_with_label("<-");

    window2 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    hBox21 = gtk_hbox_new(FALSE, 10);
    hBox22 = gtk_hbox_new(FALSE, 10);
    hBox23 = gtk_hbox_new(FALSE, 10);
    vBox2 = gtk_vbox_new(FALSE, 10);
    clienteLbl2 = gtk_label_new("Cliente");
    razaLbl2 = gtk_label_new("Raza");
    pesoLbl2 = gtk_label_new("Peso");
    miApp.inCliente = gtk_entry_new();
    miApp.inRaza = gtk_entry_new();
    miApp.inPeso = gtk_entry_new();
    miApp.insertarNodo = gtk_button_new_with_label("Insertar mascota");

    gtk_window_set_title(GTK_WINDOW(window1), "Mascotas");
    gtk_container_set_border_width(GTK_CONTAINER(window1), 100);
    gtk_window_set_title(GTK_WINDOW(window2), "Alta de mascotas");
    gtk_container_set_border_width(GTK_CONTAINER(window2), 100);

    // 3. Registro de callbacks


    // 4. Define jerarquía de instancias (pack de widgets)
    gtk_container_add(GTK_CONTAINER(window1), vBox1);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), miApp.clienteLbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), miApp.razaLbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), miApp.pesoLbl);
    gtk_box_pack_start_defaults(GTK_BOX(vBox1), botAlta);
    gtk_box_pack_start_defaults(GTK_BOX(hBox1), miApp.botonIzq);
    gtk_box_pack_start_defaults(GTK_BOX(hBox1), botSalir);
    gtk_box_pack_start_defaults(GTK_BOX(hBox1), miApp.botonDer);
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
    gtk_widget_show_all(window2);

    // 6. El programa se queda en loop
    gtk_main();

    return 0;
}