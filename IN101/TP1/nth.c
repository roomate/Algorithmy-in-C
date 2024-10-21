#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

// Function to count the number of char in a string.
int count_lgth_str(char* str)
{
    int n = 0;
    char a = str[n];
    while (a != '\0')
    {
        n++;
        a = str[n];
    }
    return n;
}

char nth(unsigned int index, char* str, bool* validity)
{
    int strlen = count_lgth_str(str);
    //If the index is too high or negative.
    if (index >= strlen)
    {
        *validity = false;
        printf("Error, index exceeds the length of the string.");
        return 0;
    }
    return str[index];
}

int main(int argc, char *argv[])
{
    bool *t = malloc(sizeof(bool));
    //If not the right number of arguments.
    if (argc != 3)
    {
        printf("Number of argument is wrong.\n");
        return 1; //Interruption of the code.
    }
    char result = nth(atoi(argv[2]), argv[1], t);
    if (t == false)
    {
        return 0;
    }
    printf("%c\n", result);
    return 0;
}