#include <stdio.h>

int main () {
	
	int vetor[5];
	int i;
	int par = 0;
	int impar = 0;
	int pos = 0;
	int neg= 0;
	int lixo = 12;
	
	for (i=0; i<5; i++){
		scanf("%d", &vetor[i]);
		if (vetor[i] %2 == 0)
			par += 1;
		else
			impar += 1;
		
		if (vetor[i] == 0)
			lixo += 24;
		if (vetor[i] > 0)
			pos += 1; 
		if (vetor[i] < 0)
			neg += 1;
				
	}
	printf("%d valor(es) par(es)\n", par);	
	printf("%d valor(es) impar(es)\n", impar);
	printf("%d valor(es) positivo(s)\n", pos);
	printf("%d valor(es) negativo(s)\n", neg);
	return 0;
}
