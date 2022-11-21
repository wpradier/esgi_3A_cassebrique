#include "cassebrique.h"

int    is_possible_to_move(t_map* our_map, t_player* player, t_direction movement){


    t_cordinates player_cord = player->cordinates;
    
    switch (movement)
    {
        // all condition check if it's possible to move even if there are no wall arround the map
    case UP:
        if(player_cord.x == 0){
        
            if(our_map->state[our_map->height-1][player_cord.y]->type == 'x' || our_map->state[our_map->height-1][player_cord.y]->type == 'm'){
                return 0;
            }
            else{
                return 1;
            }
        
        }else{
            if(our_map->state[player_cord.x-1][player_cord.y]->type == 'x' || our_map->state[player_cord.x-1][player_cord.y]->type == 'm'){
                return 0;
            }
            else{
                return 1;
            }
        }
        break;




    case DOWN:
        if(player_cord.x == (unsigned)our_map->height-1){
            if(our_map->state[0][player_cord.y]->type == 'x' || our_map->state[0][player_cord.y]->type == 'm'){
                return 0;
            }
            else{
                return 1;
            }
            
        }
        else{
            if(our_map->state[player_cord.x+1][player_cord.y]->type == 'x' || our_map->state[player_cord.x+1][player_cord.y]->type == 'm'){
                return 0;
            }
            else{
                return 1;
            }
        }
        break;




    case LEFT:
        if(player_cord.y == 0){
            if(our_map->state[player_cord.x][our_map->width-1]->type == 'x' || our_map->state[player_cord.x][our_map->width-1]->type == 'm'){
                return 0;
            }
            else{
                return 1;
            }
            
        }else{
            if(our_map->state[player_cord.x][player_cord.y-1]->type == 'x' || our_map->state[player_cord.x][player_cord.y-1]->type == 'm'){
                return 0;
            }
            else{
                return 1;
            }
        }
        break;



    case RIGHT:
        if(player_cord.y == (unsigned)our_map->width-1){
            if(our_map->state[player_cord.x][0]->type == 'x' || our_map->state[player_cord.x][0]->type == 'm'){
                return 0;
            }
            else{
                return 1;
            }
        
        }else{
            if(our_map->state[player_cord.x][player_cord.y+1]->type == 'x' || our_map->state[player_cord.x][player_cord.y+1]->type == 'm'){
                return 0;
            }
            else{
                return 1;
            }
        }
        break;

    default:
        return 0;
        break;
    }
    return 1;
}