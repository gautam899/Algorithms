#include <iostream>
#include <vector>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void helper(TreeNode *root, int &sum, int isLeft)
    {
        if (!root)
            return;

        if (!root->left && !root->right)
        {
            if (isLeft == 1)
                sum += root->val;
            return;
        }
        helper(root->left, sum, 1);
        helper(root->right, sum, 0);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        int isLeft = 0;
        helper(root, sum, isLeft);
        return sum;
    }
};

int main()
{
    Solution sol;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    int ans = sol.sumOfLeftLeaves(node1);
    return 0;
}