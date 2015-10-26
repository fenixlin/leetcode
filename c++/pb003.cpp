// Problem 3 Longest Substring Without Repeating Characters
// stl:map, easy, O(n)

#include <map>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> last;
        int start = 0, ans = 0, i = 0;
        for (char ch : s) {
            if (last.find(ch) != last.end()) {
                if (i-start>ans) ans = i-start;
                if (last[ch]+1>start) start = last[ch]+1;
            }
            last[ch] = i;
            i++;
        }
        if (i-start>ans) ans = i-start;
        return ans;
    }
};

TEST(case1, test1) {
    Solution sol;
    EXPECT_EQ(2, sol.lengthOfLongestSubstring("abba"));
    EXPECT_EQ(3, sol.lengthOfLongestSubstring("abbca"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
