#include "cassebrique.h"

void		  add_option(t_startmode selected_option, t_startmode added_option, const char *opt_text) {
    char	  *choice_str = ">";
    char	  *non_choice_str = " ";
    char	  MSGBUFF[256];

    strcpy(MSGBUFF, "");
    if (selected_option == added_option) {
      attron(A_STANDOUT);
      strcat(MSGBUFF, choice_str);
    } else {
      strcat(MSGBUFF, non_choice_str);
    }

    strcat(MSGBUFF, opt_text);

    printw(MSGBUFF);
    attroff(A_STANDOUT);
}

t_startmode	  select_startmode_menu(void) {
    t_startmode	  startmode;
    char	  MSGBUFF[256];
    char	  *select_msg = "Select start mode:";
    int		  pressed_key;
    int		  STARTMODES_AMOUNT = 3; // Number of startmodes excluding NOSTART
    size_t	  menu_cols_offset;

    startmode = LOCAL;

    while (1) {
	clear();

	menu_cols_offset = (COLS / 2) - (strlen(select_msg) / 2);

	strcpy(MSGBUFF, select_msg);

	move((LINES / 2) - 3, menu_cols_offset);
	attron(A_BOLD);
	printw(MSGBUFF);
	attroff(A_BOLD);

	move((LINES / 2) - 2, menu_cols_offset);
	add_option(startmode, LOCAL, "Start solo game");
	move((LINES / 2) - 1, menu_cols_offset);
	add_option(startmode, SERVER, "Start game server");
	move((LINES / 2), menu_cols_offset);
	add_option(startmode, CLIENT, "Join game server");


	move(LINES - 1, 0);
	printw("Press \"q\" or \"esc\" to leave.");

	refresh();
	pressed_key = getch();
	if (pressed_key == KEY_UP) {
	    if (startmode == 0) {
		startmode = STARTMODES_AMOUNT;
	    }
	    startmode--;
	}

	if (pressed_key == KEY_DOWN) {
	    startmode = (startmode + 1) % STARTMODES_AMOUNT;
	}

	if (pressed_key == 27 || pressed_key == 'q') { // ESCAPE KEY
	    return NOSTART;
	}

	if (pressed_key == KEY_ENTER || pressed_key == 10) { // ENTER KEY
	    return startmode;
	}
    }
}
