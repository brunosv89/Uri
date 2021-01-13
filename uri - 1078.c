#include <stdio.h>

int main () {
	
	int N; 
	scanf("%d", &N);
	
	int i;
	for (i=1; i <= 10; i++){
		printf("%d x %d = %d\n", i, N, i*N);
	}
	
	return 0;
}
