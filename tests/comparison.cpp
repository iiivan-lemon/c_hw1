#include <gtest/gtest.h>

#define STRESS_ITERATION_NUMBER 5

TEST(Comparision1, Results) {
    FILE *f_consistent = fopen("consistent_res.txt", "r");
    FILE *f_parallel = fopen("parallel_res.txt", "r");

    if (f_parallel == nullptr && f_consistent == nullptr) {
        ASSERT_FALSE(f_parallel == nullptr && f_consistent == nullptr);
    } else if (f_consistent == nullptr) {
        fclose(f_parallel);
        ASSERT_FALSE(f_consistent == nullptr);
    } else if (f_parallel == nullptr) {
        fclose(f_consistent);
        ASSERT_FALSE(f_parallel == nullptr);
    } else {
        double res_consistent_k = 0;
        double res_consistent_b = 0;
        double res_parallel_k = 0;
        double res_parallel_b = 0;
        for (int i = 0; i < 3; ++i) {
            if (fscanf(f_consistent, "%lf %lf", &res_consistent_k, &res_consistent_b) != 2) {
                fclose(f_consistent);
            }
            if (fscanf(f_parallel, "%lf %lf", &res_parallel_k, &res_parallel_b) != 2) {
                fclose(f_parallel);
            }
            EXPECT_EQ(res_consistent_k, res_parallel_k);
            EXPECT_EQ(res_consistent_b, res_parallel_b);
        }

        fclose(f_parallel);
        fclose(f_consistent);
    }
}

TEST(Comparision2, Time) {
    FILE *f_consistent = fopen("consistent_time.txt", "r");
    FILE *f_parallel = fopen("parallel_time.txt", "r");
    if (f_parallel == nullptr && f_consistent == nullptr) {
        ASSERT_FALSE(f_parallel == nullptr && f_consistent == nullptr);
    } else if (f_consistent == nullptr) {
        fclose(f_parallel);
        ASSERT_FALSE(f_consistent == nullptr);
    } else if (f_parallel == nullptr) {
        fclose(f_consistent);
        ASSERT_FALSE(f_parallel == nullptr);
    } else {
        double time_consistent = 0;
        double time_parallel = 0;

        EXPECT_EQ(fscanf(f_consistent, "%lf", &time_consistent), 1);
        printf("Consistent: %lf\n", time_consistent);

        EXPECT_EQ(fscanf(f_parallel, "%lf", &time_parallel), 1);
        printf("Parallel: %lf\n", time_parallel);


        fclose(f_parallel);
        fclose(f_consistent);
    }
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
