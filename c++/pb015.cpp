// Brute force, O(n^2), somewhat ugly though
// Tried adding elements into "small" one by one, but middle element is hard to choose reasonably(e.g. middle one of 3) without repeatance.
// Optimization could be done on searching order

#include <set>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        set<int> small(nums.begin(), nums.end());
        map<int, stack<int>> twoSums;
        set<int> unique; 
        for (int i = 0; i<nums.size(); i++) {
            if ((i==0 || nums[i]!=nums[i-1]) && (i==nums.size()-1 || nums[i]!=nums[i+1]))
                unique.insert(nums[i]);
        }        
        for (int i = 1; i+1<nums.size(); i++) {
            if (i>1 && nums[i]==nums[i-1]) continue;
            for (int j = i+1; j<nums.size(); j++) {
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                if (nums[i]==0 && nums[j]==0) continue;
                twoSums[nums[i]+nums[j]].push(nums[i]);
            }
        }
        for (int i = 1; i+1<nums.size(); i++) 
            if (nums[i-1]==0 && nums[i+1]==0) {
                ans.push_back(vector<int>()={0,0,0});
                break;
            }

        for (int i: small) {
            if (i>0) break;
            while (!twoSums[-i].empty()) {
                int mid = twoSums[-i].top();
                if (mid > i) ans.push_back(vector<int>() = {i, mid ,-i-mid});
                else if (mid == i && unique.find(mid)==unique.end()) ans.push_back(vector<int>() = {i, mid ,-i-mid});
                else break;
                twoSums[-i].pop();
            }
        }
        return ans;
    }
};

TEST(case1, test1) {
    Solution sol;
    vector<vector<int>> v;
    v = {{-1,0,1},{-1,-1,2}};
    EXPECT_EQ(v, sol.threeSum(vector<int>()={-1,0,1,2,-1,-4}));
    v = {{-1,0,1},{-1,-1,2}};
    EXPECT_EQ(v, sol.threeSum(vector<int>()={-1,0,1,2,-1}));
    v = {};
    EXPECT_EQ(v, sol.threeSum(vector<int>()={-1,0,2}));
    v = {};
    EXPECT_EQ(v, sol.threeSum(vector<int>()={}));
    v = {};
    EXPECT_EQ(v, sol.threeSum(vector<int>()={0,0}));
    v = {{0,0,0}};
    EXPECT_EQ(v, sol.threeSum(vector<int>()={0,0,0}));
    v = {{-2,0,2},{-2,1,1}};
    EXPECT_EQ(v, sol.threeSum(vector<int>()={-2,0,1,1,2}));
    v = {{-1,0,1}};
    EXPECT_EQ(v, sol.threeSum(vector<int>()={-1,0,1,0}));
    v = {};
    EXPECT_EQ(v, sol.threeSum(vector<int>()={-1,0,0}));
    //v = {};
    //EXPECT_EQ(v, sol.threeSum(vector<int>()={7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6}));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
