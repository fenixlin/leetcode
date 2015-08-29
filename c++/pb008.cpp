// Brute force, O(n)

#include <string>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int sign = 1;
        int ans = 0;
        string::iterator i = str.begin();
       
        while (*i==' ' && i!=str.end()) i++;
        if (*i=='-') { sign = -1; i++; }
            else if (*i=='+') i++;
        for (; i!=str.end(); i++) {
            if (*i<'0' || *i>'9') return (-sign)*ans;
            if (ans<-214748364) return (sign>>1) ^ 0x7fffffff;
            if (ans==-214748364 && (sign>0 && *i>'7' || sign<0 && *i>'8')) return (sign>>1) ^ 0x7fffffff;
            ans = ans*10 - (*i-'0');
        }
        return (-sign)*ans;
    }
};

TEST(case1, test1) {
    Solution sol;
    EXPECT_EQ(123, sol.myAtoi("123"));
    EXPECT_EQ(-123, sol.myAtoi("-123"));
    EXPECT_EQ(2147483647, sol.myAtoi("2234236469"));
    EXPECT_EQ(10, sol.myAtoi("0000000000000000000000010"));
    EXPECT_EQ(123, sol.myAtoi("+000123"));
    EXPECT_EQ(-1, sol.myAtoi("-1abc"));
    EXPECT_EQ(-1, sol.myAtoi("-1.0000"));
    EXPECT_EQ(-2147483648, sol.myAtoi("-2147483648"));
    EXPECT_EQ(-2147483648, sol.myAtoi("-2147483649"));
    EXPECT_EQ(2147483646, sol.myAtoi("2147483646"));
    EXPECT_EQ(2147483647, sol.myAtoi("2147483648"));
    EXPECT_EQ(0, sol.myAtoi("-0"));
    
    EXPECT_EQ(0, sol.myAtoi("           "));
    EXPECT_EQ(1, sol.myAtoi("           01 0"));
    EXPECT_EQ(10, sol.myAtoi("           010"));
    EXPECT_EQ(-12, sol.myAtoi("      -0012a10"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
