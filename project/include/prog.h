#ifndef PROJECT_INCLUDE_PROG_H_
#define PROJECT_INCLUDE_PROG_H_

#include <stdio.h>

struct res_coefficients {
    double k;
    double b;
};
typedef struct res_coefficients res_coef;

res_coef *linear_regress(double *, const size_t);


#endif     //   PROJECT_INCLUDE_PROG_H_
