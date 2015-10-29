// Brute force, O(nL)

#include <vector>
#include <cstdio>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<vector<int>> v = {{1},{}};
        int flag = 0;
        while (--n>0) {
            v[1-flag].clear();
            int last = v[flag][0];
            int count = 1;
            for (int i=1; i<v[flag].size(); i++) 
                if (v[flag][i]==last) count++;
                    else {
                        v[1-flag].push_back(count);
                        v[1-flag].push_back(last);
                        last = v[flag][i];
                        count = 1;
                    }
            v[1-flag].push_back(count);
            v[1-flag].push_back(last);
            flag = 1-flag;
        }
        string str = "";
        for (int x: v[flag])
            str.append(to_string(x));
        return str;
    }
};

TEST(case1, test1) {
    Solution sol;
    EXPECT_EQ("21", sol.countAndSay(3));
    EXPECT_EQ("1", sol.countAndSay(1));
    EXPECT_EQ("111221", sol.countAndSay(5));
    EXPECT_EQ("312211", sol.countAndSay(6));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
