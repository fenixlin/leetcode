// Problem 1 Two Sum
// Double ended queue(deque) - O(nlogn)
// Good illustration of stl - pair & sort

#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> kv;
        for (int i=0; i<nums.size(); i++) {
            kv.push_back(make_pair(nums[i], i+1));
        }
        int i = 0;
        int j = kv.size()-1;
        sort(kv.begin(), kv.end(), 
                [](pair<int, int> x, pair<int, int> y) {
                    return x.first < y.first;
                });
        while (i<j && kv[i].first + kv[j].first != target) {
            while (kv[i].first + kv[j].first > target) j--;
            while (kv[i].first + kv[j].first < target) i++;
        }
        if (kv[i].second < kv[j].second)
            return vector<int>{kv[i].second, kv[j].second};
        else
            return vector<int>{kv[j].second, kv[i].second};
    }
};

TEST(case1, test1) {
    typedef vector<int> V;
    Solution sol;
    V v = V{-1,-2,-3,-4,-5};
    V r = sol.twoSum(v, -8);
    EXPECT_EQ(3,r[0]);
    EXPECT_EQ(5,r[1]);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
