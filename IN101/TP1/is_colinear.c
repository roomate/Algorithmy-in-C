#include <stdlib.h>
#include <stdio.h>

#define EPSILON 1e-5

struct vec
{
    float x;
    float y;
};

typedef enum { false, true } bool;

bool is_colinear(struct vec A, struct vec B, struct vec C)
{
    struct vec AB;
    AB.x = B.x - A.x;
    AB.y = B.y - A.y;

    struct vec BC;
    BC.x = C.x - B.x;
    BC.y = C.y - B.y;
    
    if (AB.x*BC.y - AB.y*BC.x < EPSILON && AB.x*BC.y - AB.y*BC.x > - EPSILON) //To take into account the rounding errors.
    {
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    if (argc != 7)
    {
        printf("Wrong number of arguments.\n");
        return 0;
    }
    struct vec A;
    A.x = atof(argv[1]);
    A.y = atof(argv[2]);

    struct vec B;
    B.x = atof(argv[3]);
    B.y = atof(argv[4]);

    struct vec C;
    C.x = atof(argv[5]);
    C.y = atof(argv[6]);

    bool res = is_colinear(A,B,C);
    if (res == true)
    {
        printf("The three points are colinear.\n");
        return 0;
    }
    printf("The three points are not colinear.\n");
    return 0;
}