#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int bit3 : 1;
    unsigned int bit4 : 1;
    unsigned int bit5 : 1;
    unsigned int bit6 : 1;
    unsigned int bit7 : 1;
    unsigned int bit8 : 1;
} reg;

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
