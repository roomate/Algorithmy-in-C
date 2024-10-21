#include <stdio.h>

#include <stdlib.h>

struct guerrier {
	char* nom;
	double lifepoint;
	double healthrate;
	int attackpoint;
};

void afficher_guerrier (struct guerrier g) {
	printf("Le guerrier s'appelle %s et a %.2f points de vie\n", g.nom, g.lifepoint);
};

void attaque(struct guerrier* pjoueurs, struct guerrier* padversaires) {
	padversaires->lifepoint = padversaires->lifepoint - pjoueurs->attackpoint;
};

void bouclier(struct guerrier* pjoueur) {
	pjoueur->lifepoint = pjoueur->lifepoint + pjoueur->healthrate*(100 - pjoueur->lifepoint);
};

void swap( struct guerrier** ppjoueur, struct guerrier** ppadversaire) {
	struct guerrier* temp = *ppjoueur;
	*ppjoueur = *ppadversaire;
	*ppadversaire = temp;
};

int rand_int( int p) {
	return 2 * rand()%(p+1) - p;
}

int main() {
	struct guerrier Ar = { "Aragorn", 100, 0.6, 20};
	struct guerrier Bo = { "Boromir", 100, 0.4, 30};
	struct guerrier* pjoueur = &Ar;
	struct guerrier* padversaire = &Bo;
	char touche;
	int nb_tour=0;
	struct guerrier* gagnant = 0;
	while ( Ar.lifepoint>0 && Bo.lifepoint>0) {
		scanf(" %c",&touche);
		if (touche == 'a') {
			attaque(pjoueur,padversaire);
		} else if ( touche == 'b') { 
			bouclier( pjoueur);
		}
		afficher_guerrier(*pjoueur);
		afficher_guerrier(*padversaire);
		padversaire->lifepoint = padversaire->lifepoint + rand_int(5);
		swap(&pjoueur, &padversaire);
		nb_tour+=1;
	}
	gagnant=padversaire;
	printf("Le gagnant est %s", gagnant->nom);
}
