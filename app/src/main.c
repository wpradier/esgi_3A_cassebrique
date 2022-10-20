#include "cassebrique.h"

int	  main(void) {
    char  *test_str;
    char cwd[256];


    if (getcwd(cwd, sizeof(cwd)) == NULL)
        perror("getcwd() error");
    else
        printf("current working directory is: %s\n", cwd);

    test_str = ft_strnew(28);
    if (!test_str) {
	printf(RED);
	printf("ft_strnew call returned NULL\n");
	printf(NC);
	return 1;
    }

    strcpy(test_str, "Everything is working fine!\n");

    printf(GREEN);
    printf("%s\n", test_str);
    printf(NC);



    free(test_str);

    //Gestion du fichier de la map
    init_map("/Users/smveer/Desktop/PiscineC/esgi_3A_cassebrique/app/map.cassebrique");
    return 0;
}
