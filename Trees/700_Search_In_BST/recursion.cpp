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
    void helper(TreeNode *root, int val, TreeNode *&ans)
    {
        if (!root)
            return;
        if (root->val == val)
        {
            ans = root;
            return;
        }
        if (val > root->val)
        {
            helper(root->right, val, ans);
        }
        else
        {
            helper(root->left, val, ans);
        }
    }
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *ans = nullptr;
        helper(root, val, ans);
        return ans;
    }
};