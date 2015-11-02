// Brute force, O(n)

#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = (m--)+(n--)-1;
        while (n>=0) {
            nums1[idx--] = m>=0 && nums1[m]>nums2[n]? nums1[m--] : nums2[n--];
        }
    }
};

TEST(case1, test1) {
    Solution sol;
    typedef vector<int> V;
    V v1,v2,r;
    v1 = {1,2,4,0,0};
    v2 = {3,5};
    r = {1,2,3,4,5};
    sol.merge(v1,3,v2,2);
    EXPECT_EQ(r, v1);
    v1 = {0,0,3,0,0,0,0,0,0};
    v2 = {-1,1,1,1,2,3};
    r = {-1,0,0,1,1,1,2,3,3};
    sol.merge(v1,3,v2,6);
    EXPECT_EQ(r, v1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
