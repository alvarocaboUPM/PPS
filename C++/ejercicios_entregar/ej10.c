// PPS - Programación en C
// Ejercicio #10 - Creación de un tipo de datos que implemente una pila (LIFO)

#include <stdio.h>
#include "pilavector.h"

// Elementos para probar la pila:
const tdata uno = {1, "mat_a1", "dni_a1", "nombre_a1", "mail_a1", 3.0f};
const tdata dos = {2, "mat_a2", "dni_a2", "nombre_a2", "mail_a2", 4.9f};
const tdata tres = {3, "mat_a3", "dni_a3", "nombre_a3", "mail_a3", 10.0f};

// Punto de entrada, probaremos el funcionamiento de la pila:
int main(void) {
  // Mostramos el tamaño de las estructuras de datos que usamos:
  puts("\nInfo consumo de memoria:\n");
  printf("\tTamaño tdata (struct pilainfo): %llu bytes\n", sizeof(tdata));
  printf("\tTamaño pila == array tdata[50]: %llu bytes\n", sizeof(tdata[50]));
  printf("\tTamaño tpv (struct pilavector): %llu bytes\n\n", sizeof(tpv));
  // Primero la inicializamos:
  puts("Inicializamos la pila...\n");
  puts("-------------------------------------------------------\n");
  init();
  printf("Debería estar vacía... ");
  if (!vacia()) {
    printf("[!] ¡No lo está!\n");
  } else {
    printf("sí.\n");
  }
  putchar('\n');
  // Mostramos su contenido, debería estar vacía:
  puts("-------------------------------------------------------\n");
  puts("Mostramos su contenido... (nada):\n");
  puts("-------------------------------------------------------\n");
  display();
  putchar('\n');
  puts("-------------------------------------------------------\n");
  // Añadimos un par de elementos:
  puts("Añadimos un par de elementos...\n");
  push(uno);
  push(dos);
  // Volvemos a mostrar su contenido:
  puts("-------------------------------------------------------\n");
  puts("Volvemos a mostrar su contenido (debería haber 2):\n");
  puts("-------------------------------------------------------\n");
  display();
  putchar('\n');
  puts("-------------------------------------------------------\n");

  // Extraemos el elemento de la cima y añadimos uno nuevo:
  puts("Extraemos el elemento de la cima...\n");
  puts("-------------------------------------------------------\n");
  tdata temp = pop();
  printf("pop() retorna:\n"
         "\tID: %d\n"
         "\tMatrícula: %s\n"
         "\tDNI: %s\n"
         "\tNombre: %s\n"
         "\tMail: %s\n\n", temp.id, temp.matricula, temp.dni, temp.nombre, temp.mail);
  puts("-------------------------------------------------------\n");
  puts("Añadimos uno nuevo...\n");
  push(tres);
  // Ahora la pila debería contener el 3º en la cima y debajo el 1º:
  puts("-------------------------------------------------------\n");
  puts("Ahora debería estar el 3º en la cima y debajo el 1º:\n");
  puts("-------------------------------------------------------\n");
  display();
  putchar('\n');
  puts("-------------------------------------------------------\n");
  // Vaciamos la pila:
  puts("Vaciamos la pila...\n");
  puts("-------------------------------------------------------\n");
  vaciar();
  printf("Debería estar vacía... ");
  if (vacia()) {
    printf("sí.\n");
  } else {
    printf("[!] ¡No lo está!\n");
  }
  putchar('\n');
  puts("-------------------------------------------------------\n");
  // Vamos a llenar la pila ahora:
  puts("Vamos a llenar la pila ahora...\n");
  for (int i = 0; i < MAXPILA; i++) {
    push(uno);
  }
  puts("-------------------------------------------------------\n");
  printf("Listo, debería estar llena... ");
  if (llena()) {
    printf("sí.\n");
  } else {
    printf("[!] ¡No lo está!\n");
  }
  putchar('\n');
  puts("-------------------------------------------------------\n");
  printf("Al estar llena no deberíamos poder añadir más... ");
  if (push(uno)) {
    printf("ok.\n");
  } else {
    printf("[!] WTF?!\n");
  }
  puts("\n-------------------------------------------------------\n\nFin.");
}
