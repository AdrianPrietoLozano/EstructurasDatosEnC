#include <stdio.h>
#include <stdlib.h>

typedef int TIPODATO;

typedef struct nodo
{
	TIPODATO dato;
	struct nodo *siguiente;
} Nodo;


void inicializarNodos(Nodo **cabeza, Nodo **actual, Nodo**cola);
int isEmpty(Nodo *cabeza);
void insertar(Nodo **cabeza, Nodo **actual, Nodo **cola, const TIPODATO dato);
void insertarAlFinal(Nodo **cabeza, Nodo **actual, Nodo **cola, TIPODATO dato);
void insertarAlInicio(Nodo **cabeza, Nodo **actual, Nodo **cola, TIPODATO dato);
unsigned tamanio(Nodo *cabeza);
TIPODATO eliminar(Nodo **cabeza, Nodo **actual, Nodo **cola); // eliminar el nodo actual
TIPODATO datoActual(Nodo *cabeza, Nodo *actual);
void siguiente(Nodo**actual, Nodo *cola);
void anterior(Nodo *cabeza, Nodo **actual);
void irAPosicion(Nodo *cabeza, Nodo **actual, const int posicion);
int posicionActual(Nodo *cabeza, Nodo *actual);
void irAlFinal(Nodo *cabeza, Nodo **actual, Nodo *cola);
void irAlInicio(Nodo *cabeza, Nodo **actual);
void vaciar(Nodo **cabeza, Nodo **actual, Nodo **cola);

// esta función depende del dato a almacenar
// void mostrar(Nodo *cabeza);




////////////////////////////
/////// L I S T O //////////
////////////////////////////


/* esta función debe llamarse antes de poder utilizar la lista ligada */
void inicializarNodos(Nodo **cabeza, Nodo **actual, Nodo **cola)
{
	Nodo *vacio;
	vacio = malloc(sizeof(Nodo));

	if(vacio != NULL)
	{
		vacio->siguiente = NULL;
		*cabeza = *actual = *cola = vacio;
	}
}


/* retorna 1 si la lista esta vacía o 0 en caso contrario */
int isEmpty(Nodo *cabeza)
{
	return cabeza->siguiente == NULL;
}


/* El nuevo nodo siempre se inserta atrás del nodo actual.
La única forma de insertar al final es usando la función insertarAlFinal
*/
void insertar(Nodo **cabeza, Nodo **actual, Nodo **cola, const TIPODATO dato)
{
	Nodo *nuevo;
	nuevo = malloc(sizeof(Nodo));

	if(nuevo != NULL)
	{
		nuevo->dato = dato;
		nuevo->siguiente = (*actual)->siguiente;

		(*actual)->siguiente = nuevo;

		if(*actual == *cola) // si la lista estaba vacía
			*cola = (*actual)->siguiente;
	}
	else
		puts("Error: no se pudo insertar. No hay espacio");
}


/* inserta un elemento al final de la lista */
void insertarAlFinal(Nodo **cabeza, Nodo **actual, Nodo**cola, TIPODATO dato)
{
	Nodo *nuevo;
	nuevo = malloc(sizeof(Nodo));

	if(nuevo != NULL)
	{
		nuevo->dato = dato;
		nuevo->siguiente = NULL;

		(*cola)->siguiente = nuevo;
		*cola = nuevo;
	}
	else
		puts("Error: no se pudo insertar. No hay espacio");
}


/* inserta un elemento al inicio de la lista */
void insertarAlInicio(Nodo **cabeza, Nodo **actual, Nodo **cola, TIPODATO dato)
{
	Nodo *nuevo;
	nuevo = malloc(sizeof(Nodo));

	if(nuevo != NULL)
	{
		nuevo->dato = dato;
		nuevo->siguiente = (*cabeza)->siguiente;
		(*cabeza)->siguiente = nuevo;

		if(*cabeza == *cola) // si la lista estaba vacía
			*cola = nuevo;
	}
	else
		puts("Error: no se pudo insertar. No hay espacio");
}


/* retorna el tamanio de la lista */
unsigned tamanio(Nodo *cabeza)
{
	int tamanio;
	cabeza = cabeza->siguiente; // esto debido a que cabeza apunta a un nodo anterior
								// no apunta al nodo directamente

	for(tamanio = 0; cabeza != NULL; cabeza = cabeza->siguiente, tamanio++);

	return tamanio;
}


/* elimina un elemento de la lista.
Si la eliminación se hace sin errores se retorna el dato almacenado en el nodo */
TIPODATO eliminar(Nodo **cabeza, Nodo **actual, Nodo **cola)
{
	if(isEmpty(*cabeza))
	{
		puts("Lista vacía");
		exit(-1);
	}

	TIPODATO dato = (*actual)->siguiente->dato;
	Nodo *nodoAEliminar = (*actual)->siguiente;

	if((*actual)->siguiente == *cola)
		cola = actual;

	(*actual)->siguiente = (*actual)->siguiente->siguiente;

	if(*actual == *cola) // actual no debe ser igual a la cola a menos que la lista este vacía
		anterior(*cabeza, actual);

	free(nodoAEliminar);
	return dato;
}


/* mueve el nodo actual a un nodo antes de la cola */
void irAlFinal(Nodo *cabeza, Nodo **actual, Nodo *cola)
{
	*actual = cola;
	anterior(cabeza, actual);
}


/* mueve el nodo actual al inicio de la lista */
void irAlInicio(Nodo *cabeza, Nodo **actual)
{
	*actual = cabeza;
}


/* Vacía la lista liberando la memoria de los nodos e inicializa los nodos cabeza, actual y cola */
void vaciar(Nodo **cabeza, Nodo **actual, Nodo **cola)
{
	Nodo *temporal;
	while(*cabeza != NULL)
	{
		temporal = *cabeza;
		*cabeza = (*cabeza)->siguiente;
		free(temporal);
	}

	inicializarNodos(cabeza, actual, cola);
}


/* posiciona el nodo actual una posicióna hacia adelante */
void siguiente( Nodo **actual, Nodo *cola)
{
	if( (*actual == cola) ||  // si la lista esta vacía
		(*actual)->siguiente == cola ) // actual no debe apuntar a la cola a menos que la lista este vacía
	{
		return;
	}

	*actual = (*actual)->siguiente;
}


/* posiciona el nodo actual una posición anterior */
void anterior(Nodo *cabeza, Nodo **actual)
{
	if(!(*actual == cabeza))
	{
		while( cabeza->siguiente != *actual )
			cabeza = cabeza->siguiente;

		*actual = cabeza;
	}
}


/* Posiciona el nodo actual a una posición en la lista.
La primera posición se cuenta desde 0.*/
void irAPosicion(Nodo *cabeza, Nodo **actual, const int posicion)
{
	if(posicion < 0 || posicion >= tamanio(cabeza))
	{
		puts("Posicion fuera de rango");
		exit(-1);
	}

	for(int i = 0; i < posicion && cabeza != NULL; i++)
		cabeza = cabeza->siguiente;

	*actual = cabeza;
}


/* retorna el dato almacenado en el nodo actual */
TIPODATO datoActual(Nodo *cabeza, Nodo *actual)
{
	if(isEmpty(cabeza))
	{
		puts("Lista vacia");
		exit(-1);
	}

	return actual->siguiente->dato;
}


/* retorna la posición del nodo acutal en la lista */
int posicionActual(Nodo *cabeza, Nodo *actual)
{
	int pos;
	for(pos = 0; cabeza != actual; cabeza = cabeza->siguiente, pos++);

	return pos;
}

