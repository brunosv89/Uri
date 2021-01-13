#include <stdio.h>

int main () {
	
	int testes, PA, PB, anos=0, i;
	double G1, G2;
	int cresc1, cresc2;
	
	//casos de teste:
	scanf("%d", &testes);
	
	for (i = 0; i < testes; i++){
		scanf("%d %d %lf %lf", &PA, &PB, &G1, &G2);
		anos = 0;
		while (PA <= PB && anos <= 100){
			cresc1 = PA * (G1/100);
			cresc2 = PB * (G2/100);
			PA = PA + cresc1;
			PB = PB + cresc2;
			anos += 1;
		}
		if (anos <= 100)
			printf("%d anos.\n", anos);
		else
			printf("Mais de um seculo.\n");	
	}
	 		
	return 0;
}
