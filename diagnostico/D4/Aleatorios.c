#include <stdio.h>

int main() {
    int arreglo[5];  // Declarar un arreglo de 5 elementos
    
    // Llenar el arreglo con números del 1 al 10, tomando cada dos números
    for (int i = 0, j = 1; i < 5; i++, j += 2) {
        arreglo[i] = j;
    }

    // Imprimir el contenido del arreglo
    for (int i = 0; i < 5; i++) {
        printf("%d ", arreglo[i]);
    }
    
    return 0;
}