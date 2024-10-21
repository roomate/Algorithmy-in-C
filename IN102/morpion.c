#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* creer_grille() {
	int* T = calloc(9,sizeof(int));
	return T;
}

void afficher(int* grille) {
	int i=0;
	char a;
	for (int i=0; i<9; i++) {
		if (grille[i]==0) {
			a='.';
		} else if (grille[i]==1) {
			a='x';
		} else {
			a='o';
		} 
		if (i%3==2) {
			printf("%c\n",a);
		} else {
			printf("%c",a);
		}
	}
}


void test_affichage() {
	int* T=creer_grille();
	afficher(T);
	T[3]=1;
	7[T]=2;
	printf("\n");
	afficher(T);
}

void placer(int* grille, int chiffre, int joueur) {
	grille[chiffre-1]=joueur;
}

void placer_alea(int* grille, int joueur) {
	srand(time(0));
	int a=rand()%9;
	while (grille[a]!=0) {
		a=rand()%9;
	}
	placer(grille,a,joueur);
}
int check( int* grille, int joueur, int start, int incrément) {
	int index = start;
	for (int i = 0; i<3; i++) {
		if (grille[index] != joueur) {
			return 0;
		}
		index += increment;
	}
	return 1;
}


int a_gagne(int* grille, int joueur) {
	for (int i=0; i<3; i++) {
		if (check(grille, joueur,i,3)==1) {
			return 1;
		}
	}
	for (int i=0; i<9; i+=3) {
		if(check(grille,joueur,i,1)==1) {
			return 1;
		}
	}
		if (check(grille,joueur,0,4)==1) {
			return 1;
		}
		if (check(grille,joueur,2,2)==1) {
			return 1;
		}
	return 0;
}

int main() {
	int *grille=creer_grille();
	int chiffre;
	int a=0;
	int i=rand()%2+1;
	int k=0;
	while (a=!0) {
		k+=1;
		if (k>9) {
			printf("Il s'agit d'un match nul");
			return 0;
		}
		joueur=i%2+1;
		i+=1;
		if (joueur==1) {
			scanf(" %c",&chiffre);
			placer(grille,chiffre,joueur);
		} else {
			placer_alea(grille, joueur);
		}
		a=a_gagne(grille, joueur);
	}
	printf("Le gagnant est le joueur %d", joueur);
}



