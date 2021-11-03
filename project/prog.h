#ifndef PROJECT_PROG_H_
#define PROJECT_PROG_H_

#include <stdio.h>

struct res_coefficients {
    double k;
    double b;
};
typedef struct res_coefficients res_coef;

res_coef *linear_regress(double *, const int);


#endif     //   PROJECT_PROG_H_
