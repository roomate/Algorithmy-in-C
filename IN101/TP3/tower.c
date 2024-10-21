#include <stdlib.h>
#include <stdio.h>

typedef enum {true, false, error} bool;

bool possible(char* pos_ini, char* pos_fin)
{
    int letter_ini = pos_ini[0];
    int figure_ini = pos_ini[1];

    int letter_fin = pos_fin[0];
    int figure_fin = pos_fin[1];

    if (letter_ini < 'A' || letter_ini > 'H' || figure_ini < '1' || figure_ini > '8') {return error;}
    if (letter_fin < 'A' || letter_fin > 'H' || figure_fin < '1' || figure_fin > '8') {return error;}
    if (letter_ini - letter_fin == figure_ini - figure_fin) {return true;}
    return false;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Wrong number of arguments.\n");
        return 1;
    }

    char* pos_ini = argv[1];
    char* pos_fin = argv[2];

    bool res = possible(pos_ini, pos_fin);
    switch(res)
    {
        case true : printf("Authorized.\n"); break;
        case false : printf("Non-authorized.\n"); break;
        case error : printf("There is an error in the argument.\n"); break;
    }
    return 0;
}