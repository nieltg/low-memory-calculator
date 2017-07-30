#include <stdio.h>
#include <stdlib.h>

#include "../src/main.h"
#include "../src/math.h"
#include "../src/math/add.h"
#include "../src/misc/util.h"

/* Environment. */

reg reg1;
reg reg2;
reg reg3;
reg reg4;

MATH_IMPL(MATH_ADD,reg1,reg2);

/* Test. */

int main (int argc, char** argv) {

    unsigned int i, j, val;

    for (i = 0; i < 256; i++) {
        for (j = 0; j < 256; j++) {
            UTIL_CAST_UCHAR(reg1) = i;
            UTIL_CAST_UCHAR(reg2) = j;

            val = i + j;
            MATH_ADD(reg1, reg2);

            if (UTIL_CAST_UCHAR(reg1) != (unsigned char) val) {
                fprintf (stderr, "%u + %u = %u, not %u\n", i, j, val,
                    UTIL_CAST_UCHAR(reg1));
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}
