// Problem 2 Add Two Numbers
// Brute force, O(n), easy

#include <cstddef>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *now = NULL, *prev = NULL, *head = NULL;
        int carry = 0;
        while (l1!=NULL || l2!=NULL || carry!=0) {
            now = new ListNode(carry);
            if (l1!=NULL) {
                now->val += l1->val;
                l1 = l1->next;
            }
            if (l2!=NULL) {
                now->val += l2->val;
                l2 = l2->next;
            }
            if (now->val>9) {
                carry = 1;
                now->val %= 10;
            }
            else carry = 0;
            if (prev!=NULL) prev->next = now;
                else head = now;
            prev = now;            
        }
        return head;
    }
};

TEST(case1, test1) {
    Solution sol;
    ListNode* h1 = new ListNode(2);
    h1->next = new ListNode(4);
    h1->next->next = new ListNode(3);
    ListNode* h2 = new ListNode(5);
    h2->next =  new ListNode(6);
    h2->next->next = new ListNode(4);
    EXPECT_EQ(8, sol.addTwoNumbers(h1,h2)->next->next->val);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
