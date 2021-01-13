/* Leia 2 valores de ponto flutuante de dupla precisão A e B,
que correspondem a 2 notas de um aluno. A seguir, calcule a média do aluno, 
sabendo que a nota A tem peso 3.5 e a nota B tem peso 7.5 (A soma dos pesos portanto é 11).
Assuma que cada nota pode ir de 0 até 10.0, sempre com uma casa decimal. */

#include <stdio.h>

int main() {
	
	double a, b, media = 0;
	
	scanf("%lf", &a);
	scanf("%lf", &b);
	
	a = a * 3.5;
	b = b * 7.5;
	
	media = (a + b) / 11;
	
	printf("MEDIA = %.5lf\n", media);
	
	
}
