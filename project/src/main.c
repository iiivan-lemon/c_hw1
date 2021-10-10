#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "from_one_to_three.h"


int main() {
    int m =1 ;
    int a[3][3] = {{1},{2},{2}};
    int **pa = (int **) a;
    int *col;
    int ***res = from_one_to_three(pa, 5, 3);
    col = columns(3);
    if(col == NULL){
        return 1;
    }
    for(int i =0 ;i < 3 ; ++i){
        for(int j =0 ; j< m; ++j){
            for(int k =0; k < col[i];++k){
                printf("%d ", res[i][j][k]);
            }

        }
        printf("\n");

    }
    free_res(res,col,m);


    return 0;
}
