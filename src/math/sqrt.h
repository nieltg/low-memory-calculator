/*
 * sqrt.h by nieltg, Daniel
 */

#pragma once

#include "../misc/util.h"

#define MATH_SQRT_STMT(rega) \
    if (UTIL_CAST_UCHAR(rega) < 1) { \
        UTIL_CAST_UCHAR(rega) = 0; \
    } else if (UTIL_CAST_UCHAR(rega) < 4) { \
        UTIL_CAST_UCHAR(rega) = 1; \
    } else if (UTIL_CAST_UCHAR(rega) < 9) { \
        UTIL_CAST_UCHAR(rega) = 2; \
    } else if (UTIL_CAST_UCHAR(rega) < 16) { \
        UTIL_CAST_UCHAR(rega) = 3; \
    } else if (UTIL_CAST_UCHAR(rega) < 25) { \
        UTIL_CAST_UCHAR(rega) = 4; \
    } else if (UTIL_CAST_UCHAR(rega) < 36) { \
        UTIL_CAST_UCHAR(rega) = 5; \
    } else if (UTIL_CAST_UCHAR(rega) < 49) { \
        UTIL_CAST_UCHAR(rega) = 6; \
    } else if (UTIL_CAST_UCHAR(rega) < 64) { \
        UTIL_CAST_UCHAR(rega) = 7; \
    } else if (UTIL_CAST_UCHAR(rega) < 81) { \
        UTIL_CAST_UCHAR(rega) = 8; \
    } else if (UTIL_CAST_UCHAR(rega) < 100) { \
        UTIL_CAST_UCHAR(rega) = 9; \
    } else if (UTIL_CAST_UCHAR(rega) < 121) { \
        UTIL_CAST_UCHAR(rega) = 10; \
    } else if (UTIL_CAST_UCHAR(rega) < 144) { \
        UTIL_CAST_UCHAR(rega) = 11; \
    } else if (UTIL_CAST_UCHAR(rega) < 169) { \
        UTIL_CAST_UCHAR(rega) = 12; \
    } else if (UTIL_CAST_UCHAR(rega) < 196) { \
        UTIL_CAST_UCHAR(rega) = 13; \
    } else if (UTIL_CAST_UCHAR(rega) < 225) { \
        UTIL_CAST_UCHAR(rega) = 14; \
    } else { \
        UTIL_CAST_UCHAR(rega) = 15; \
    }
