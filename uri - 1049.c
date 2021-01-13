/*Neste problema, você deverá ler 3 palavras que definem o tipo de animal possível segundo o esquema
 abaixo, da esquerda para a direita.
Em seguida conclua qual dos animais seguintes foi escolhido, através das três palavras fornecidas. */

#include <stdio.h>
#include <string.h>

int main(){
	
	char p1[15], p2[15], p3[15];
		
	//ler 3 palavras
	scanf("%s", &p1);
	scanf("%s", &p2);
	scanf("%s", &p3);
	
	
	if (strcmp(p1, "vertebrado") == 0)
		if (strcmp(p2, "ave") == 0)
			if (strcmp(p3, "carnivoro") == 0)
				printf("aguia\n");
			else
				printf("pomba\n");	
		else //mamifero
			if (strcmp(p3, "onivoro") == 0)
				printf("homem\n");
			else //herbivoro
				printf("vaca\n");
	else //invertebrado
		if (strcmp(p2, "inseto") == 0)
			if (strcmp(p3, "hematofago") == 0)
				printf("pulga\n");
			else
				printf("lagarta\n");	
		else //anelideo
			if (strcmp(p3, "hematofago") == 0)
				printf("sanguessuga\n");
			else
				printf("minhoca\n");
	
	return 0;
}
