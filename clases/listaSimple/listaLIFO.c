/*
    @file 
    @brief: Este ejemplo es para manipular una lista LIFOP de nodos que están
            definidos con una parte de nombre (string)y un apuntador next al 
            al siguiente nodo del mismo tipo.
            1) Defina una varibale apuntador de nombre inicio de tipo nodo y asígnela a NULL
            Con esto la variable indica que es una lista vacía
            2)Haga una función de nombre push que inserte un nueve nodo con una palabra que 
            ingrese el usuario y encadena la lista de forma LIFO. El usuario va tecleando
            palbara, se insertan todas, excepto "salir", con esta palabra termina la inserción.
    @author Diego Altamirano Tovar
    @date 21/09/23
*/

#include "defTipos.h"

nodo *push(char pal[], nodo *pt);
void comprobarLista(nodo *pt);
void dibujarNodos(nodo *pt);
nodo * pop(nodo *pt);

int main(int argc, char *argv[])
{
    int i,j=0;
    nodo *inicio;
    char pal[40];

    inicio = NULL;
    printf("\nEste programa inserta palabras en una lista LIFO, dame tus palabras: ");
    scanf("%s",pal);
    while(strcmp(pal, "salir") != 0)
    {
        inicio = push(pal, inicio);
        printf("\nDame otra palabra para insertar en LIFO: ");
        scanf("%s",pal);
        j++;
    }
    comprobarLista(inicio);
    dibujarNodos(inicio);

    for(i=0;i=(j-1);i++)
    {
        inicio=pop(inicio);
        dibujarNodos(inicio);
    }

    return 0;
}

