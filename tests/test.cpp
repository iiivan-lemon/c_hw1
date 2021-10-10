#include <gtest/gtest.h>
#include <cstring>

extern "C" {
#include "from_one_to_three.h"
}

#define SUCCESS_CODE 0


TEST(NOT_NULL_TEST, Assert_1) {
    int a[1][10] = {{5, 6, 7, 8, 9, 5, 6, 7, 8, 9}};
    int **pa = (int **) a;
    EXPECT_FALSE(from_one_to_three(pa, 1, 10) == nullptr);
    EXPECT_FALSE(pa == nullptr);

}

TEST(VALUE_CHECK, Assert_2) {
    int test[3][2][2] = {{{1, 4}, {7, 10}},
                         {{2, 5}, {8, 11}},
                         {{0, 3}, {6, 9}}};
    int a[2][6] = {{0, 1, 2, 3, 4,  5},
                   {6, 7, 8, 9, 10, 11}};
    int **pa;
    pa = (int **) a;
    int *col;
    int ***res = from_one_to_three(pa, 2, 6);
    col = columns(6);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < col[i]; ++k) {
                EXPECT_EQ(test[i][j][k] , res[i][j][k]);
            }

        }
    }
    free_res(res, col, 2);


}

TEST(BAD_VALUE, Assert_3) {
    int a[1][1] = {{1}};
    int** pa = (int **) a;
    int *col;
    col = columns(1);
    EXPECT_TRUE(from_one_to_three(pa, 1, 1) == nullptr);
    EXPECT_TRUE(col == nullptr);
}

TEST(NULL_TEST, Assert_4) {
    int a[] = {5, 6, 7, 8, 9, 5, 6, 7, 8, 9};
    int **pa = (int **) a;
    EXPECT_TRUE(from_one_to_three(pa, 10, 0) == nullptr);

}


