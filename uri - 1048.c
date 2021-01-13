#include <stdio.h>

int main (){
	
	float sal, reaj, novosal, valorreaj, novoreaj;
		
	//ler o salario
	scanf("%f", &sal);
	
	//determinar o reajuste
	if (sal > 0 && sal < 400.00)
		reaj = 0.15;
	else if (sal > 400.00 && sal <= 800.00)
		reaj = 0.12;
	else if (sal > 800.00 && sal < 1200.00)
		reaj = 0.10;
	else if (sal > 1200.00 && sal < 2000.00)
		reaj = 0.07;
	else
		reaj = 0.04;
	
	valorreaj = sal * reaj;
	novosal = valorreaj + sal;
	
	if (novosal > 0 && novosal < 400.00)
		novoreaj = 15;
	else if (novosal > 400.00 && novosal <= 800.00)
		novoreaj = 12;
	else if (novosal > 800.00 && novosal < 1200.00)
		novoreaj = 10;
	else if (novosal > 1200.00 && novosal < 2000.00)
		novoreaj = 7;
	else
		novoreaj = 4;
	
	printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %.0f %%\n", novosal, valorreaj, novoreaj);
		
	return 0;
	
	
}
