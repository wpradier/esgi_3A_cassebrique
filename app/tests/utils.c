#include "unit-tests.h"
#include "cassebrique.h"

char *teststr;

void endStrTest(void) {
    free(teststr);
}


Test(utils, strnew_fills_allocated_memory_with_zeros, .fini = endStrTest) {
    size_t testsize;

    testsize = 5;

    teststr = ft_strnew(testsize);
    for (size_t i = 0; i < testsize + 1; i++) {
	cr_assert_eq(teststr[0], '\0');
    }
}

Test(utils, strnew_allocates_sizearg_plus_one, .fini = endStrTest) {
    teststr = ft_strnew(0);

    cr_assert_eq(teststr[0], '\0');
}

Test(utils, strnew_negative_size_returns_null, .fini = endStrTest) {
    teststr = ft_strnew(-1);

    cr_assert_eq(teststr, NULL);
}
