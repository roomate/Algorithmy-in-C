#include <stdio.h>
#include <stdlib.h>

void egypt_frac(long int a, long int b, long int* sequence, int *index)
{
    if (a == 0) {return;}
    if (a % b == 0) { sequence[*index] = b/a; return;}
    int n;
    if (*index == 0) {n = 2;}
    else {n = sequence[*index - 1];}
    while (n*a - b < 0) {n++;}
    sequence[*index] = n;
    *index += 1;
    printf("%d\n", *index);
    egypt_frac(n*a-b, n*b, sequence, index);
}

int main(int argc, char* argv[])
{
    if (argc != 3) {printf("Wrong number of argument.\n");}
    long int a = atoi(argv[1]);
    long int b = atoi(argv[2]);
    if (a > b) {printf("Error, numerator is greator than denominator.\n"); return 1;}
    if (a < 0 || b < 0){printf("Error, numerator or denominator is negative.\n"); return 1;}
    long int* sequence = calloc(256,sizeof(long int));
    printf("The egyptian fraction of %ld/%ld is:\n", a,b);
    printf("%ld/%ld = ",a,b);
    int i = 0;
    int *index = &i;
    egypt_frac(a,b,sequence,index);
    printf("1/%ld", sequence[0]);
    for (int i = 1; sequence[i] != 0; i++)
    {
        printf(" + ");
        printf("1/%ld ", sequence[i]);
    }
    printf("\n");
    return 0;
}