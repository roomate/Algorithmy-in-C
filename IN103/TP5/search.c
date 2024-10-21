#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "station.h"
#include "queue.h"


bool shortest_path (struct station_t* src, struct station_t* dest)
{
    struct queue_t* path = queue_alloc(256);
    if (path == NULL) {printf("Error. Unable to allocate memory.\n"); return false;}
    if (strcmp(src->name, dest->name) == 0) {return true;}
    enqueue(path, src);
    src->seen = true;
    while (!is_empty(path))
    {
        struct station_t* station = take(path);
        
        struct stations_list_t* neigh = malloc(sizeof(struct stations_list_t));
        neigh = station->neighbours;
        while (neigh->next != NULL)
        {
            if (!neigh->station->seen) {enqueue(path, neigh->station);neigh->station->seen = true; neigh->station->prev_in_path = station;}
            if (strcmp(dest->name, neigh->station->name) == 0) {queue_free(path); return true;}
            neigh = neigh->next;
        }
    }
    queue_free(path);
    return false;
}

void print_shortest_path_reversed(struct station_t* src, struct station_t* dest)
{
    struct station_t* tmp = malloc(sizeof(struct station_t));
    if (tmp == NULL) {printf("Error. Unable to allocate memory.\n"); exit(1);}
    printf("%s\n", dest->name);
    if (dest != NULL)
    {
        tmp = dest->prev_in_path;
        while (strcmp(tmp->name, src->name) != 0)
        {
            printf("%s\n", tmp->name);
            tmp = tmp->prev_in_path;
        }
    }
}
