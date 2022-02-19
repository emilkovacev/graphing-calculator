#include <stdio.h>
#include <stdlib.h>

#include "objects.c"

int main(int argc, char *argv[]) {
    Grid g = new_grid(-100, 100, -100, 100);

    Polynomial p1 = new_poly_args(3, 0.0, 0.0, 0.0, 0.05);
    init_poly(p1, g);

    Polynomial p2 = new_poly_args(1, 7.0, -0.5);
    init_poly(p2, g);

    render_pbm(g);
    return 0;
}

