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
    bool isSymmetric(TreeNode* root) {
        return (root == NULL || runSymmetric(root->left, root->right));
    }
    bool runSymmetric(TreeNode* x, TreeNode* y) {
        return (x==NULL? y==NULL : 
                y!=NULL &&
                x->val == y->val &&
                runSymmetric(x->left, y->right) &&
                runSymmetric(x->right, y->left));
    }
};

TEST(case1, test1) {
    Solution sol;
    TreeNode* y;
    y = new TreeNode(1);
    y->left = new TreeNode(2);
    EXPECT_EQ(false, sol.isSymmetric(y));
    y = new TreeNode(1);
    y->left = new TreeNode(2);
    y->right = new TreeNode(2);
    y->left->left = new TreeNode(3);
    y->left->right = new TreeNode(4);
    y->right->left = new TreeNode(4);
    y->right->right = new TreeNode(3);
    EXPECT_EQ(true, sol.isSymmetric(y));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
