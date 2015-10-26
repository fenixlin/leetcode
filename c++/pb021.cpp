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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newlist_tail = NULL;
        ListNode* newlist_head = NULL;
        ListNode* nextnode;
        while (l1!=NULL && l2!=NULL) {
            if (l1->val < l2->val) {
                nextnode = l1;
                l1 = l1->next;
            } else {
                nextnode = l2;
                l2 = l2->next;
            }
            if (newlist_tail!=NULL) {
                newlist_tail->next = nextnode;
                newlist_tail = nextnode;
            }
            else newlist_head = newlist_tail = nextnode;
        }
        if (l1!=NULL) nextnode = l1;
            else nextnode = l2;
        if (newlist_tail!=NULL) newlist_tail->next = nextnode;
            else newlist_head = nextnode;
        return newlist_head;
    }
};

TEST(case1, test1) {
    Solution sol;
    ListNode* h1 = new ListNode(1);
    h1->next = new ListNode(3);
    ListNode* h2 = new ListNode(2);
    h2->next =  new ListNode(4);
    h2->next->next = new ListNode(5);
    EXPECT_EQ(4, sol.mergeTwoLists(h1,h2)->next->next->next->val);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
