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
    std::pair<int, int> dfs(TreeNode *root)
    {
        if (!root)
            return {0, 0};

        // [dominiant nodes in left/right subtree, maximum node value in
        // left/right subtree]
        auto [l, max1] = dfs(root->left);
        auto [r, max2] = dfs(root->right);

        int res = l + r;
        int maxv = std::max({root->val, max1, max2});
        res = l + r + (root->val == maxv);
        return {res, maxv};
    }
    int countDominantNodes(TreeNode *root)
    {
        return dfs(root).first;
    }
};
