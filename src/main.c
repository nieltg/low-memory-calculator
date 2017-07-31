#include <stdio.h>
#include <stdlib.h>

#include "main.h"
#include "misc/util.h"
#include "parse/expr.h"

reg reg1;
reg reg2;
reg reg3;
reg reg4;

int main (int argc, char* argv[]) {
    
    FILE *file = fopen ("data.txt", "r");
    char c;

    if (file == NULL) {
        printf ("File not found!\n");
        exit (1);
    }

    EXPR_EVAL_STMT(file,c,reg1,reg2,reg3,reg4);
    printf("%u\n", UTIL_CAST_UINT(reg1));
    
    return 0;
}
