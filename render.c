#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "font8x8_basic.h"

#define ROW_COUNT 8
#define COL_COUNT 8

void usage(char *exec) {
    printf("Usage: %s <char_code>\n", exec);
    printf("       <char_code> Decimal character code between 0 and 127\n");
}

void render(char *bitmap, int ord) {
    int x,y;
    int set;
    int mask;

    printf("    (");
    if(isprint(ord)) {
    	printf(" -- '%c'", ord);
    }
    printf("\n");

    for (x=0; x < ROW_COUNT; x++) {
        printf("      (");
        for (y=0; y < COL_COUNT; y++) {
            set = bitmap[x] & 1 << y;
            printf("%s", set ? "'1'" : "'0'");
            if (y < COL_COUNT - 1) {
                printf(", ");
            }
        }
        if (x < ROW_COUNT - 1) {
            printf("),\n");
        } else {
            printf(")\n");
        }
    }
    printf("    )");
}

int main(int argc, char **argv) {

    printf("-- Auto generated file.\n"
	"-- See https://github.com/jonasjj/font8x8-vhdl-package\n\n"
	"library ieee;\n"
        "use ieee.std_logic_1164.all;\n\n"
	"library dot_matrix;\n"
	"use dot_matrix.types.all;\n\n"
        "package charmap is\n"
	"  constant charmap : charmap_type := (\n");
  
    int ord;
    for (ord = 0; ord < 128; ord++) {
        char *bitmap = font8x8_basic[ord];
	render(bitmap, ord);
	if (ord < 128 -1) {
	     printf(",\n");
	} else {
	     printf("\n");
	}
    }
    
    printf("  );\n");
    printf("end package;\n");

    return 0;
}
