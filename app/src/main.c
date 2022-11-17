#include "cassebrique.h"

int	  main(void) {
    char  *test_str; // string for test function
    // t_map *map; // Map to use
    // char* mapString;

    /* Test Function */
    test_str = ft_strnew(28);
    if (!test_str) {
        error_msg("ft_strnew call returned NULL");
        return 1;
    }
    strcpy(test_str, "Everything is working fine!");
    success_msg(test_str);
    free(test_str);

    /*map = init_map("maps/test.cassebrique");
    if(map != NULL){
        mapString = display_map(map);

        printf("\nTaille de la chaîne %lu", strlen(mapString));
        printf("\n");

        success_msg(mapString);

        free(mapString);
        highlight_msg("Freed map string");

        free_map(map);
    }*/

    return 0;
}
