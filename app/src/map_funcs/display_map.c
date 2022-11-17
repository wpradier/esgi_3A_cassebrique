//
// Created by Manveer Singh on 26/10/2022.
//
#include "cassebrique.h"

char *display_map(t_map *map){
    char* mapString; // String to return
    mapString = malloc(sizeof(char)*map->height*(map->width+1)+1);

    for (int i = 0; i < map->height; ++i) {
        for (int j = 0; j < map->width; ++j) {
            switch (map->state[i][j].type) {
                case 'x':
                    if(i == 0 && j == 0){
                        strcpy(mapString, "█");
                    }else{
                        strcat(mapString, "█");
                    }
                    break;
                case 'm':
                    if(i == 0 && j == 0){
                        strcpy(mapString, "▒");
                    }else{
                        strcat(mapString, "▒");
                    }
                    break;
                case ' ':
                    if(i == 0 && j == 0){
                        strcpy(mapString, "-");
                    }else{
                        strcat(mapString, "-");
                    }
                    break;
                case 'p':
                    // We check the content to show player name, else we add 'p'
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
                    break;
                default:
                    if(i == 0 && j == 0){
                        strcpy(mapString, &map->state[i][j].type);
                    }else{
                        strcat(mapString, &map->state[i][j].type);
                    }
                    break;
            }
        }
        // For each new line
        strcat(mapString, "\n");
    }

    return mapString;
}
