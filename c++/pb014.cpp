// Brute force, O(nm)

#include <vector>
#include <string>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size()==0) return "";
        int index = 0;
        bool cut = false;
        while (!cut) {
            char x;
            if (index<strs[0].length()) x=strs[0][index];
                else break;
            for (int i=1; i<strs.size(); i++)
                if (index>=strs[i].length() || strs[i][index] != x) {
                    cut = true;
                    break;
                }
            if (!cut) index++;
        }
        return strs[0].substr(0, index);
    }
};

TEST(case1, test1) {
    Solution sol;
    vector<string> strs;
    strs = {"abcbe","abcbw"};
    EXPECT_EQ("abcb", sol.longestCommonPrefix(strs));
    strs = {"abcbe","abcbw","abcccccccc","abcbws"};
    EXPECT_EQ("abc", sol.longestCommonPrefix(strs));
    strs = {"ya","yark","yawn","yaaaaa"};
    EXPECT_EQ("ya", sol.longestCommonPrefix(strs));
    strs = {"yawn","yarn","sawn","yown"};
    EXPECT_EQ("", sol.longestCommonPrefix(strs));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
