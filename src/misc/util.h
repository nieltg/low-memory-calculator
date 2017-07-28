/*
 * util.h by nieltg, Daniel
 */

#pragma once

/* Bit manipulation. */

#define _UTIL_SET_STMT(rega,i,regb,j) \
    (regb).bit##j = (rega).bit##i

#define _UTIL_SET_ZERO_STMT(rega,i) \
    (rega).bit##i = 0

/* Byte manipulation. */

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
