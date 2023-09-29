/*
    @file 
    @brief: Este ejemplo es para manipular una lista LIFOP de nodos que están
            definidos con una parte de nombre (string)y un apuntador next al 
            al siguiente nodo del mismo tipo.
            1) Defina una varibale apuntador de nombre inicio de tipo nodo y asígnela a NULL
            Con esto la variable indica que es una lista vacía
            2)Haga una función de nombre push que inserte un nueve nodo con una palabra que 
            ingrese el usuario y encadena la lista de forma LIFO. El usuario va tecleando
            palabra, se insertan todas, excepto "salir", con esta palabra termina la inserción.
            3) El ingreso de los datos (cadenas) serán desde un archivo de texto, el nombre del 
            archivo se ingresa en la línea de comandos.
    @author Diego Altamirano Tovar
    @date 21/09/23
*/

#include "defTipos.h"

nodo *push(char pal[], nodo *pt);
void comprobarLista(nodo *pt);
void dibujarNodos(nodo *pt);
nodo *pop(nodo *pt);
nodo *borrarTodos(nodo *pt);
nodo *eliminarPalabra(char pal[],nodo *pt);

int main(int argc, char *argv[])
{
    nodo *inicio;
    char pal[40];
    FILE *fp;

    fp = fopen(argv[1],"r");
    if(fp==NULL)
    {
        printf("archivo no disponible\n");
        exit(1);
    }
    
    inicio = NULL;
    printf("\nEste programa inserta palabras en una lista LIFO de un archvio de texto: \n");
    while(fscanf(fp,"%s",pal)==1)
    {
        inicio = push(pal,inicio);
    }
    fclose(fp);

    comprobarLista(inicio);
    dibujarNodos(inicio);
    printf("\nDame una palabra que desees borrar: ");
    scanf("%s",pal);
    inicio=eliminarPalabra(pal,inicio);
    dibujarNodos(inicio);
    inicio=borrarTodos(inicio);
    return 0;
}

