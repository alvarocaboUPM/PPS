#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

//Cabeceras
int peek(queue*);
void poll(queue*);

int peek(queue* cola){
    //return elemento en la cima de la pila
    return cola->first->data[0];
}

void poll(queue* cola){
//removes the object at the top
    //Suponemos l>0
    if(cola->first->len ==1){
        //Desencolamos el primero y lo liberamos
        node_t* primero = cola->first; //Salvamos su puntero
        cola->first =NULL; 
        free(primero);
    }
    else{
        node_t *primero = cola->first;
        //Adelantamos a todos una posición
        int i;
        for(i=0; i< cola->first->len;i++){
            //Adelantamos los datos
            primero->data[i]
        }
        
        
    }


}

