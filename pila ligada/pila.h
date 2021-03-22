#include <stdlib.h>
#include <stdio.h>

typedef int TIPODATO;

typedef struct nodo
{
	TIPODATO dato;
	struct nodo *siguiente;
} Nodo;


void push(Nodo **cima, const TIPODATO dato);
TIPODATO pop(Nodo **cima);
int isEmpty(Nodo *cima);
int tamanio(Nodo *cima);
TIPODATO top(Nodo *cima);
void vaciar(Nodo **cima);


// falta probarlo
void vaciar(Nodo **cima)
{
	Nodo *aux;

	while(*cima != NULL)
	{
		aux = *cima;
		*cima = (*cima) -> siguiente;
		free(aux);
	}
}



int isEmpty(Nodo *cima)
{
	return cima == NULL;
}


int tamanio(Nodo *cima)
{
	int tamanio;
	for(tamanio = 0; cima != NULL; cima = cima -> siguiente, tamanio++);

	return tamanio;
}


TIPODATO top(Nodo *cima)
{
	if(isEmpty(cima))
	{
		puts("Pila vacia");
		exit(-1);
	}

	return cima -> dato;
}


TIPODATO pop(Nodo **cima)
{
	if(isEmpty(*cima))
	{
		puts("Error: pila vacia");
		exit(-1);
	}

	Nodo *aux = *cima;
	TIPODATO dato = (*cima) -> dato;

	*cima = (*cima)->siguiente;
	free(aux);
	return dato;
}


void push(Nodo **cima, const TIPODATO dato)
{
	Nodo *nuevo;

	nuevo = malloc(sizeof(Nodo));

	if(nuevo != NULL)
	{
		nuevo -> dato = dato;
		nuevo -> siguiente = *cima;

		*cima = nuevo;		
	}
	else
		puts("No hay espacio");
}