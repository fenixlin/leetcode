// Brute force, O(n)

#include <vector>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int result = 0;
        if (nums.size()>0) result++;
        for (vector<int>::iterator i=nums.begin()+1; i<nums.end(); i++) 
            if (*i!=*(i-1)) result++;
                else nums.erase(i--);
        return result;
    }
};

TEST(case1, test1) {
    typedef vector<int> V;
    V v;
    Solution sol;
    v = V{1,1,2};
    EXPECT_EQ(2, sol.removeDuplicates(v));
    v = V{1,2};
    EXPECT_EQ(2, sol.removeDuplicates(v));
    v = V{};
    EXPECT_EQ(0, sol.removeDuplicates(v));
    v = V{8};
    EXPECT_EQ(1, sol.removeDuplicates(v));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
