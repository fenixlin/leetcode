// Brute force, O(n)

#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        size_t tail = s.find_last_not_of(" \t\n");
        if (tail==string::npos) return 0;
        size_t head = s.find_last_of(" \t\n",tail);
        if (tail==string::npos) head = 0;
        return static_cast<int>(tail-head);
    }
};

TEST(case1, test1) {
    Solution sol;
    EXPECT_EQ(9, sol.lengthOfLastWord("Valar Morghulis"));
    EXPECT_EQ(3, sol.lengthOfLastWord(" Quick Brown Fox \t\n "));
    EXPECT_EQ(5, sol.lengthOfLastWord("Yummy"));
    EXPECT_EQ(0, sol.lengthOfLastWord(""));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
