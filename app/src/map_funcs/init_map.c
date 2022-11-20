#include "cassebrique.h"

#define BUFF_SIZE 256

// Map file with cursor set to starting bombs line
void	    setMapBombs(t_map *map, FILE *map_file) {
    char    buff[BUFF_SIZE];

    fgets(buff, BUFF_SIZE, map_file);
    buff[strlen(buff) - 1] = '\0'; // remove trailing \n

    map->players_start_bombs = atoi(buff);
}

// Map file with cursor set to map dimensions line
void	    setMapDimensions(t_map *map, FILE *map_file) {
    char    buff[BUFF_SIZE];

    fgets(buff, BUFF_SIZE, map_file);
    buff[strlen(buff) - 1] = '\0'; // remove trailing \n

    sscanf(buff, "%d %d", &map->width, &map->height);
}

void	    setMapInitialState(t_map *map, FILE *map_file) {
    char    buff[BUFF_SIZE];

    if (!(map->state = malloc(sizeof(t_cell**) * (map->height)))) {
	    perror("MAP STATE MALLOC ERROR");
    }
    
    for (int i = 0; i < map->height; i++) {
        if (!(map->state[i] = malloc(sizeof(t_cell*) * (map->width)))) {
            perror("MAP STATE MALLOC ERROR");
        }
        fgets(buff, BUFF_SIZE, map_file);
        buff[strlen(buff) - 1] = '\0'; // remove trailing \n

        for (int j = 0; j < map->width; j++) {
            map->state[i][j] = malloc(sizeof(t_cell));
            map->state[i][j]->type = buff[j];
            map->state[i][j]->content = NULL;
        }
    }
}

t_map	    *init_map(FILE *map_file) {
    t_map   *map;

    if (!(map = malloc(sizeof(t_map)))) {
	return NULL;
    }
    
    // These functions move file cursor for convenience.
    setMapBombs(map, map_file);
    setMapDimensions(map, map_file);
    setMapInitialState(map, map_file);

    return map;
}
