#include <gtest/gtest.h>
#include <cstring>

extern "C" {
#include "from_one_to_three.h"
}




TEST(NOT_NULL_TEST, Assert_1) {
    int a[1][10] = {{5, 6, 7, 8, 9, 5, 6, 7, 8, 9}};
    int **pa = (int **) a;
    int ***res = from_one_to_three(pa, 1, 10);
    EXPECT_FALSE(res == nullptr);
    EXPECT_FALSE(pa == nullptr);
    free_res(res, 1);
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
                EXPECT_EQ(test[i][j][k], res[i][j][k]);
            }
        }
    }
    free_res(res, 2);
    free(col);
}

TEST(BAD_VALUE, Assert_3) {
    int a[1][1] = {{1}};
    int **pa = (int **) a;
    int ***res = from_one_to_three(pa, 1, 1);
    EXPECT_TRUE(res == nullptr);
}

TEST(NULL_TEST, Assert_4) {
    int a[] = {5, 6, 7, 8, 9, 5, 6, 7, 8, 9};
    int **pa = (int **) a;
    EXPECT_TRUE(from_one_to_three(pa, 10, 0) == nullptr);
}


