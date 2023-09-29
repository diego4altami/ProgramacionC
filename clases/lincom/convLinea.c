/* 
@file convLinea.c
@brief  Haga un ejemplo que lea de la línea de comandos estos datos:
        $./convLinea.exe <nombre> <peso> <estatura> 
        A partir de los datos de la línea de comandos, haga lo siguiente:
        1)Construya esta frase y haga que se imprima en pantalla:
         "Conozco a <nombre>, el mide <estatura> y pesa <peso>."
@author Diego Altamirano 
@date 22/ago/2023
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    float estatura, peso;
    char nombre[40],frase[150];
    
    sscanf(argv[1],"%s", nombre);
    sscanf(argv[2],"%f", &peso);
    sscanf(argv[3],"%f", &estatura);

    sprintf(frase,"Conozco a %s, el mide %f y pesa %f.", nombre, estatura, peso);
    printf("\n%s\n",frase);
    return 0;
}