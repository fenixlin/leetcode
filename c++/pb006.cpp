// Brute force, O(n), easy (deal 4 chars every time)

#include <string>
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;

        string answer = "";
        int k = numRows+numRows-2;
        for (int i = 0; i < numRows; i++) {
            int j = i;
            int len = s.length();
            bool flag = i>0 && i!=(k>>1);
            while (j < len) {
                answer.push_back(s[j]);
                if (flag && j+k-i-i<len) answer.push_back(s[j+k-i-i]);
                j += k;
            }
        }
        return answer;
    }
};

TEST(case1, test1) {
    Solution sol;
    EXPECT_EQ("PAHNAPLSIIGYIR",sol.convert("PAYPALISHIRING",3));
    EXPECT_EQ("PAYPALISHIRING",sol.convert("PAYPALISHIRING",1));
    EXPECT_EQ("PAYPLA",sol.convert("PAYPAL",5));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
