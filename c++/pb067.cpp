// Brute force, O(n)

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length();
        int j = b.length();
        string result = i>j ? a : b;
        int k = result.length();
        char carry = '0';
        while (--i>=0 && --j>=0) {
            result[--k] = a[i] ^ b[j] ^ carry;
            carry = (a[i] & b[j]) | ((a[i] | b[j]) & carry);
        }
        if (carry&1) {
            while (--k>=0 && result[k]&1) result[k]='0';
            if (k<0) result = "1"+result;
                else result[k] = '1';
        }
        return result;
    }
};

TEST(case1, test1) {
    Solution sol;
    EXPECT_EQ("11", sol.addBinary("10","1"));
    EXPECT_EQ("10000", sol.addBinary("1","1111"));
    EXPECT_EQ("110001", sol.addBinary("101111","10"));
    EXPECT_EQ("100000001011110101", sol.addBinary("1010110001101110","10101011010000111"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
