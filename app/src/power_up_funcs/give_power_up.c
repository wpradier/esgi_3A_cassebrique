//
// Created by Manveer Singh on 20/11/2022.
//
#include "cassebrique.h"


double get_sum_of_all_rates(t_config* config){
    return
    config->bomb_up_rate+
    config->bomb_down_rate+
    config->yellow_flame_rate+
    config->blue_flame_rate+
    config->red_flame_rate+
    config->pass_bomb_rate+
    config->bomb_kick_rate+
    config->invincibility_rate+
    config->heart_rate+
    config->health_up_rate;
}

double* get_probabilities(t_config* config){
    double* powers_probabilities;
    double sum_of_all_rates;

    powers_probabilities = malloc(sizeof(double)*config->number_of_powers);

    sum_of_all_rates = get_sum_of_all_rates(config);

    for (int i = 0; i <= config->number_of_powers; ++i) {
        switch (i) {
            case 0:
                powers_probabilities[i] = (double)config->powers_spawn_rate/sum_of_all_rates;
                break;
            case 1:
                powers_probabilities[i] = (double)config->bomb_up_rate/sum_of_all_rates;
                break;
            case 2:
                powers_probabilities[i] = (double)config->bomb_down_rate/sum_of_all_rates;
                break;
            case 3:
                powers_probabilities[i] = (double)config->yellow_flame_rate/sum_of_all_rates;
                break;
            case 4:
                powers_probabilities[i] = (double)config->blue_flame_rate/sum_of_all_rates;
                break;
            case 5:
                powers_probabilities[i] = (double)config->red_flame_rate/sum_of_all_rates;
                break;
            case 6:
                powers_probabilities[i] = (double)config->pass_bomb_rate/sum_of_all_rates;
                break;
            case 7:
                powers_probabilities[i] = (double)config->bomb_kick_rate/sum_of_all_rates;
                break;
            case 8:
                powers_probabilities[i] = (double)config->invincibility_rate/sum_of_all_rates;
                break;
            case 9:
                powers_probabilities[i] = (double)config->heart_rate/sum_of_all_rates;
                break;
            case 10:
                powers_probabilities[i] = (double)config->health_up_rate/sum_of_all_rates;
                break;
            default:
                break;
        }
    }
    return powers_probabilities;
}

t_power_up give_power_up(t_config* config){
    double* powers_probabilities;
    t_power_up power_to_return;

    /* Intializes random number generator */
    time_t t;
    srand((unsigned) time(&t));

    powers_probabilities = get_probabilities(config);

    do {

        power_to_return = rand() % config->number_of_powers +1;

    } while (rand() % 100 > powers_probabilities[power_to_return] * 100);

    if(rand() % 100 > powers_probabilities[0] * 100){
        power_to_return = NO_POWER;
    }
    free(powers_probabilities);
    return power_to_return;

}