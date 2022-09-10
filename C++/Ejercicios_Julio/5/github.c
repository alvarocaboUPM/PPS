#include <stdio.h>

#define DIM 80

int main(int argc, char * argv[]){
	char x;	
	int sc = scanf("%c", &x);


	while(sc == 1){
		if(x == 32){
			printf(" ");
		}
		printf("%c", x);
		sc = scanf("%c", &x);
	}
	return 0;
}