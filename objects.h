#include <stdio.h>
#include <stdlib.h>

#define EMPTY ' '
#define POINT 'x'

typedef struct Grid {
    int x_min;
    int x_max;
    int x_range;
    
    int y_min;
    int y_max;
    int y_range;
    
    char **array;
} Grid;


typedef struct Point {
    int x;
    int y;
} Point;

typedef struct Line {
    double slope;
    int b;
} Line;

typedef struct Polynomial {
    int degree;  // number of coefficients
    double *coef;  // polynomial coefficients in order from x_0 -> x_n
} Polynomial;
