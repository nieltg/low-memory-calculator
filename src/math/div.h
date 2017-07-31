/*
 * div.h by nieltg, Daniel
 */

#pragma once

#include "../math.h"
#include "../misc/shift.h"
#include "../misc/util.h"

/* Bit operations. */

#define _MATH_DIV_SET_RESULT_STMT(rega,i,val) \
    (rega).bit##i = (val)

/* Byte operations. */

#define _DIV_SHIFT_ITER_UNIT(rega,chain_stmt) \
    if ((rega).bit8) { \
        UTIL_LOAD_BIN_STMT(rega,0,0,0,0,0,0,0,0); \
    } else { \
        SHIFT_LEFT1_STMT(rega); \
        chain_stmt; \
    }

#define _DIV_SHIFT_ITER1_STMT(rega) \
    ;

#define _DIV_SHIFT_ITER2_STMT(rega) \
    _DIV_SHIFT_ITER_UNIT(rega,_DIV_SHIFT_ITER1_STMT(rega))

#define _DIV_SHIFT_ITER3_STMT(rega) \
    _DIV_SHIFT_ITER_UNIT(rega,_DIV_SHIFT_ITER2_STMT(rega))

#define _DIV_SHIFT_ITER4_STMT(rega) \
    _DIV_SHIFT_ITER_UNIT(rega,_DIV_SHIFT_ITER3_STMT(rega))

#define _DIV_SHIFT_ITER5_STMT(rega) \
    _DIV_SHIFT_ITER_UNIT(rega,_DIV_SHIFT_ITER4_STMT(rega))

#define _DIV_SHIFT_ITER6_STMT(rega) \
    _DIV_SHIFT_ITER_UNIT(rega,_DIV_SHIFT_ITER5_STMT(rega))

#define _DIV_SHIFT_ITER7_STMT(rega) \
    _DIV_SHIFT_ITER_UNIT(rega,_DIV_SHIFT_ITER6_STMT(rega))

#define _DIV_SHIFT_ITER8_STMT(rega) \
    _DIV_SHIFT_ITER_UNIT(rega,_DIV_SHIFT_ITER7_STMT(rega))

#define _DIV_SHIFT_ITER_N_STMT(rega,n) \
    _DIV_SHIFT_ITER##n##_STMT(rega)

#define _MATH_DIV_UNIT_STMT(rega,regb,rego,regt1,i,bit_stmt0,bit_stmt1) \
    UTIL_MOVE_STMT(regb,rego); \
    _DIV_SHIFT_ITER_N_STMT(rego,i); \
    if ((UTIL_CAST_UCHAR(rego) != 0) && \
        (UTIL_CAST_UCHAR(rega) >= UTIL_CAST_UCHAR(rego))) { \
        MATH_SUB(rega,rego,regt1); \
        bit_stmt1; \
        _MATH_DIV_SET_RESULT_STMT(rego,i,1); \
    } else { \
        bit_stmt0; \
        _MATH_DIV_SET_RESULT_STMT(rego,i,0); \
    }

#define _MATH_DIV_UNIT2_STMT(rega,regb,rego,regt1,i,j,bit_stmt0,bit_stmt1) \
    _MATH_DIV_UNIT_STMT(rega,regb,rego,regt1,i, \
        _MATH_DIV_UNIT_STMT(rega,regb,rego,regt1,j,bit_stmt0,bit_stmt1), \
        _MATH_DIV_UNIT_STMT(rega,regb,rego,regt1,j,bit_stmt0,bit_stmt1))

#define _MATH_DIV_UNIT4_STMT(rega,regb,rego,regt1,i,j,k,l,bit_stmt0,bit_stmt1) \
    _MATH_DIV_UNIT2_STMT(rega,regb,rego,regt1,i,j, \
        _MATH_DIV_UNIT2_STMT(rega,regb,rego,regt1,k,l,bit_stmt0,bit_stmt1), \
        _MATH_DIV_UNIT2_STMT(rega,regb,rego,regt1,k,l,bit_stmt0,bit_stmt1))

#define MATH_DIV_STMT(rega,regb,regt1,regt2) \
    UTIL_MOVE_STMT(regb,regt2); \
    _MATH_DIV_UNIT4_STMT(rega,regt2,regb,regt1,8,7,6,5, \
        _MATH_DIV_UNIT4_STMT(rega,regt2,regb,regt1,4,3,2,1,,), \
        _MATH_DIV_UNIT4_STMT(rega,regt2,regb,regt1,4,3,2,1,,))
