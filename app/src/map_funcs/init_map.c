#include "cassebrique.h"

/*
 * Prend un chemin de fichier map (.cassebrique)
 * Retourne un t_map complètement mallocé
 * Retourne NULL en cas d'erreur
 * Doit:
 *  - Valider le fichier .cassebrique (fonction validate pour le format)
 *  - Valider les valeurs liés à la logique de jeu (assez de joueurs... Création d'une fonction externe count_players ?)
 */

t_map	  *init_map(char *path);
