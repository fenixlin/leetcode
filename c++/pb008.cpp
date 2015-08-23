// Brute force, O(n)

class Solution {
public:
    int myAtoi(string str) {
                    
    }
};

TEST(case1, test1) {
    Solution sol;
    EXPECT_EQ(123, sol.myAtoi("123"));
    EXPECT_EQ(-123, sol.myAtoi("-123"));
    EXPECT_EQ(0, sol.myAtoi("2234236469"));
    EXPECT_EQ(10, sol.myAtoi("0000000000000000000000010"));
    EXPECT_EQ(123, sol.myAtoi("+000123"));
    EXPECT_EQ(0, sol.myAtoi("-1abc"));
    EXPECT_EQ(0, sol.myAtoi("-1.0000"));
    EXPECT_EQ(-2147483648, sol.myAtoi("-2147483648"));
    EXPECT_EQ(0, sol.myAtoi("-2147483649"));
    EXPECT_EQ(0, sol.myAtoi("-0"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
