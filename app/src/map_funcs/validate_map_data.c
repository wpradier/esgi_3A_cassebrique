//
// Created by Manveer Singh on 27/10/2022.
//
#include "cassebrique.h"

int validate_map_data(t_map *map){
    int incomplete = 0;
    int count_players = 0;
    int player_space; // To check mobility of player

    if(!map->players_start_bombs){
        warning_msg("Default amount of bombs not set");
        incomplete = 1;
    }

    if(!map->height){
        warning_msg("Map height not set");
        incomplete = 1;
    }

    if(!map->width){
        warning_msg("Map width not set");
        incomplete = 1;
    }

    for (int i = 0; i < map->height; ++i) {
        for (int j = 0; j < map->width; ++j) {
            if(map->state[i][j].type == 'p'){
                count_players++;

                // Here we verify if player have
                // space to move around him on the starting point
                player_space = 0;
                if(i < map->height-2){
                    if(map->state[i+1][j].type == ' '){
                        player_space++;
                    }
                }
                if(j < map->width-2){
                    if(map->state[i][j+1].type == ' '){
                        player_space++;
                    }
                }
                if(i > 1){
                    if(map->state[i-1][j].type == ' '){
                        player_space++;
                    }
                }
                if(j > 1){
                    if(map->state[i][j-1].type == ' '){
                        player_space++;
                    }
                }

                if(player_space < 2){
                    warning_msg("A player doesn't have enough space to start the game");
                    incomplete = 1;
                }
            }
        }
    }

    if(count_players < 2){
        warning_msg("Map needs at least 2 players");
        incomplete = 1;
    }

    for (int i = 0; i < map->height; ++i) {
        for (int j = 0; j < map->width; ++j) {
            if(map->state[0][j].type != 'x'){
                warning_msg("Top wall incomplete");
                incomplete = 1;
            }

            if(map->state[i][0].type != 'x'){
                warning_msg("Left wall incomplete");
                incomplete = 1;
            }

            if(map->state[map->height-1][j].type != 'x'){
                warning_msg("Bottom wall incomplete");
                incomplete = 1;
            }

            if(map->state[i][map->width-1].type != 'x'){
                warning_msg("Right wall incomplete");
                incomplete = 1;
            }

            if(incomplete == 1)
                return 0;
        }
    }

    return 1;
}