#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    /*Cantidad de atomos*/

    float posicion[3][3],R[10][3],V[3][3];
    float a=4.0651,n=11;
    float RHO[3][3];
    float m=8;
    float sumaV;
    float sumaRHO,U;
    float c=53.581;


    /*CASO 1: FILA*/
    /*LLENAR POSICIONES*/
    for(float i=0; i<100 ;i++)
    {
        for (int fila=0; fila<3;fila++)
        {
            for(int columna=0;columna<3;columna++)
            {
                /*FIJAR EJE Y,Z EN 0*/
                if (columna==2 || columna==1)
                {
                    posicion[fila][columna]=0;
                }
                else if(fila==0 && columna==0)
                {
                    posicion[fila][columna]=0;
                }
                else
                {
                    posicion[fila][columna]=fila-i/100;
                }
                printf("%.2f\t", posicion[fila][columna]);
            }
        }
                printf("\n");
    }

    /*CALCULAR R*/
    printf("Distancias\n"); 
    for(float i=0; i<100 ;i++)
    {
        for (int fila=1;fila<3;fila++)
        {
            for(int columna=0;columna<3;columna++)
            {
                if(columna==fila)
                {
                    R[fila][columna]=0;
                }
                if (fila==1 && columna==0)
                {
                    R[fila][columna]=posicion[fila][columna];
                }
                if(fila>1 && fila!=columna)
                {
                    R[fila][columna]= sqrt(pow((posicion[fila][columna])-(posicion[columna][columna]),2)+pow((posicion[fila][columna+1]-posicion[columna][columna+1]),2)+pow((posicion[fila][columna+2]-posicion[columna][columna+fila]),2));
                }
                printf("%.2f\t", R[fila][columna]);
            }
        }
        printf("\n");
    }


    /*CALCULAR V*/
    for(float i=0; i<100 ;i++)
    {
        for (int fila=0;fila<3;fila++)
        {
            for(int columna=0;columna<3;columna++)
            {
                if(fila==columna || R[fila][columna]==0)
                {
                    V[fila][columna]=0;
                }
                else
                {
                    V[fila][columna]=pow(a/R[fila][columna],n);
                }
            }
            printf("\n");
        }
    }


    /*PRINT V*/
    printf("Valor de V:\n");
    for(float i=0; i<100 ;i++)
    {
        for (int fila=0;fila<3;fila++)
        {
            for(int columna=0;columna<3;columna++)
            {
                sumaV=sumaV+V[fila][columna];
                printf(" %.2f\t", V[fila][columna]);
            }
            printf("\n");
        }
    }
    printf("La suma de V es %f\n",sumaV);


    /*CALCULAR RHO*/
    for(float i=0; i<100 ;i++)
    {
        for (int fila=0;fila<3;fila++)
        {
            for(int columna=0;columna<3;columna++)
            {
                if(fila==columna || R[fila][columna]==0)
                {
                    RHO[fila][columna]=0;
                }
                else
                {
                    RHO[fila][columna]=pow(a/R[fila][columna],m);
                }
            }
        }    
        printf("\n");
    }


    /*PRINT RHO*/
    printf("Valor de RHO:\n");
    for (int fila=0;fila<3;fila++)
    {
        for(int columna=0;columna<3;columna++)
        {
            printf("%.2f\t", RHO[fila][columna]);
            sumaRHO=sumaRHO+RHO[fila][columna];
        }
        printf("\n");
    }
    printf("La suma de rho es %f\n", sumaRHO);


    /*CALCULAR EL POTENCIAL*/
    U=(0.5*sumaV)+sqrt(sumaRHO*c);
    printf("El potencial para el oro es: %f\n",U);


    return 0;
}