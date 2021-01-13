#include <stdio.h>

int main () {
	
	int testes;
	//quantidade de casos de testes:
	scanf("%d", &testes);
	 	
 	//cada casos de testes:
 	
 	int quant = 0;
	int somatotal = 0;
	int somasapo = 0;
	int somacoelho = 0;
	int somarato = 0;
 	char animal;

	int i;
 	for (i = 0; i < testes; i++ ){
 		scanf("\n%d %c", &quant, &animal);	 //entrada de dados do usuario
 		somatotal = somatotal + quant;    //já obtenho a soma total das cobaias
 		if (animal == 'C')
 			somacoelho += quant;
 			//printf("Soma coelho: %d\n", somacoelho);
 		if (animal == 'R')
 			somarato += quant;
 			//printf("Soma rato: %d\n", somarato);
 		if (animal == 'S')
 			somasapo += quant;
			//printf("Soma sapo: %d\n", somasapo);
	}
	
	printf("Total: %d cobaias\n", somatotal);
	printf("Total de coelhos: %d\n", somacoelho);
	printf("Total de ratos: %d\n", somarato);
	printf("Total de sapos: %d\n", somasapo);
	
	float percentcoelho = (float) somacoelho / somatotal;
	float percentrato = (float) somarato / somatotal;
	float percentsapo = (float) somasapo / somatotal;
	 
	printf("Percentual de coelhos: %.2f %%\n", percentcoelho * 100);
	printf("Percentual de ratos: %.2f %%\n", percentrato * 100);
	printf("Percentual de sapos: %.2f %%\n", percentsapo * 100);
	return 0;
}
