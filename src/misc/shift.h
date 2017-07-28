/*
 * shift.h by nieltg, Daniel
 */

#pragma once

#include "util.h"

/* Bit shift. */

#define _SHIFT_SET_STMT(rega,i,j) \
    _UTIL_SET_STMT(rega,i,rega,j)

/* Byte shift. */

#define SHIFT_LEFT1_STMT(rega) \
    _SHIFT_SET_STMT(rega,7,8); \
    _SHIFT_SET_STMT(rega,6,7); \
    _SHIFT_SET_STMT(rega,5,6); \
    _SHIFT_SET_STMT(rega,4,5); \
    _SHIFT_SET_STMT(rega,3,4); \
    _SHIFT_SET_STMT(rega,2,3); \
    _SHIFT_SET_STMT(rega,1,2); \
    _UTIL_SET_ZERO_STMT(rega,1)
