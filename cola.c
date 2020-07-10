#include "colas.h"

int main()
{
   pNodo primero = NULL;

   push(&primero, 20);
   printf("Agregando: %d\n",primerValor(&primero));
   push(&primero, 40);
   printf("Agregando: %d\n",primerValor(&primero));

   printf("Quitando: %d\n",pop(&primero));
   printf("Quitando: %d\n",pop(&primero));

   push(&primero, 50);
   printf("Agregando: %d\n",primerValor(&primero));
   
   printf("Quitando: %d\n",pop(&primero));

   printf("Estado actual: %d\n",primerValor(&primero));

   return 0;
}

