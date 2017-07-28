#include <stdio.h>
#include <stdlib.h>

#include "main.h"

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

    while ((c = fgetc (file)) != EOF) {
    }
    
    return 0;
}
