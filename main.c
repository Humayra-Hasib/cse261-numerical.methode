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

/* (2) Perform regression calculation (also generates synthetic data) */
void perform_regression(double x[], double y[], int n,
                        double a_true, double b_true,
                        double *intercept, double *slope) {
    srand((unsigned int)time(NULL));
    double xmax = 5.0;
    for (int i = 0; i < n; ++i) {
        x[i] = (n == 1) ? 0.0 : (xmax * i) / (n - 1);
        double yi = a_true * exp(b_true * x[i]);
        double eps = ((double)rand() / RAND_MAX) * 0.10 - 0.05; // ~[-5%,+5%]
        yi *= (1.0 + eps);
        if (yi <= 0.0) yi = 1e-12;
        y[i] = yi;
    }

    double sx = 0.0, sy = 0.0, sxx = 0.0, sxy = 0.0;
    for (int i = 0; i < n; ++i) {
        double Xi = x[i];
        double Yi = log(y[i]);
        sx  += Xi;
        sy  += Yi;
        sxx += Xi * Xi;
        sxy += Xi * Yi;
    }
    double denom = n * sxx - sx * sx;
    if (fabs(denom) < 1e-12) {
        *slope = 0.0;
        *intercept = sy / n;
    } else {
        *slope = (n * sxy - sx * sy) / denom;
        *intercept = (sy - (*slope) * sx) / n;
    }
}

/* (3) Present estimated parameters */
void present_estimated_parameters(double intercept, double slope,
                                  double a_true, double b_true,
                                  double *a_hat, double *b_hat) {
    *a_hat = exp(intercept);
    *b_hat = slope;
    printf("True model:      y = %.6f * exp(%.6f * x)\n", a_true, b_true);
    printf("Estimated model: y = %.6f * exp(%.6f * x)\n\n", *a_hat, *b_hat);
}

/* (4) Validate results + show residuals (returns RMSE) */
double validate_results(double x[], double y[], int n,
                        double a_hat, double b_hat) {
    double ss = 0.0;
    printf(" i      x[i]         y[i]        fitted_y       residual\n");
    for (int i = 0; i < n; ++i) {
        double fitted = a_hat * exp(b_hat * x[i]);
        double resid  = y[i] - fitted;
        ss += resid * resid;
        printf("%2d   %10.6f   %10.6f   %10.6f   %10.6f\n",
               i, x[i], y[i], fitted, resid);
    }
    double rmse = sqrt(ss / n);
    printf("\nRMSE = %.6f\n\n", rmse);
    return rmse;
}

/* (5) Final conclusion */
void final_conclusion(double rmse) {
    printf("(6) Conclusion: ");
    if (rmse < 0.2) {
        printf("Excellent fit (very small residual error).\n");
    } else if (rmse < 0.5) {
        printf("Good fit; residuals are moderate.\n");
    } else {
        printf("Fit is weak; consider more data or a different model/noise assumption.\n");
    }
}

int

