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
    bool helper(TreeNode *root, TreeNode *prev)
    {
        if (!root)
            return true;
        if (root->val != prev->val)
            return false;
        return helper(root->left, root) && helper(root->right, root);
    }
    bool isUnivalTree(TreeNode *root)
    {
        return helper(root, root);
    }
};

int main()
{
    Solution sol;
    // TODO: Create a BST and call the function isUnival
    return 0;
}