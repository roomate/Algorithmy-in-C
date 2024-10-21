// #include <stdio.h>

// int main(void) {
// 	int n=10;
// 	for (int i=1; i<=n; i++) {
// 		for ( int j=1; j<=n; j++) {
// 			printf("%d x %d = %2d ",i ,j, i*j);
// 		}
// 	printf("\n");
// 	}
// }

// #include <stdio.h>
// void multiplier(int* px, int c) {
//    *px = *px * c;
// }
// int main() {
//   int x = 7;
//   int y = 3;
//   multiplier(&x,y);
//   printf("%d\n",x);
// }

#include <stdio.h>

int position( char* ch, char x) {
	int i=0;
	while (ch[i]!=0) {
		if ( ch[i]==x) {
			printf("%d", i);
			return 0;
		}
		i+=1;
	}
	printf("-1");
	return 0;
}

int main() {
	char M[]= "suissesse";
	position(M,'x');
	int T[3]={2,3,4};
	for (int i=0; i<sizeof(T); i++) {
		printf("%d", T[i]);
	}
	return 0;
}
