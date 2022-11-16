//
// Created by Manveer Singh on 26/10/2022.
//
#include "cassebrique.h"

char *display_map(t_map *map){
    //printf("\nDefault bombs amount: %d", map->players_start_bombs);
    //printf("\nWidth of map: %d", map->width);
    //printf("\nHeight of map: %d", map->height);
    //printf("\nMap:\n"):
    char* mapString;
    mapString = malloc(sizeof(char)*map->height*(map->width+1)+1);

    for (int i = 0; i < map->height; ++i) {
        for (int j = 0; j < map->width; ++j) {
            //printf("%s", (char*)map->state[i][j].content);
            if(map->state[i][j].type != 'p'){
                if(i == 0 && j == 0){
                    strcpy(mapString, &map->state[i][j].type);
                }else{
                    strcat(mapString, &map->state[i][j].type);
                }
            }else{
                if(map->state[i][j].content != NULL){
                    if(i == 0 && j == 0){
                        strcpy(mapString, map->state[i][j].content); // todo content.name
                    }else{
                        strcat(mapString, map->state[i][j].content); // todo content.name
                    }
                }else{
                    if(i == 0 && j == 0){
                        strcpy(mapString, &map->state[i][j].type);
                    }else{
                        strcat(mapString, &map->state[i][j].type);
                    }
                }
            }

        }
        //printf("\n");
        strcat(mapString, "\n");
    }
    //success_msg("Map created as string");
    return mapString;
}
