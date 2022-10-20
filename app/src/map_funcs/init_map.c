#include "cassebrique.h"

/*
 * Prend un chemin de fichier map (.cassebrique)
 * Retourne un t_map complètement mallocé
 * Retourne NULL en cas d'erreur
 * Doit:
 *  - Valider le fichier .cassebrique (fonction validate pour le format)
 *  - Valider les valeurs liés à la logique de jeu (assez de joueurs... Création d'une fonction externe count_players ?)
 */

void init_map(char *path){
    FILE *textfile;
    char ch;

    textfile = fopen(path, "r");
    if(textfile == NULL){
        printf(RED);
        printf("Erreur d'ouverture du fichier de la map\n");
        printf(NC);
    } else{
        printf(GREEN);
        printf("Ouverture du fichier de la map avec succès\n");
        printf(NC);

        while((ch = fgetc(textfile))!=EOF) {
            putchar(ch);
        }

        fclose(textfile);
    }
}
