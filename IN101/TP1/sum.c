#include <stdlib.h>
#include <stdio.h>

int sum(int x, int y)
{
    int res = 0;
    for (int i = x; i <= y; i++)
    {
        if (i % 5 == 0 && i % 2 != 0)
        {
            res = res + i;
        }
    }
    return res;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        printf("Wrong number of arguments.\n");
        return 1;
    }
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    
    int summ = sum(x,y);
    printf("The result is %d\n", summ);
    return 0;
}