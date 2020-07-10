#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "colas.h"

int menorC(pNodo *inicio);
int sizeC(pNodo *inicio);

int main(int argc,char *argv[]){
	//Declaracion de variables
	int x=1,size,tf=0,ti=0,a,b,dato1,dato2,k=0;
	int aux[2];
	//Inicio de cola
	pNodo arrive = NULL,burst = NULL;

	//Abrir el archivo
	FILE *f = fopen(argv[1], "r");
	if (f==NULL){
		perror ("ERROR: Quizá escribió mal el nombre del archivo");
		return -1;
	}

	while(feof(f)==0){
		k++;
		fscanf (f, "%d %d", &dato1,&dato2);
	}
	k--;	
 
	//Guardar los datos en un array local
	int procesos[2][k];
	size = k;
	f = fopen(argv[1],"r");

	fscanf (f, "%d %d", &dato1,&dato2);
	while(feof(f)==0 && k>=0){
		printf("%d %d\n",dato1,dato2);
		procesos[0][size-k]=dato1;
		procesos[1][size-k]=dato2;
		push(&arrive,dato1);
		push(&burst,dato2);
		fscanf (f, "%d %d", &dato1,&dato2);
		k--;
	}
	
	//Verificacion
	if (argc==4){
		if(strcmp(argv[2],"rr")==0){
			int w = 0,l=0;
			while(primerValor(&arrive)!=-1){
				a=pop(&arrive);
				b=pop(&burst);
       				
				if(l==0){
					ti=a;
				}else{
					ti=tf;
				}

				tf = b + ti;
				w = tf-ti;

 				printf("runs %d-%d -> end = %d, (arr = %d), turn = %d, (burst = %d), wait = %d\n",ti,tf,tf,ti,w,b,w-b);

				l++;
			} 
		
		}else{printf("ERROR: Loa datos ingresados están mal\n");}

	}else if(argc==3){
		if(strcmp(argv[2],"fcfs")==0){
			int w = 0,l=0;	
			while(primerValor(&arrive)!=-1){
				a=pop(&arrive);
				b=pop(&burst);
				{
					if(l==0){
						ti=a;
					}else{
						ti=tf;
					}
					tf = b + ti;
					w = tf-ti;
					printf("runs %d-%d -> end = %d, (arr = %d), turn = %d, (burst = %d), wait = %d\n",ti,tf,tf,ti,w,b,ti-a);
					l++;
				}
			}
		}else if(strcmp(argv[2],"sjf")==0){

			int w = 0,l=0,menor =0;
			//while(primerValor(&arrive)!=-1){

				//Para el primero
				a=pop(&arrive);
				b=pop(&burst);
				ti = a;			
				tf = b + ti;				
				w = tf-ti;					
   				printf("runs %d-%d -> end = %d, (arr = %d), turn = %d, (burst = %d), wait = %d\n",ti,tf,tf,ti,w,b,ti-a);		
				l++;

				//Para el segundo
				a=pop(&arrive);
				b=pop(&burst);
				if(b!=menorC(&burst)){
					push(&arrive,a);
					push(&burst,b);	
				}else{
					ti = tf;
					tf = b + ti;
 					w = tf-ti;
   					printf("runs %d-%d -> end = %d, (arr = %d), turn = %d, (burst = %d), wait = %d\n",ti,tf,tf,ti,w,b,ti-a);
				}

			//}

			/*int w = proceso[0][0]+procesos[1][0];

			for(int i=0;i<size-1;i++){
				for(int k=0;k<size-1;k++){

					if(procesos[1][k]>procesos[1][k+1]){
						aux[0]=procesos[0][k];		
		    				aux[1]=procesos[1][k];

						procesos[0][k]=procesos[0][k+1];	
		     				procesos[1][k]=procesos[1][k+1];
					
						procesos[0][k+1]=aux[0];
						procesos[1][k+1]=aux[1];
					}
			        }
			}

			for(int k=0;k<size;k++){
				printf("alv: %d %d\n",procesos[0][k],procesos[1][k]);
			}*/
		}else{printf("ERROR: Loa datos ingresados están mal\n");}

	}else{printf("ERROR: Loa datos ingresados están mal\n");}

return 0;
}

int menorC(pNodo *inicio){
	int i = 0, v, menor = 0;
	pNodo nodo = *inicio;
	int size = sizeC(&nodo);

	menor = pop(&nodo);
	push(&nodo,v);
	while(i < size-1){
		v = pop(&nodo);
		if(menor>v){
			menor = v;
		}
		push(&nodo,v);
	}

	return menor;
}

int sizeC(pNodo *inicio){
	pNodo nodo = *inicio;
	int k=1;
	if(!*inicio){
		return 0;
	}
	while(nodo->siguiente){
		nodo = nodo->siguiente;
		k++;
		printf("%d\n",k);
	}
	return k;
}
