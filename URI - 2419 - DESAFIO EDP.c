/////// Desafio de Grafos - EDP
////// Aluno: Bruno Soares Vasques
///// Dezembro 2020


#include <stdio.h>
#include <string.h>

// Considera-se que um quadrado é parte da costa nlogônica se:
// ele é um quadrado ocupado por terra que tem um lado em comum com um quadrado ocupado por água.
// terra: #
// agua: .
// Saída: quantos quadrados fazem parte da costa? Ou seja, quantos # possuem . como vizinho?

#define L 100
#define C 100

int verificaCosta (char m[L][C], int l, int c) {
	
	int soma;
	int i,j;
	
	for (i=0; i<l; i++){
		for (j=0; j<c ; j++){
			if (m[i][j] == '#')
				if (m[i-1][j] != '#' || m[i][j-1] != '#' || m[i][j+1] != '#' || m[i+1][j] != '#' )
					soma += 1;
		}
	}
	
	printf("\nO numero de quadrados-costa eh: %d", soma);
	
}


int main () {
	
	int linhas=0, colunas=0;
	char matriz[L][C];
	
	printf("linhas e colunas: "); // lê numero de linhas e colunas
	fflush(stdin);
	scanf("%d %d", &linhas, &colunas);
	
	// preenchendo o mapa
	int i;
	for(i=0; i<linhas; i++)                               
		scanf("%s", &matriz[i]); 
		
	// imprimindo mapa
	printf("\nO Mapa de Nlogonia:\n");
	int p,q;
	for (p = 0 ; p<linhas ; p++){
		printf("\n");
		for (q = 0 ; q<colunas ; q++){
			printf("%c ", matriz[p][q]);
		}
		
	}
	printf("\n");
	
	// varrendo e calculando:
	verificaCosta (&matriz, linhas, colunas);
	

}


