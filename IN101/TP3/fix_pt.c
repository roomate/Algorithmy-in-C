#include <stdlib.h>
#include <stdio.h>

typedef enum {true, false} bool;

bool fixpt(int* tab, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (tab[i] > i)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    int len = atoi(argv[1]);
    float* tab = malloc(sizeof(float)*len);
    for (int i= 0; i < len; i++)
    {
        tab[i] = atoi(argv[i + 2]);
    }
    bool res = fixpt(tab, len);
    switch(res)
    {
        case true : printf("There is a fixe point.\n"); break;
        case false : printf("There is no fixe point.\n"); break;
    }
    return 0;
}