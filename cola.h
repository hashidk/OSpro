#include <stdlib.h>
#include <stdio.h>

typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
} tipoNodo;

typedef tipoNodo *pNodo;


void Anadir(pNodo *primero, pNodo *ultimo, int v);
int Leer(pNodo *primero, pNodo *ultimo);


void Anadir(pNodo *primero, pNodo *ultimo, int v)
{
   pNodo nuevo;

 
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;
   nuevo->siguiente = NULL;
   if(*ultimo) (*ultimo)->siguiente = nuevo;
   *ultimo = nuevo;
   if(!*primero) *primero = nuevo;
}

int Leer(pNodo *primero, pNodo *ultimo)
{
   pNodo nodo;
   int v;     
   
   nodo = *primero;
   if(!nodo) return 0; /* Si no hay nodos en la pila retornamos 0 */
   *primero = nodo->siguiente;
   v = nodo->valor; 
   free(nodo);
   if(!*primero) *ultimo = NULL;
   return v;
}