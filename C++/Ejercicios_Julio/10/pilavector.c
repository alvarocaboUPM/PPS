#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilavector.h"

/* La pila implementada como un struct con dos campos, datos y top */
tpv mipila;

/*
 * Inicializar todos los contenedores en la pila a 0 y la cima a -1 (indica vacía)
 * Opción con memset()
 */
void init(void) {
   memset((void *) &mipila, 0, sizeof(tpv));
   mipila.top = -1;     /*// pila vacía*/
}

/*
 * Restaurar la pila al estado inicial
 * Innecesario escribir nuevo código
 */
void vaciar(void) {
	init();
}

/*
 * Comprobar si está llena. Devuelve 1 si lo está y 0 en caso contrario
 * Puesto que no hay item especial en la pila, está llena si top == MAXPILA-1
 */
int llena(void) {
/*
 * item especial externo => top en [-1,MAXPILA-1]
 */
   return (mipila.top == MAXPILA-1);
}

/*
 * Comprobar si está vacía. Devuelve 1 si lo está y 0 en caso contrario
 * Pila vacía si mipila.top == -1
 */
int vacia(void) {
/*
 * item especial externo => top en [-1,MAXPILA-1]
 */
   return (mipila.top == -1);
}

/*
 * Operación push: apila item
 * Devuelve 0 si apila y -1 en caso contrario
 */
int push(tdata item) {

	if (mipila.top < MAXPILA-1) {
		mipila.top++;
		mipila.datos[mipila.top] = item;
		return 0;
	}
	return -1;
}

/*
 * Operación pop: devuelve el contenido en la cima de la pila
 * En esta implementación de la pila NO hay un item especial que marca vacía
 */
tdata pop(void) {
   tdata item;

   if (mipila.top > -1) {
	   item = mipila.datos[mipila.top];
	   mipila.top--;
   }
   else
	   item.id = -1;       /* Simula item especial que marca pila vacía */
   return item;
}

/*
 * Mostrar el contenido de la pila
 */
void display(void) {
   int i;
   
   if (mipila.top == -1)
      printf("\nPila vacía!");
   else {
	  printf("Contenido pila:\n");
      for (i = mipila.top; i >= 0; i--) {
          printf("\tID: %d\n", mipila.datos[i].id);
          printf("\tMatrícula: %s\n", mipila.datos[i].matricula);
          printf("\tAlumno: %s\n", mipila.datos[i].nombre);
          printf("\tMail: %s\n", mipila.datos[i].mail);
          printf("\tNota: %f\n", mipila.datos[i].nota);
      }
   }
}