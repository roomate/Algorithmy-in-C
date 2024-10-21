#include <stdlib.h>
#include <stdio.h>

typedef enum {
    BO_False,
    BO_True,
    BO_Error
} bool;

bool same_sum(int n, int c)
{
    if (n < 0) { return BO_Error;}
    if (c == 0) {return ((n == 0) ? BO_True : BO_False);}
    if (c > 9) { return BO_Error;}
    return ((n % c == 0) ? BO_True : BO_False);
}

int main(int argc, char* argv[])
{
    //If the operator did not enter the right number of arguments.
    if (argc != 3)
    {
        printf("Number of argument entered is wrong.\n");
        return 0; //Interruption of the code.
    }
    int n = atoi(argv[1]);
    int c = atoi(argv[2]);
    bool res = same_sum(n,c);
    switch (res)
    {
        case BO_True : printf("True\n"); break;
        case BO_False : printf("False\n"); break;
        case BO_Error : printf("Error\n"); break;
    }
    return 0;
}