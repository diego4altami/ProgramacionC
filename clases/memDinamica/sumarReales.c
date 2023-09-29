#include "defTipos.h"

extern float sumarReales( float arreglo[], int tam)
{
    float suma=0;
    int i;
    float real;

    for(i = 0; i < tam; i++)
    {
        printf("\nDame el real[%i]: \n",i);
        scanf("%f",&real);
        suma+=real;
    }
    return suma;
}