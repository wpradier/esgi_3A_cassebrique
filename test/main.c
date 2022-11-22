#include "test.h"

typedef struct s_input {
  int val;
  pthread_mutex_t mutex_input;
  pthread_cond_t  cond_write;
} t_input;

static t_input input = {
  .val = 0,
};



void  *thr_f(void *args) {
    while (1) {
	input.val = getch();
    }
}

int main(void) {
    pthread_t	tID;
    int		ret;


    initscr();
    keypad(stdscr, TRUE);

    ret = pthread_create(
	&tID, NULL, thr_f, NULL);
    
    int pos = 0;
    int time = 0;

    while (1) {
	clear();

	if (input.val == KEY_DOWN) {
	    pos++;
	    input.val = 0;
	}
	if (input.val == KEY_UP) {
	    pos--;
	    input.val = 0;
	}


	move((LINES / 2) + pos, COLS / 2);
	printw("LOL");

	move(LINES - 1, 0);
	printw("time: %d", time);
	refresh();
	
	time++;
	usleep(100 * 1000);
    }
}

