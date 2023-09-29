/* 
@file darResultados.c
@brief  Este programa es un ejemplo para crear una lista
        de n alumnos con los siguientes datos: #cuenta,
        nombre, carrera, fecha de nacimiento y promedio.
        1) Desde la línea de comando, indique el tamaño 
           de alumnos a manipular.
            $./grupoAlumno.exe 10
        2) Con el dato del tamaño, genere una arreglo de alumnos
           utilizando ADM.
        3) Haga una función que permita capturar los n datos.
        4) Haga una función que reciba como argumento de I/O la 
           dirección de un elemento del arreglo y actualice los datos.
           La función se llamará actualizarDatos.
        5) Al final del programa llame a 2 funciones que guarden los datos
           datos de la lista de alumnos en un archivo de texto, lista.txt
           y otro en binario, lista.bin
        6) Compruebe que los datos en el archivo binario están guardados correctamente.
        7) Modifique el programa para que si el usuario ingresa n<=0 en la línea de comandos
           el programa lea la información del archivo de texto o binario y con la ayuda de asignación dinámica de memoria
           coloque correctamente los datos en memoria que esté referida o apuntada por el apuntador grupo 
@author Diego Altamirano 
@date 05/sep/2023
*/

#include "defTipos.h"

void capturarAlumnos(int tam, tipoAlumno grupo[]);
void imprimirGrupo(int tam, tipoAlumno grupo[]);
void actualizarDatos(tipoAlumno *alumnos);
int guardarArchTex(int tam, tipoAlumno grupo[]);
int guardarArchBin(int tam, tipoAlumno grupo[]);
int imprimirEnPantallaBinario(char nomArch[]);
void cargarBinMem(int tam, tipoAlumno grupo[], char nomArch[]);
void cargarTxtMem(int tam, tipoAlumno grupo[], char nomArch[]);
int contarAlumnosText(char nomArch[]);

int main(int argc, char *argv[])
{
    int tam, pos;
    tipoAlumno *grupo;
    char opcion;

    sscanf(argv[1], " %d", &tam);
    if(tam>0)
    {
        grupo = (tipoAlumno *)malloc(tam * sizeof(tipoAlumno));
        if(grupo==NULL)
        {
            printf("no hay suficiente memoria");
            exit(1);
        }
        capturarAlumnos(tam, grupo);
        printf("\nDeseas modificar a un usuario ['s'|'n']: \n");
        scanf(" %c", &opcion);
        if(opcion=='s')
        {
            printf("\nDame el número de alumno que desea actualizar: ");
            scanf(" %d",&pos);
            actualizarDatos(&grupo[pos-1]);
        }
        imprimirGrupo(tam, grupo);
        guardarArchTex(tam, grupo);
        guardarArchBin(tam, grupo);
        imprimirEnPantallaBinario("lista.bin");
    }
    else //lectura de los datos de los archivos
    {
            printf("\nQué datos deseas cargar en memoria: archivo binario ['b'] o texto ['t']: ");
            scanf(" %c",&opcion);
            if(opcion == 'b')
            {
                tam = imprimirEnPantallaBinario("lista.bin");
                grupo = (tipoAlumno*)malloc(tam*sizeof(tipoAlumno));
                if(grupo==NULL)
                {
                    printf("no hay suficiente memoria");
                    exit(1);
                }
                cargarBinMem(tam, grupo, "lista.bin");
                imprimirGrupo(tam,grupo);
            }
            else
            {
                if(opcion=='t')
                {
                    tam = contarAlumnosText("lista.txt");
                    grupo = (tipoAlumno*)malloc(tam*sizeof(tipoAlumno));
                    if(grupo==NULL)
                    {
                        printf("no hay suficiente memoria");
                        exit(1);
                    }                
                    cargarTxtMem(tam,grupo,"lista.txt");
                    imprimirGrupo(tam,grupo);
                }
                else
                {
                    printf("\nComando no válido.\n");
                }
            }
    }

    return 0;
}