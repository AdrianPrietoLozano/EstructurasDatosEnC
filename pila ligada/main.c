#include <stdio.h>
#include<time.h>
#include "pila.h"

void mostrar(Nodo *cima);
int generarNumRandom(int min, int max);

int main()
{

	Nodo *cima = NULL;
	mostrar(cima);
	printf("\n");

	srand(time(0));

	for (int i = 0; i < 10; i++) {
		push(&cima, generarNumRandom(1, 100));
		mostrar(cima);
		printf("%s = %d\n", "Valor al frente", top(cima));
		printf("%s = %d\n\n","tamanio", tamanio(cima));
	}
	
	printf("\n----------------------------------------\n\n");

	int tamanioPila = tamanio(cima);
	for (int i = 0; i < tamanioPila; i++) {
		int eliminado = pop(&cima);
		printf("%d se sacó de la pila\n", eliminado);
		mostrar(cima);
		printf("%s = %d\n\n","tamanio", tamanio(cima));
	}

	return 0;
}

int generarNumRandom(int min , int max) {
	return (rand() % (max - min + 1)) + min;
}

void mostrar(Nodo *cima)
{
	if(isEmpty(cima))
		puts("Pila Vacia");
	else
	{
		while(cima != NULL)
		{
			printf("%d --> ", cima -> dato);
			cima = cima -> siguiente;
		}
		puts("NULL");
	}
}