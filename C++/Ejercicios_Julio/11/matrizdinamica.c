#include <stdio.h>
#include <stdlib.h>

long int** reservar(int i, int j){
    /*Función que reserva espacio para una matriz y sus elementos*/

    long int **matrix;
	int k;

    //Reservamos la matriz
	matrix = (long int **) malloc( i * sizeof(long int *)) ;
	
	if (matrix == NULL)
		exit(71);

    //Reservamos i vectores para las filas de size (columnas/fila * size(longint))
	for (k = 0; k < i; k++)
	{
		matrix[k] = (long int *) malloc( j * sizeof(long int));
		if (matrix[k] == NULL)
			exit(71);
	}

	return matrix;
}

void liberar(long int **matrix, int m, int p)
{
	int i;

	for(i = 0; i < m; i++)
		free(matrix[i]);
	
	free(matrix);
}

void rellenar(long int **matrix, int m, int p)
{

    /*REGLAS
    Fila 1 todos los elementos serán 1´s (a1j=1 j=1….p)
    - Columna 1 todos los elementos serán 1´s (ai1=1 i=1….m)
    - Restos de elementos aij= ai-1j + aij-1 i=2….m j=2….p Si al calcular un elemento,
    se cumple que aij >1.e6 entonces aij =1 */

    int i,j;

    for(i = 0; i < m; i++)
	{
		for(j = 0; j < p; j++)
			matrix[i][j] = 1;
	}

    //Resto
    for(i = 1; i < m; i++)
	{
		for(j = 1; j < p; j++)
		{
			matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
			if (matrix[i][j] > 1000000)
				matrix[i][j] = 1; 
		}
			
	}
}

int main( int argc, char* argv[] ){
   
    long int **matriz;

    int i,j;
    i = atoi(argv[1]);
    j = atoi(argv[2]);

    matriz = reservar(i,j);
    rellenar(matriz,i,j);

    int m,p;
    for(m = 0; m < i; m++)
	{
		for(p = 0; p < j; p++)
			printf("%li\t", matriz[m][p]);
		printf("\n");	
	}

    liberar(matriz, i, j);
    return 0;
}