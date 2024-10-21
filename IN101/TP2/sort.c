#include <stdio.h>
#include <stdlib.h>

typedef enum {true, false} bool;

bool sort(float* tab, int len)
{
    if (len < 2) {return true;}
    bool sense = (tab[0] < tab[len - 1]);
    if (sense)
    {
        for (int i = 0; i < len - 1; i++)
        {
            if (tab[i + 1] < tab[i]) {return false;}
        }
        return true;
    }
    else
    {
        for (int i = 0; i < len - 1; i++)
        {
            if (tab[i + 1] > tab[i]) {return false;}
        }
        return true;
    }
}

int main(int argc, char* argv[])
{
    int len = atoi(argv[1]);
    float *tab = malloc(len*sizeof(float));
    for (int i = 0; i < len; ++i)
    {
        tab[i] = atof(argv[i + 2]);
    }
    bool res = sort(tab, len);
    switch(res)
    {
        case false : printf("The tab is not sorted.\n"); break;
        case true : printf("The tab is sorted.\n"); break;
    }
    return 0;
}