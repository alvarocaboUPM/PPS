/* Escribe un programa que lea enteros y los almacene en un array para imprimirlos en el 
   orden inverso. Tu programa admitirá un máximo de M enteros (pongamos 1000). Si en la 
   entrada estándar hay más de M enteros sólo se invertirán los M primeros. En el momento 
   en el que haya algo diferente a un entero, el programar invertirá todos los enteros leídos 
   hasta ese momento. */

#include <stdio.h> 
#include <stdlib.h> // Para NULL

#define M 1000 
int main(void) {
  int enteros[M];
  int elementos = 0;
  FILE *f;
  f = fopen("numeros.txt", "r");
  if(f!=NULL){
	  while (!(feof(f))) {
	    int a;
	    int check=fscanf(f, "%d", &a);
	    printf("%d\n",a);
	    if(check !=1||elementos == M){
	    		fclose(f);
				break;	
		}
			enteros[elementos] = a;
			printf("%d\n",a);
	    	elementos ++; 
	  }
	  while (elementos != -1) {
	    printf("Elemento: %d\n", enteros[elementos]);
	    elementos --;
	  	}
	
	  return 0;
  }
  else{
  	puts("Error en fopen");
	return 1;
  }
}
