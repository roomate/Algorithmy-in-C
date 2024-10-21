#include <stdio.h>
#include <stdlib.h>




int trouver_max(int* X, int m) {
	int k=0;
	int max=X[0];
	for (int i=1; i<=m-1; i++) {
		if (max < X[i]) {
			max=X[i];
			k=i;
		}
	}
	printf("%d, %d\n", max, k);
	return max;
}

int main(int argc, char *argv[]) {
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	int z = atoi(argv[3]);
	int T[3];
	T[0]=x;
	T[1]=y;
	T[2]=z;
	int M=trouver_max(T,3);
	printf("le plus grand des 3 nombres est %d", M);
}


int main() {
	int n=20;
	int T[n];
	T[0]=3;
	for (int i=1; i<=n; i++) {
		if (T[i-1]%2==0) {
			T[i]=T[i-1]/2;
		} else {
			T[i]= 3*T[i-1] + 1;
		}
	}
	trouver_max(T,n);
	int L[3]={2,3,4};
	for (int i=0; i<sizeof(L); i++) {
		printf("%d", L[i]);
	}
}