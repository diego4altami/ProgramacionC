/* 
@file darResultados.c
@brief  Ese archivo tiene  las funciones externas que son
        utilizadas por el programa invertirFrase.c
@author Diego Altamirano 
@date 23/sept/2023
*/

#include "tipos.h"

extern nodo *leerDatos(char nomArch[])
{
    FILE *fp
    nodo *pt;
    tipoAlumno alumno[1];

    pt=NULL;

    fp = fopen(nomArch,"r");
    if(fp ==NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    
    while()
    {
        fscanf(fp," %[^\t]", alumno[1].nombre);
        fscanf(fp,"%f\t", alumnos[1].calCalc);
        fscanf(fp,"%f\t", alumnos[1].calFis);
        fscanf(fp,"%f\t", alumnos[1].calCalc);
        
        pt = push(alumno,pt);
    }

    fclose(fp);

    return pt;
}
