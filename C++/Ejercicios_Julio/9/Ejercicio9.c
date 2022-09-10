#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "notas.h"

lista_notas* lectura(char* filename, int*len);
void liberar(lista_notas*);

int main( int argc, char* argv[] ){
    lista_notas* milista; //Lista (Sin ordenar)
    int l; //Parámetro de salida que guardará la longitud de la lista

    //Lectura del archivo pasado por parámetro
    milista=lectura(argv[1],&l);
    lista_notas* head = milista;
    //Leemos la lista (Prueba)
    while(milista->siguiente !=NULL){
        if(milista->nota<5)
        printf("%s %s %d \n", milista->nombre, milista->apellido, milista->nota);
        milista=milista->siguiente;
    }

    //Leemos la lista (Prueba)
    while(head->siguiente !=NULL){
        if(head->nota>=5)
        printf("%s %s %d \n", head->nombre, head->apellido, head->nota);
        //Desencolamos
        head=head->siguiente;
    }

return 0;
}

lista_notas * lectura(char* filename, int*len){
    /*Esta función lee un archivo formateado [nombre][apellido][nota], 
    crea un array de lineas de texto y devuele en la variable l 
    el nº de lineas que ha leido*/

    //Puntero de cabecera de lista (valor de retorno)
    lista_notas *head=NULL;
    

    //Puntero al nodo de trabajo
    lista_notas *next=NULL;
   

    //Puntero que guarda el ptr anterior
    lista_notas *pre=NULL;
    
    //1. Abrimos archivo
    FILE* f; 
    f = fopen(filename, "r");
    //No es necesario control de errores
    if(f == NULL) exit (1);

    //2. Definimos los maxsizes
    int maxNom = 50;
    int maxAp = 100;
    
    int lineMax= maxNom+maxAp+sizeof(int)+ 2;
    
    //3. Incializamos:
    char buffer[lineMax]; //buffer de lectura
    int i=0; //Contador de caracteres leidos
    const char delim[] = " ";

    //4. Bucle de lectura
    while(fgets(buffer, lineMax, f)){
        //Quitamos los '\n' del final
        int l= strlen(buffer);
        buffer[l+1] = '\0';

        //Reservamos espacio para la linea
        char* line = (char *)malloc((l+1) * sizeof(char));
        
        //Guardamos el buffer en memoria
        strcpy(line, buffer);
        
        char **elements = (char **)malloc(3 * sizeof(char*)); //Guardamos 3 punteros
        char *ptr = strtok(line, delim);
        int j=0;

        while(ptr != NULL)
        {
            elements[j]= ptr;
            ptr = strtok(NULL, delim);  //Siguiente llamada a strtok
            j++;
        }

        /*Elementos (char*):
        [0] -> nombre
        [1] -> ap
        [2] -> nota
        */

        //4.1 Head es null
        if(head==NULL){
            head = (struct notas *)malloc(sizeof(struct notas));

            head->nombre = elements[0];
            head->apellido = elements[1];
            
            head->nota = atoi(elements[2]); //atoi(string) -> int

            next = (struct notas *)malloc(sizeof(struct notas));
            head ->siguiente =next;
            i++;
            //printf("HEAD SIGUIENTE: %p\n", head ->siguiente);
        }
        else{
            //llenamos el primer nodo
            //printf("SIGUIENTE: %p\n", next);
            next->nombre= elements[0];
            //printf("NOMBRE -> %s\n",next->nombre);
            next->apellido = elements[1];
        
            next->nota = atoi(elements[2]);; //atoi(string) -> int
            //printf("NOTA -> %d\n",next->nota);
            next->siguiente = NULL;
            
            //guardamos su direccion
            pre = next;
            //printf("NOM: %s\n", pre->nombre);
            //reutilizamos la variable para crear uno nuevo
            next= (lista_notas *)malloc(sizeof(lista_notas));
            pre->siguiente=next;
            //printf("SIGUIENTE LINKED: %p\n", pre->siguiente);
            i++;
        }
        *len = i;
        free(elements);
    }
    fclose(f);
    return head;
}

void liberar(lista_notas* cola){
    lista_notas* ptr;
    while (cola != NULL)
    {
       ptr = cola;
       cola = cola->siguiente;
       free(ptr);
    }
}

