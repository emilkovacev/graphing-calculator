#include <stdio.h>
#include <stdlib.h>

#include "objects.c"

int main(int argc, char *argv[]) {
    Grid g = new_grid(-50, 50, -20, 20);

    Polynomial p1 = new_poly_args(4, 0.0, 0.0, 0.0, 0.05);
    init_poly(p1, g);

    Polynomial p2 = new_poly_args(4, 0.0, -3.0, 0.0, 0.01);
    init_poly(p2, g);

    render(g);
    return 0;
}

