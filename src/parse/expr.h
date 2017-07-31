/*
 * expr.h by nieltg, Daniel
 */

#pragma once

#include <stdio.h>

#include "../math.h"
#include "../misc/util.h"
#include "num.h"

#define _EXPR_READ_EXPECT_STMT(file,ch) \
    if ((ch = fgetc (file)) == EOF) { \
        printf("%s:%u: Unexpected EOF\n", __FILE__, __LINE__); \
        return -1; \
    }

#define _EXPR_EVAL3_STMT(file,ch,rega,regt1) \
    UTIL_ZERO_STMT(rega); \
    if (ch == 'r') { \
        _EXPR_READ_EXPECT_STMT(file,ch); \
        NUM_READ_STMT(file,ch,rega,regt1); \
        MATH_SQRT(rega); \
    } else { \
        NUM_READ_STMT(file,ch,rega,regt1); \
    }

#define _EXPR_EVAL2_STMT(file,ch,rega,regt1,regt2) \
    UTIL_ZERO_STMT(rega); \
    _EXPR_EVAL3_STMT(file,ch,rega,regt1); \
    while (ch != EOF) { \
        if (ch == '^') { \
            _EXPR_READ_EXPECT_STMT(file,ch); \
            _EXPR_EVAL3_STMT(file,ch,regt1,regt2); \
            MATH_POW(rega,regt1,regt2); \
        } else { \
            break; \
        } \
    }

#define _EXPR_EVAL1_STMT(file,ch,rega,regt1,regt2,regt3) \
    UTIL_ZERO_STMT(rega); \
    _EXPR_EVAL2_STMT(file,ch,rega,regt2,regt3); \
    while (ch != EOF) { \
        if (ch == '+') { \
            _EXPR_READ_EXPECT_STMT(file,ch); \
            _EXPR_EVAL2_STMT(file,ch,regt1,regt2,regt3); \
            MATH_ADD(rega,regt1); \
        } else if (ch == '-') { \
            _EXPR_READ_EXPECT_STMT(file,ch); \
            _EXPR_EVAL2_STMT(file,ch,regt1,regt2,regt3); \
            MATH_SUB(rega,regt1,regt2); \
        } else if (ch == '*') { \
            _EXPR_READ_EXPECT_STMT(file,ch); \
            _EXPR_EVAL2_STMT(file,ch,regt1,regt2,regt3); \
            MATH_MUL(rega,regt1); \
        } else if (ch == '/') { \
            _EXPR_READ_EXPECT_STMT(file,ch); \
            _EXPR_EVAL2_STMT(file,ch,regt1,regt2,regt3); \
            MATH_DIV(rega,regt1,regt2,regt3); \
            UTIL_MOVE_STMT(regt1,rega); \
        } else if (ch == '%') { \
            _EXPR_READ_EXPECT_STMT(file,ch); \
            _EXPR_EVAL2_STMT(file,ch,regt1,regt2,regt3); \
            MATH_DIV(rega,regt1,regt2,regt3); \
        } else { \
            printf ("%s:%u: Invalid character: %c\n", __FILE__, __LINE__, ch); \
            return -1; \
        } \
    }

#define EXPR_EVAL_STMT(file,ch,rega,regt1,regt2,regt3) \
    _EXPR_READ_EXPECT_STMT(file,ch); \
    _EXPR_EVAL1_STMT(file,ch,rega,regt1,regt2,regt3)
