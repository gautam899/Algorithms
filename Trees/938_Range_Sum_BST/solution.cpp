#include <iostream>
#include <limits.h>
#include <queue>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode()
    {
        val = 0;
    }

    TreeNode(int _val)
    {
        val = _val;
    }

    TreeNode(int _val, TreeNode *_left, TreeNode *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution
{
public:
    int helper(TreeNode *root, int low, int high)
    {
        if (!root)
            return 0;
        if (root->val < low)
        {
            return helper(root->right, low, high);
        }
        if (root->val > high)
        {
            return helper(root->left, low, high);
        }
        return root->val + helper(root->left, low, high) +
               helper(root->right, low, high);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        return helper(root, low, high);
    }
};

int main()
{
    Solution sol;
    // TODO: Create a BST and call the function root, low and high.
    return 0;
}