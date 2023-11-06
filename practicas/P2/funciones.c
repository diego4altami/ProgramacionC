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

extern void imprimirListaDobleCirc(refs refscirc)
{
    refscirc.aux = refscirc.inicio;

    if((refscirc.inicio == NULL) && (refscirc.fin == NULL))
    {
        printf("\nNo puedo imprimir una lista vacía.\n");
    }
    else
    {
        do
       {
            printf("\nClaeve: %d", refscirc.aux->datos1.clave);
            printf("\tCategoría: %s", refscirc.aux->datos1.categoria);
            printf("\tProducto: %s", refscirc.aux->datos1.producto);
            printf("\tPrecio: %f\n\n", refscirc.aux->datos1.precio);
            printf("\tInventario: %d\n\n", refscirc.aux->datos1.inventario);
            refscirc.aux = refscirc.aux->der;
       }while(refscirc.aux != refscirc.inicio); 
    }

    return;
}

extern void imprimirListaDoble(refs refslin)
{
    refslin.aux = refslin.inicio;

    if((refslin.inicio == NULL) && (refslin.fin == NULL))
    {
        printf("\nLista vacía.\n");
    }
    while(refslin.aux != NULL)
    {
        printf("\nClaeve: %d", refslin.aux->datos2.clave);
        printf("\tCategoría: %s", refslin.aux->datos2.categoria);
        printf("\tProducto: %s", refslin.aux->datos2.producto);
        printf("\tPrecio: %f\n\n", refslin.aux->datos2.precio);
        printf("\tInventario: %d\n\n", refslin.aux->datos2.inventario);
        refslin.aux = refslin.aux->der;
    }

    return;
}

extern nodocar *push(nodocar *pt, datcar data)
{
    nodocar *nuevo;

    nuevo = (nodocar *)malloc(sizeof(nodocar));
    if(nuevo == NULL)
    {
        printf("\nNo hay memoria disponible.\n");
        exit(1);
    }
    nuevo->datos = data;
    nuevo->next = pt;
    pt = nuevo;

    return pt;
}

extern void agregarCarrito1(nav *nav)
{
    int compra;
    datcar articulo;

    printf("El inventario es: %i\n", nav->refscirc->aux->datos1.inventario);

    printf("El prod es: %s\n", nav->refscirc->aux->datos1.producto);
    printf("¿Cuántos artículos desea agregar?\n");
    scanf(" %i", &compra);
    if(compra > nav->refscirc->aux->datos1.inventario)
    {
        printf("\n No tenemos tantos en la tienda, vuelva a intentar con una menor cantidad\n");
    }
    else
    {
        nav->refscirc->aux->datos1.inventario = nav->refscirc->aux->datos1.inventario - compra;
        strcpy(articulo.categoria, nav->refscirc->aux->datos1.categoria);
        strcpy(articulo.producto, nav->refscirc->aux->datos1.producto);
        articulo.precio = nav->refscirc->aux->datos1.precio;
        articulo.cantidad = compra;
        nav->iniciocar = push(nav->iniciocar, articulo);
    }

    return;
}

extern void agregarCarrito2(nav *nav)
{
    int compra;
    datcar articulo;

    printf("El inventario es: %i\n", nav->refslin->aux->datos2.inventario);

    printf("El prod es: %s\n", nav->refslin->aux->datos2.producto);
    printf("¿Cuántos artículos desea agregar?\n");
    scanf(" %i", &compra);
    if(compra > nav->refslin->aux->datos2.inventario)
    {
        printf("\n No tenemos tantos en la tienda, vuelva a intentar con una menor cantidad\n");
    }
    else
    {
        nav->refslin->aux->datos2.inventario = nav->refslin->aux->datos2.inventario - compra;
        strcpy(articulo.categoria, nav->refslin->aux->datos2.categoria);
        strcpy(articulo.producto, nav->refslin->aux->datos2.producto);
        articulo.precio = nav->refslin->aux->datos2.precio;
        articulo.cantidad = compra;
        nav->iniciocar = push(nav->iniciocar, articulo);
    }

    return;
}

extern void mostrarCarrito(nodocar *pt)
{
    printf("\n Artículos guardados en el carrito:\n");
    if(pt != NULL)
    {
        while(pt != NULL)
        {
            printf(" %s", pt->datos.producto);
            pt = pt->next;
        }
    }
    else
    {
        printf("\nLista vacía\n");
    }
    return;
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
            if(opc == 'A' || opc == 'a')
            {
                flag = 0;
                printf(" Esta es la bandera :%i\n", flag);
                nav->refscirc->aux = nav->refscirc->aux->izq;
            }
            if(opc == 'd' || opc == 'D')
            {
                flag = 0;
                printf(" Esta es la bandera :%i\n", flag);
                nav->refscirc->aux = nav->refscirc->aux->der;
            }
            if(opc == 'B' || opc == 'b')
            {
                flag = 1;
                printf(" Esta es la bandera :%i\n", flag);
            }
            if(opc == 'c' || opc == 'C')
            {
                flag = 0;
                // system("clear");
                if(nav->refscirc->aux->datos1.inventario == 0)
                {
                    printf("El producto no está disponible por el momento.\n\n");
                }
                else
                {
                    agregarCarrito1(nav);
                }
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
            else
            {
                agregarCarrito2(nav);
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
            navegarCategoria1(nav);
            // system("clear");
        }
        else if(opcion == 'B' || opcion == 'b'){
            opcion = '\0';
            // system("clear");
            navegarCategoria2(nav);
            // system("clear");
        }
        else if(opcion == 'C' || opcion == 'c'){
            opcion = '\0';
            mostrarCarrito(nav->iniciocar);
            printf("\n\n");
        }
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