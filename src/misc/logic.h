/*
 * logic.h by nieltg, Daniel
 */

#pragma once

/* Bit manipulation. */

#define LOGIC_AND(a,b) \
    ((a) ? ((b) ? 1 : 0) : 0)

#define LOGIC_OR(a,b) \
    ((a) ? 1 : ((b) ? 1 : 0))

#define LOGIC_XOR(a,b) \
    LOGIC_AND(!LOGIC_AND(a,b),LOGIC_OR(b,a))

/* Byte manipulation. */

#define _LOGIC_APPLY_UNIT_STMT(rega,regb_const,i,call_stmt) \
    (rega).bit##i = call_stmt((rega).bit##i,(regb_const).bit##i)

#define _LOGIC_APPLY_STMT(rega,regb_const,call_stmt) \
    _LOGIC_APPLY_UNIT_STMT(rega,regb_const,1,call_stmt); \
    _LOGIC_APPLY_UNIT_STMT(rega,regb_const,2,call_stmt); \
    _LOGIC_APPLY_UNIT_STMT(rega,regb_const,3,call_stmt); \
    _LOGIC_APPLY_UNIT_STMT(rega,regb_const,4,call_stmt); \
    _LOGIC_APPLY_UNIT_STMT(rega,regb_const,5,call_stmt); \
    _LOGIC_APPLY_UNIT_STMT(rega,regb_const,6,call_stmt); \
    _LOGIC_APPLY_UNIT_STMT(rega,regb_const,7,call_stmt); \
    _LOGIC_APPLY_UNIT_STMT(rega,regb_const,8,call_stmt)

#define LOGIC_XOR_STMT(rega,regb_const) \
    _LOGIC_APPLY_STMT(rega,regb_const,LOGIC_XOR)
