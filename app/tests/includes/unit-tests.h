#ifndef MY_UNIT_TESTS_H
# define MY_UNIT_TESTS_H


/* LIBRARIES */

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <criterion/criterion.h>
# include <criterion/redirect.h>

/* COLORS */

# define _RED "\033[0;31m"
# define _GREEN "\033[0;32m"
# define _NC "\033[0m"


/* PROTOTYPES */

char	    *ft_strnew(size_t size);

#endif
