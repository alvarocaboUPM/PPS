#include <dirent.h>
#include <sys/stat.h>
/*
 * Descripción entradas de directorio
 */
typedef struct scandir {
 struct dirent entry;
 /*dirent.h
        ino_t  d_ino          file serial number
        char   d_name[256]    name of entry
        unsigned char   d_type         tipo
 */
 struct stat info;

} scandir_t;

typedef scandir_t *scandir_p;

typedef struct ascdir 
{
 scandir_p aadr; /* dirección array de scandir_t */
 int nent; /* nº de entradas en el array */
} scanarr_t;

/*
 * Función que devuelve en la dirección indicada por strmode
 * un string con los (9) permisos de una entrada
 * Los permisos son tres grupos de tres caracteres rwx
 * La información se obtiene del campo st_mode en stp
 */
void smode (char *strmode, struct stat stp);

/*
 * Función que recupera en un array las entradas contenidas en
 * un directorio cuyo path absoluto se suministra en el argumento dirp
 * La función requiere que el último carácter del path sea '/'
 * Dicho array es construido dinámicamente en la propia función
 * de modo que en scptr la función devuelve un puntero a scanarr_t
 * 
 * De cara al control de errores la función devuelve un valor positivo
 * si la ejecución es correcta o, en caso de error, un valor negativo
 */
int pps_scandir(scanarr_t *scptr, const char *dirp);
