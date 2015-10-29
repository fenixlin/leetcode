// Brute force, O(n)

#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) { 
        int offset = 0;
        for (int i=0; i<nums.size(); i++)
            if (nums[i]==val) offset++;
                else nums[i-offset] = nums[i];
        return nums.size()-offset;
    }
};

TEST(case1, test1) {
    typedef vector<int> V;
    V v;
    Solution sol;
    v = V{1,1,3,2,3};
    EXPECT_EQ(3, sol.removeElement(v,3));
    v = V{1,2};
    EXPECT_EQ(2, sol.removeElement(v,3));
    v = V{};
    EXPECT_EQ(0, sol.removeElement(v,5));
    v = V{0,0,0,0,0};
    EXPECT_EQ(0, sol.removeElement(v,0));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
