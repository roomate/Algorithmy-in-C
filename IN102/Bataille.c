#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #define N 6

// int c2i(int x, int y) {
// 	return x-1 + (y-1)*N;
// }

// enum etat { vide, occupe, rate, detruit};

// void afficher(int* grille, int cache) {
// 	for (int i=1; i<=N; i++) {
// 		for (int j=1; j<=N; j++) {
// 			if (grille[c2i(j,i)]==vide) {
// 				printf(".");
// 			} else if (grille[c2i(j,i)]==occupe) {
// 				if (cache==1) {
// 					printf("*");
// 				} else {
// 					printf(".");
// 				}
// 			} else if (grille[c2i(j,i)]==rate) {
// 				printf("O");
// 			} else if (grille[c2i(j,i)]==detruit) {
// 				printf("X");
// 			}
// 		}
// 		printf("\n")
// 	}
// }

// enum sens {droit, bas};
// void placer(int* grille, int i, int j, int lng) {
// 	srand(time(0));
// 	int s=rand()%2;
// 	if (s==droit) {
// 		for (int l=0; l<lng; l++) {
// 			grille[c2i(i,j)+l]=occupe;
// 		}
// 	} else if (s==bas) {
// 		for (int l=0; l<lng; l+=N) {
// 			grille[c2i(i,j)+l]=occupe;
// 		}
// 	}
// }

// void placer_alea(int* grille, int lng) {
// 	srand(time(0));
// 	int a=rand()%(N*N);
// 	int b=1;
// 	int i=0;
// 	while (b==1) {
// 		i=0;
// 		while (a%6 + lng - 1 >=6) {
// 			a=rand()%(N*N);
// 		}
// 		while (grille[a+i]==vide && i<lng) {
// 			i+=1;
// 		}
// 		if (i==lng) {
// 			b=0;
// 		}
// 	placer(grille,a%6,a/6,lng);
// 	}
// }

// void tirer(int* grille, int i, int j) {
// 	if (grille[c2i(i,j)]==vide) {
// 		grille[c2i(i,j)]=rate;
// 	} else if (grille[c2i(i,j)]) {
// 		grille[c2i(i,j)]=detruit;
// 	}
// }

// int tout_detruit(int* grille) {
// 	for (int i=1; i<=N; i++) {
// 		for (int j=1; j<=N; j++) {
// 			if (grille[c2i(j,i)]==occupe) {
// 				return 0;
// 			}
// 		}
// 	}
// 	return 1;
// }



// int main() {
// 	int* grille=calloc(N*N, sizeof(int));
// 	int i;
// 	int j;
// 	int k=0;
// 	placer_alea(grille);
// 	while (tout_detruit(grille)==0) {
// 		k+=1;
// 		printf("Donnez la coordonnée i");
// 		scanf("%i", &i);
// 		printf("Donnez la coordonnée j");
// 		scanf("%i", &j);
// 		tirer(grille,i,j);
// 	}
// 	printf("Il y a eu %d tours joués", k);
// 	return 0;
// }

double vec [10];

double element(int i)
{
	return vec[i - 1];

}

int main()
{
	for (int i = 0; i<10; ++i)
	{
		double b = element(i);
		double* a = &b;
		*a = i;
	}
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", 3);
	}
	return 0;
}