#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct _nodo {
	   int llegada;
	   int rafaga;
	   struct nodo *siguiente;
}tipoNodo;

typedef tipoNodo *pNodo;

/* Funciones con colas: */
void push(pNodo *primero, pNodo *ultimo, int dato1,int dato2);
int pop(pNodo *primero, pNodo *ultimo);


int main(int argc,char *argv[]){
	int x=1,size;

	//Abrir el archivo
	FILE *f = fopen(argv[1], "r");
	if (f==NULL)
	{
		perror ("ERROR: Quizá escribió mal el nombre del archivo");
		return -1;
	}
	int dato1,dato2,k=0;
	fscanf (f, "%d %d", &dato1,&dato2);
	while(feof(f)==0){
		printf("%d %d\n",dato1,dato2);
		fscanf (f, "%d %d", &dato1,&dato2);
		k++;
	}
	int v[2][k];
	size=k;
	f = fopen(argv[1],"r");
	while(feof(f)==0 && k>=0){
		fscanf (f, "%d %d", &dato1,&dato2),
		v[0][size-k]=dato1;
		v[1][size-k]=dato2;
		k--;
	}


	for(int i=0; i<size;i++){
		printf("alv %d %d\n",v[0][i],v[1][i]);
	}
	
	if (argc==4){
		if(strcmp(argv[2],"rr")==0){
			printf("Por aqui empieza el rr\n");
		
		}else{printf("ERROR: Loa datos ingresados están mal\n");}

	}else if(argc==3){
		if(strcmp(argv[2],"fcfs")==0){                                                                                                                               printf("Por aqui empieza el fcfs\n");
		}else if(strcmp(argv[2],"sjf")==0){
		       	printf("Por aqui empieza el sjf\n");

		}else{printf("ERROR: Loa datos ingresados están mal\n");}

	}else{printf("ERROR: Loa datos ingresados están mal\n");}

return 0;
}

