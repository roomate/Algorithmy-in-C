#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char nth (char* L, int a) {
	if (a>=0 && a<strlen(L)) {
		printf("Le caractère a la %d ième position est %c",a + 1,L[a]);
		return L[a];
	} else {
		printf("Error");
		return '!';
	}
}

float poly( float x) {
	float y = x*(2 + x*x*( 5 - 3*x))+ 5;
	return y;
}

void col(float* A, float* B, float* C) {
	if ((B[0]-A[0])*(C[1]-A[1])==((B[1]-A[1])*(C[0]-A[0]))) {
		printf("Les points sont alignés");
	} else {
		printf("Les points ne sont pas alignés");
	}
}

enum bool_option {
	BO_False;
	BO_True;
	BO_error;
}

enum bool_option same_sum (int n, unsigned int c) {
	if (c>9) return BO_Error;
	if (n<0) return BO_False;
	if (c==0) return ((n==0) ? BO_True : BO_False);
	return ((n%c == 0) ? BO_True : BO_False);
}




// int main( int argc, char *argv[]) {
// 	if (argc !=3) {
// 		printf("Error, Wrong number of arguments.\n");
// 		return 1;
// 	}

// 	switch (same_sum(atoi(argv[1]), atoi (argv[2]))) {
// 		case BO_True : printf("True\n"); break; 
// 		case BO_False : printf("False\n"); break;
// 		case BO_Error : printf("Error. Invalid input.\n"); break;
// 	}
// 	return 0;
// }

bool changed_digit(char* str) {
	char must_be;
	int start_at=1;

	if (str[0] == '+') { must_be='9' ; start_at=2};
	else if (str[0]=='-') { must_be = '0' ; start_at=2};
	else if (str[1]=='\0') return true;
	else must_be='9';

	while (str[start_at]!='\0') {
		if (str([start_at]!= must_be)) return false;
		start_at ++;
	}


int main (int argc, char* argv[]) {
	if (argc !=2) {
		printf("Error. Wrong number of arguments.\n");
		return 1;
	}
	printf("%d\n", change(argv[1]));
	return 0;
}