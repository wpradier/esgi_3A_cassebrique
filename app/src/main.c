#include "cassebrique.h"

int	  main(void) {
    char  *test_str; // string for test function

    /* Test Function */
    test_str = ft_strnew(28);
    if (!test_str) {
        error_msg("ft_strnew call returned NULL");
        return 1;
    }
    strcpy(test_str, "Everything is working fine!");
    success_msg(test_str);
    free(test_str);

    return 0;
}
