#include "cassebrique.h"

void	    add_map_option(short isSelected, const char *opt_text) {
    char    *choice_str = ">";
    char    *non_choice_str = " ";
    char    MSGBUFF[256];

    strcpy(MSGBUFF, "");
    if (isSelected) {
	attron(A_STANDOUT);
	strcat(MSGBUFF, choice_str);
    } else {
	strcat(MSGBUFF, non_choice_str);
    }

    strcat(MSGBUFF, opt_text);

    printw(MSGBUFF);
    attroff(A_STANDOUT);
}


t_map	    *select_map_menu(void) {
    t_map   *map;
    //t_map   **map_list;

    map = NULL;

    /*map_list = */list_available_maps();
    getch();

    while (1) {
	clear();

	printw("MAPS:");
	getch();
    }

    return map;
}
