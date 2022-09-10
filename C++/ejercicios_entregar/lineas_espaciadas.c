
/*
Realice un programa "lineas_espaciadas.c" que reciba como entrada el nombre de un
fichero texto y que, en salida estándar, muestre el contenido de dicho fichero a la vez que
añade una línea en blanco después de cada salto de línea.
*/
#include <stdio.h> 
#include <stdlib.h>

#define MAX 80
void lectura(char filename[]){
  FILE *f;
  f = fopen(filename, "r");
  ///////////////////////////////
  char line[80];
  int elementos=0;
  if(f==NULL){
  	puts("ERROR");
	exit (EXIT_FAILURE);}
  else{
	  while (feof(f)==0) { //ciclo de lectura
	    int check = fscanf(f, "%[^\n]", line);
	    if(check !=1||elementos == MAX){
	    		fclose(f);
				break;	
		}
		printf("%s", line);	
		puts("\n");
		fgetc(f);
		elementos++;
	  }
	}
 }
 
int main(){
	char filename[MAX];
	scanf("%s",filename);
	lectura(filename);
	return 0;
}


