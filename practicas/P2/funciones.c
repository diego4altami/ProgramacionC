#include "tiposTienda.h"

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

extern void navegarCategoria1(refs refscirc)
{
    char opc;
    int flag;

    refscirc.aux = refscirc.inicio;

    if((refscirc.inicio == NULL) && (refscirc.fin == NULL))
    {
        printf("\nNo puedo imprimir una lista vacía.\n");
    }
    else
    {
        do
        {
            printf("\nClave: %d", refscirc.aux->datos1.clave);
            printf("\tCategoría: %s", refscirc.aux->datos1.categoria);
            printf("\tProducto: %s", refscirc.aux->datos1.producto);
            printf("\tPrecio: %f\n\n", refscirc.aux->datos1.precio);
            printf("\tInventario: %d\n\n", refscirc.aux->datos1.inventario);
            printf("a) <- Anterior\tb) Salir\tc) Agregar al carrito\td) Siguiente ->");
            printf("\n\nSeleccione una opción: ");
            scanf(" %c", &opc);
            if(opc == 'A' || opc == 'a'){
                flag = 0;
                refscirc.aux = refscirc.aux->izq;
            }
            if(opc == 'd' || opc == 'D'){
                flag = 0;
                refscirc.aux = refscirc.aux->der;
            }
            if(opc == 'B' || opc == 'b'){
                flag = 1;
            }
            if(opc == 'c' || opc == 'C'){
                flag = 0;
                // system("clear");
                if(refscirc.aux->datos1.inventario == 0){
                    printf("El producto no está disponible por el momento.\n\n");
                }
                else{
                    agregarCarrito(&refscirc.aux->datos1.inventario, refscirc.aux, &carr);
                }
            }
        }while(flag == 0); 
    }

    return;
}

extern void navegarCategoria2(refs refslin)
{

    char opc;
    int flag = 0;

    refslin.aux = refslin.inicio;

    if((refslin.inicio == NULL) && (refslin.fin == NULL))
    {
        printf("\nLista vacía.\n");
    }
    while(flag != 1)
    {
        printf("\nClave: %d", refslin.aux->datos2.clave);
        printf("\tCategoría: %s", refslin.aux->datos2.categoria);
        printf("\tProducto: %s", refslin.aux->datos2.producto);
        printf("\tPrecio: %f\n\n", refslin.aux->datos2.precio);
        printf("\tInventario: %d\n\n", refslin.aux->datos2.inventario);
        printf("a) <- Anterior\tb) Salir\tc) Agregar al carrito\td) Siguiente ->");
        printf("\n\nSeleccione una opción: ");
        scanf(" %c", &opc);
        if(opc == 'A' || opc == 'a')
        {
            flag = 0;
            if(refslin.aux->izq == NULL){
                printf("Inicio de la lista. Ya no hay más elementos\n\n");
            }
            else{
                refslin.aux = refslin.aux->izq;
            }
        }
        if(opc == 'd' || opc == 'D')
        {
            flag = 0;
            if(refslin.aux->der == NULL)
            {
                printf("Fin de la lista.\n\n");
            }
            else
            {
                refslin.aux = refslin.aux->der;
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
            if(refslin.aux->datos2.inventario == 0)
            {
                // system("clear");
                printf("Este producto no está disponible por el momento.\n\n");
            }
            else
            {
                agregarCarritocat2(&refslin.aux->datos2.inventario, refslin.aux, &carr);
            }
        }
    }
    return;
}



extern void navegar(nav *nav)
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
            navegarCategoria1(*(nav->refscirc));
            // system("clear");
        }
        else if(opcion == 'B' || opcion == 'b'){
            opcion = '\0';
            // system("clear");
            navegarCategoria2(*(nav->refslin));
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