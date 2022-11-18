#include "cassebrique.h"

/*
 * Prend un chemin de fichier map (.cassebrique)
 * Retourne un t_map complètement mallocé
 * Retourne NULL en cas d'erreur
 * Doit:
 *  - Valider le fichier .cassebrique (fonction validate pour le format)
 *  - Valider les valeurs liés à la logique de jeu (assez de joueurs... Création d'une fonction externe count_players ?)
 */

#define BUFF_SIZE 256

// Map file with cursor set to starting bombs line
void	    setMapBombs(t_map *map, FILE *map_file) {
    char    buff[BUFF_SIZE];

    fgets(buff, BUFF_SIZE, map_file);
    buff[strlen(buff) - 1] = '\0'; // remove trailing \n

    map->players_start_bombs = atoi(buff);
}

// Map file with cursor set to map dimensions line
void	    setMapDimensions(t_map *map, FILE *map_file) {
    char    buff[BUFF_SIZE];

    fgets(buff, BUFF_SIZE, map_file);
    buff[strlen(buff) - 1] = '\0'; // remove trailing \n

    sscanf(buff, "%d %d", &map->width, &map->height);
}

void	    setMapInitialState(t_map *map, FILE *map_file) {
    char    buff[BUFF_SIZE];

    printf("ALLOCATING %d * (t_cell*)\n", map->height);
    if (!(map->state = malloc(sizeof(t_cell**) * (map->height)))) {
	perror("MAP STATE MALLOC ERROR");
    }
    
    for (int i = 0; i < map->height; i++) {
	printf("ALLOCATING %d * (t_cell) for map->state[%d]\n", map->width, i);
	if (!(map->state[i] = malloc(sizeof(t_cell*) * (map->width)))) {
	    perror("MAP STATE MALLOC ERROR");
	}
	fgets(buff, BUFF_SIZE, map_file);
	buff[strlen(buff) - 1] = '\0'; // remove trailing \n

	for (int j = 0; j < map->width; j++) {
        map->state[i][j] = malloc(sizeof(t_cell));
	    map->state[i][j]->type = buff[j];
	    map->state[i][j]->content = NULL;
	    printf("map->state[%d][%d]->type == '%c'\n", i, j, map->state[i][j]->type);
	}
    }
}

t_map	    *init_map(FILE *map_file) {
    t_map   *map;

    if (!(map = malloc(sizeof(t_map)))) {
	return NULL;
    }
    
    // These functions move file cursor for convenience.
    setMapBombs(map, map_file);
    setMapDimensions(map, map_file);
    setMapInitialState(map, map_file);

    return map;
}

/*t_map *init_map(char *name) {

    // Here we will verify file name's extension
    if (validate_map_format(name) != 1) {
	  warning_msg("File name incorrect (extension .cassebrique)");
	  return NULL;
      }

      FILE *textfile; // file to open
      char file_contents[256]; // Buffer to read each line of the file
      int counter = 1; // Counter to get the number of the line currently being read
      t_map *map; // Map to return after reading file

      map = malloc(sizeof(t_map));

      textfile = fopen(name, "r");
      if (!textfile) {
	  error_msg("File didn't open");
	  return NULL;
      } else {
	  //success_msg("File opened successfully");

	  // This permit us to know height and width of the map,
	  // and to allocate memory for cells content
	  while (fscanf(textfile, "%[^\n] ", file_contents) != EOF) {
	      if (counter == 1)
		  sscanf(file_contents, "%hd", &map->players_start_bombs);
	      if (counter == 2) {
		  sscanf(file_contents, "%d %d", &map->width, &map->height);
		printf("HEIGHT: %d, WIDTH: %d\n", map->height, map->width);
                map->state = malloc(sizeof(t_cell*) * (map->height));
                if (map->state == NULL)
                    return NULL;
                for (int i = 0; i < map->height; ++i) {
		    printf("ALLOCATING STATE[%d]\n", i);
                    map->state[i] = malloc(sizeof(t_cell) * map->width);
                    if (map->state[i] == NULL)
                        return NULL;
                }
                break;
            }
            counter++;
        }

        // This permit us to get or create map content
        for (int i = 0; i < map->height; i++) {
            //printf("\n");
            for (int j = 0; j < map->width; j++) {
                file_contents[j] = fgetc(textfile);
                if(file_contents[j] == '\n'){
                    j = j-1;
                    continue;
                } else{
                    //printf("%c", file_contents[j]);
                    map->state[i][j].type = file_contents[j];
                    map->state[i][j].content = NULL;
                }
              }

            }
        }
        fclose(textfile);
    }

    if(validate_map_data(map) != 0){
        error_msg("Map not valid");
        return NULL;
    }
    return map;
} */
