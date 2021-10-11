#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
#include "from_one_to_three.h"
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main() {
    int m = 0;
    int n = 0;
    printf("enter num of rows and columns: \n");
    if (scanf("%d%d", &m, &n) == -1) {
        exit(1);
    }
    int a[m][n];
    printf("enter values for a[%d][%d]\n", m, n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (scanf("%d", &a[i][j]) == -1) {
                exit(1);
            }
        }
    }
    printf("\n");
    int **pa = (int **) a;
    int ***res = from_one_to_three(pa, m, n);
    int *col = amount_columns(n);
    if (col == NULL) {
        return(EXIT_FAILURE);
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < col[i]; ++k) {
                printf("%d ", res[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    free_res(res, 2);
    free(col);
    return(EXIT_SUCCESS);
}
