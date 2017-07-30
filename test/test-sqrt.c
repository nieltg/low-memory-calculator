#include <stdio.h>
#include <stdlib.h>

#include "../src/main.h"
#include "../src/math.h"
#include "../src/math/sqrt.h"
#include "../src/misc/util.h"

/* Environment. */

reg reg1;
reg reg2;
reg reg3;
reg reg4;

MATH_IMPL(MATH_SQRT,reg1);

/* Test. */

/*
 * Reference:
 * https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
 */

unsigned int i_sqrt (unsigned int num) {
    unsigned int res = 0;
    unsigned int bit = 1 << 30;
 
    while (bit > num)
        bit >>= 2;
        
    while (bit != 0) {
        if (num >= res + bit) {
            num -= res + bit;
            res = (res >> 1) + bit;
        }
        else
            res >>= 1;

        bit >>= 2;
    }

    return res;
}

int main (int argc, char** argv) {

    unsigned int i, j, val;

    for (i = 0; i < 256; i++) {
        UTIL_CAST_UCHAR(reg1) = i;

        val = i_sqrt (i);
        MATH_SQRT(reg1);

        if (UTIL_CAST_UCHAR(reg1) != (unsigned char) val) {
            fprintf (stderr, "sqrt %u = %u, not %u\n", i, val,
                UTIL_CAST_UCHAR(reg1));
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}
