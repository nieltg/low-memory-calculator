/*
 * util.h by nieltg, Daniel
 */

#pragma once

#include "logic.h"

/* Bit manipulation. */

#define _UTIL_SET_STMT(rega,i,regb,j) \
    (regb).bit##j = (rega).bit##i

#define _UTIL_SET_VAL_STMT(rega,i,a) \
    (rega).bit##i = a

#define _UTIL_SET_ZERO_STMT(rega,i) \
    (rega).bit##i = 0

/* Byte manipulation. */

#define UTIL_CAST_UCHAR(rega) \
    *(unsigned char*)(&(rega))

#define UTIL_LOAD_BIN_STMT(rega,h,g,f,e,d,c,b,a) \
    _UTIL_SET_VAL_STMT(rega,1,a); \
    _UTIL_SET_VAL_STMT(rega,2,b); \
    _UTIL_SET_VAL_STMT(rega,3,c); \
    _UTIL_SET_VAL_STMT(rega,4,d); \
    _UTIL_SET_VAL_STMT(rega,5,e); \
    _UTIL_SET_VAL_STMT(rega,6,f); \
    _UTIL_SET_VAL_STMT(rega,7,g); \
    _UTIL_SET_VAL_STMT(rega,8,h)

#define UTIL_MOVE_STMT(rega,regb) \
    _UTIL_SET_STMT(rega,1,regb,1); \
    _UTIL_SET_STMT(rega,2,regb,2); \
    _UTIL_SET_STMT(rega,3,regb,3); \
    _UTIL_SET_STMT(rega,4,regb,4); \
    _UTIL_SET_STMT(rega,5,regb,5); \
    _UTIL_SET_STMT(rega,6,regb,6); \
    _UTIL_SET_STMT(rega,7,regb,7); \
    _UTIL_SET_STMT(rega,8,regb,8)

#define UTIL_ZERO_STMT(rega) \
    _UTIL_SET_ZERO_STMT(rega,1); \
    _UTIL_SET_ZERO_STMT(rega,2); \
    _UTIL_SET_ZERO_STMT(rega,3); \
    _UTIL_SET_ZERO_STMT(rega,4); \
    _UTIL_SET_ZERO_STMT(rega,5); \
    _UTIL_SET_ZERO_STMT(rega,6); \
    _UTIL_SET_ZERO_STMT(rega,7); \
    _UTIL_SET_ZERO_STMT(rega,8)

#define UTIL_MOVE_ZERO_STMT(rega,regb) \
    UTIL_MOVE_STMT(rega,regb); \
    UTIL_ZERO_STMT(rega)

#define UTIL_SWAP_STMT(rega,regb) \
    LOGIC_XOR_STMT(rega,regb); \
    LOGIC_XOR_STMT(regb,rega); \
    LOGIC_XOR_STMT(rega,regb)
