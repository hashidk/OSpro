#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "colas.h"

int main(int argc,char *argv[]){
	//Declaracion de variables
	int x=1,size,tf=0,ti=0,a,b,dato1,dato2,k=0;
	int aux[2];
	
	//Inicio de cola de procesos nuevos
	pNodo nuevo[2];
	nuevo[0] = NULL;
	nuevo[1] = NULL;
	
	//Cola de espera
	pNodo espera[2];
	espera[0] = NULL;
	espera[1] = NULL;

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
		push(&(nuevo[0]),dato1);
		push(&(nuevo[1]),dato2);
		fscanf (f, "%d %d", &dato1,&dato2);
		k--;
	}
	
	//Verificacion
	if (argc==4){
		if(strcmp(argv[2],"rr")==0){
			int w = 0,l=0;
			while(primerValor(&(nuevo[0]))!=-1){
				a=pop(&(nuevo[0]));
				b=pop(&(nuevo[1]));
       				
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
		
		}else{printf("ERROR: Los datos ingresados están mal\n");}

	}else if(argc==3){
		if(strcmp(argv[2],"fcfs")==0){
			int w = 0,l=0;	
			while(primerValor(&(nuevo[0]))!=-1){
				a=pop(&(nuevo[0]));
				b=pop(&(nuevo[1]));
				{
					if(l==0){
						ti=a;
					}else{
						ti=tf;
					}
					tf = b + ti;
					w = tf-a;
					printf("runs %d-%d -> end = %d, (arr = %d), turn = %d, (burst = %d), wait = %d\n",ti,tf,tf,ti,w,b,ti-a);
					l++;
				}
			}
		}else if(strcmp(argv[2],"sjf")==0){

			int w = 0,l=0,menor =0,texecution=0;
			//while(primerValor(&arrive)!=-1){

				//Para el primero
				a=pop(&(nuevo[0]));
				b=pop(&(nuevo[1]));
				ti = a;			
				tf = b + ti;				
				w = tf-a;					
   				printf("runs %d-%d -> end = %d, (arr = %d), turn = %d, (burst = %d), wait = %d\n",ti,tf,tf,ti,w,b,ti-a);		
				l++;
				texecution = tf;

				//Para el segundo
				int xx = menorC(&(nuevo[0]),&(nuevo[1]),texecution);

				a=pop(&(nuevo[0]));
				b=pop(&(nuevo[1]));
				do{
					if(b==xx){
						break;
					}
					push(&(espera[0]),a);
					push(&(espera[1]),b);
					a=pop(&(nuevo[0]));
					b=pop(&(nuevo[1]));
				}while(b!=-1);
				
				ti = tf;
				tf = b + ti;
 				w = tf-a;
   				printf("runs %d-%d -> end = %d, (arr = %d), turn = %d, (burst = %d), wait = %d\n",ti,tf,tf,ti,w,b,ti-a);
				texecution = tf;

				do{
					push(&espera[0],pop(&nuevo[0]));
					push(&espera[1],pop(&nuevo[1]));
				}while(primerValor(&nuevo[0])!=-1);
				
				//PARA EL RESTO
				while (sizeC(&espera[0])>0)
				{
					xx = menorC(&(espera[0]),&(espera[1]),texecution);

					do{
						l=0;
						a=pop(&(espera[0]));
						b=pop(&(espera[1]));
						if(b==xx){
							break;
						}
						push(&(espera[0]),a);
						push(&(espera[1]),b);
						l++;
					}while(l<sizeC(&espera[0]));
				
					ti = tf;
					tf = b + ti;
 					w = tf-a;
   					printf("runs %d-%d -> end = %d, (arr = %d), turn = %d, (burst = %d), wait = %d\n",ti,tf,tf,ti,w,b,ti-a);	   
					texecution = tf;
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
