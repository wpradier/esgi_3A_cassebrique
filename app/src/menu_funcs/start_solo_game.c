#include "cassebrique.h"

void	      start_solo_game(void) {
    t_map     *map;


    printw("Starting solo game...\n");
    refresh();

    map = select_map_menu();

    printw("MAP: %p\n", map);
}
