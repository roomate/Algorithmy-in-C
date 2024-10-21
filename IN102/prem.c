#include <stdio.h>
/*int main() {
	int m=7;
	for (int i=1; i<=7; i++) {
		for (int j=1; j<=8+i; j++) {
			if (j<9) {
				printf(" ");
			} else {
				printf("*");
			}
		}printf("\n");
	}
}*/

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