#ifndef CASSEBRIQUE_H
# define CASSEBRIQUE_H


/* LIBRARIES */

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <sys/socket.h>
# include <sys/ipc.h>
# include <arpa/inet.h>
# include <ncurses.h>
# include <time.h>
# include <dirent.h>


/* COLORS */

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define NC "\033[0m"


/* POWERUPS */

# define BOMBUP 1


/* STARTMODES */

typedef enum e_startmode {
  LOCAL,
  SERVER,
  CLIENT,
  NOSTART
} t_startmode;

/* STRUCTS */

typedef struct s_config {
  unsigned short bomb_max_range;
  // Spawn rates
  unsigned short bomb_up_rate;
  unsigned short bomb_down_rate;
  unsigned short yellow_flame_rate;
  unsigned short blue_flame_rate;
  unsigned short red_flame_rate;
  unsigned short pass_bomb_rate;
  unsigned short bomb_kick_rate;
  unsigned short invincibility_rate;
  unsigned short heart_rate;
  unsigned short health_up_rate;
} t_config;


typedef struct s_player {
  char name;
  unsigned short health_points;
  unsigned short bombs;
  unsigned short bomb_range;
  unsigned short is_passing_bombs;
  unsigned short is_bomb_kick;
  unsigned int invincible;
  unsigned short heart;
} t_player;



typedef struct cell {
  char		  type;
  void		  *content;
} t_cell;


typedef struct s_map {
  unsigned short  players_start_bombs;
  int		  width;
  int		  height;
  t_cell	  ***state;
} t_map;


typedef struct s_game {
  t_player	  **players;
  unsigned short  players_amount;
  t_config	  *config;
  t_map		  *map;
  int		  playmode;
} t_game;

/* PROTOTYPES */


// Utils
char	    *ft_strnew(size_t size);

// Configuration
t_config    *init_config(char *path);
void	    free_config(t_config *config);
void	    display_config(t_config *config);

// Map
int	    validate_map_format(char *path);
int	    validate_map_data(t_map *path);
t_map	    *init_map(char *path);
void	    free_map(t_map *map);
char	    *display_map(t_map *map);
t_map	    **list_available_maps(void);

// Menu
t_startmode select_startmode_menu(void);
void	    start_solo_game(void);
t_map	    *select_map_menu(void);


#endif
