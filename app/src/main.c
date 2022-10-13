#include "cassebrique.h"

int	  main(void) {
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
