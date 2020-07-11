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
int menorC(pNodo *arrive, pNodo *burst, int te);
int sizeC(pNodo *inicio);
void imprimirCola(pNodo *arrive,pNodo *burst);

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

int menorC(pNodo *arrive, pNodo *burst, int te){
	int i = 0, vB, vA, menorB = 0, menorA = 0;
	pNodo nodoB = *burst, nodoA = *arrive;
	pNodo auxB = NULL, auxA = NULL;
	if(!*burst){
		return -1;
	}
	menorA = pop(&nodoA);
	menorB = pop(&nodoB);
	push(&auxA,menorA);	
	push(&auxB,menorB);
	while(vA!=-1){
		vA = pop(&nodoA);
		vB = pop(&nodoB);
		if(menorB>vB && vA<=te && vB!=-1){
			menorB = vB;
		}
		push(&auxA,vA);
		push(&auxB,vB);
		i++;
	}
	*burst = auxB;
	*arrive = auxA;

	return menorB;
}

int sizeC(pNodo *inicio){
	pNodo nodo = *inicio;
	int k=0;
	if(!*inicio){
		return 0;
	}
	pNodo nodoA = *inicio;
	pNodo auxA = NULL;
	int a=pop(&nodoA);
	while(a!=-1){
		push(&auxA,a);
		a =pop(&nodoA);
		k++;
	}
	nodoA = auxA;
	return k;
}

void imprimirCola(pNodo *arrive,pNodo *burst){
	pNodo nodoA = *arrive, nodoB = *burst;
	pNodo auxA = NULL, auxB = NULL;
	int a, b;

	a =pop(&nodoA);
	b =pop(&nodoB);
	while(a!=-1){
		printf("%d %d\n",a,b);
		push(&auxA,a);
		push(&auxB,b);
		a =pop(&nodoA);
		b =pop(&nodoB);
	}

	*arrive = auxA;
	*burst = auxB;
	
}