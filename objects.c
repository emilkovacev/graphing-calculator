#include <math.h>
#include <stdarg.h>
#include "objects.h"

// create a point structure with coordinates (x, y)
Point new_point(int x, int y);

// initialize a point pt on Grid g
int init_pt(struct Point pt, Grid g);

// check that a point address is within bounds
int check_point(Point p, Grid g);

// create a new Line with equation x0 + slope * x1
Line new_line(double slope, int x0);

// initialize a Line on Grid g)
int init_line(Line l, Grid g);

Polynomial new_poly(int degree, double *coef);

int init_poly(Polynomial p, Grid g);

Grid new_grid(int x_min, int x_max, int y_min, int y_max);

// render the initialized grid
void render(Grid grid);


Point new_point(int x, int y) {
    Point pt;
    pt.x = x;
    pt.y = y;
    return pt;
}

int init_pt(struct Point pt, Grid g) {
    if (check_point(pt, g) != 0) return -1;
    int x = pt.x - g.x_min;
    int y = pt.y - g.y_min;
    g.array[y][x] = POINT;
    return 0;
}

int check_point(Point p, Grid g) {
    if ((p.x >= g.x_min && p.x < g.x_max) &&
        (p.y >= g.y_min && p.y < g.y_max)) {
        return 0;
    } else {
        return -1;
    }
}

Line new_line(double slope, int b) {
    Line l;
    l.slope = slope;
    l.b = b;
    return l;
}

int init_line(Line l, Grid g) {
    for (int x = g.x_min; x < g.x_max; x++) {
        int y = (l.slope * x) + l.b;
        if (y >= g.y_max) continue;
        Point pt = new_point(x, y);
        init_pt(pt, g);
    }
    return 0;
}

Polynomial new_poly(int degree, double *coef) {
    Polynomial p;
    p.degree = degree;
    p.coef = coef;
    return p;
}

Polynomial new_poly_args(int degree, ...) {
    Polynomial p;
    p.degree = degree;
    va_list valist;
    va_start(valist, degree);

    printf("degree: %i\n", degree);
    p.coef = malloc(degree * sizeof(double));
    for (int i = 0; i < degree; i++) {
        p.coef[i] = va_arg(valist, double);
        printf("coef[%i] = %lf\n", i, p.coef[i]);
    }
    return p;
}

int calc_poly(double x, Polynomial p) {
    printf("%lf", x);
    int total = 0;
    
    for (int i = 0; i < p.degree; i++) {
        double c = i;
        total += pow(x, c) * p.coef[i];
    }
    return total;
}

int init_poly(Polynomial p, Grid g) {
    for (int x = g.x_min; x < g.x_max; x++) {
        int y = calc_poly(x, p);
        printf("(%i, %i)\n", x, y);
        if (y >= g.y_min && y < g.y_max) {
            Point pt = new_point(x, y);
            init_pt(pt, g);
        }
    }
    return 0;
    
}


Grid new_grid(int x_min, int x_max, int y_min, int y_max) {
    Grid g;
    g.x_min = x_min;
    g.x_max = x_max;
    g.x_range = x_max - x_min;
    
    g.y_min = y_min;
    g.y_max = y_max;
    g.y_range = y_max - y_min;


    g.array = malloc(g.y_range*sizeof(void *));

    for (int y = 0; y < g.y_range; y++) {
        g.array[y] = malloc(g.x_range*sizeof(char));
    }
    
    for (int y = 0; y < g.y_range; y++) {
        for (int x = 0; x < g.x_range; x++) {
            g.array[y][x] = EMPTY;
        }
    }
    return g;
}

void render(Grid g) {
    for (int i = g.y_range - 1; i >= 0; i--) {
        for (int j = 0; j < g.x_range; j++) {
            if (i == 0 || i == g.y_range - 1 ||
                j == 0 || j == g.x_range - 1) {
                printf("+");
            } else {
                printf("%c", g.array[i][j]);
            }
        }
        printf("\n");
    }
}
