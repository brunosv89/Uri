/* Fa�a um programa que leia o nome de um vendedor, o seu sal�rio fixo e o 
total de vendas efetuadas por ele no m�s (em dinheiro). 
Sabendo que este vendedor ganha 15% de comiss�o sobre suas vendas efetuadas,
informar o total a receber no final do m�s, com duas casas decimais. */

#include <stdio.h>

int main() {


char nome;
double salariototal, salfixo, vendas = 0;

scanf("%s", &nome);
scanf("%lf", &salfixo);
scanf("%lf", &vendas);

salariototal = salfixo + (vendas * 0.15);

printf("TOTAL = R$ %lf\n", salariototal);

}
