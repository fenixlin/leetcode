// Brute force, O(n)

#include <gtest/gtest.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL) return q==NULL;
        if (q==NULL) return p==NULL;
        return (isSameTree(p->left, q->left) && 
                isSameTree(p->right, q->right) &&
                p->val == q->val);
    }
};

TEST(case1, test1) {
    Solution sol;
    TreeNode* x;
    TreeNode* y;
    x = new TreeNode(1);
    y = new TreeNode(1);
    y->left = new TreeNode(2);
    EXPECT_EQ(false, sol.isSameTree(x, y));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
