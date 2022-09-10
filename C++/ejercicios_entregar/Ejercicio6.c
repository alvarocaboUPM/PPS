#include <stdio.h>  /* printf */
#include <stdlib.h> // Para NULL y atoi

#define MAX 79
 int main(){
	char cadena[MAX], c, backslash; int line_size=0;
    int i, puesto; backslash ='\\';
	int check=0;
	///////////////Read Input//////////////////////
	puts("Escriba el string a transformar: ");
	gets(cadena); 
	int size= 0;
	while(cadena[size]!=NULL){
	/*OK  -> printf("%c\n", cadena[size]);*/
	size++;
	}
	printf("SIZE --> %d\n", size);
	char resultado[size];
	//////////////Cambiar elementos/////////////////
	while (line_size!=size){
		puesto=0;
	    c= cadena[line_size]; 
			if(check==1){
			    switch(c){
			     case 116: resultado[line_size]='\t';
			     		     check=0; puesto=1;
				 		   break;
			     case 110:  resultado[line_size]='\n';
			     			 check=0; puesto=1;
				            break;
				 default: resultado[line_size]=' ';
				}
			}
		if(c==backslash){check=1; resultado[line_size]=' ';}
		 
		if(puesto!=1&&check!=1) resultado[line_size]=c;
		//printf("En el char: %c en linea: %d, con check: %d--> resultado: %c\n", c, line_size,check, resultado[line_size]);
		printf("%c", resultado[line_size]);
		line_size++;
	}
	return 0;
	}
