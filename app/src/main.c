#include "cassebrique.h"

int	  main(void) {
    t_map *map;
    char* mapString;
    char *map_file_name;
    FILE *map_file;
    t_startmode	    startmode;

    initscr();
    keypad(stdscr, TRUE);

    startmode = select_startmode_menu();
    clear();

    switch (startmode) {
	case NOSTART:
	    endwin();
	    printf("Bye!\n");
	    break;
	case LOCAL:
	    start_solo_game();
	    break;
	case SERVER:
	    endwin();
	    printf("NOT IMPLEMENTED\n");
	    break;
	case CLIENT:
	    endwin();
	    printf("NOT IMPLEMENTED\n");
	    break;

    endwin();

    map_file_name = "maps/test.cassebrique";
    if (validate_map_format(map_file_name) != VALID_MAP_FORMAT) {
	perror("File format validation error.");
	return EXIT_FAILURE;
    }

    map_file = fopen(map_file_name, "r");

    printf("WELCOME\n");
    map = init_map(map_file);
    if(map != NULL){
        mapString = display_map(map);

        printf("\nTaille de la chaîne %lu", strlen(mapString));
        printf("\n");

        success_msg(mapString);

        free(mapString);
        highlight_msg("Freed map string\n");

        free_map(map);
    }

    return EXIT_SUCCESS;
}
