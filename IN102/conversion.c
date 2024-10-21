#include <stdio.h>
#include <stdlib.h>

int main() {
	float x = 2.05;
	float y = 5.0/9 * ( x-32 );
	printf("%.2f Farenheit == %.2f Celsius\n", x, y);
	int T[3]={2,3,4};
	for (int i=0; i<sizeof(T); i++) {
		printf("%d", T[i]);
	}
	return 0;
}