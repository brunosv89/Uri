/* Leia dois valores inteiros.
A seguir, calcule o produto entre estes dois valores e atribua esta opera��o � vari�vel PROD.
A seguir mostre a vari�vel PROD com mensagem correspondente. */

#include <stdio.h>

int main() {
	
	int a, b, prod = 0;
	
	scanf("%d", &a);
	scanf("%d", &b);
	
	prod = a * b;
	
	printf("%d\n", prod);
	
}
