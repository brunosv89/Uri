/*Faça um programa que leia três valores e apresente o maior dos três valores
 lidos seguido da mensagem “eh o maior”*/

#include <stdio.h>

int main(){
	
	int a, b, c, maiorAB, maiorABC;
	
	scanf("%d %d %d", &a, &b, &c);
	
	maiorAB = (a + b + abs(a-b)) / 2;
	maiorABC = (maiorAB + c + abs(maiorAB - c)) / 2;
	
	printf("%d eh o maior\n", maiorABC);
	
	return 0;
	
	
}
