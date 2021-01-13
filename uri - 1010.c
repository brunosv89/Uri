#include <stdio.h>

int main() {
	
	
	int c1, c2, p1, p2;
	float v1,v2;
	float valor1, valor2, total;
	
	scanf("%d %d %f", &c1, &p1, &v1);
	scanf("%d %d %f", &c2, &p2, &v2);
	 
	valor1 = (p1 * v1);
	valor2 = (p2 * v2);
		
	total = (valor1 + valor2);
	
	printf("VALOR A PAGAR: R$ %.2f", total);
	
}

