/*
 * math.h by nieltg, Daniel
 */

#pragma once

#include "math/add.h"

/* Add. */

#define MATH_ADD(rega,regb) \
    math_add_##rega##_##regb ()

void MATH_ADD(reg1,reg2);
void MATH_ADD(reg1,reg3);
