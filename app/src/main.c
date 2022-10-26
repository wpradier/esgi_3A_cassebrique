#include "cassebrique.h"



int	  main(void) {
    t_config *my_test = init_config("./cassebrique.conf");
    display_config(my_test);
    free_config(my_test);


    
    char  *test_str;

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
    
    
    return 0;
}
