#include <stdio.h>

int main (){
	
	float vetor[6];
	int i;
	int quantos = 0;
	float soma = 0;
	float media;
	
	for (i=0; i<6; i++){
		scanf("%f", &vetor[i]);
		if (vetor[i] > 0){
			quantos += 1;
			soma = soma + vetor[i];
		}
	}
	media = soma/quantos;
	
	printf("%d valores positivos\n", quantos);
	printf("%.1f\n", media);
	
	return 0;
}
