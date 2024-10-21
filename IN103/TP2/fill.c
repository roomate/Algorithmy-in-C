#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "gfxprims.h"
#include "queue.h"

int Random(int min, int max)
{
    int rd_num = rand()%(max - min + 1) + min;
    return rd_num;
}


void fill (int width, int height, int nb_init)
    {
    int i ;
    bool *processed ;
    struct queue_t *q ;
    struct point_info_t *init_points ;

    /* Allocation de la file. Taille max: width * height. */
    q = queue_alloc (width * height) ;
    if (q == NULL) {
    printf ("No mem for queue.\n") ;
    return ;
    }

    /* Allocation du tableau pour se souvenir des points initiaux et redessiner
        par dessus en noir à la fin. */
    init_points = malloc (nb_init * sizeof (struct point_info_t)) ;
    if (init_points == NULL) {
    printf ("Nom mem for initial points.\n") ;
    queue_free (q);
    return ;
    }

    /* Allocation du tableau disant si un point a déjà été mis en file. */
    processed = malloc (width * height * sizeof (bool)) ;
    if (processed == NULL) {
    printf ("No mem for processed array.\n") ;
    free (init_points) ;
    queue_free (q) ;
    return ;
    }

    /* Au début, aucun point n'a déjà été traité. */
    for (i = 0; i < width * height; i++) processed[i] = false ;

    /*Initialisation par échantillonage de la position des nb_init graines, ainsi que la couleur de la colonie associée.*/
    for (int i = 0; i < nb_init; i++) {
        struct point_info_t* point = &init_points[i];
        int x = Random(0,width - 1); int y = Random(0,height - 1); 
        point->x = x; point->y = y;
        char r = Random(0,255); char g = Random(0,255); char b = Random(0,255);
        point->r = r; point->g = g; point->b = b;
        processed[y*width + x] = true; /*These points have been treated once and for all*/
        enqueue(q,*point);
    }

    while (!is_empty(q))
    {
        struct point_info_t point = take(q); /*Take first element of the queue*/
        renderPixel(point.x, point.y, point.r, point.g, point.b);

        /*Take points in the neighborhood.*/
        for (int i = -1; i < 2; ++i)
        {
            int y = point.y + i;
            /*If in the domain*/
            if ((y < 0) || (y > height)) {continue;}
            for (int j = -1; j < 2; ++j)
            {
                int x = point.x + j;

                /*If in the domain*/
                if ((x < 0) || (x > width)) {continue;}
                /*If not yet processed.*/
                if (processed[width*x + y]) {continue;}

                /*Update coordinates*/
                point.x = x;
                point.y = y;
                /*Put in the new queue*/
                enqueue(q,point);
            }
        }
    }
    queue_free(q) ;
    free(processed);

    for (i = 0; i < nb_init; i++)
    renderPixel (init_points[i].x, init_points[i].y,
                    init_points[i].r, init_points[i].g, init_points[i].b) ;
    free (init_points) ;
}