#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
	int dec=1000, N = atoi(argv[1]),a,b,i,j,k;
	int aux[2],procesos[2][N];


	srand(time(NULL));
	float r1,r2,pa=atof(argv[2]),pb=atof(argv[3]);
	FILE *f =fopen(argv[4], "w");

	if(argc == 5){
		if(N > 0 && (pa>=0 && pa<1) && (pb>=0 && pb<1)){
			for(k = 0; k < N; k++){
				for(i = 0; i < 50; i++){
					r1 = (rand()%(dec+1));
					r1 = r1/(dec);
					if(r1<pa){
						procesos[0][k] = i;
						break;
					}
				}

				for(j = 0; j < 50; j++){
					r2 = 1+(rand()%(dec+1));   
		       			r2 = r2/(dec);                             
					if(r2<pb){
						procesos[1][k] = j;
						break;
					}	
				}
			}

			for(i = 0; i < N-1; i++){
				for(k = 0; k < N-1; k++){
					if(procesos[0][k]>procesos[0][k+1]){
						aux[0]=procesos[0][k];
						aux[1]=procesos[1][k];

						procesos[0][k]=procesos[0][k+1];
						procesos[1][k]=procesos[1][k+1];

						procesos[0][k+1]=aux[0];
						procesos[1][k+1]=aux[1];
					}
				}	
			}

			for(i = 0; i < N-1; i++){
				f = fopen(argv[4], "a");
				fprintf(f,"%d %d\n",procesos[0][i],procesos[1][i]);
			}

		}else{
		printf("ERROR: Valores incorrectos\n");
		}
	}else{
		printf("ERROR: Faltan valores o demasiados valores\n");
	}

return 0;
}
