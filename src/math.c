/*
 * math.c by nieltg, Daniel
 */

#include "main.h"

#include "math.h"

/* Add. */

void MATH_ADD(reg1,reg2) {
    MATH_ADD_STMT(reg1,reg2);
}

void MATH_ADD(reg1,reg3) {
    MATH_ADD_STMT(reg1,reg3);
}

/* Multiply. */

void MATH_MUL(reg1,reg2) {
    MATH_MUL_STMT(reg1,reg2);
}

void MATH_MUL(reg1,reg3) {
    MATH_MUL_STMT(reg1,reg3);
}
