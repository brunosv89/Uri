/* Escreva um programa que leia o número de um funcionário, seu número de horas trabalhadas, 
o valor que recebe por hora e calcula o salário desse funcionário. 
A seguir, mostre o número e o salário do funcionário, com duas casas decimais. */

#include <stdio.h>

int main() {
	
	int n, h = 0;
	float valor = 0;
	float salario = 0;
	
	scanf("%d", &n);
	scanf("%d", &h);
	scanf("%f", &valor);
	
	salario = h * valor;
	
	printf("NUMBER = %d\nSALARY = U$ %f", n, salario); 
	
}
