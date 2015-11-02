// Brute force, O(n)

#include <gtest/gtest.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* tmp;
        while (cur != NULL) {
            while (cur->next != NULL && cur->next->val == cur->val) {
                tmp = cur->next;
                cur-> next = tmp->next;
                delete tmp;
            }
            cur = cur->next;
        }
        return head;
    }
};

TEST(case1, test1) {
    Solution sol;
    ListNode* h = new ListNode(3);
    h->next = new ListNode(3);
    h->next->next =  new ListNode(2);
    h->next->next->next = new ListNode(1);
    h->next->next->next->next = new ListNode(1);
    EXPECT_EQ(1, sol.deleteDuplicates(h)->next->next->val);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
