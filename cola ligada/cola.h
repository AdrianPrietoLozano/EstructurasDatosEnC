#include <stdio.h>
#include <stdlib.h>

typedef int TIPODATO;

typedef struct nodo
{
	TIPODATO dato;
	struct nodo *siguiente;
} Nodo;


void encolar(Nodo **cabeza, Nodo **cola, const TIPODATO dato);
TIPODATO descolar(Nodo **cabeza, Nodo **cola);
void mostrar(Nodo *cabeza);
int isEmpty(Nodo *cabeza);
int tamanio(Nodo *cabeza);
TIPODATO valorAlFrente(Nodo *cabeza);
void vaciar(Nodo **cabeza);


void vaciar(Nodo **cabeza)
{
	Nodo *aux;

	while(*cabeza != NULL)
	{
		aux = *cabeza;
		*cabeza = (*cabeza) -> siguiente;
		free(aux);
	}
}


TIPODATO valorAlFrente(Nodo *cabeza)
{
	if(isEmpty(cabeza))
	{
		puts("Cola vacia");
		exit(-1);
	}

	return cabeza -> dato;
}


TIPODATO descolar(Nodo **cabeza, Nodo **cola)
{
	if(isEmpty(*cabeza))
	{
		puts("Cola vacia");
		exit(-1);
	}

	TIPODATO dato = (*cabeza) -> dato;
	Nodo *aux = *cabeza;
	*cabeza = (*cabeza) -> siguiente;

	if(*cabeza == NULL) // si la lista solo tenía un elemento
		*cola = NULL;

	free(aux);

	return dato;
}

void encolar(Nodo **cabeza, Nodo **cola, const TIPODATO dato)
{
	Nodo *nuevo;
	nuevo = malloc(sizeof(Nodo));
	if(nuevo != NULL)
	{
		nuevo -> dato = dato;
		nuevo -> siguiente = NULL;

		if(isEmpty(*cabeza))
			*cabeza = nuevo;
		else
			(*cola) -> siguiente = nuevo;
		
		*cola = nuevo; // el nuevo elemento es ahora la cola
	}
	else
		puts("No hay espacio");
}


int tamanio(Nodo *cabeza)
{
	int tamanio;
	for(tamanio = 0; cabeza != NULL; cabeza = cabeza -> siguiente, tamanio++);

	return tamanio;
}


int isEmpty(Nodo *cabeza)
{
	return (cabeza == NULL);
}
