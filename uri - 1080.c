#include <stdio.h>

int main () {
	
	
	int vetor[100];
	int n, i, maior = 0, aux;
	
	for (n = 0; n < 100; n++){
		scanf("%d", &vetor[n]);
	}
	
	
	for (i = 0; i < 100; i++){
		if (vetor[i] > maior){
			maior = vetor[i];
			aux = i + 1;
		}	
	}
	
	printf("%d\n", maior);
	printf("%d\n", aux);
	
	return 0;
}
