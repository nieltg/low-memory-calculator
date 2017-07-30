/*
 * math.h by nieltg, Daniel
 */

#pragma once

#define MATH_IMPL(decl_name,...) \
    void decl_name(__VA_ARGS__) { \
        decl_name##_STMT(__VA_ARGS__); \
    }

#define _MATH_DEFINE1_DECL(decl_name,...) \
    void decl_name(reg1,##__VA_ARGS__); \
    void decl_name(reg2,##__VA_ARGS__); \
    void decl_name(reg3,##__VA_ARGS__); \
    void decl_name(reg4,##__VA_ARGS__)

#define _MATH_DEFINE2_DECL(decl_name,...) \
    _MATH_DEFINE1_DECL(decl_name,reg1,##__VA_ARGS__); \
    _MATH_DEFINE1_DECL(decl_name,reg2,##__VA_ARGS__); \
    _MATH_DEFINE1_DECL(decl_name,reg3,##__VA_ARGS__); \
    _MATH_DEFINE1_DECL(decl_name,reg4,##__VA_ARGS__)

#define _MATH_DEFINE3_DECL(decl_name,...) \
    _MATH_DEFINE2_DECL(decl_name,reg1,##__VA_ARGS__); \
    _MATH_DEFINE2_DECL(decl_name,reg2,##__VA_ARGS__); \
    _MATH_DEFINE2_DECL(decl_name,reg3,##__VA_ARGS__); \
    _MATH_DEFINE2_DECL(decl_name,reg4,##__VA_ARGS__)

/* Add. */

#define MATH_ADD(rega,regb) \
    math_add_##rega##_##regb ()

_MATH_DEFINE2_DECL(MATH_ADD);

/* Substract. */

#define MATH_SUB(rega,regb,regt1) \
    math_sub_##rega##_##regb##_##regt1 ()

_MATH_DEFINE3_DECL(MATH_SUB);

/* Multiply. */

#define MATH_MUL(rega,regb) \
    math_mul_##rega##_##regb ()

_MATH_DEFINE2_DECL(MATH_MUL);

/* Power. */

#define MATH_POW(rega,regb,regt1) \
    math_pow_##rega##_##regb##_##regt1 ()

_MATH_DEFINE3_DECL(MATH_POW);

/* Square root. */

#define MATH_SQRT(rega) \
    math_sqrt_##rega ()

_MATH_DEFINE1_DECL(MATH_SQRT);
