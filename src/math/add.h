/*
 * add.h by nieltg, Daniel
 */

#pragma once

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

/* Byte adder. */

#define _MATH_ADD_UNIT_STMT(a,b,c,i,carry_in) \
    (c).bit##i = _MATH_ADD_FULL_ADDER((a).bit##i,(b).bit##i,carry_in)

#define _MATH_ADD_UNIT_CARRY_STMT(a,b,c,i,carry_io) \
    (carry_io) = _MATH_ADD_FULL_ADDER_CARRY((a).bit##i,(b).bit##i,carry_io)

#define MATH_ADD_STMT(a,b,c) \
    _MATH_ADD_UNIT_STMT(a,b,c,1,(c).bit8); \
    _MATH_ADD_UNIT_CARRY_STMT(a,b,c,1,(c).bit8); \
    _MATH_ADD_UNIT_STMT(a,b,c,2,(c).bit8); \
    _MATH_ADD_UNIT_CARRY_STMT(a,b,c,2,(c).bit8); \
    _MATH_ADD_UNIT_STMT(a,b,c,3,(c).bit8); \
    _MATH_ADD_UNIT_CARRY_STMT(a,b,c,3,(c).bit8); \
    _MATH_ADD_UNIT_STMT(a,b,c,4,(c).bit8); \
    _MATH_ADD_UNIT_CARRY_STMT(a,b,c,4,(c).bit8); \
    _MATH_ADD_UNIT_STMT(a,b,c,5,(c).bit8); \
    _MATH_ADD_UNIT_CARRY_STMT(a,b,c,5,(c).bit8); \
    _MATH_ADD_UNIT_STMT(a,b,c,6,(c).bit8); \
    _MATH_ADD_UNIT_CARRY_STMT(a,b,c,6,(c).bit8); \
    _MATH_ADD_UNIT_STMT(a,b,c,7,(c).bit8); \
    _MATH_ADD_UNIT_CARRY_STMT(a,b,c,7,(c).bit8); \
    _MATH_ADD_UNIT_STMT(a,b,c,8,(c).bit8)
