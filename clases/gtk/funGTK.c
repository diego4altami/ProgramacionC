#include <gtk-2.0/gtk/gtk.h>

/*
@file funGTK.c
@brief Este programa tiene las función usadas en otro programa.
@date 09/11/23
@author Diego Altamirano Tovar
*/

/*
@file funGTK.c
@brief Esta función es un callbackque tiene asociado el objetivo
       botón. Si se da el evento de click, se ejecuta un comando
       para terminal y enseguida se ejecuta una función que termina
       la app o el precoeso de la aplicación.
@date 09/11/23
@author Diego Altamirano Tovar
@param *was_clicked es un apuntador a un Widget de botón.
@param used_data es un apuntador (apuntador void) gponter.
@return void.
*/

extern void print_and_quit (GtkButton *was_clicked, gpointer user_data)
{
    /*Use glibs printf equivalent to print a mesasage*/
    /*7. Aquí se da la condición de fin de programa*/
    g_print("Gracias por usrme");
    gtk_main_quit();
}

extern gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer  )
{
    g_print("El window manager está preguntado por cerrar la ventana ")
}