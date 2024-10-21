#include <stdlib.h>
#include <stdio.h>

//division of a by b 
int quotient(int a, int b)
{
    unsigned int r = a;
    unsigned int q = 0;
    while (r >= b)
    {
        r = r - b;
        q++;
    }
    return q;
}

void divide(int a, int b, int nb_decim)
{
    if (b == 0) {printf("Error, denominator is 0.\n");}
    else
    {
        int r;
        if (a < 0 && b > 0)
        {
            printf("-");
            a = -a;
        }
        else if (a > 0 && b < 0)
        {
            printf("-");
            b = - b;
        }
        else if (a < 0 && b < 0)
        {
            a = -a;
            b = -b;
        }
        if (a >= b)
        {
            int quot = quotient(a,b);
            printf("%d", quot);
            r = a - quot*b;
        }
        else{
            printf("0");
            r = a;
        }
        while (r > 0 && nb_decim > 0)
        {
            printf(".");
            unsigned int k = 10;
            while (k*r < b) {k *= 10; printf("%d",0);}
            r = k*r;
            int quot = quotient(r,b);
            printf("%d",quot);
            nb_decim -= 1;
            r -= quot*b;
        }
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    if (argc != 4) {printf("Wrong number of arguments.\n"); return 1;}
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int nb_decim = atoi(argv[3]);
    divide(a,b, nb_decim);
    return 0;
}