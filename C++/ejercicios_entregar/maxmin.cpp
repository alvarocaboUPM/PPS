/*
Realice un programa (maxmin) que reciba como entra el nombre de un fichero de texto
que contiene un n�mero real (float) por l�nea y que despu�s de leerlo escriba por pantalla
el valor m�ximo y el valor m�nimo en una sola l�nea (formato %10.2f). 

- Si el fichero est� vac�o -> debe escribir los valores 0.00 y 0.00. 
- Suponer que los n�meros del fichero son n�meros reales v�lidos. 
-Hay que comprobar que en la llamada se ha pasado un argumento de entrada, en caso contrario terminar sin imprimir nada y devolver al sistema operativo
el n�mero -1. Si el fichero no se puede leer tambi�n se devolver� el n�mero -1 sin imprimir nada
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
	    float a; //Guarda el n�mero
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
