#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "load_dic.h"

void display_string(char* str)
{
    for (int i = 0; str[i] != '\0'; i++) {printf("%c", str[i]);}
    printf("\n");
}

bool find_word_naive (char **words, char *word, unsigned int num_words)
{
    for (int i = 0; i < num_words; i++)
    {
        if (strcmp(word, words[i]) == 0){return true;}
    }
return false;
}

void test_dico(char** dico, int size)
{
    for (int i = 0; i < size; i++)
    {
        char* word = dico[i];
        bool res = find_word_naive(dico, word);
        if (res == false) {printf("Error, a word is not in the dico.\n"); return;}
    }
    printf("Everything is okay.");
}

int main (int argc, char *argv[])
{
    if  (argc != 2) {printf("Wrong number of argument.\n"); return 1;}
    char text[256];
    bool res;
    char* fname = argv[1]; /*name of the file*/
    int* size = malloc(sizeof(int));
    char** words = load_file(fname, size);
    printf("Please, enter a word:");
    gets(text);
    printf("\n");
    while (strcmp(text,"^-d") != 0)
    {
        res = find_word_naive(words, text, *size);
        switch(res)
        {
            case true : printf("This word does belong to the dico.\n"); break;
            case false : printf("This word does not belong to the dico.\n"); break;
        }
        printf("Please, enter a word:");
        gets(text);
        printf("\n");
    }
    free(size);
    return 0;
}