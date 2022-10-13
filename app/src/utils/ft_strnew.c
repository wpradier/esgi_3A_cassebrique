#include "cassebrique.h"


char	      *ft_strnew(size_t size) {
    char      *new_str;
    size_t    tot_size;

    tot_size = sizeof(char) * (size + 1);

    if (tot_size <= 0 || !(new_str = malloc(tot_size))) {
	return NULL;
    }

    bzero(new_str, tot_size);

    return new_str;
}
