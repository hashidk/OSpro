#include "colas.h"

int main()
{
   pNodo primero = NULL, segundo = NULL;


   printf("Primero: %d\n",primerValor(&primero));

   push(&primero, 20);
   push(&primero, 40);
   push(&primero, 10);

   push(&segundo, 20);
   push(&segundo, 40);
   push(&segundo, 10);

   printf("tamaño de primero: %d\n",sizeC(&primero));


   printf("Cola:");
   imprimirCola(&primero,&segundo);
   imprimirCola(&primero,&segundo);
 //  printf("Menor de la cola: %d\n",menorC(&primero));  

   printf("Quitando: %d\n",pop(&primero));
   printf("Quitando: %d\n",pop(&primero));

   push(&primero, 50);
   printf("Agregando: 50\n");
   
   printf("Quitando: %d\n",pop(&primero));

   printf("Estado actual: %d\n",primerValor(&primero));

  
   return 0;
}

