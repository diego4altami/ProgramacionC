/*
    @file funcones.c
    @brief este archivo contiene las funciones que son llamadas
           desde listaFIFO.c, permite crear una lista simple y 
           varias operaciones en los nodos de la lista
    @author Diego Altamirano Tovar
    @date 26/09/23

*/

/*
    @author Diego Altamirano Tovar
    @brief 
    @date 26/09/23
    @param 
    @return 
*/
extern void enQueueCirc(nodo **ptPrimero, nodo **ptUltimo, char nom[], int pri)
{
    nodo *nuevo;

    nuevo = (nodo * )malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }
    strcpy(nuevo->nombre, nom);
    nuevo->prioridad = pri;

    if((*ptPrimero == NULL)&&(*ptUltimo == NULL))
    {
        *ptPrimero = nuevo;
        *ptUltimo = nuevo;
        nuevo->next = nuevo;
    }
    else
    {
        nuevo ->next = *ptPrimero;
        *ptUltimo = nuevo;
    }
    return;
}

/*
    @author Diego Altamirano Tovar
    @brief 
    @date 26/09/23
    @param 
    @return 
*/

extern void imprimirColaCirc(nodo *first, nodo *last)
{
    nodo *nuevo = first;


    if ((first == NULL) && (last == NULL))
    {
        printf("\nCola vacía.\n");
        return;
    }

    do 
    {
        printf("\n%s\t", nuevo->nombre);
        printf("%i\n", nuevo->prioridad);
        nuevo = nuevo->next;
    } while (nuevo != first);


    return;
}

extern dequeueCirc()