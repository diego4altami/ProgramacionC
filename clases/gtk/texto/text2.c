#include <gtk-2.0/gtk/gtk.h>

void tomarTexto(GtkButton *was_clicked, gpointer user_data);

gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data);

int main(int argc, char *argv[]) 
{   
    GtkWidget *top_widget, *separator, *botCopiaTexto, *box;
    GtkWidget *texto; //Variable de apuntador a un "text view", objeto que puede contener texto.
    GtkWidget *scrolWin; //Variable de apuntador a un "scroll", nos permite agregar un scroll a un "text view"

    /* 1. Se inicializa el entorno */
    gtk_init(&argc, &argv);
    /* 2. Crea los widgets */
    top_widget = gtk_window_new( GTK_WINDOW_TOPLEVEL ); 
    box = gtk_vbox_new( FALSE, 10);
    texto = gtk_text_view_new(); 
    scrolWin = gtk_scrolled_window_new(NULL, NULL);
    separator = gtk_hseparator_new( );
    botCopiaTexto = gtk_button_new_with_label( "Imprimir texto capturado en terminal." ); 
    
    /* 2b. Inicializa atributos */
    gtk_window_set_title(GTK_WINDOW(top_widget), "Texto con scroll"); 
    gtk_window_resize(GTK_WINDOW(top_widget), 500, 500); 
    gtk_container_set_border_width(GTK_CONTAINER(top_widget), 100);

    /* 3. Registro de callbacks */
    //El siguiente callback se ejecuta cuando se le da click al botón
    //se manda el apuntador a *texto que es el objeto en el que se puede escribir y realizar 
    g_signal_connect(G_OBJECT(botCopiaTexto), "clicked", G_CALLBACK(tomarTexto), texto); 
    g_signal_connect(G_OBJECT(top_widget), "delete_event", G_CALLBACK(delete_event_handler), NULL);

    /* 4. Define jerarquía de instancias (pack the widgets)*/
    gtk_container_add(GTK_CONTAINER(scrolWin), texto);//Aquí se hace al objeto "texto" hijo de scrolWin para 
    gtk_container_add(GTK_CONTAINER(top_widget), box);
    gtk_box_pack_start_defaults(GTK_BOX(box), scrolWin); 
    gtk_box_pack_start_defaults(GTK_BOX(box), separator); 
    gtk_box_pack_start_defaults(GTK_BOX(box), botCopiaTexto);

    /* 5. Mostrar los widgets */
    gtk_widget_show_all(top_widget);
    /* 6. El programa se queda en loop */
    gtk_main();
    return 0; 
}

extern void tomarTexto(GtkButton *was_clicked, gpointer user_data) 
{
    GtkTextBuffer *buffer; //Es necesario declarar una variable de tipo buffer para manipular la copia del texto 
    GtkTextIter inicio, fin, pos; //Se requieren las variables de inicio y fin de texto que se va a copiar
    const gchar *textoEnVentana;//Es una variable de cadena de GTK que mantiene constante el contenido del texto
    char textoFinal[1680];
    //Esta es una variable de C que tiene el tamaño promedio de una cuartilla de texto //Revisar estos links que dan numeralia de la densidad y tamaño de palabras y caráteres //de un documento profesional:
    // https://concepto.de/cuartilla/
    // https://www.cafedelescritor.com/cuantas-palabras-tiene-una-novela/
    // https://publuu.com/es/knowledge-base/omo-escribir-un-libro-infantil/
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(user_data));// se crea la variable y se le anexa el texto del text view 
    gtk_text_buffer_get_bounds(GTK_TEXT_BUFFER(buffer), &inicio, &fin);//se colocan los marcadores del inicio y fin del texto 
    textoEnVentana = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(buffer), &inicio, &fin, FALSE); //Se copia el contenido del *texto
    //en la variable de texto de GTK 
    strcpy(textoFinal, textoEnVentana);//Copia a una variable de cadena de C para asegurarme que tengo el texto de la manera
    //más simple para manipularlo con otras funciones de C 
    printf("\n%s\n", textoFinal);//Hago la comprobación en pantalla
    return; 
}

extern gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    /* Recibe cierre de ventana del window manager */
    g_print("\nEsta aplicación ya se cerró.\n"); 
    gtk_main_quit();
    return(FALSE); /* FALSE no previene de cierre*/
}