#include <stdio.h>
#include <stdlib.h>

#include "objects.c"

int main(int argc, char *argv[]) {
    Grid g = new_grid(0, 100, 0, 100);

    double *coef = malloc(3*sizeof(double));
    coef[0] = 15.0; coef[1] = -10.0; coef[2] = 2.0;
    Polynomial p1 = new_poly(3, coef);
    
    init_poly(p1, g);

    render(g);
    return 0;
}
