#include <stddef.h>
#include <malloc.h>
#include "from_one_to_three.h"

int *columns(int n) {
    int *a;
    a = (int *) malloc(3 * sizeof(int));
    if (a == NULL) {
        return NULL;
    }

    if (n % 3 == 0) {
        a[0] = a[1] = a[2] = n / 3;
    } else if (n % 3 == 1) {
        a[0] = a[1] = (n - 1) / 3;
        a[2] = a[0] + 1;

    } else {
        a[0] = a[2] = (n + 1) / 3;
        a[1] = a[2] - 1;
    }
    if (!a[0] || !a[1] || !a[2]) {
        return NULL;
    }

    return  a;
}

void free_res(int ***res, int *col, int m) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < m; ++j)
            free(res[i][j]);
    }
    for (int i = 0; i < 3; ++i) {
        free(res[i]);
    }
    free(res);
    free(col);
}


int ***from_one_to_three(int **a, int m, int n) {
    if (a == NULL || m < 1 || n < 1) {
        return NULL;
    }

    int *pa = (int *) a;
    int ***res;
    res = (int ***) malloc(3 * sizeof(int **));
    if (res == NULL) {
        return NULL;
    }

    int* col = columns(n);
    if (col == NULL) {
        free(res);
        return NULL;
    }

    for (int i = 0; i < 3; ++i) {
        res[i] = (int **) malloc(m * sizeof(int *));
        if (res[i] == NULL) {
            free(res);
            free(col);
            return NULL;
        }
        for (int j = 0; j < m; ++j) {
            res[i][j] = (int *) malloc(col[i] * sizeof(int));
            if (res[i][j] == NULL) {
                free(res);
                free(col);
                return NULL;
            }
        }
    }


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j % 3 == 1) {
                res[0][i][j / 3] = pa[i * n + j];
            } else if (j % 3 == 2) {
                res[1][i][j / 3] = pa[i * n + j];
            } else {
                res[2][i][j / 3] = pa[i * n + j];
            }
        }
    }
    free(col);
    return res;
}
