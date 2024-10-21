#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Find the index of a string in a list of string
int find_index_string(char *list[], char* str, int len_list)
{
    for (int i = 0; i < len_list; i++)
    {
        if (strcmp(list[i], str) == 0) {return i;}
    }
}

void amounts(char* fname)
{
    FILE* file = fopen(fname, "rb");
    if (file == NULL) {printf("Error, unable to open the file.\n");}

    int nb_persons; //declare the variable where the information is stored.
    fscanf(file, "%u", &nb_persons);

    char **list_name = malloc(sizeof(char*)*nb_persons);
    if (list_name == NULL)
    {
        printf("Error. Unable to allocate memory to store person's names.\n");
        fclose(file);
        return;
    }

    char tmp_names[256];
    for (int i = 0; i < nb_persons; i++)
    {
        fscanf(file, "%s", &tmp_names);
        list_name[i] = malloc(sizeof(char)*(strlen(tmp_names) + 1));
        if (list_name[i] == NULL) 
        {
            printf("Error. Unable to allocate memory to store a name.\n"); 
            fclose(file);
            for (int j = i - 1; i >= 0; j--) {free(list_name[j]);}
            free(list_name);
            return;
        }
        strcpy(list_name[i], tmp_names); //Do not do list_name[i] == *tmp_names because otherwise you can not then modify *tmp_names without modifying list_name[i]
    }

    int* balance = calloc(nb_persons, sizeof(int)); //Can use malloc, but then has to initiate all the entries to 0.
    if (balance == NULL) {printf("Error. Unable to allocate memory.\n");}
    char name_debit[256];
    char name_credit[256];
    char amount[256];
    fscanf(file, "%s %s %d", name_debit, name_credit, amount);
    while (!feof(file))
    {
        int index_debit = find_index_string(list_name, name_debit, nb_persons);
        int index_credit = find_index_string(list_name, name_credit, nb_persons);

        balance[index_debit] -= *amount;
        balance[index_credit] += *amount;

        fscanf(file, "%s %s %d", name_debit, name_credit, amount);
    }
    fclose(file);
    for (int i = 0; i < nb_persons; i++){ free(list_name[i]); }
    free(list_name);
    free(balance);
}

int main(int argc, char* argv[])
{
    char* fname = argv[1];
    if (argc != 2)
    {
        printf("Wrong number of argument.\n");
        return 1;
    }
    compute_amounts(fname);
    return 0;
}