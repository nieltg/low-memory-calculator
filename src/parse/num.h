/*
 * num.h by nieltg, Daniel
 */

#pragma once

#include <stdio.h>

#include "../math.h"

/* Read character. */

#define _NUM_MUL10_STMT(rega,regt1) \
    UTIL_LOAD_BIN_STMT(regt1,0,0,0,0,1,0,1,0); \
    MATH_MUL(rega,regt1)

#define _NUM_READ1_EXCEPT0_STMT(ch) \
    printf ("%s:%u: Not a number: %c\n", __FILE__, __LINE__, ch); \
    return -1

#define _NUM_READ1_EXCEPT1_STMT(ch) \
    break

#define _NUM_READ1_CHECK_STMT(ch,except_stmt) \
    if (ch == '0') { \
    } else if (ch == '1') { \
    } else if (ch == '2') { \
    } else if (ch == '3') { \
    } else if (ch == '4') { \
    } else if (ch == '5') { \
    } else if (ch == '6') { \
    } else if (ch == '7') { \
    } else if (ch == '8') { \
    } else if (ch == '9') { \
    } else { \
        except_stmt(ch); \
    }

#define _NUM_READ1_STMT(ch,rega) \
    if (ch == '0') { \
        UTIL_LOAD_BIN_STMT(rega,0,0,0,0,0,0,0,0); \
    } else if (ch == '1') { \
        UTIL_LOAD_BIN_STMT(rega,0,0,0,0,0,0,0,1); \
    } else if (ch == '2') { \
        UTIL_LOAD_BIN_STMT(rega,0,0,0,0,0,0,1,0); \
    } else if (ch == '3') { \
        UTIL_LOAD_BIN_STMT(rega,0,0,0,0,0,0,1,1); \
    } else if (ch == '4') { \
        UTIL_LOAD_BIN_STMT(rega,0,0,0,0,0,1,0,0); \
    } else if (ch == '5') { \
        UTIL_LOAD_BIN_STMT(rega,0,0,0,0,0,1,0,1); \
    } else if (ch == '6') { \
        UTIL_LOAD_BIN_STMT(rega,0,0,0,0,0,1,1,0); \
    } else if (ch == '7') { \
        UTIL_LOAD_BIN_STMT(rega,0,0,0,0,0,1,1,1); \
    } else if (ch == '8') { \
        UTIL_LOAD_BIN_STMT(rega,0,0,0,0,1,0,0,0); \
    } else if (ch == '9') { \
        UTIL_LOAD_BIN_STMT(rega,0,0,0,0,1,0,0,1); \
    }

/* Read number. */

#define _NUM_READ_UNIT_STMT(ch,rega,regt1,except_stmt) \
    _NUM_READ1_CHECK_STMT(ch,except_stmt); \
    _NUM_MUL10_STMT(rega,regt1); \
    _NUM_READ1_STMT(ch,regt1); \
    MATH_ADD(rega,regt1)

#define NUM_READ_STMT(file,ch,rega,regt1) \
    UTIL_ZERO_STMT(rega); \
    _NUM_READ_UNIT_STMT(ch,rega,regt1,_NUM_READ1_EXCEPT0_STMT); \
    while ((ch = fgetc (file)) != EOF) { \
        _NUM_READ_UNIT_STMT(ch,rega,regt1,_NUM_READ1_EXCEPT1_STMT); \
    }
