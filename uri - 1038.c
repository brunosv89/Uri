#include <stdio.h>

int main() {
	
	
	float lanche, total;
	int quant, cod;
	
	//escolher o codigo
	scanf("%d", &cod);
	switch(cod){
		case 1:
			lanche = 4.00;
			break;
		case 2:
			lanche = 4.50;
			break;
		case 3:
			lanche = 5.00;
			break;
		case 4:
			lanche = 2.00;
			break;
		case 5:
			lanche = 1.50;
			break;
	}
	
	//insere a quantidade
	scanf("%d", &quant);
	//calcula o valor total
	total = (lanche * quant);
	//imprime
	printf("Total: R$ %.2f\n", total);
	
	return 0;
}

