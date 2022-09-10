/*
Realice un programa (maxmin) que reciba como entra el nombre de un fichero de texto
que contiene un número real (float) por línea y que después de leerlo escriba por pantalla
el valor máximo y el valor mínimo en una sola línea (formato %10.2f). 

- Si el fichero está vacío -> debe escribir los valores 0.00 y 0.00. 
- Suponer que los números del fichero son números reales válidos. 
-Hay que comprobar que en la llamada se ha pasado un argumento de entrada, en caso contrario terminar sin imprimir nada y devolver al sistema operativo
el número -1. Si el fichero no se puede leer también se devolverá el número -1 sin imprimir nada
*/

#include <stdio.h> 
#include <stdlib.h> // Para NULL

#define MAX 1000
int main(void) {
  FILE *f;
  f = fopen("num_nulo.txt", "r");
  
  float num[MAX];
  float max=0.00; float min=0.00;
  int elementos = 0;
  
  if(leer(f)==0){
	  //for (int i = elementos - 1; i >= 0; i--) //leer el array
      //printf("%f ",num[i]);
      
      min=num[elementos-1]; 
	  for(int i=elementos-1; i>=0;i--) {
	  	//printf("n a examinar: %f\n",num[i]);
	    if(num[i]>max){
	    	max=num[i];
	    	//printf("He cambiado max: %f\n",max);
		 }
	    	
	    if(num[i]<min){
	    	min=num[i];
	    	//printf("He cambiado min: %f\n", min);
		 }
	  	}
	  
	  printf("El maximo es: %f\n", max);
	  printf("El minimo es: %f\n", min);
	  return 0;
  }
  else{
  	puts("Error en fopen");
  	return -1;
  }
}

int leer(FILE *f){
  float num[MAX];
  float max=0.00; float min=0.00;
  int elementos = 0;
  int c;
  
  if(f==NULL){
  	
	c=-1;}
  else{		
	  while (feof(f)==0) { //ciclo de lectura
	    float a; //Guarda el número
	    int check=fscanf(f, "%f", &a);
	    if(check ==0||elementos == MAX){
	    		fclose(f);
				break;	
		}
			num[elementos] = a;
	    	elementos ++; 
	  }
	  c=0;
	}
	return c;
}
