// Brute force, O(n)

#include <stack>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        for (char ch : s) {
            switch (ch) {
                case '(':   st.push(1); break;
                case '[':   st.push(2); break;
                case '{':   st.push(3); break;
                case ')':   if (!st.empty() && st.top()==1) { st.pop(); break; }
                                else return false;
                case ']':   if (!st.empty() && st.top()==2) { st.pop(); break; }
                                else return false;
                case '}':   if (!st.empty() && st.top()==3) { st.pop(); break; }
                                else return false;
            }
        }
        return st.empty();
    }
private:
    stack<int> st;
};

TEST(case1, test1) {
    Solution sol;
    EXPECT_EQ(true, sol.isValid(string("")));
    EXPECT_EQ(true, sol.isValid(string("()[]")));
    EXPECT_EQ(true, sol.isValid(string("([{}])")));
    EXPECT_EQ(false, sol.isValid(string("(]{}[)")));
    EXPECT_EQ(false, sol.isValid(string("(")));
    EXPECT_EQ(false, sol.isValid(string("]")));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
