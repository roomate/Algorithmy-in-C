#include <stdlib.h>
#include <stdio.h>

struct intervalle {
	int a;
	int b;
}

void affichage(int a, int b) {
	printf("[%d,%d]",a,b);
}

int main() {
	struct intervalle A={-1,9};
	struct intervalle B={-3,5};
	affichage(A.a,A.b);
	affichage(B.a,B.b);
}