#include <gtk-2.0/gtk/gtk.h>
#include <string.h>
#include <stdlib.h>

void tomaTexto(GtkWidget *boton, gpointer entry); //Toma el texto del entry 
void closeTheApp(GtkWidget *window, gpointer data); //Acción sobre la ventana, hace algo cuando se cierra la aplicación
void borraTexto(GtkWidget *boton, gpointer entry); //Borra las entradas

gint main(gint argc, gchar *argv[])
{
    /*0. Declaración de variables */
    GtkWidget *window, *vbox, *hbox, *question, *label, *entrada, *boton;
    GtkWidget *botonLimpia; 

    /*1. Inicializar el ambiente*/
    gtk_init(&argc,&argv);

    /*2. Creación de los objetos y modificación de atributos */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //Declaramos la ventana
    gtk_window_set_title (GTK_WINDOW(window), "Ejemplo de Entry"); //Título de la ventana
    gtk_container_set_border_width(GTK_CONTAINER(window),10); 
    question = gtk_label_new("¿Deseas ingresar datos?"); //Declaramos los objetos que vamos a hacer
    label = gtk_label_new("Entrada (Entry):");
    boton = gtk_button_new_with_label("Guarda");
    botonLimpia =  gtk_button_new_with_label("Limpia");
    entrada = gtk_entry_new();

    /*Comando para insertar texto en el campo de entrada*/
    gtk_entry_set_text(GTK_ENTRY(entrada), "Escribe un dato...");

    /*3. Registro de los Callbacks */   /*Asociados a eventos de la ventana*/
    g_signal_connect(GTK_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(closeTheApp), question);
    g_signal_connect(GTK_OBJECT(boton), "clicked", GTK_SIGNAL_FUNC(tomaTexto), entrada);
    g_signal_connect(GTK_OBJECT(botonLimpia), "clicked", GTK_SIGNAL_FUNC(borraTexto), entrada);

    /* 4. Define jerarquía de instancias (pack the widgets)*/
    /*Horizontal box*/
    hbox = gtk_hbox_new(FALSE, 5);
    gtk_box_pack_start_defaults(GTK_BOX(hbox), label);
    gtk_box_pack_start_defaults(GTK_BOX(hbox), entrada);

    /*Vertical Box*/
    vbox = gtk_vbox_new(FALSE, 5);
    gtk_box_pack_start_defaults(GTK_BOX(vbox), question); //Esta es la pregunta que modificamos al principio
    gtk_box_pack_start_defaults(GTK_BOX(vbox), hbox); //Metiendo la caja horizontal que se hizo antes
    gtk_box_pack_start_defaults(GTK_BOX(vbox), boton); //primer botón
    gtk_box_pack_start_defaults(GTK_BOX(vbox), botonLimpia); //Segundo botón

    gtk_container_add(GTK_CONTAINER(window), vbox); // Meter toda la caja vertical en una ventana

    /* 5. Mostrar los widgets */
    gtk_widget_show_all(window);

    /* 6. El programa se queda en loop */
    gtk_main();
    return 0; 
}  

void tomaTexto(GtkWidget *boton, gpointer entry)
{
    FILE *fp;
    char datos[20];
    fp = fopen("datos.txt", "a");
    if (fp == NULL)
    {
        g_print("\nArchivo no disponible.");
        exit(1); 
    }
    strcpy(datos, gtk_entry_get_text(entry));
    fprintf(fp,"%s\n",datos);
    gtk_entry_set_text(GTK_ENTRY(entry),"Guardado en archivo..." );
    fclose(fp);
    return; 
}

void borraTexto(GtkWidget *boton, gpointer entry)
{
    gtk_entry_set_text(GTK_ENTRY(entry),"" );
    return;
}

void closeTheApp(GtkWidget *window, gpointer data)
{
    gtk_label_set_text(GTK_LABEL(data), "Vas a salir.");
    g_print("\nSalir de el ejemplo entriesBoton\n");
    gtk_main_quit();
    return; 
}
