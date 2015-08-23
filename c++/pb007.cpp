// Brute force, O(n)

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x==0) return 0;
        int i = abs(x);
        int ans = 0;
        int split = 0;
        while (i>0) {
            if (ans>100000000)
            {
                split = ans/100000000; 
                ans %= 100000000;
            }
            ans = ans*10+i%10;
            i /= 10;
        }
        if (split>2 || (split==2 && ans>147483647)) return 0;
        return (split*1000000000+ans) * (x/abs(x)); 
    }
};

TEST(case1, test1) {
    Solution sol;
    EXPECT_EQ(321, sol.reverse(123));
    EXPECT_EQ(-321, sol.reverse(-123));
    EXPECT_EQ(0, sol.reverse(0));
    EXPECT_EQ(-0, sol.reverse(-0));
    EXPECT_EQ(-1, sol.reverse(-100));
    EXPECT_EQ(0, sol.reverse(1534236469));
    EXPECT_EQ(2147483641, sol.reverse(1463847412));
    EXPECT_EQ(-2143847412, sol.reverse(-2147483412));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
