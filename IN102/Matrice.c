#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>


void calcul_norme(int* M, int n) {
	int L=0;
	int N;
	int k;
	for (int j=0; j<n; j++) {
		N=0;
		for (int i=0; i<n; i++) {
			N+=abs(M[n*i+j]);
		}
		if (N>L) {
			L=N; 
			k=j;
		}
	}
	printf("%d, %d", L,k);
}


int main(int argc, char* argv[]) {
	int n=atoi(argv[1]);
	int a;
	int* T=calloc(n*n,sizeof(int));
	for (int i=0; i<n; i++ ) {
		for (int j=0; j<n; j++) {
			scanf("%d", &a);
			T[n*i + j]=a;
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n-1; j++) {
			printf("%d,", T[n*i+j]);
		}
		printf("%d\n",T[n*i+n-1]);
	}
	calcul_norme(T,n);
	free(T);
	return 0;
}