#include <stdlib.h>
#include <stdio.h>

typedef struct _nodo {
	   int valor;
	   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;


void push(pNodo *inicio, int v);
int pop(pNodo *inicio);
int primerValor(pNodo *inicio);

void push(pNodo *inicio, int v)
{
	pNodo nuevo,aux=*inicio;	    
	nuevo = (pNodo)malloc(sizeof(tipoNodo));

	nuevo->valor = v;
	nuevo->siguiente = NULL;

	if(!*inicio){
		*inicio = nuevo;
	}else{
		while(aux->siguiente){
			aux = aux->siguiente;
		}

		aux->siguiente = nuevo;
	}
}

int pop(pNodo *inicio)
{
	pNodo nodo,nodo1;
	int v;

	nodo = *inicio;
	nodo1 = nodo;

	if(!*inicio){
		return -1;
	}
	
	*inicio = nodo->siguiente;
	v = nodo->valor;
	free(nodo);

	return v;
}

int primerValor(pNodo *inicio){
	int v;
	if(!*inicio){
		return -1;
	}else{
		v = (*inicio)->valor;
		return v;
	}
}
