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
    void dfs(TreeNode *root, std::vector<int> &ans)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            ans.push_back(root->val);
        }
        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        std::vector<int> ans1;
        std::vector<int> ans2;
        dfs(root1, ans1);
        dfs(root2, ans2);
        return ans1 == ans2;
        // T.C: O(N+M).
    }
};