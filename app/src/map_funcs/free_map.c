//
// Created by Manveer Singh on 25/10/2022.
//
#include "cassebrique.h"

void free_map(t_map *map){

    for (int i = 0; i < map->height; ++i) {
        free(map->state[i]);
    }
    highlight_msg("Freed map lines");

    free(map->state);
    highlight_msg("Freed map skeleton");

    free(map);
    highlight_msg("Freed map");
}