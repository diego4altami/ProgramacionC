/* 
@file darResultados.c
@brief  Ese archivo tiene  las funciones externas que son
        utilizadas por el programa grupoAlumnos.c
@author Diego Altamirano 
@date 05/sept/2023
*/

#include "defTipos.h"

extern int guardarArchTex(int tam, tipoAlumno grupo[])
{
    int guardados = 0,i=0;
    FILE *fp;

    fp = fopen("lista.txt","w");
    for(i=0;i<tam;i++)
    {
        fprintf(fp,"%i \t", grupo[i].numCta);
        fprintf(fp,"%s \t", grupo[i].nombre);
        fprintf(fp,"%s \t", grupo[i].carrera);
        fprintf(fp,"\t %i/", grupo[i].fecha.dia);
        fprintf(fp,"%i/", grupo[i].fecha.mes);
        fprintf(fp,"%i \t", grupo[i].fecha.anio);
        fprintf(fp,"%f \t \n", grupo[i].promedio);
    }
    fclose(fp);
    guardados = i;

    return 0;
}

extern int guardarArchBin(int tam, tipoAlumno grupo[])
{
    int guardados = 0,i=0;
    FILE *fp;

    fp = fopen("lista.bin","w+b");
    if(fp==NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    for(i=0; i<tam; i++)
    {
        fwrite(&grupo[i],sizeof(tipoAlumno), 1, fp);
    }
    fclose(fp);
    guardados = i;

    return guardados;
}

extern void capturarAlumnos(int tam, tipoAlumno grupo[])
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("\nDame la cuenta: ");
        scanf("%d", &grupo[i].numCta);
        printf("\nDame el nombre: ");
        scanf(" %[^\n]", grupo[i].nombre);
        printf("\nDame la carrera: ");
        scanf(" %[^\n]", grupo[i].carrera);
        printf("\nDame fecha de nacimiento: ");
        scanf("%d/%d/%d", &grupo[i].fecha.dia,&grupo[i].fecha.mes,&grupo[i].fecha.anio);
        printf("\nDame el promedio: ");
        scanf("%f", &grupo[i].promedio);
    }

    return;
}


extern void imprimirGrupo(int tam, tipoAlumno grupo[])
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("\n%d.- %i %s %s", i+1, grupo[i].numCta,grupo[i].nombre,grupo[i].carrera);
        printf("%d/%d/%d %f\n",grupo[i].fecha.dia,grupo[i].fecha.mes,grupo[i].fecha.anio,grupo[i].promedio);
    }

    return;
}

extern void actualizarDatos(tipoAlumno *alumno)
{
    printf("\nIngresa los datos que desea actualizar. \n");
    printf("\nDame el número de cuenta: \n");
    scanf("%d", &alumno->numCta);
    printf("\nDame el nombre: \n");
    scanf(" %[^\n]", alumno->nombre);
    printf("\nDame la carrera: \n");
    scanf(" %[^\n]", alumno->carrera);
    printf("\nDame fecha de nacimiento: dd/mm/aaaa ");
    scanf("%d/%d/%d", &alumno->fecha.dia, &alumno->fecha.mes, &alumno->fecha.anio);
    printf("\nDame el promedio: ");
    scanf("%f", &alumno->promedio);

    return;
}

extern int imprimirEnPantallaBinario(char nomArch[])
{
    tipoAlumno alumno;
    FILE *fp;
    int numAlumnos =0;

    fp = fopen(nomArch,"r+b");
    if(fp ==NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    while(fread(&alumno, sizeof(tipoAlumno),1,fp)==1)
    {
        printf("\n Alumno: %s, Cuenta %d, Promedio: %f \n",alumno.nombre,alumno.numCta,alumno.promedio);
        numAlumnos++;
    }
    printf("\nEl archivo contiene %d alumnos\n", numAlumnos);
    fclose(fp);

    return numAlumnos;
}

extern void cargarBinMem(int tam, tipoAlumno grupo[], char nomArch[])
{
    int i;
    FILE *fp;
    fp = fopen(nomArch,"r+b");
    if(fp ==NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    for(i = 0; i < tam; i++)
    {
        fread(&grupo[i],sizeof(tipoAlumno),1,fp);
    }
    fclose(fp);

    return;
}

extern int contarAlumnosText(char nomArch[])
{
    int tam=0;
    char renglon[200];
    tipoAlumno alumno;
    FILE *fp; 

    fp = fopen(nomArch,"r");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }    
    while(fscanf(fp," %[^\n]",renglon) == 1)
    {
        tam++;
    }
    fclose(fp);

    return tam;
}

extern void cargarTxtMem(int tam, tipoAlumno grupo[], char nomArch[])
{
    int i;
    FILE *fp;
    fp = fopen(nomArch,"r");
    if(fp ==NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    for(i = 0; i < tam; i++)
    {
        fscanf(fp,"%d\t", &grupo[i].numCta);
        fscanf(fp," %[^\t]", grupo[i].nombre);
        fscanf(fp," %[^\t]", grupo[i].carrera);
        fscanf(fp,"%d/%d/%d\t", &grupo[i].fecha.dia,&grupo[i].fecha.mes,&grupo[i].fecha.anio);
        fscanf(fp,"%f\n", &grupo[i].promedio);
    }
    fclose(fp);

    return;
}

extern int contarAlumnos(char nomArch[])
{
    int tamArch, num;
    FILE *fp;

    fp = fopen(nomArch,"r+b");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
    }
    fseek(fp,0,SEEK_END);
    tamArch = ftell(fp);
    num = tamArch/sizeof(tipoAlumno);
    fclose(fp);

    return num;
}

extern void actualizarAlumno(int pos,char nomArch[])
{
    FILE *fp;
    int tam, numAlumnos;
    tipoAlumno alumno;

    actualizarDatos(&alumno);
    fp = fopen(nomArch,"r+b");
        if(fp == NULL)
        {
            printf("\nArchivo no disponible.\n");
        }
    fseek(fp,(pos-1)*sizeof(tipoAlumno),SEEK_SET);
    fwrite(&alumno,sizeof(tipoAlumno), 1, fp);
    fclose(fp);

    return; 
}

extern int retotnatValor(char nomArch[])
{
    FILE *fp;
    int tamArch, num;

    fp = fopen(nomArch, "r+b");
    if(fp == NULL)
    {
        printf("\nArchivo no disponible.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    tamArch = ftell(fp);
    num = tamArch/sizeof(tipoAlumno);
    fclose(fp);

    return num;
}