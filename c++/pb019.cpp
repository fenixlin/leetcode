// Brute force, O(n)

#include <vector>
#include <gtest/gtest.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prophet = head;
        ListNode* cur = head;
        ListNode* pre = NULL;
        for (int i=1; i<n; i++) {
            prophet = prophet->next;
        }
        while (prophet->next != NULL) {
            prophet = prophet->next;
            pre = cur;
            cur = cur->next;
        }
        if (pre!=NULL) pre->next = cur->next;
            else head = cur->next;
        delete(cur);
        return head;
    }
};

TEST(case1, test1) {
    Solution sol;
    ListNode* h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    h->next->next->next =  new ListNode(4);
    h->next->next->next->next = new ListNode(5);
    EXPECT_EQ(5, sol.removeNthFromEnd(h,2)->next->next->next->val);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
