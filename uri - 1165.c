#include <stdio.h>

int main (){
	
	int n, i, entradas = 0, count = 0;
	scanf("%d", &entradas);
	
	for (i = 0; i < entradas; i++) {
		scanf("%d", &n);
		int verificador = 0;
		for (count = 2; count <= n/2; count++){
		
			if (n % count == 0) {
				verificador++;
				break;
			}
		}
		if (verificador == 0)
			printf("%d eh primo\n", n);
		else
			printf("%d nao eh primo\n", n);		
	}
	
	return 0;
}
