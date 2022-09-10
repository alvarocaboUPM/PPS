#include <stdio.h>  /* printf */
#include <stdlib.h> // Para NULL y atoi
//atoi convierte char[] en int
#define MAX 80

void expandir(int);
int main(int argc, char** argv){
	if(argc < 2) //Comprobamos que se ha introducido arg
		return 1;
	int num = atoi(argv[1]);
	expandir(num);
	return 0;
}

void expandir(int n){
	char letra;
	while((letra = getchar())!= EOF){
		
		if(letra == ' '){
			//Escribimos espacios (incluyendo el ya escrito)
			int i;
			for(i=0;i<n;i++) printf(" "); 
		}
		printf("%c", letra);
	}
}