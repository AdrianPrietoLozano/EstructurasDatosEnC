#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

void mostrar(Nodo *cabeza);
int getNumAleatorio()
{
	return (0 + ( rand() % 1000 ));
}

int main()
{
	Nodo *cabeza = NULL;
	Nodo *actual = NULL;
	Nodo *cola = NULL;

	// randomize random number generator using current time
	srand( time( NULL ) );

	inicializarNodos(&cabeza, &actual, &cola);
	mostrar(cabeza);
	printf("%s: %u\n", "Tamanio", tamanio(cabeza));

	printf("Insertando elementos\n");
	// inserta 1000 números aleatorios en la lista
	for(unsigned i = 0; i < 1000; i++)
	{
		insertarAlInicio(&cabeza, &actual, &cola, getNumAleatorio());
	}

	mostrar(cabeza);
	printf("%s: %u\n", "Tamanio", tamanio(cabeza));

	printf("\n\n");
	
	irAPosicion(cabeza, &actual, 3);
	printf("%s = %d, %s: %i\n\n", "dato actual", datoActual(cabeza, actual), "posición", posicionActual(cabeza, actual));
	siguiente(&actual, cola);
	printf("%s = %d, %s: %i\n\n", "dato actual", datoActual(cabeza, actual), "posición", posicionActual(cabeza, actual));
	siguiente(&actual, cola);
	printf("%s = %d, %s: %i\n\n", "dato actual", datoActual(cabeza, actual), "posición", posicionActual(cabeza, actual));
	siguiente(&actual, cola);
	printf("%s = %d, %s: %i\n\n", "dato actual", datoActual(cabeza, actual), "posición", posicionActual(cabeza, actual));
	siguiente(&actual, cola);
	printf("%s = %d, %s: %i\n\n", "dato actual", datoActual(cabeza, actual), "posición", posicionActual(cabeza, actual));
	siguiente(&actual, cola);
	printf("%s = %d, %s: %i\n\n", "dato actual", datoActual(cabeza, actual), "posición", posicionActual(cabeza, actual));

	vaciar(&cabeza, &actual, &cola);
	printf("%s\n", "Se vació la lista");
	printf("%s: %u\n", "Tamanio", tamanio(cabeza));

	return 0;
}



void mostrar(Nodo *cabeza)
{
	if(isEmpty(cabeza))
		puts("Lista vacia");
	else
	{
		while(cabeza->siguiente != NULL)
		{
			printf("%d", cabeza->siguiente->dato);
			cabeza = cabeza->siguiente;

			if(cabeza->siguiente != NULL) { printf(" --> "); }
		}
		printf("\n");
	}
}