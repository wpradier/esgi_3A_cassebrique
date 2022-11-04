#include "test.h"

typedef struct s_input {
  int val;
  pthread_mutex_t mutex_input;
  pthread_cond_t  cond_write;
} t_input;

static t_input input = {
  .val = 0,
  .mutex_input = PTHREAD_MUTEX_INITIALIZER,
  .cond_write = PTHREAD_COND_INITIALIZER
};



void  *thr_f(void *args) {
    while (1) {
	pthread_mutex_lock(&input.mutex_input);
	pthread_cond_wait(&input.cond_write);
	
	input.val = getch();

	pthread_mutex_unlock(&input.mutex_input);
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

	move((LINES / 2) + pos, COLS / 2);
	printw("LOL");

	move(LINES - 1, 0);
	printw("time: %d", time);
	refresh();
	
	time++;
	sleep(1);
    }
}

