#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "from_one_to_three.h"


int main() {
    int m = 1;
    int a[1][1] = {{1}};
    int **pa = (int **) a;
    int ***res = from_one_to_three(pa, 1, 1);
    int *col = columns(1);
    if (col == NULL) {
        return 1;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < col[i]; ++k) {
                printf("%d ", res[i][j][k]);
            }
        }
        printf("\n");
    }
    if (free_res(res, m) == -1) {
        return -1;
    }
    free(col);


    return 0;
}
