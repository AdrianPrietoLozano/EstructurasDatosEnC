#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cola.h"

void mostrar(Nodo *cabeza);
int generarNumRandom(int min, int max);

int main()
{
	Nodo *cabeza = NULL;
	Nodo *cola = NULL;
	srand(time(0));

	printf("%s = %d\n\n","tamanio", tamanio(cabeza));

	for(int i = 0; i < 10; i++) {
		encolar(&cabeza, &cola, generarNumRandom(1, 100));
		mostrar(cabeza);
		printf("%s = %d\n", "Valor al frente", valorAlFrente(cabeza));
		printf("%s = %d\n\n","tamanio", tamanio(cabeza));
	}

	printf("--------------------------------\n\n");

	int tamanioCola = tamanio(cabeza);
	for(int i = 0; i < tamanioCola; i++) {
		int descolado = descolar(&cabeza, &cola);
		printf("%d se descoló\n", descolado);
		mostrar(cabeza);
		printf("%s = %d\n\n","tamanio", tamanio(cabeza));
	}

	return 0;
}

int generarNumRandom(int min , int max) {
	return (rand() % (max - min + 1)) + min;
}

void mostrar(Nodo *cabeza)
{
	if(isEmpty(cabeza))
		puts("Cola Vacia");
	else
	{
		while(cabeza != NULL)
		{
			printf("%d --> ", cabeza -> dato);
			cabeza = cabeza -> siguiente;
		}
		puts("NULL");
	}
}