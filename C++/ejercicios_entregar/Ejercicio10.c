#include <stdio.h>
#include "pilavector.h"

tpv mipila;

void init (void)
{
	int i = 0;
	int j = 0;
	while(i < MAXPILA)
	{
		mipila.datos[i].id = 0;
		mipila.datos[i].nota = 0.0f;
		mipila.datos[i].nombre[i] = '\0';
		mipila.datos[i].mail[i] = '\0';
		while(j < 10)
		{
			mipila.datos[i].matricula[j] = '\0';
			mipila.datos[i].dni[j] = '\0';
			j++;
		}
		i++;
	}
	mipila.top = -1;
}

void vaciar (void)
{
	int i = 0;
	int j = 0;
	while(i < MAXPILA)
	{
		mipila.datos[i].id = 0;
		mipila.datos[i].nota = 0.0f;
		mipila.datos[i].nombre[i] = '\0';
		mipila.datos[i].mail[i] = '\0';
		while(j < 10)
		{
			mipila.datos[i].matricula[j] = '\0';
			mipila.datos[i].dni[j] = '\0';
			j++;
		}
		i++;
	}
	mipila.top = -1;
}

int llena (void)
{
	if (MAXPILA - 1 == mipila.top)
	{
		return 1;
	}
	return 0;
}

int vacia(void)
{
	if(mipila.top==-1){
	return 1;
	}else
	{
	return 0;
	}

}


int push (tdata item)
{
	/*Si esta llena no ha podido apilar, 
	por tanto devuelve -1
	*/
	if (llena() == 1)
	{
		return -1;
	}	
		mipila.datos[++mipila.top] = item;
	
	return 0;
}

tdata pop (void)
{
	if (vacia() == 1)
	{
		printf("La pila esta vacia");
	}
	
	else
	{
		return mipila.datos[mipila.top--];
	}
}

void display (void)
{
	
	int i=top;
	while(i>-1){
	
		printf("Contenido de la pila: \n"
         "\tID: %d\n"
         "\tMatricula: %s\n"
         "\tDNI: %s\n"
         "\tNombre: %s\n"
         "\tMail: %s\n"
         "\tNota: %f\n\n"
         , mipila.datos[i].id, mipila.datos[i].matricula, mipila.datos[i].dni, mipila.datos[i].nombre, id=mipila.datos[i].mail, id=mipila.datos[i].nota);
		 i--;}
         
}
