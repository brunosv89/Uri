/* Leia quatro valores inteiros A, B, C e D. 
A seguir, calcule e mostre a diferen�a do produto de A e B pelo produto de C e D segundo a f�rmula:
DIFERENCA = (A * B - C * D). */

#include <stdio.h>

int main() {
	
	int a, b, c, d, dif = 0;
	
	scanf("%d", &a);	
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	
	dif = a * b - c * d;
	
	printf("DIFERENCA = %d", dif);
	
	
	
}
