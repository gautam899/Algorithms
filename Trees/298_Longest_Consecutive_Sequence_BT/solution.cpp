#include <iostream>

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
    int dfs(TreeNode *root, int &ans)
    {
        if (!root)
            return 0;

        int leftLen = dfs(root->left, ans) + 1;
        int rightLen = dfs(root->right, ans) + 1;

        if (root->left && root->left->val - root->val != 1)
        {
            leftLen = 1; // Reset the left length to 1.
        }
        if (root->right && root->right->val - root->val != 1)
        {
            rightLen = 1; // Reset the right length to 1
        }

        int currMaxLen = std::max(rightLen, leftLen);

        ans = std::max(ans, currMaxLen);
        return ans;
    }
    int longConsecutiveSequence(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};