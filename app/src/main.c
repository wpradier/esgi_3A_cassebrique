#include "cassebrique.h"

int	  main(void) {
    printf("WELCOME\n");

    t_map *map;
    char* mapString;
    char *map_file_name;
    FILE *map_file;

    /* Intializes random number generator */
    time_t t;
    srand((unsigned) time(&t));

    map_file_name = "maps/test.cassebrique";
    if (validate_map_format(map_file_name) != VALID_MAP_FORMAT) {
        perror("File format validation error.");
        return EXIT_FAILURE;
    }

    t_config* config;
    //t_power_up power;

    config = malloc(sizeof(t_config));

    config->number_of_powers = 10;
    config->powers_spawn_rate = 50;

    config->bomb_up_rate = 20;
    config->bomb_down_rate = 0;
    config->yellow_flame_rate = 0;
    config->blue_flame_rate = 0;
    config->red_flame_rate = 50;
    config->pass_bomb_rate = 0;
    config->bomb_kick_rate = 0;
    config->invincibility_rate = 0;
    config->heart_rate = 0;
    config->health_up_rate = 10;


    map_file = fopen(map_file_name, "r");

    map = init_map(map_file);
    if(map != NULL){
        init_power_ups(map, config);

        mapString = display_map(map);

        printf("\nTaille de la chaîne %lu", strlen(mapString));
        printf("\n");

        success_msg(mapString);

        free(mapString);
        highlight_msg("Freed map string\n");

        free_map(map);
    }

    // -------------------------------------



    return 0;
}
