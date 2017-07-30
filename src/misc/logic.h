/*
 * logic.h by nieltg, Daniel
 */

#pragma once

/* Bit manipulation. */

#define LOGIC_NOT(a) \
    !(a)

#define LOGIC_AND(a,b) \
    ((a) ? ((b) ? 1 : 0) : 0)

#define LOGIC_OR(a,b) \
    ((a) ? 1 : ((b) ? 1 : 0))

#define LOGIC_XOR(a,b) \
    LOGIC_AND(LOGIC_NOT(LOGIC_AND(a,b)),LOGIC_OR(b,a))

/* Byte manipulation. */

#define _LOGIC_APPLY_UNIT1_STMT(call_stmt,i,rega,...) \
    (rega).bit##i = call_stmt((rega).bit##i,##__VA_ARGS__)

#define _LOGIC_APPLY_UNIT2_STMT(call_stmt,i,rega,regb_const,...) \
    _LOGIC_APPLY_UNIT1_STMT(rega,i,call_stmt,(regb_const).bit##i,##__VA_ARGS__)

#define _LOGIC_APPLY_N_STMT(call_stmt,n,rega,...) \
    _LOGIC_APPLY_UNIT##n##_STMT(call_stmt,1,rega,##__VA_ARGS__); \
    _LOGIC_APPLY_UNIT##n##_STMT(call_stmt,2,rega,##__VA_ARGS__); \
    _LOGIC_APPLY_UNIT##n##_STMT(call_stmt,3,rega,##__VA_ARGS__); \
    _LOGIC_APPLY_UNIT##n##_STMT(call_stmt,4,rega,##__VA_ARGS__); \
    _LOGIC_APPLY_UNIT##n##_STMT(call_stmt,5,rega,##__VA_ARGS__); \
    _LOGIC_APPLY_UNIT##n##_STMT(call_stmt,6,rega,##__VA_ARGS__); \
    _LOGIC_APPLY_UNIT##n##_STMT(call_stmt,7,rega,##__VA_ARGS__); \
    _LOGIC_APPLY_UNIT##n##_STMT(call_stmt,8,rega,##__VA_ARGS__)

#define LOGIC_NOT_STMT(rega) \
    _LOGIC_APPLY_N_STMT(LOGIC_NOT,1,rega)

#define LOGIC_XOR_STMT(rega,regb_const) \
    _LOGIC_APPLY_N_STMT(LOGIC_XOR,2,rega,regb_const)
