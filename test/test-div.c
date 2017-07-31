#include <stdio.h>
#include <stdlib.h>

#include "../src/main.h"
#include "../src/math.h"
#include "../src/math/add.h"
#include "../src/math/sub.h"
#include "../src/math/div.h"
#include "../src/misc/util.h"

/* Environment. */

reg reg1;
reg reg2;
reg reg3;
reg reg4;

MATH_IMPL(MATH_ADD,reg1,reg2);
MATH_IMPL(MATH_ADD,reg2,reg3);

MATH_IMPL(MATH_SUB,reg1,reg2,reg3);

MATH_IMPL(MATH_DIV,reg1,reg2,reg3,reg4);

/* Test. */

int main (int argc, char** argv) {

    unsigned int i, j, val1, val2;

    for (i = 0; i < 256; i++) {
        for (j = 0; j < 256; j++) {
            UTIL_CAST_UCHAR(reg1) = i;
            UTIL_CAST_UCHAR(reg2) = j;

            if (j > 0) {
                val1 = i % j;
                val2 = i / j;
            } else {
                val1 = i;
                val2 = 0;
            }

            MATH_DIV(reg1,reg2,reg3,reg4);

            if (UTIL_CAST_UCHAR(reg1) != (unsigned char) val1) {
                fprintf (stderr, "%u %% %u = %u, not %u\n", i, j, val1,
                    UTIL_CAST_UINT(reg1));
                return EXIT_FAILURE;
            }

            if (UTIL_CAST_UCHAR(reg2) != (unsigned char) val2) {
                fprintf (stderr, "%u / %u = %u, not %u\n", i, j, val2,
                    UTIL_CAST_UINT(reg2));
                return EXIT_FAILURE;
            }
        }
    }

    return EXIT_SUCCESS;
}
