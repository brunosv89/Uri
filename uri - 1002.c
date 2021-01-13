/*
A fórmula para calcular a área de uma circunferência é: area = p . raio2.
Considerando para este problema que p = 3.14159:
- Efetue o cálculo da área, elevando o valor de raio ao quadrado e multiplicando por p.
*/

#include <stdio.h>

int main() {
	
double raio = 0;
double p = 3.14159;
double area = 0;

scanf("%lf", &raio);

area = (p * (raio * raio));

printf("A=%.4lf\n", area);

	
}
