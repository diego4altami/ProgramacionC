#include <gtk-2.0/gtk/gtk.h>

/** *
* @file texto.c
* @brief Esteeselejemplodelaventana;semodificóparaquetengauntextodeentrada.
* @author EjemplomodificadodelKrause
* @date 23/nov/2023 *
*
*/
/*Prototipos de funciones. En GTK son conocidas estas funciones como Callbacks
 */

void print_and_quit(GtkButton *was_clicked, gpointer user_data);
gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data);

void print_and_quit(GtkButton *was_clicked, gpointer user_data)
{
    g_print("Gracias por usarme\n");
    gtk_main_quit();
    return;
}

gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    /* Recibe cierre de ventana del window manager */
    g_print("\nEsta aplicación ya se cerró.\n"); 
    gtk_main_quit();
    return(FALSE); /* FALSE no previene de cierre*/
}

int main(int argc, char *argv[])
{
    GtkWidget *top_widget, *box, *texto, *separator, *exit_btn, *scrolWin;

    /* 1. Se inicializa el entorno */
    gtk_init(&argc, &argv);

    /* 2. Crea los widgets */
    top_widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box = gtk_vbox_new(FALSE, 10);
    texto = gtk_text_view_new();
    scrolWin = gtk_scrolled_window_new(NULL, NULL);
    separator = gtk_hseparator_new();
    exit_btn = gtk_button_new_with_label("Salir");

    /* 2b. Inicializa atributos */
    gtk_window_set_title(GTK_WINDOW(top_widget), "Texto con scroll");
    gtk_window_resize(GTK_WINDOW(top_widget), 500, 500);
    gtk_container_set_border_width(GTK_CONTAINER(top_widget), 100);
    gtk_widget_set_name(top_widget, "gtkfun");
    gtk_widget_set_name(box, "vertical box");
    gtk_widget_set_name(texto, "fun_texto");
    gtk_widget_set_name(separator, "separator");
    gtk_widget_set_name(exit_btn, "Salir");

    /* 3. Registro de callbacks */
    g_signal_connect(G_OBJECT(exit_btn), "clicked", G_CALLBACK(print_and_quit), NULL);
    g_signal_connect(G_OBJECT(top_widget), "delete_event", G_CALLBACK(delete_event_handler), NULL);
    g_signal_connect(G_OBJECT(top_widget), "destroy", G_CALLBACK(print_and_quit), NULL);

    /* 4. Define jerarquía de instancias (pack the widgets)*/
    gtk_container_add(GTK_CONTAINER(scrolWin), texto);
    gtk_container_add(GTK_CONTAINER(top_widget), box);
    gtk_box_pack_start_defaults(GTK_BOX(box), scrolWin);
    gtk_box_pack_start_defaults(GTK_BOX(box), separator);
    gtk_box_pack_start_defaults(GTK_BOX(box), exit_btn);

    /* 5. Mostrar los widgets */
    gtk_widget_show_all(top_widget);

    /* 6. El programa se queda en loop */
    gtk_main();
    g_print("Bye!\n");

    return 0; 
}
