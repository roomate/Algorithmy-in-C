#include <stdio.h>
#include <stdlib.h>

float eval(float x)
{
    return 5 + x*(2 + x*(x*(5 - 3*x)));
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Wrong number of argument.\n");
    }
    float x = atof(argv[1]);
    printf("%.2f\n", eval(x));
    return 0;
}