#include <stdio.h>

int main (){
	
	//salário:
	float salario, faixa1, faixa2, faixa3, imposto, imposto1, imposto2,imposto3, valorimp;
	scanf("%f", &salario);
	
	if (salario => 0 && salario <= 2000.00)
		printf("Isento\n");
	
	if (salario > 2000.00 && salario <= 3000.00){
	
		faixa1 = salario - 2000;
		imposto = faixa1 * 0.08;
		printf("R$ %.2f\n", imposto);
	}
	
	if(salario > 3000.00 && salario <= 4500.00){
		
		faixa2 = salario - 3000;
		imposto2 = faixa2 * 0.18;
		imposto = 80.00 + imposto2;
		printf("R$ %.2f\n", imposto);
		
	}
		
	else {
		
		faixa3 = salario - 4500;
		imposto3 = faixa3 * 0.28;
		imposto = 80.00 + 270.00 + imposto3;
		printf("R$ %.2f\n", imposto);
	}
		
	
	return 0;
}
