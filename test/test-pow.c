#include <stdio.h>
#include <stdlib.h>

#include "../src/main.h"
#include "../src/math.h"
#include "../src/math/add.h"
#include "../src/math/mul.h"
#include "../src/math/pow.h"
#include "../src/misc/util.h"

/* Environment. */

reg reg1;
reg reg2;
reg reg3;
reg reg4;

MATH_IMPL(MATH_ADD,reg1,reg1);
MATH_IMPL(MATH_ADD,reg1,reg2);

MATH_IMPL(MATH_MUL,reg1,reg2);

MATH_IMPL(MATH_POW,reg1,reg2,reg3);

/* Test. */

unsigned int uint_pow (unsigned int b, unsigned int n) {

    unsigned int a = 1;

    if (!n)
        return 1;
    
    while (n > 1) {
        if (n & 1) {
            a *= b;
        }

        b *= b;
        n /= 2;
    }

    return a * b;
}

int main (int argc, char** argv) {

    unsigned int i, j, val;

    for (i = 0; i < 256; i++) {
        for (j = 0; j < 256; j++) {
            UTIL_CAST_UCHAR(reg1) = i;
            UTIL_CAST_UCHAR(reg2) = j;

            val = uint_pow (i, j);
            MATH_POW(reg1, reg2, reg3);

            if (UTIL_CAST_UCHAR(reg1) != (unsigned char) val) {
                fprintf (stderr, "%u ^ %u = %u, not %u\n", i, j, val,
                    UTIL_CAST_UINT(reg1));
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}
