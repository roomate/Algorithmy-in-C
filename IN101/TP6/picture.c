#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {true, false} bool;

struct image
{
    int width;
    int length;
    int level_max;
    int** pixels;
};

void free_data(int** pixels, int i)
{
    for (int j= i - 1; j >= 0; j--)
    {
        free(pixels[j]);
    }
    free(pixels);
}

void initialize(char* fname, struct image* pixx)
{
    FILE* file = fopen(fname, "rb");
    if (file == NULL) {printf("Error. File is empty.\n"); return;}

    char buffer_c[10];
    int read;

    read = fscanf(file, "%s", buffer_c);
    if (strcmp(buffer_c, "P2") != 0) {printf("Error. Wrong format.\n"); fclose(file); return;}

    read = fscanf(file, "%d", &(pixx->width));
    if (read != 1) {printf("Error. File is missing data.\n"); fclose(file); return;}

    read = fscanf(file, "%d", &(pixx->length));
    if (read != 1) {printf("Error. File is missing data.\n"); fclose(file); return;}

    read = fscanf(file, "%d", &(pixx->level_max));
    if (read != 1) {printf("Error. File is missing data.\n"); fclose(file); return;}

    int** tab = malloc(sizeof(int*)*pixx->width);
    if (tab == NULL) {printf("Error. Unable to allocate memory.\n"); fclose(file); return;}
    
    int buffer;
    for (int i = 0; i < pixx->width; i++)
    {
        tab[i] = malloc(sizeof(int)*pixx->length);
        //If error
        if (tab[i] == NULL) {
            printf("Error. Unable to allocate memory.\n");
            free_data(tab, i);
            fclose(file);
            return;
        }
    }
    for (int i = 0; i < pixx->width; i++)
    {
        for (int j = 0; j < pixx->length; j++)
        {
            read = fscanf(file, "%d", &buffer);
            //If not error.
            if (read != 1) {printf("Error. File is missing data.\n"); free_data(tab, i); fclose(file); return;}
            tab[i][j] = buffer;
        }
    }
    if (!feof(file)) {printf("Error. Too much pixels.\n"); free_data(pixx->pixels, pixx->width); return ;}
    pixx->pixels = tab;
    fclose(file);
}

void process(int threshold, struct image* pixx)
{
    if (pixx->pixels == NULL) {return;}
    for (int i = 0; i < pixx->width; i++)
    {
        for (int j = 0; j < pixx->length; j++)
        {
            if (pixx->pixels[i][j] > threshold) {pixx->pixels[i][j] = pixx->level_max;}
            else {pixx->pixels[i][j] = 0;}
        }
    }
}

bool save_pgm(char* fname, struct image pixx)
{
    FILE* file = fopen(fname, "wb");

    //Check that the file is not null.
    if (file == NULL) {return false;}

    //Check the pixels are not empty.
    if (pixx.pixels == NULL) {return false;}

    //Write in the metadata.
    fprintf(file, "%s\n %d\n %d\n %d\n", "P2", pixx.width, pixx.length, pixx.level_max);

    for (int i = 0; i < pixx.width; i++)
    {
        for (int j = 0; j < pixx.length; j++)
        {
            //Write the data into the file.
            fprintf(file, "%d\n", pixx.pixels[i][j]);
        }
    }
    fclose(file);
    return true;
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("Wrong number of argument.\n");
        return 1;
    }
    char* fname = argv[1];
    int ratio = atoi(argv[2]);
    if(ratio < 0) {printf("Error. Threshold is negative.\n"); return 1;}
    struct image* pixx;

    initialize(fname, pixx); //Fill the struct image pixx.
    if (pixx->pixels == NULL) {return 1;}

    int thresh = ratio * pixx->level_max / 255;
    process(thresh, pixx);

    char* processed_fname = argv[3];
    bool res = save_pgm(processed_fname, *pixx);
    if (!res) {printf("Error. Saving unsuccessful.\n"); free_data(pixx->pixels, pixx->width); return 1;}

    free_data(pixx->pixels, pixx->width);
    return 0;
}