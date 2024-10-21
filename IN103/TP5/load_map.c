#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "station.h"



static unsigned int nb_stations = 0 ;
static struct stations_list_t *all_stations = NULL ;

static struct station_t* get_or_create_station (char *name)
{
  struct stations_list_t *list_cell ;
  struct station_t *st ;
  /* On commence par rechercher si la stations n'existerait pas déjà. */
  struct stations_list_t *stations = all_stations ;
  while (stations != NULL) {
    if (strcmp (stations->station->name, name) == 0)
      return (stations->station) ;
    stations = stations->next ;
  }

  /* Si on arrive ici, c'est qu'on n'a pas trouvé un noeud déjà
     existant. On va le créer. */
  st = malloc (sizeof (struct station_t)) ;
  st->name = malloc ((1 + strlen (name)) * sizeof (char)) ;
  st->seen = false ;
  strcpy (st->name, name) ;
  st->neighbours = NULL ;

  /* On rajoute le noeud en tête de la liste de toutes les stations. */
  list_cell = malloc (sizeof (struct stations_list_t)) ;
  list_cell->station = st ;
  list_cell->next = all_stations ;
  all_stations = list_cell ;
  /* Une station de plus de créee. */
  nb_stations++ ;
  return (st) ;
}



/** \brief Retourne le pointeur sur la tête de la liste chaînée de stations
    construites. */
struct stations_list_t* get_all_stations ()
{
  return (all_stations) ;
}


bool load_map (char *fname)
{
  FILE* file = fopen(fname, "rb");
  if (file == NULL) {printf("Error. Unable to open file.\n"); return false;}
  char buffer[256];
  struct station_t* current_station;

  while (fgets(buffer, 256, file) != NULL) /*Get the name of the metro line*/
  {
    struct station_t* prev_station = NULL;
    while (strcmp(fgets(buffer, 256, file),".\n") != 0) /*While not at the end of the metro line.*/
    {
      if (buffer[strlen(buffer) - 1] == '\n') {buffer[strlen(buffer) - 1] = '\0';}
      current_station = get_or_create_station(buffer);

      if (prev_station != NULL) /*If the pointer is not null*/
      {
        struct stations_list_t* neighbour_prev = malloc(sizeof(struct stations_list_t));
        if (neighbour_prev == NULL) {printf("Error. Unable to allocate memory.\n"); return false;}
        neighbour_prev->station = prev_station;
        neighbour_prev->next = current_station->neighbours;
        current_station->neighbours = neighbour_prev;

        neighbour_prev = malloc(sizeof(struct stations_list_t));
        if (neighbour_prev == NULL) {printf("Error. Unable to allocate memory.\n"); return false;}

        neighbour_prev->station = current_station;
        neighbour_prev->next = prev_station->neighbours;
        prev_station->neighbours = neighbour_prev;
      }
      prev_station = current_station;
    }
  }
}