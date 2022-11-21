#include "cassebrique.h"

void	    display_config(t_config *config){

        //printf("%d\n",(*config).bomb_max_range);
        printf("bomb_max_range = %d\n",config->bomb_max_range);
        printf("bomb_up_rate = %d\n",config->bomb_up_rate);
        printf("bomb_down_rate = %d\n",config->bomb_down_rate);
        printf("yellow_flame_rate = %d\n",config->yellow_flame_rate);
        printf("blue_flame_rate = %d\n",config->blue_flame_rate);
        printf("red_flame_rate = %d\n",config->red_flame_rate);
        printf("pass_bomb_rate = %d\n",config->pass_bomb_rate);
        printf("bomb_kick_rate = %d\n",config->bomb_kick_rate);
        printf("invincibility_rate = %d\n",config->invincibility_rate);
        printf("heart_rate = %d\n",config->heart_rate);
        printf("health_up_rate = %d\n",config->health_up_rate);
        printf("number_of_powers = %d\n",config->number_of_powers);
        printf("powers_spawn_rate = %d\n",config->powers_spawn_rate);
        

}  