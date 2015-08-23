// Problem 2 Add Two Numbers
// Brute force, O(n), easy

#include <cstddef>
#include <iostream>
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

int main() {
    Solution sol;
    cout << sol.addTwoNumbers(new ListNode(0), new ListNode(0))->val << endl;
}
