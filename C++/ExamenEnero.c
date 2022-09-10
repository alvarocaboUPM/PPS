#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "scandir.h"

void a_lsdir(scanarr_t* array_files, int i1, int i2);

int main( int argc, char* argv[])
{
    //Comprobamos nº de argumentos
    if(argc!=2) return -1;
    
    //Comprobamos que finaliza con un '/'
    char* path = (char*)malloc(sizeof(char));
    strcpy(path,argv[1]); 
    int l = strlen(path);
    char barra = path[l-1]; //Último char antes del '\0'

    if(barra != '/'){
        path = (char*)realloc(path, l+2); //FALLO (l+1 en vez de l+2)
        path[l] = '/';
    }

    scanarr_t* array_files = malloc(sizeof(scanarr_t)); 
    pps_scandir(array_files, path);
    //Se van a leer strlen(array_files) entradas
    printf("a_lsdir en la ruta: %s\n", path);
    printf("========\n");
    a_lsdir(array_files, 1, array_files->nent);

    //Liberamos memoria
    free(path);
    free(array_files);
    return 0;
}

void a_lsdir(scanarr_t* array_files, int i1, int i2)
{
/*
 * Funcion que muestra el nombre del fichero, el tamaño en bytes y los
 * tres grupos de permisos de las entradas en el rango (i1,i2) de filas
 * del array (tipo scanarr_t) */

    //Precondición: 0 < i1,i2 < nº entradas; i1<i2
    if(i1>=i2 || i1<1 || i2<2 || i2 > array_files->nent){
        exit (-1); //FALLO (OLVIDAR PARÉNTESIS)
    }

    //Guardamos la dirección del array
    scandir_p array = array_files->aadr;
    scandir_t file; //row de trabajo
    int i; //Counter
    char* permisos; 

    for(i=i1-1; i<i2;i++){
        file = array[i]; //Guardamos el dato de trabajo
        //Creamos los permisos
        permisos = calloc(9, sizeof(char)); //9 caracteres
        smode(permisos, file.info);
        //Distinguimos el tipo
        if(file.entry.d_type == DT_DIR) //FALLO (USAR CONSTANTE)
        printf("%s\t DT_DIR\t Permisos: %s\n", file.entry.d_name, permisos);
        else{
            printf("%s\t %d KB\t Permisos: %s\n", file.entry.d_name, (int)file.info.st_size, permisos);
        }
        free(permisos);
    }

}


