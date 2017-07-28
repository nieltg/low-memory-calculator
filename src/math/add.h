/*
 * add.h by nieltg, Daniel
 */

#pragma once

#include <stdio.h>

#include <misc/logic.h>

/* Bit adder. */

#define _MATH_ADD_HALF_ADDER(a,b) \
    LOGIC_XOR(a,b)

#define _MATH_ADD_HALF_ADDER_CARRY(a,b) \
    LOGIC_AND(a,b)

#define _MATH_ADD_FULL_ADDER(a,b,carry) \
    _MATH_ADD_HALF_ADDER(carry,_MATH_ADD_HALF_ADDER(a,b))

#define _MATH_ADD_FULL_ADDER_CARRY(a,b,carry) \
    LOGIC_OR( \
        _MATH_ADD_HALF_ADDER_CARRY(carry,_MATH_ADD_HALF_ADDER(a,b)), \
        _MATH_ADD_HALF_ADDER_CARRY(a,b))

#define _MATH_ADD_FULL_ADDER_STMT(a,b,carry_const,carry_stmt0,carry_stmt1) \
    if (_MATH_ADD_FULL_ADDER_CARRY(a,b,carry_const)) { \
        carry_stmt1; \
    } else { \
        carry_stmt0; \
    } \
    (a) = _MATH_ADD_FULL_ADDER(a,b,carry_const)

/* Byte adder. */

#define _MATH_ADD_UNIT2_STMT(rega,regb,i,j,carry_const,carry_stmt0,carry_stmt1) \
    _MATH_ADD_FULL_ADDER_STMT(rega.bit##i,regb.bit##i,carry_const, \
        _MATH_ADD_FULL_ADDER_STMT(rega.bit##j,regb.bit##j,0,carry_stmt0,carry_stmt1), \
        _MATH_ADD_FULL_ADDER_STMT(rega.bit##j,regb.bit##j,1,carry_stmt0,carry_stmt1))

#define _MATH_ADD_UNIT4_STMT(rega,regb,i,j,k,l,carry_const,carry_stmt0,carry_stmt1) \
    _MATH_ADD_UNIT2_STMT(rega,regb,i,j,carry_const, \
        _MATH_ADD_UNIT2_STMT(rega,regb,k,l,0,carry_stmt0,carry_stmt1), \
        _MATH_ADD_UNIT2_STMT(rega,regb,k,l,1,carry_stmt0,carry_stmt1))

#define MATH_ADD_STMT(rega,regb) \
    _MATH_ADD_UNIT4_STMT(rega,regb,1,2,3,4,0, \
        _MATH_ADD_UNIT4_STMT(rega,regb,5,6,7,8,0,, \
            printf ("math/add: warning: Overflow!\n")), \
        _MATH_ADD_UNIT4_STMT(rega,regb,5,6,7,8,1,, \
            printf ("math/add: warning: Overflow!\n")))
