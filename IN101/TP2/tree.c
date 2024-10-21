#include <stdlib.h>
#include <stdio.h>

int poww(int a, int n)
{
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        res *= a;
    }
    return res;
}

void space_extr(int n)
{
    for (int i = 0; i < poww(2, n) - 1; i++)
    {
        printf(" ");
    }
}

void space_inter(int n)
{
    for (int i = 0; i < poww(2, n+1) - 1; i++)
    {
        printf(" ");
    }
}

void tree(int h)
{
    for (int n = h - 1; n >= 0; n--)
    {
        space_extr(n);
        for (int i = 0; i < poww(2,h - 1 - n) - 1; i++)
        {
            printf("*");
            space_inter(n);
        }
        printf("*");
        space_extr(n);
        printf("\n\n");
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Wrong number of arguments.\n");
        return 1;
    }
    int h = atoi(argv[1]);
    tree(h);
    return 0;
}