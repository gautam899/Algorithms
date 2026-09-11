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
    void helper(TreeNode *root, long long &ans, int mini)
    {
        if (!root)
            return;
        if (root->val > mini)
        {
            ans = std::min(ans, (long long)root->val);
        }

        helper(root->left, ans, mini);
        helper(root->right, ans, mini);
    }
    int findSecondMinimumValue(TreeNode *root)
    {
        // Because of the fact mentioned in the problem statement that for every non-leaf node with 2 child, the root is the min of the two child. This make the root node global minimum. The goal is to find the smallest number just greater than the root node.
        long long ans = LLONG_MAX;
        int mini = root->val;
        helper(root, ans, mini);
        return (ans == LLONG_MAX) ? -1 : ans;
    }
};