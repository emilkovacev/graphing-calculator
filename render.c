#include <stdio.h>
#include <stdlib.h>

#include "objects.c"

#define EMPTY ' '
#define POINT 'x'


int main(int argc, char *argv[]) {
    Grid g = new_grid(0, 10, 0, 10);
    
    /* init_line(3, 0, grid); */
    /* init_line(-0.03, 12, grid); */
    render(g);
    return 0;
}


