#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    true,
    false,
} bool;

bool change_(char* str)
{
    int numb = atoi(str);
    if (numb >= -10 && numb <= 9)
    {
        return true;
    }
    if (str[1] == '\0') {return false;}
    //If it is a negative number, all digits except most significant one must be 0s.
    if (str[0] == '-')
    {
        for (int i = 2; str[i]!= '\0'; i++)
        {
            if (str[i] != '0')
            {
                printf("%c", str[i]);
                return false;
            }
        }
    }
    //If it is a positive number, all digits except most significant one must be 9s.
    else
    {
        for (int i = 1; str[i] != '\0'; i++)
        {
            if (str[i] != '9')
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Wrong number of arguments.\n");
        return 1;
    }
    char* str = argv[1];
    bool res = change_(str);
    switch (res)
    {
        case true : printf("True\n"); break;
        case false : printf("False\n"); break;
    }
    return 0;
}