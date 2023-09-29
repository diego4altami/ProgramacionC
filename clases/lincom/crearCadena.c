/* 
@file crearCadena.c
@brief  este es un ejemplo de sprintf 
@author Diego Altamirano 
@date 22/ago/2023
*/
#include <stdio.h>

int main(void)
{
    float peso, altura;
    char nombre[40], cadena[100];

    printf("\nDame el nombre: ");
    scanf("%[^\n]",nombre);
    printf("\nDame su peso y altura: ");
    scanf("%f %f",&peso, &altura);
    sprintf(cadena, "Esta persona se llama %s y pesa %f y mide %f.",nombre,peso, altura);
    printf("\n%s\n",cadena);
    return 0;
}