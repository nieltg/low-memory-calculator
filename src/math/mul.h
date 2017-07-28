/*
 * mul.h by nieltg, Daniel
 */

#pragma once

#include <stdio.h>

#include "../math.h"
#include "../misc/logic.h"
#include "../misc/shift.h"
#include "../misc/util.h"

/* Byte multiplier. */

#define _MATH_MUL_SINGLE_OP_STMT(rega,regb,c) \
    if (c) { \
        MATH_ADD(rega,regb); \
    } \
    SHIFT_LEFT1_STMT(regb); \

#define _MATH_MUL_UNIT_STMT(rega,regb,i,bit_stmt0,bit_stmt1) \
    if ((regb).bit##i) { \
        bit_stmt1; \
        _MATH_MUL_SINGLE_OP_STMT(rega,regb,1); \
    } else { \
        bit_stmt0; \
        _MATH_MUL_SINGLE_OP_STMT(rega,regb,0); \
    }

#define _MATH_MUL_UNIT2_STMT(rega,regb,i,j,bit_stmt0,bit_stmt1) \
    _MATH_MUL_UNIT_STMT(rega,regb,i, \
        _MATH_MUL_UNIT_STMT(rega,regb,j,bit_stmt0,bit_stmt1), \
        _MATH_MUL_UNIT_STMT(rega,regb,j,bit_stmt0,bit_stmt1))

#define _MATH_MUL_UNIT4_STMT(rega,regb,i,j,k,l,bit_stmt0,bit_stmt1) \
    _MATH_MUL_UNIT2_STMT(rega,regb,i,j, \
        _MATH_MUL_UNIT2_STMT(rega,regb,k,l,bit_stmt0,bit_stmt1), \
        _MATH_MUL_UNIT2_STMT(rega,regb,k,l,bit_stmt0,bit_stmt1))

#define MATH_MUL_STMT(rega,regb) \
    _MATH_MUL_UNIT4_STMT(rega,regb,8,7,6,5, \
        _MATH_MUL_UNIT4_STMT(rega,regb,4,3,2,1, \
            UTIL_MOVE_ZERO_STMT(rega,regb), \
            UTIL_MOVE_ZERO_STMT(rega,regb)), \
        _MATH_MUL_UNIT4_STMT(rega,regb,4,3,2,1, \
            UTIL_MOVE_ZERO_STMT(rega,regb), \
            UTIL_MOVE_ZERO_STMT(rega,regb)))
