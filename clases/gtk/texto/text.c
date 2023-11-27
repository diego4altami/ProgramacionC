#include <gtk-2.0/gtk/gtk.h>

void print_and_quit(GtkButton *was_clicked, gpointer user_data);
gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data);
void on_insert_text(GtkTextBuffer *buffer, GtkTextIter *location, gchar *text, gint len, gpointer data);

#define MAX_CHARS 1800
#define MAX_CHARS_PER_LINE 60

void on_insert_text(GtkTextBuffer *buffer, GtkTextIter *location, gchar *text, gint len, gpointer data) {

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

int main(int argc, char *argv[]) {
    GtkWidget *top_widget, *box, *texto, *separator, *exit_btn, *scrolWin;
    GtkTextBuffer *buffer;

    gtk_init(&argc, &argv);

    top_widget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    box = gtk_vbox_new(FALSE, 10);
    texto = gtk_text_view_new();
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(texto));
    scrolWin = gtk_scrolled_window_new(NULL, NULL);
    separator = gtk_hseparator_new();
    exit_btn = gtk_button_new_with_label("Salir");

    gtk_window_set_title(GTK_WINDOW(top_widget), "Texto con scroll");
    gtk_window_resize(GTK_WINDOW(top_widget), 500, 500);
    gtk_container_set_border_width(GTK_CONTAINER(top_widget), 100);

    g_signal_connect(G_OBJECT(exit_btn), "clicked", G_CALLBACK(print_and_quit), NULL);
    g_signal_connect(G_OBJECT(top_widget), "delete_event", G_CALLBACK(delete_event_handler), NULL);
    g_signal_connect(G_OBJECT(top_widget), "destroy", G_CALLBACK(print_and_quit), NULL);
    g_signal_connect(G_OBJECT(buffer), "insert-text", G_CALLBACK(on_insert_text), NULL);

    gtk_container_add(GTK_CONTAINER(scrolWin), texto);
    gtk_container_add(GTK_CONTAINER(top_widget), box);
    gtk_box_pack_start_defaults(GTK_BOX(box), scrolWin);
    gtk_box_pack_start_defaults(GTK_BOX(box), separator);
    gtk_box_pack_start_defaults(GTK_BOX(box), exit_btn);

    gtk_widget_show_all(top_widget);

    gtk_main();

    return 0; 
}
