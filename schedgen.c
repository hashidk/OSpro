#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

	if(argc == 5){
		if(atoi(argv[1]) > 0 && (atof(argv[2])>=0 && atof(argv[2])<1) && (atof(argv[3])>=0 && atof(argv[3])<1)){
			printf("Por el momento todo bien");
		}else{
		printf("ERROR: Valores incorrectos\n");
		}
	}else{
		printf("ERROR: Faltan valores o demasiados valores\n");
	}

return 0;
}
