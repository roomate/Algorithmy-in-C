#include <stdio.h>
#include <stdlib.h>

typedef enum {
    True,
    False
} bool;

int turns(float n, float r1, float r2, bool* error)
{
    if (r1 < 0 || r2 <= 0)
    {
        *error = True;
        return 0;
    }
    return n*r1/r2;
}

int main(int argc, char* argv[])
{
    float nb_turns = atoi(argv[1]); //Number of turns
    int nb_gears = atoi(argv[2]); //Number of gears

    bool *error = malloc(sizeof(bool));
    *error = False;

    float gears1 = atof(argv[3]);
    float gears2 = atof(argv[nb_gears - 1 + 2]);

    float res = turns(nb_turns,gears1,gears2,error);

    if (*error == True)
    {
        printf("Error, one of the wheel's diameter is negative.\n");
        return 1;
    }
    printf("The number of turn carried out is %.1f\n", res);
}