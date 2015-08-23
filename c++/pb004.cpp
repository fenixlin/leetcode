// Problem 4 Median of Two Sorted Arrays
// Binary search(nested), O(log(m+n))
// HARD, takes me a day or more
// first find the smaller "median" with the help of binary search
// then find another one with carefulness

#include <iostream>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int r1 = nums1.size()-1;
        int l1 = 0;
        int r2 = nums2.size()-1;
        int l2 = 0;
        int limit = (nums1.size() + nums2.size() + 1)/2; //middle index, 2 for n=3, 4 for n=8
        int mid, tmp=0;
        while (l1<r1){
            mid = (l1+r1)/2;
            tmp = binarySearch(nums2, nums1[mid]);
            if (tmp+mid+1<limit) l1=mid+1;
            else r1=mid;
        }
        while (l2<r2){  
            mid = (l2+r2)/2;
            tmp = binarySearch(nums1, nums2[mid]);
            if (tmp+mid+1<limit) l2=mid+1;
            else r2=mid;
        }
        //in case the only number left hasn't been checked, get the median or the smaller "median" with a number >= it
        if (l1<=r1 && binarySearch(nums2, nums1[l1])+l1+1<limit) l1++;
        if (l2<=r2 && binarySearch(nums1, nums2[l2])+l2+1<limit) l2++;

        //distinguish which is median or smaller "median"
        if (l2>r2 || (l1<=r1 && nums1[l1]<=nums2[l2])) return postProcess(nums1, nums2, l1);
        else return postProcess(nums2, nums1, l2);
    }
private:
    double postProcess(vector<int>& host, vector<int>& guest, int x) {
        int limit = (host.size()+guest.size()+1)/2;
        if ((host.size()+guest.size())%2==0) {
            int y = binarySearch(guest, host[x]);
            //case of (bigger "median" == smaller "median")
            if (y+x+1>limit) return host[x];
            //case of (bigger "median" > smaller "median")
            if (y>=guest.size()) return (host[x]+host[x+1])*1./2;
            if (x+1>=host.size()) return (host[x]+guest[y])*1./2;
            return (host[x]+min(host[x+1], guest[y]))*1./2;
        }
        else return host[x]*1.;
    }
    // Search the rightmost place j where x_i<=x if i<j
    int binarySearch(vector<int>& nums, int x) {
        int l = 0, r = nums.size()-1, mid;
        while (l < r-1) {
            mid = (l+r)/2;
            if (nums[r]>x && nums[r-1]<=x) break;
            if (nums[mid]<=x) l = mid;
                else r = mid - 1;
        }
        if (nums.size()<=0) return 0;
        if (nums[r]<=x) return r+1;
            else if (nums[r-1]<=x) return r;
            else return r-1;
    }
};

TEST(case1, test1) {
    typedef vector<int> V;
    V v1,v2;
    Solution sol;
    v1 = V{1,2}, v2=V{3,4};
    EXPECT_EQ(2.5, sol.findMedianSortedArrays(v1, v2));
    v1 = V{}, v2=V{2,3};
    EXPECT_EQ(2.5, sol.findMedianSortedArrays(v1, v2));
    v1 = V{}, v2=V{1};
    EXPECT_EQ(1, sol.findMedianSortedArrays(v1, v2));
    v1 = V{1}, v2=V{2,3};
    EXPECT_EQ(2, sol.findMedianSortedArrays(v1, v2));
    v1 = V{1,2,3}, v2=V{1,2};
    EXPECT_EQ(2, sol.findMedianSortedArrays(v1, v2));
    v1 = V{1}, v2=V{1};
    EXPECT_EQ(1, sol.findMedianSortedArrays(v1, v2));
    v1 = V{}, v2=V{2,3,4,5};
    EXPECT_EQ(3.5, sol.findMedianSortedArrays(v1, v2));
    v1 = V{1,1,3,3}, v2=V{1,1,3,3};
    EXPECT_EQ(2, sol.findMedianSortedArrays(v1, v2));
    v1 = V{3,4,5}, v2=V{1,1,1,2,8};
    EXPECT_EQ(2.5, sol.findMedianSortedArrays(v1, v2));
    v1 = V{1,2,2}, v2=V{1,3,8};
    EXPECT_EQ(2, sol.findMedianSortedArrays(v1, v2));
    v1 = V{1,2,2}, v2=V{1,2,3};
    EXPECT_EQ(2, sol.findMedianSortedArrays(v1, v2));
    v1 = V{1,2}, v2=V{1,1};
    EXPECT_EQ(1, sol.findMedianSortedArrays(v1, v2));
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
