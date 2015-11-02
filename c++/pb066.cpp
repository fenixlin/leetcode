// Brute force, O(n)

#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i=digits.size()-1; i>=0; i--){
            digits[i] = (digits[i]+1)%10;
            if (digits[i]>0) break;
        }
        if (digits[0]==0) digits.insert(digits.begin(), 1);
        return digits;
    }
};

TEST(case1, test1) {
    Solution sol;
    typedef vector<int> V;
    V v,r;
    v = V{1,2,3};
    r = V{1,2,4};
    EXPECT_EQ(r, sol.plusOne(v));
    v = V{9};
    r = V{1,0};
    EXPECT_EQ(r, sol.plusOne(v));
    v = V{0};
    r = V{1};
    EXPECT_EQ(r, sol.plusOne(v));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
