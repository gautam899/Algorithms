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
    int ans = 0;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftMax = dfs(root->left);
        int rightMax = dfs(root->right);

        if (root->val >= leftMax && root->val >= rightMax)
        {
            ans++;
        }

        return std::max(root->val, std::max(leftMax, rightMax));
    }
    int countDominantNodes(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};
