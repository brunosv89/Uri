/* Escreva um programa que leia o n�mero de um funcion�rio, seu n�mero de horas trabalhadas, 
o valor que recebe por hora e calcula o sal�rio desse funcion�rio. 
A seguir, mostre o n�mero e o sal�rio do funcion�rio, com duas casas decimais. */

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
