#include <stdio.h>
#include <string.h>

int main(){

	int ddd;
	char cidade[15];	
	
	scanf("%d", &ddd);
	switch(ddd){
		case 61: 
			strcpy(cidade, "Brasilia");
			printf("%s\n", cidade);
			break;
		case 71:
			strcpy(cidade, "Salvador");
			printf("%s\n", cidade);
			break;
		case 11: 
			strcpy(cidade, "Sao Paulo");
			printf("%s\n", cidade);
			break;
		case 21:
			strcpy(cidade, "Rio de Janeiro");
			printf("%s\n", cidade);
			break;
		case 32: 
			strcpy(cidade, "Juiz de Fora");
			printf("%s\n", cidade);
			break;
		case 19:
			strcpy(cidade, "Campinas");
			printf("%s\n", cidade);
			break;
		case 27:
			strcpy(cidade, "Vitoria");
			printf("%s\n", cidade);
			break;
		case 31:
			strcpy(cidade, "Belo Horizonte");
			printf("%s\n", cidade);
			break;
		default:
			printf("DDD nao cadastrado\n");
	}
					
	return 0;	
}

