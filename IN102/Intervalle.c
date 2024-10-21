#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct intervalle {
	int a;
	int b;
};


void affichage(int a, int b) {
	printf("[%d,%d]\n",a,b);
}

void saisie_intervalle() {
	int z;
	int e;
	scanf("%d",&z);
	scanf("%d",&e);
	affichage(fmin(z,e),fmax(z,e));
}

struct intervalle intersection(struct intervalle A, struct intervalle B) {
	struct intervalle C;
	C.a=fmax(A.a, B.a);
	C.b=fmin(A.b,B.b);
	if (C.a > C.b) {
		printf("L'intersection est l'ensemble vide");
	}

	return C;
}

struct intervalle* saisie_tableau(int N) {
	struct intervalle* T=calloc(N,sizeof(struct intervalle));
	for (int i=0; i<N; i++) {
		saisie_intervalle();
	}
	return T;
}

void intersection_tableau(struct intervalle* A, int N) {
	int i=N;
	while (i>1) {
		struct intervalle D = intersection(A[0],A[i-1]);
		if ( D.a <= D.b ) {
			A[0].a=D.a;
			A[0].b=D.b;
			i=i-1;
		} else {
			i=i-1;
		}
	affichage(A[0].a,A[0].b);
	}
}

void affichage_tableau_inverse(struct intervalle* A, int N) {
	struct intervalle I;
	for (int i=0; i<N/2; i++) {
		I=A[i];
		A[i]=A[N-i-1];
		A[N-1-i]=I;
	}
	for (int i=0; i<N; i++) {
		affichage(A[i].a,i[A].b);
	}
}

int main() {
	int N;
	printf("Quelle longueur de tableau ?");
	scanf("%d", &N);
	struct intervalle* B=calloc(N,sizeof(struct intervalle));
	for (int i=0; i<N; i++) {
		int A;
		int C;
		scanf("%d",&A);
		scanf("%d",&C);
		B[i]=(struct intervalle) {A,C};
	}
	intersection_tableau(B,N);
	affichage_tableau_inverse(B,N);
	return 0;
}