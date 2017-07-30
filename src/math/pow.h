/*
 * pow.h by nieltg, Daniel
 */

#pragma once

#include <stdio.h>

#include "../math.h"
#include "../misc/logic.h"
#include "../misc/util.h"

/* Byte multi-multiplier. */

#define _MATH_POW_SINGLE_OP_STMT(rega,regb,regt1,c) \
    UTIL_MOVE_STMT(rega,regb); \
    MATH_MUL(rega,regb); \
    if (c) { \
        UTIL_MOVE_STMT(regt1,regb); \
        MATH_MUL(rega,regb); \
    }

#define _MATH_POW_UNIT_STMT(rega,regb,regt1,i,bit_stmt0,bit_stmt1) \
    if ((regb).bit##i) { \
        bit_stmt1; \
        _MATH_POW_SINGLE_OP_STMT(rega,regb,regt1,1); \
    } else { \
        bit_stmt0; \
        _MATH_POW_SINGLE_OP_STMT(rega,regb,regt1,0); \
    }

#define _MATH_POW_UNIT2_STMT(rega,regb,regt1,i,j,bit_stmt0,bit_stmt1) \
    _MATH_POW_UNIT_STMT(rega,regb,regt1,i, \
        _MATH_POW_UNIT_STMT(rega,regb,regt1,j,bit_stmt0,bit_stmt1), \
        _MATH_POW_UNIT_STMT(rega,regb,regt1,j,bit_stmt0,bit_stmt1))

#define _MATH_POW_UNIT4_STMT(rega,regb,regt1,i,j,k,l,bit_stmt0,bit_stmt1) \
    _MATH_POW_UNIT2_STMT(rega,regb,regt1,i,j, \
        _MATH_POW_UNIT2_STMT(rega,regb,regt1,k,l,bit_stmt0,bit_stmt1), \
        _MATH_POW_UNIT2_STMT(rega,regb,regt1,k,l,bit_stmt0,bit_stmt1))

#define MATH_POW_STMT(rega,regb,regt1) \
    UTIL_MOVE_STMT(rega,regt1); \
    UTIL_LOAD_BIN_STMT(rega,0,0,0,0,0,0,0,1); \
    _MATH_POW_UNIT4_STMT(rega,regb,regt1,1,2,3,4, \
        _MATH_POW_UNIT4_STMT(rega,regb,regt1,5,6,7,8,,), \
        _MATH_POW_UNIT4_STMT(rega,regb,regt1,5,6,7,8,,))
