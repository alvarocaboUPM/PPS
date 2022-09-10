#include <stdio.h>  /* printf */
#include <stdlib.h> // Para NULL y atoi
//atoi convierte char[] en int
#define MAX 80


int main(int argc, char** argv){
	if(argc==0) return -1;
	char text[MAX];
	int space= atoi(argv[1]);
	puts("Texto: ");
	gets(text);
	int size= 0;
	while(text[size]!=NULL) size++;
	printf("SIZE -> %d\n", size);
    ///////////////////////////////
  	char c; int i, elementos=0;
	 while(elementos!=size){
	 	c=text[elementos];
			putchar(c);
		if(c==32){
			for(i=0;i<=space; i++)
			putchar(' ');
			}
		elementos++;
	  }
	
	return 0;
	}