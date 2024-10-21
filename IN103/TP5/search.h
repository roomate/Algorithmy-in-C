#ifndef __SHORTEST_PATH_H__
#define __SHORTEST_PATH_H__

#include <stdbool.h>
#include "station.h"

bool shortest_path(struct station_t* src, struct station_t* dest);
void print_shortest_path_reversed(struct station_t* src, struct station_t* dest);
#endif