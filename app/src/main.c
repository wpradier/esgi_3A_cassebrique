#include "cassebrique.h"

int	  main(void) {
    char  *test_str; // string for test function
    char cwd[256]; // Buffer to get current directory
    t_map *map; // Map to use

    /* Test Function */
    test_str = ft_strnew(28);
    if (!test_str) {
        error_msg("ft_strnew call returned NULL");
        return 1;
    }
    strcpy(test_str, "\nEverything is working fine!");
    success_msg(test_str);
    free(test_str);

    /* Get current directory */
    if (getcwd(cwd, sizeof(cwd)) == NULL)
        error_msg("getcwd() error");
    else
        highlight_msg("Current working directory is:");
    printf("\n%s", cwd);

    /* Gestion du fichier de la map */
    map = init_map("./map.cassebrique");
    free_map(map);
    return 0;
}
