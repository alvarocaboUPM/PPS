
#include <stdio.h> 
#include <stdlib.h> // Para NULL

#define S 1000
#define I 1
int main(){
	
	/*
	Para poder multiplicar matrices: (A(m,n))
		1)Sea A(m,n), B(n,p) --> n=n
		2) C=A*B; C(i,j)=sum(A(i,m)*B(n,j)
		
	 	3 -> m
		2 -> n
		3 -> p
		A(3,2)xB(2,3)
		
				 1 2
		A ->	-1 0
				-3 -1
				
		B ->   	 2 0 1
				-5 2 3
	 */
	 
	
	int n, m, p; int check_S=0; int check_I=0;
	int count=0;
	int lectura[S^3]; //the max size of n*m*n
	FILE *f;
  	f = fopen("matrices.txt", "r");

  	if(f!=NULL){
  	while (!(feof(f))){
  			int a; int check=fscanf(f, "%i", &a); //el elemento que lee se mete en a
	        if(check !=1){
	    		fclose(f); //cierra el archivo
				break;	//no lee m�s
		  	}
		  	lectura[count]=a;
		  	printf("Lectura: %d\n",a); //ok
		  	count++;
  	    }
  	 
  	    m= lectura[0];
  	    n=lectura[1];
  	    p= lectura[2];
  	    
  	    printf("n: %i m: %i p: %i, count: %i \n", n,m,p, count); //ok
  	    
  	    int i;  int k;
  	    puts("\nLectura limpia: \n");
  	    

  	    int A[m][n]; int B[n][p]; int C[m][p];
  	    
  	    //Matriz A
  	    puts("\nA: \n"); int j=1; int c=0;
  	    for(i=0; i<n;i++)
  	    	A[0][n]=0;
		  for(i=1; i<=m;i++){ //FILAS
  	    	j=1;
			  while(c<n*i){
  	    		A[i][j]=lectura[c+3];
  	    		 j++; c++;
			  }
		  }
		  
		for (i=1;i<=m;i++)
		   for (j=1;j<=n;j++)
		     printf("A(%d,%d)=\t %d\n",i,j,A[i][j]);
		
		puts("\n");
		//Matriz B
		for(i=0; i<p;i++)
  	    	A[0][p]=0;
		for(i=1; i<=n;i++){
		j=1;
  	    	while(c-6<p*i){
  	    		B[i][j]=lectura[c+3];
  	    		 j++; c++;
			  }
		  }
		
		for (i=1;i<=n;i++)
		   for (j=1;j<=p;j++)
		     printf("B(%d,%d)=\t %d\n",i,j,B[i][j]);
		
		puts("\n");
		
		//Ajuste del 0 de lectura
			c=0;
			for(j=1; j<=n; j++){
				if(A[1][j]==0||A[1][j]==-1)
					A[1][j]=lectura[c+3];
					c++;
			}
		
		//Producto A*B=C 
		 for (i=1;i<=m;i++) {
	 		for (j=1;j<=p;j++){ 
		  		C[i][j]=0;
         		for (k=1;k<=n;k++){
         			//printf("En k=%d -->%d + A[%d][%d](%d)*B[%d][%d](%d) = ", k, C[i][j], i, k, A[i][k], k, j, B[k][j]);
					C[i][j]=C[i][j]+A[i][k]*B[k][j];
				 }
          		printf("C(%d,%d): %d\n",i, j,C[i][j]);
       		}
    	}
    puts("\n");
    	for(i=1; i<=m; i++){
    		for(j=1; j<=p; j++){
    			printf("%d ", C[i][j]);
			  }
			  puts("\n");
			}
		
	return 0;
	}

	else{
		puts("Error en fopen");
	return 1;
  	}
}

