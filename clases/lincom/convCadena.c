/* 
@file convCadena.c
@brief  este ejemplo es para entender sscanf y sprintf
@author Diego Altamirano 
@date 22/ago/2023
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    float peso, altura;
    char cad1[20],cad2[20],frase[80];

    printf("\nEscribe una frase que tenga la altura y el peso de alguien: ");
    scanf(" %[^\n]",frase);
    sscanf(frase, "%s %f %s %f",cad1, &altura, cad2, &peso);
    printf("\nEsta persona %s estos %f kg y %s estos %f metros.\n", cad2, peso, cad1, altura);
    
    return 0;
}