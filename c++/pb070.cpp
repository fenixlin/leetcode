// Brute force, O(n)

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int x[2] = {1 ,1};
        int flag = n & 1;
        while (n-- > 1) {
            flag ^= 1;
            x[flag] = x[flag] + x[flag^1];
        }
        return x[flag];
    }
};

TEST(case1, test1) {
    Solution sol;
    EXPECT_EQ(1, sol.climbStairs(0));
    EXPECT_EQ(1, sol.climbStairs(1));
    EXPECT_EQ(2, sol.climbStairs(2));
    EXPECT_EQ(3, sol.climbStairs(3));
    EXPECT_EQ(5, sol.climbStairs(4));
    EXPECT_EQ(8, sol.climbStairs(5));
    EXPECT_EQ(13, sol.climbStairs(6));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
