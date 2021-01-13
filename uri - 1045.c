/* Leia 3 valores de ponto flutuante A, B e C e ordene-os em ordem decrescente,
de modo que o lado A representa o maior dos 3 lados. A seguir, determine o 
tipo de triângulo que estes três lados formam, com base nos seguintes casos, 
sempre escrevendo uma mensagem adequada:

    se A = B+C, apresente a mensagem: NAO FORMA TRIANGULO
    se A2 = B2 + C2, apresente a mensagem: TRIANGULO RETANGULO
    se A2 > B2 + C2, apresente a mensagem: TRIANGULO OBTUSANGULO
    se A2 < B2 + C2, apresente a mensagem: TRIANGULO ACUTANGULO
    se os três lados forem iguais, apresente a mensagem: TRIANGULO EQUILATERO
    se apenas dois dos lados forem iguais, apresente a mensagem: TRIANGULO ISOSCELES */
    
#include <stdio.h>
    
int main(){
    	
	double a, b, c, aux;
	scanf("%lf %lf %lf", &a, &b, &c);
	    	
    if (c > a){
    	
		aux = a;
		a = c;
  		c = aux;
    }
  
  	if (b > a){
  		aux = a;
  		a = b;
  		b= aux;
	}
	  		
  	if (c > b) {
		aux = b;
		b = c;
		c = aux;
	}	
  		
  	//printf("%.1lf %.1lf %.1lf", a, b , c);
  	
  	if (a >= b + c)
  		printf("NAO FORMA TRIANGULO\n");
  	
	else if ((a*a) == (b*b) + (c*c)) {
  		printf("TRIANGULO RETANGULO\n");
  		if(a == b && b == c)
  			printf("TRIANGULO EQUILATERO\n");
  		else if(a == b || b == c || a == c)
  			printf("TRIANGULO ISOSCELES\n");
	
  		}
  	
	else if((a*a) > (b*b) + (c*c)) {
	
  		printf("TRIANGULO OBTUSANGULO\n");
  		if(a == b && b == c)
  			printf("TRIANGULO EQUILATERO\n");
  		else if(a == b || b == c || a == c)
  			printf("TRIANGULO ISOSCELES\n");
  
  		}
  		
	
	else {

  		printf("TRIANGULO ACUTANGULO\n");
  		if(a == b && b == c)
  			printf("TRIANGULO EQUILATERO\n");
  		else if(a == b || b == c || a == c)
  			printf("TRIANGULO ISOSCELES\n");
	
		}
	  
	  	
   	return 0;
   	
}

