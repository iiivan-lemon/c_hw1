#include <malloc.h>
#include <math.h>
#include <stdio.h>

#include "prog.h"

#define ACCURACY 0.01

res_coef *linear_regress(double *a, const size_t size) {
    if (size < 2) {
        return NULL;
    }

    double Sx = 0;
    double Sy = 0;
    double Sxx = 0;
    double Sxy = 0;
    for (size_t i = 0; i < size; ++i) {
        Sx += i;
        Sy += a[i];
        Sxy += i * a[i];
        Sxx += i * i;
    }

    res_coef *res = (res_coef *) malloc(sizeof(res_coef));
    if (res == NULL) {
        return NULL;
    }
    res->k = (Sxy * size - Sx * Sy) / (Sxx * size - Sx * Sx);
    res->b = (Sy - res->k * Sx) / size;
    res->b = round(res->b / ACCURACY) * ACCURACY;
    return res;
}

