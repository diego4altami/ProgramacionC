#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct categoria1 
     {
        int clave;
        char categoria[40];
        char producto[40];
        float precio;
        int inventario;
     };
typedef struct categoria1 cat1;

struct categoria2 
     {
        int clave;
        char categoria[40];
        char producto[40];
        float precio;
        int inventario;
     };
typedef struct categoria2 cat2;

struct porcomprar
    {
        char categoria[40];
        char producto[40];
        float precio;
        int cantidad;
    };
typedef struct porcomprar datcar;

struct elemento
    {
        cat1 datos1;
        cat2 datos2;
        struct elemento *izq, *der;
        
    };
typedef struct elemento nodo;

struct elementotipocarro
    {
        datcar datos;
        nodo *next;
    };
typedef struct elementotipocarro nodocar;

struct referencias
    {
        nodo *inicio, *fin, *aux;
    };
typedef struct referencias refs;

struct navegacion
    {
        refs *refscirc, *refslin;
        nodocar *iniciocar;
    };
typedef struct navegacion nav;

void leerTxt(char *nomArch, nav *nav);
void leerBin(char *nomArch, nav *nav);
void imprimirListaDobleCirc(refs refcirc);
void imprimirListaDoble(refs reflin);
void navegar(nav *nav);

int main (int argc, char *argv[])
{
    nav *navegador;
    
    navegador = (nav *)malloc(sizeof(nav));
    if (navegador == NULL) 
    {
        printf("No hay memoria suficiente\n");
        exit(1);
    }
    navegador->refscirc = (refs *)malloc(sizeof(refs));
    if (navegador->refscirc == NULL) {
        printf("Error al asignar memoria para refscirc\n");
        exit(1);
    }   
    navegador->refslin = (refs *)malloc(sizeof(refs));
    if (navegador->refslin == NULL) {
        printf("Error al asignar memoria para refscirc\n");
        exit(1);
    }   
    navegador->refscirc->inicio == NULL;
    navegador->refscirc->fin == NULL;
    navegador->refscirc->aux == NULL;

    navegador->refslin->inicio == NULL;
    navegador->refslin->fin == NULL;
    navegador->refslin->aux == NULL;

    if(argc != 3) 
    {
        printf("Uso: %s <nombre_archivo> -t|-b\n", argv[0]);
        exit(1);
    }
    if(strcmp(argv[2], "-t") == 0)
    {
        leerTxt(argv[1], navegador);
    }
    else if(strcmp(argv[2], "-b") == 0)
    {
        leerBin(argv[1], navegador);
    }
    else 
    {
        printf("Opción no reconocida: %s\n", argv[2]);
        exit(1);
    }
    printf("\nImpresión de la cola (categoría 1): ");
    imprimirListaDobleCirc(*(navegador->refscirc));
    printf("\nImpresión de la lista (categoría 2): ");
    imprimirListaDoble(*(navegador->refslin));

    navegar(navegador);

    return 0;
}

extern void insertarCola(cat1 dat1, refs *refscirc)
{
    nodo *nuevo;
    
    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible\n");
        exit(1);
    }
    
    nuevo->datos1 = dat1;
    if((refscirc->inicio == NULL) && (refscirc->fin == NULL))
    {
        nuevo->der = nuevo;
        nuevo->izq = nuevo;
        refscirc->inicio = nuevo;
        refscirc->fin = nuevo;
    }
    else{
        nuevo->izq = refscirc->fin;
        nuevo->der = refscirc->inicio;
        refscirc->fin->der = nuevo;
        refscirc->inicio->izq = nuevo;
        refscirc->fin = nuevo;
    }

    return;
}

extern void insertarListaDoble(refs *refslin, cat2 dat2)
{
    nodo *nuevo;

    nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }

    nuevo->izq = NULL;
    nuevo->der = NULL;
    nuevo->datos2 = dat2;

    if((refslin->inicio == NULL) && (refslin->fin == NULL))
    {
        refslin->inicio = nuevo;
        refslin->fin = nuevo;
    }
    else
    {
        nuevo->izq = refslin->fin;
        refslin->fin->der = nuevo;
        refslin->fin = nuevo;
    }

    return;
}

extern void leerTxt(char *nomArch, nav *nav)
{
    FILE *fp;
    cat1 datos1;
    cat2 datos2;

    fp = fopen(nomArch, "r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fscanf(fp, " %d\t %[^\t] %[^\t] %f\t %d\n", &datos1.clave, datos1.categoria, datos1.producto, &datos1.precio, &datos1.inventario) == 5)
    {
        if((strcmp("Electrónica", datos1.categoria) == 0) || (strcmp("Bebés", datos1.categoria) == 0) || (strcmp("Libros", datos1.categoria) == 0))
        {
            insertarCola(datos1, nav->refscirc);
        }
        else if((strcmp("Ropa", datos1.categoria) == 0) || (strcmp("Hogar", datos1.categoria) == 0) || (strcmp("Música", datos1.categoria) == 0))
        {
            printf(" %f\n", datos1.precio);
            datos2.clave = datos1.clave;
            strcpy(datos2.categoria, datos1.categoria);
            strcpy(datos2.producto, datos1.producto);
            datos2.precio = datos1.precio;
            datos2.inventario = datos1.inventario;
            insertarListaDoble(nav->refslin, datos2);
        }
    }
    fclose(fp);

    return;
}

extern void leerBin(char *nomArch, nav *nav)
{
    FILE *fp;
    cat1 datos1;
    cat2 datos2;

    fp = fopen(nomArch, "rb");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fread(&datos1, sizeof(cat1), 1, fp) == 1)
    {
        if((strcmp("Electrónica", datos1.categoria) == 0) || (strcmp("Bebés", datos1.categoria) == 0) || (strcmp("Libros", datos1.categoria) == 0))
        {
            insertarCola(datos1, nav->refscirc);
        }
        else if((strcmp("Ropa", datos1.categoria) == 0) || (strcmp("Hogar", datos1.categoria) == 0) || (strcmp("Música", datos1.categoria) == 0))
        {
            datos2.clave = datos1.clave;
            strcpy(datos2.categoria, datos1.categoria);
            strcpy(datos2.producto, datos1.producto);
            datos2.precio = datos1.precio;
            datos2.inventario = datos1.inventario;
            insertarListaDoble(nav->refslin, datos2);
        }
    }
    fclose(fp);

    return;
}

extern void imprimirListaDobleCirc(refs fila)
{
    fila.aux = fila.inicio;

    if((fila.inicio == NULL) && (fila.fin == NULL))
    {
        printf("\nNo puedo imprimir una lista vacía.\n");
    }
    else
    {
        do
       {
            printf("\nClaeve: %d", fila.aux->datos1.clave);
            printf("\tCategoría: %s", fila.aux->datos1.categoria);
            printf("\tProducto: %s", fila.aux->datos1.producto);
            printf("\tPrecio: %f\n\n", fila.aux->datos1.precio);
            printf("\tInventario: %d\n\n", fila.aux->datos1.inventario);
            fila.aux = fila.aux->der;
       }while(fila.aux != fila.inicio); 
    }

    return;
}

extern void imprimirListaDoble(refs nav)
{
    nav.aux = nav.inicio;

    if((nav.inicio == NULL) && (nav.fin == NULL))
    {
        printf("\nLista vacía.\n");
    }
    while(nav.aux != NULL)
    {
        printf("\nClaeve: %d", nav.aux->datos2.clave);
        printf("\tCategoría: %s", nav.aux->datos2.categoria);
        printf("\tProducto: %s", nav.aux->datos2.producto);
        printf("\tPrecio: %f\n\n", nav.aux->datos2.precio);
        printf("\tInventario: %d\n\n", nav.aux->datos2.inventario);
        nav.aux = nav.aux->der;
    }

    return;
}

extern void agregarCarrito()
{


}

extern void navegarCategoria1(nav *nav)
{
    char opc;
    int flag;

    nav->refscirc->aux = nav->refscirc->inicio;

    if((nav->refscirc->inicio == NULL) && (nav->refscirc->fin == NULL))
    {
        printf("\nNo puedo imprimir una lista vacía.\n");
    }
    else
    {
        do
        {
            printf("\nClave: %d", nav->refscirc->aux->datos1.clave);
            printf("\tCategoría: %s", nav->refscirc->aux->datos1.categoria);
            printf("\tProducto: %s", nav->refscirc->aux->datos1.producto);
            printf("\tPrecio: %f\n\n", nav->refscirc->aux->datos1.precio);
            printf("\tInventario: %d\n\n", nav->refscirc->aux->datos1.inventario);
            printf("a) <- Anterior\tb) Salir\tc) Agregar al carrito\td) Siguiente ->");
            printf("\n\nSeleccione una opción: ");
            scanf(" %c", &opc);
            if(opc == 'A' || opc == 'a'){
                flag = 0;
                nav->refscirc->aux = nav->refscirc->aux->izq;
            }
            if(opc == 'd' || opc == 'D'){
                flag = 0;
                nav->refscirc->aux = nav->refscirc->aux->der;
            }
            if(opc == 'B' || opc == 'b'){
                flag = 1;
            }
            if(opc == 'c' || opc == 'C'){
                flag = 0;
                // system("clear");
                if(nav->refscirc->aux->datos1.inventario == 0){
                    printf("El producto no está disponible por el momento.\n\n");
                }
                // else{
                //     agregarCarrito(&nav->refscirc->aux->datos1.inventario, refscirc.aux, &carr);
                // }
            }
        }while(flag == 0); 
    }

    return;
}

extern void navegarCategoria2(nav *nav)
{

    char opc;
    int flag = 0;

    nav->refslin->aux = nav->refslin->inicio;

    if((nav->refslin->inicio == NULL) && (nav->refslin->fin == NULL))
    {
        printf("\nLista vacía.\n");
    }
    while(flag != 1)
    {
        printf("\nClave: %d", nav->refslin->aux->datos2.clave);
        printf("\tCategoría: %s", nav->refslin->aux->datos2.categoria);
        printf("\tProducto: %s", nav->refslin->aux->datos2.producto);
        printf("\tPrecio: %f\n\n", nav->refslin->aux->datos2.precio);
        printf("\tInventario: %d\n\n", nav->refslin->aux->datos2.inventario);
        printf("a) <- Anterior\tb) Salir\tc) Agregar al carrito\td) Siguiente ->");
        printf("\n\nSeleccione una opción: ");
        scanf(" %c", &opc);
        if(opc == 'A' || opc == 'a')
        {
            flag = 0;
            if(nav->refslin->aux->izq == NULL){
                printf("Inicio de la lista. Ya no hay más elementos\n\n");
            }
            else{
                nav->refslin->aux = nav->refslin->aux->izq;
            }
        }
        if(opc == 'd' || opc == 'D')
        {
            flag = 0;
            if(nav->refslin->aux->der == NULL)
            {
                printf("Fin de la lista.\n\n");
            }
            else
            {
                nav->refslin->aux = nav->refslin->aux->der;
            }
        }
        if(opc == 'B' || opc == 'b')
        {
            flag = 1;
        }
        if(opc == 'c' || opc == 'C')
        {
            flag = 0;
            // system("clear");
            if(nav->refslin->aux->datos2.inventario == 0)
            {
                // system("clear");
                printf("Este producto no está disponible por el momento.\n\n");
            }
            // else
            // {
            //     agregarCarrito(&nav->refslin->aux->datos2.inventario, refslin.aux, &carr);
            // }
        }
    }
    return;
}


extern void navegar(nav nav)
{
    char opcion;
    int bandera;

    bandera = 0;

    do {
        printf("A) Visualizar categoría 1\nB) Visualizar categoría 2 \nC) Comprar\nD) Salir\n");
        printf("Seleccione una opción: ");
        scanf(" %c", &opcion);
        if(opcion == 'A' || opcion == 'a') {
            opcion = '\0';
            // system("clear");
            navegarCategoria1(&nav);
            // system("clear");
        }
        else if(opcion == 'B' || opcion == 'b'){
            opcion = '\0';
            // system("clear");
            navegarCategoria2(&nav);
            // system("clear");
        }
        // else if(opcion == 'C' || opcion == 'c'){
        //     opcion = '\0';
        //     mostrarCarrito(nav.carro);
        //     printf("\n\n");
        // }
        else if(opcion == 'D' || opcion == 'd'){
            bandera = 1;
        }
        else {
            // system("clear");
            printf("Por favor, seleccione una opción del menú.\n\n");
        }
    } while(bandera == 0);

    return;
}
