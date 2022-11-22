#include "cassebrique.h"

void	    add_map_option(short isSelected, const char *opt_text) {
    char    *choice_str = ">";
    char    *non_choice_str = " ";
    char    MSGBUFF[256];

    printf("IN MAP OPTION\n");
    getch();
    strcpy(MSGBUFF, "");
    printf("MSG: %s\n", MSGBUFF);
    getch();
    if (isSelected) {
	attron(A_STANDOUT);
	strcat(MSGBUFF, choice_str);
	printf("MSG: %s\n", MSGBUFF);
	getch();
    } else {
	strcat(MSGBUFF, non_choice_str);
	printf("MSG: %s\n", MSGBUFF);
	getch();
    }


    strcat(MSGBUFF, opt_text);

    printf("MSG: %s\n", MSGBUFF);
    getch();
    printw(MSGBUFF);
    attroff(A_STANDOUT);
}


t_map		*select_map_menu(void) {
    char	MSGBUFF[256];
    t_map	*map;
    t_map_list	*map_list;
    int		curr_map_option;
    char	*select_msg = "Select map:";
    int		options_offset_start;
    int		curr_options_offset;
    int		pressed_key;
    int		menu_cols_offset;

    map_list = list_available_maps();
    printf("FIRST MAP SELECT: %s\n", map_list->names[0]);
    getch();
    if (map_list->length <= 0) {
	perror("No maps");
	return NULL;
    }

    curr_map_option = 0;
    map = map_list->list[curr_map_option];

    options_offset_start = -4;
    while (1) {
	clear();
    
	curr_options_offset = options_offset_start;
	menu_cols_offset = (COLS / 2) - (strlen(select_msg) / 2);

	strcpy(MSGBUFF, select_msg);

	move((LINES / 2) + curr_options_offset++, menu_cols_offset);
	attron(A_BOLD);
	printw(MSGBUFF);
	attroff(A_BOLD);


	printf("BEFORE LOOP\n");
	getch();
	printf("FIRST MAP: %s\n", map_list->names[0]);
	getch();
	for (int i = 0; i < map_list->length; i++) {
	    printf("IN SELECT MAP %d\n", i);
	    getch();
	    move((LINES / 2) + curr_options_offset++, menu_cols_offset);
	    printf("CURR MAP NAME: %s\n", map_list->names[i]);
	    getch();
	    add_map_option(i == curr_map_option, map_list->names[i]);
	}

	move(LINES - 1, 0);
	printw("Press \"q\" or \"esc\" to leave.");

	refresh();

	pressed_key = getch();

	if (pressed_key == KEY_UP) {
	    if (curr_map_option == 0) {
		curr_map_option = map_list->length;
	    }
	    curr_map_option--;
	}

	if (pressed_key == KEY_DOWN) {
	    curr_map_option = (curr_map_option + 1) % map_list->length;
	}

	if (pressed_key == 27 || pressed_key == 'q') { // ESCAPE KEY
	    return NULL;
	}

	if (pressed_key == KEY_ENTER || pressed_key == 10) { // ENTER KEY
	    return map_list->list[curr_map_option];
	}

	map = map_list->list[curr_map_option];
    }

    return map;
}
