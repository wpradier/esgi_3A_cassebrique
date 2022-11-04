#include "cassebrique.h"

int		    main(void) {
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
	    printf("NOT IMPLEMENTED\n");
	    break;
    }

    endwin();
    return 0;
}
