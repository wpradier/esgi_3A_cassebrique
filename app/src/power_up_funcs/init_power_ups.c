//
// Created by Manveer Singh on 22/11/2022.
//
# include "cassebrique.h"

void init_power_ups(t_map *map, t_config* config){
    t_power_up* power;

    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            if (map->state[i][j]->type == 'm'){
                power = malloc(sizeof(t_power_up));
                *power = give_power_up(config);
                map->state[i][j]->content = power;
                //printf("\n%d %d %d %d", i, j, *power, *((t_power_up*)map->state[i][j]->content));
            }
        }
    }
}