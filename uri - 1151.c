#include <stdio.h>

int main() {
	
	int n;
	scanf("%d", &n);
	
	printf("0 1");
	int i, soma;
	int ant1 = 0, ant2 =1;
	
	for (i = 2; i < n; i = i + 1) {
		soma = ant1 + ant2;                    
  		ant1 = ant2;                           
  		ant2 = soma;
  		printf(" %d", soma);
	}
	printf("\n");
	return 0;	
}
