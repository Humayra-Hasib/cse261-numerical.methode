#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void define_problem(int *n, double *a_true, double *b_true) {
    *n = 15;
    *a_true = 2.0;
    *b_true = 0.3;
}

void show_linearisation_example(double a, double b) {
    double x_ex = 4.0;
    double y_ex = a * exp(b * x_ex);
    printf("(2) Linearisation example:\n");
    printf("    y = a*exp(bx). For x=%.1f, a=%.2f, b=%.2f => y=%.4f\n",
           x_ex, a, b, y_ex);
    printf("    ln(y) = ln(a) + b*x = %.4f + %.4f*%.1f = %.4f\n\n",
           log(a), b, x_ex, log(y_ex));
}
