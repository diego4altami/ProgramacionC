#include <stdio.h>

int es_falsa(int valor) {
    return !valor;
}

int main() {
    char* paradoja = "Esta oracion es falsa.";
    int resultado = es_falsa(0);

    printf("%s\n", resultado ? "Verdadero" : "Falso");

    return 0;
}
