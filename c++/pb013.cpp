// Brute force, O(n)

#include <map>
#include <string>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> val = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int ans = 0;
        int last = 0;

        for (char ch: s) {
            ans += val[ch];
            if (val[ch]>last) ans = ans-last-last;
            last = val[ch];
        }
        return ans;
    }
};

TEST(case1, test1) {
    Solution sol;
    EXPECT_EQ(1, sol.romanToInt("I"));
    EXPECT_EQ(3, sol.romanToInt("III"));
    EXPECT_EQ(19, sol.romanToInt("XIX"));
    EXPECT_EQ(499, sol.romanToInt("CDXCIX"));
    EXPECT_EQ(3999, sol.romanToInt("MMMCMXCIX"));
    EXPECT_EQ(3489, sol.romanToInt("MMMCDLXXXIX"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
