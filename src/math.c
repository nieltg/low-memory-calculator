/*
 * math.c by nieltg, Daniel
 */

#include "main.h"
#include "math/add.h"
#include "math/sub.h"
#include "math/mul.h"
#include "math/div.h"
#include "math/pow.h"
#include "math/sqrt.h"

#include "math.h"

/* Add. */

MATH_IMPL(MATH_ADD,reg1,reg1);
MATH_IMPL(MATH_ADD,reg1,reg2);
MATH_IMPL(MATH_ADD,reg1,reg3);
MATH_IMPL(MATH_ADD,reg2,reg2);
MATH_IMPL(MATH_ADD,reg2,reg3);
MATH_IMPL(MATH_ADD,reg3,reg3);
MATH_IMPL(MATH_ADD,reg3,reg4);

/* Substract. */

MATH_IMPL(MATH_SUB,reg1,reg2,reg3);

/* Multiply. */

MATH_IMPL(MATH_MUL,reg1,reg2);
MATH_IMPL(MATH_MUL,reg1,reg3);
MATH_IMPL(MATH_MUL,reg2,reg3);
MATH_IMPL(MATH_MUL,reg3,reg4);

/* Divide. */

MATH_IMPL(MATH_DIV,reg1,reg2,reg3,reg4);

/* Power. */

MATH_IMPL(MATH_POW,reg1,reg3,reg4);
MATH_IMPL(MATH_POW,reg2,reg3,reg4);

/* Square root. */

MATH_IMPL(MATH_SQRT,reg1);
MATH_IMPL(MATH_SQRT,reg2);
MATH_IMPL(MATH_SQRT,reg3);
