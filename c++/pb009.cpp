// Brute force, O(n)

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int i = 1000000000;
        int j = 1;
        if (x==0) return true;
        if (x<0) return false;
        while (x/i==0) i/=10;
        while (i>j) {
            if (x/i%10 != x/j%10) return false;
            i/=10;
            j*=10;
        }
        return true;
    }
};

TEST(case1, test1) {
    Solution sol;
    EXPECT_EQ(false, sol.isPalindrome(123));
    EXPECT_EQ(true, sol.isPalindrome(121));
    EXPECT_EQ(false, sol.isPalindrome(00100));
    EXPECT_EQ(true, sol.isPalindrome(0));
    EXPECT_EQ(true, sol.isPalindrome(5)); 
    EXPECT_EQ(true, sol.isPalindrome(8998));
    EXPECT_EQ(false, sol.isPalindrome(-121));
    EXPECT_EQ(false, sol.isPalindrome(-2134554312));
    EXPECT_EQ(false, sol.isPalindrome(0x80000000));    
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
