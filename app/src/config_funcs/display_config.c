#include "cassebrique.h"

void	    display_config(t_config *config){

        //printf("%d\n",(*config).bomb_max_range);
        printf("%d\n",config->bomb_max_range);
        printf("%d\n",config->bomb_up_rate);
        printf("%d\n",config->bomb_down_rate);
        printf("%d\n",config->yellow_flame_rate);
        printf("%d\n",config->blue_flame_rate);
        printf("%d\n",config->red_flame_rate);
        printf("%d\n",config->pass_bomb_rate);
        printf("%d\n",config->bomb_kick_rate);
        printf("%d\n",config->invincibility_rate);
        printf("%d\n",config->heart_rate);
        printf("%d\n",config->health_up_rate);
        

}  