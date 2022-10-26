#include "cassebrique.h"

/*
 * Prend un chemin de fichier map (.cassebrique)
 * Retourne un t_map complètement mallocé
 * Retourne NULL en cas d'erreur
 * Doit:
 *  - Valider le fichier .cassebrique (fonction validate pour le format)
 *  - Valider les valeurs liés à la logique de jeu (assez de joueurs... Création d'une fonction externe count_players ?)
 */

t_map *init_map(char *path){
    FILE *textfile; // file to open
    char file_contents[256]; // Buffer to read each line of the file
    int counter = 1; // Counter to get the number of the line currently being read
    t_map *map; // Map to return after reading file

    map = malloc(sizeof(t_map));

    textfile = fopen(path, "r");
    if(textfile == NULL){
        error_msg("File didn't open");
        return NULL;
    } else{
        success_msg("File opened successfully");

        // This permit us to know height and width of the map,
        // and to allocate memory for cells content
        while (fscanf(textfile, "%[^\n] ", file_contents) != EOF) {
            if(counter == 1)
                sscanf(file_contents, "%hd", &map->players_start_bombs);
            if(counter == 2) {
                sscanf(file_contents, "%d %d", &map->width, &map->height);
                map->state = malloc(sizeof(t_cell)*map->height);
                if(map->state == NULL)
                    return NULL;
                for (int i = 0; i < map->height; ++i) {
                    map->state[i] = malloc(sizeof(t_cell)*map->width);
                    if(map->state[i] == NULL)
                        return NULL;
                }
                break;
            }
            counter++;
        }

        // This permit us to get or create map content
        for (int i = 0; i < map->height; ++i) {
            while (fscanf(textfile, "%[^\n] ", file_contents) != EOF) {
                //printf("%s << %lu\n", file_contents, strlen(file_contents));
                for (int j = 0; j < map->width; ++j) {

                    //printf("%c", file_contents[j]);

                    map->state[i][j].type = file_contents[j];
                    switch (file_contents[j]) {
                        case 'x':
                            map->state[i][j].content = "█";
                            break;
                        case 'm':
                            map->state[i][j].content = "▒";
                            break;
                        case ' ':
                            map->state[i][j].content = "-";
                            break;
                        case 'p':
                            map->state[i][j].content = "p";
                            break;
                        default:
                            break;
                    }
                }
                break;
            }
        }
        fclose(textfile);
    }
    return map;
}