#include <stdio.h>
#include <stdlib.h>

#define min(x, y) ((x < y) ? x : y)
#define max(x, y) ((x > y) ? x : y)

int jackpot(int *pots, int l, int r)
{
    if (r == l + 1) {return max(pots[l], pots[r]);}
    if (l == r) {return pots[l];}

    int inter = jackpot(pots, l + 1, r - 1); //Player 1 takes the left-most pot and Player 2 the right-most pot; or the opposite.

    int double_right = jackpot(pots, l, r - 2); //Player 2 and 1 take the right-most pot.

    int double_left = jackpot(pots, l + 2, r); //Player 1 and 2 take the left-most pot.

    int inter_right = min(inter, double_right); //decide the choice of player 2 if player 1 takes the right-most
    int inter_left = min(inter, double_left); // ... if Player 1 takes the left-most.

    return max(pots[r] + inter_right, pots[l] + inter_left);
}

int main(int argc, char* argv[])
{
    if (argc < 2) {printf("Error. Wrong number of arguments.\n"); return 1;}

    int size = atoi(argv[1]);
    int *pots = malloc(sizeof(int)*size);

    for (int i = 0; i < size; i++) {pots[i] = atoi(argv[i+2]);}
    int l = 0; int r = size - 1;
    printf("%d\n",jackpot(pots, l, r));
}