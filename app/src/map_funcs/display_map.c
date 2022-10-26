//
// Created by Manveer Singh on 26/10/2022.
//
#include "cassebrique.h"

char *display_map(t_map *map){
    printf("\nDefault bombs amount: %d", map->players_start_bombs);
    printf("\nWidth of map: %d", map->width);
    printf("\nHeight of map: %d", map->height);
    printf("\nMap itself:\n");
    int counter = 0;
    for (int i = 0; i < map->height; ++i) {
        for (int j = 0; j < map->width; ++j) {
            //printf("%s", (char*)map->state[i][j].content);
            counter += sizeof((char*)map->state[i][j].content);
            printf("\n%lu", sizeof((char*)map->state[i][j].content));
        }


        if(i != map->height-1){
            counter += sizeof("\n");
            printf("\n%lu", sizeof("\n"));
        }
        printf("\n %d", counter);
        printf("\n");

    }
    printf("\nTaille du counter %d", counter);

    char* mapString;
    mapString = malloc(sizeof(char)*counter+1);

    for (int i = 0; i < map->height; ++i) {
        for (int j = 0; j < map->width; ++j) {
            //printf("%s", (char*)map->state[i][j].content);
            if(i == 0 && j == 0){
                strcpy(mapString, (char*)map->state[i][j].content);
            }else{
                strcat(mapString, (char*)map->state[i][j].content);
            }

        }
        //printf("\n");
        strcat(mapString, "\n");
    }
    success_msg("Map created as string");
    return mapString;
}
