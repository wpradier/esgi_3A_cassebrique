#include "cassebrique.h"

void bomb_explosion(t_coordinates explosion_coordinates , t_map *map ){
        printf("fonction STA\n");

    unsigned short bomb_range = map->state[1][2]->bomb->range;
    //DOWN destruction
    for(int i = 1 ; i < map->height-1;i++){
        if(i == bomb_range){
            break;
        } 
        if(i == map->width-1){
            break;
        } 
        printf("%d",explosion_coordinates.x+i);
        printf("%d",explosion_coordinates.y);

        char c = map-> state[explosion_coordinates.x+i][explosion_coordinates.y]->type;

        printf("%c",c);
        
        if(map->state[explosion_coordinates.x+i][explosion_coordinates.y]->type == 'm'){
            map->state[explosion_coordinates.x+i][explosion_coordinates.y]->type = ' ';
            break;
        }   
    }
    //UP destruction
    for(int i = 1 ; i < map->height-1;i++){
        if(i == bomb_range){
            break;
        } 
        if(i == map->width-1){
            break;
        } 
        if(map->state[explosion_coordinates.x-i][explosion_coordinates.y]->type == 'm'){
            map->state[explosion_coordinates.x-i][explosion_coordinates.y]->type = ' ';
            break;
        }

    }
    // RIGTH destruction 
    // for(int i = 1 ; i < map->height-1;i++){
    //     if(i == bomb_range){
    //         break;
    //     } 
    //     if(i == map->height-1){
    //         break;
    //     } 
    //     if(map->state[explosion_coordinates.x][explosion_coordinates.y+i]->type == 'x' || map->state[explosion_coordinates.x][explosion_coordinates.y+i]->type == 'm'){
    //         map->state[explosion_coordinates.x][explosion_coordinates.y+i]->type = ' ';
    //         break;
    //     }
    // }
    // LEFT destruction
//     for(int i = 1 ; i < map->height-1;i++){
//         if(i == bomb_range){
//             break;
//         } 
//         if(i == map->height-1){
//             break;
//         } 
//         if(map->state[explosion_coordinates.x][explosion_coordinates.y-i]->type == 'x' || map->state[explosion_coordinates.x][explosion_coordinates.y-i]->type == 'm'){
//             map->state[explosion_coordinates.x][explosion_coordinates.y-i]->type = ' ';
//             break;
//         }
//     }
 }
