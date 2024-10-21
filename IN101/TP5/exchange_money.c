#include <stdio.h>
#include <stdlib.h>

//compute the debt assigned to each person.
float *debt_vect (float** graph, int len_graph)
{
    float* debt = malloc(sizeof(int)*len_graph);
    if (debt == NULL)
    {
        printf("Error. Unable to allocate memory.\n");
        exit(1);
    }
    for (int i = 0; i < len_graph; i++) {debt[i] = 0;}
    for (int i = 0; i < len_graph; i++)
    {
        for (int j = 0; j < len_graph; j++)
        {
            debt[i] -= graph[i][j];
            debt[j] += graph[i][j];
        }
    }
    return debt;
}

int find_index_max(float *debt, int len)
{
    int index = 0;
    float max = debt[0];
    for (int i = 1; i < len; i++)
    {
        if (debt[i] > max) {index = i; max = debt[i];}
    }
    return index;
}

int find_index_min(float *debt, int len)
{
    int index = 0;
    float min = debt[0];
    for (int i = 1; i < len; i++)
    {
        if (debt[i] < min) {index = i; min = debt[i];}
    }
    return index;
}

#define min(x, y) ((x < y) ? x : y)

void print(float* debt, int len)
{
    int index_min = find_index_min(debt, len);
    int index_max = find_index_max(debt, len);
    float flow;
    if (debt[index_min] == 0) {return;}
    while (debt[index_min] != 0)
    {
        flow = min(-debt[index_min], debt[index_max]);
        debt[index_min] += flow;
        debt[index_max] -= flow;
        printf("P%d owes %f to P%d.\n", index_min, flow, index_max);
        index_min = find_index_min(debt, len);
        index_max = find_index_max(debt, len);
    }
}

int main()
{
    int len = 4;
    float **tab = malloc(sizeof(float*)*len);
    if (tab == NULL) {printf("Error. Unable to allocate memory.\n"); return 1;}
    for (int i = 0; i < len; i++)
    {
        tab[i] = calloc(len, sizeof(float));
        if (tab[i]== NULL)
        {
            printf("Error. Unable to allocate memory.\n");
            for (int j = i - 1; j >= 0; j--) {free(tab[j]); printf("Error. Unable to allocate memory.\n");}
            return 1;
        }
        tab[i][i] = 0;
    }
    tab[0][1] = 100; tab[3][1] = 40; tab[3][2] = 20; tab[0][2]= 50; tab[2][0] = 75;

    float* debt = debt_vect(tab, len);
    print(debt, len);
    for (int i = 0; i < len; i++)
    {
        free(tab[i]);
    }
    free(tab);
    free(debt);
    return 0;
}
