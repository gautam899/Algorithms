#include <iostream>
#include <algorithm>

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
    int dfs(TreeNode *root, int &res)
    {
        if (!root)
            return 0;

        int leftPath = dfs(root->left, res);
        int rightPath = dfs(root->right, res);

        int l = 0, r = 0;
        if (root->left && root->val == root->left->val)
        {
            l = leftPath + 1;
        }

        if (root->right && root->val == root->right->val)
        {
            r = rightPath + 1;
        }
        res = std::max(res, l + r);
        return std::max(l, r);
    }
    int longestUnivaluePath(TreeNode *root)
    {
        int res = 0;
        dfs(root, res);
        return res;
    }
};

int main()
{
    return 0;
}