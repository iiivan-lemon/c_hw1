#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "from_one_to_three.h"


int main() {
    int m = 2;
    int a[2][4] = {{1, 2, 3, 4},
                   {5, 6, 7, 8}};
    int **pa = (int **) a;
    int ***res = from_one_to_three(pa, 2, 4);
    int *col = columns(4);
    if (col == NULL) {
        return 1;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < col[i]; ++k) {
                printf("%d ", res[i][j][k]);
            }
            printf("\n");
        }
    }

    free_res(res, 2);
    free(col);
    return 0;
}
