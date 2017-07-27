/*
 * logic.h by nieltg, Daniel
 */

#pragma once

#define LOGIC_AND(a,b) \
    ((a) ? ((b) ? 1 : 0) : 0)

#define LOGIC_OR(a,b) \
    ((a) ? 1 : ((b) ? 1 : 0))

#define LOGIC_XOR(a,b) \
    LOGIC_AND(!LOGIC_AND(a,b),LOGIC_OR(b,a))
