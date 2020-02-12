#include <stdio.h>
#include <stdlib.h>

int main(void){
	int mat[7][7];
	char tmp1[50];
	int i,j, aux;

	FILE *file;
	
	file = fopen("MATRIZ_7x7.txt", "r"); //Lendo o arquivo já pronto com as virgulas.
	
	if(file == NULL){
		printf("Arquivo nao pode ser aberto.");
		return 0;
	}
	
	for(i = 0; i < 7; i++){
		for(j = 0; j < 7; j++){
			fscanf(file, "%d,", &mat[i][j]); //Lendo cada elemento que está na matriz.
		}
	}

	for(i = 0; i < 7; i++){
		for(j = 0; j < 7; j++){ //imprimindo na tela a minha matriz sem as virgulas.
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	
	for (i = 0; i < 7; i++) {
		for (j = i+1; j < 7; j++) { //fazendo a matriz transposta.
			if (j != i){
   				aux = mat[i][j];
   				mat[i][j] = mat[j][i];
   				mat[j][i] = aux;
			}
    	}
	}
  	
  	fclose(file); //fecho o arquivo
  	
  	file = fopen("MATRIZ_TRANS.txt", "w"); //abrindo novamente para criar outro arquivo.
  	
  	fprintf(file, "Matriz transposta: \n"); 
  	
	for (i = 0; i < 7; i++) {
    	for (j = 0; j < 7; j++) { 
			fprintf(file, "%d ", mat[i][j]); //escrevendo a matriz em um novo arquivo.
    	}
    	fprintf (file, "\n");
	}
	
	fclose(file);
}
