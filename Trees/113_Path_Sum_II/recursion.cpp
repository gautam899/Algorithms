#include <iostream>
#include <vector>

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
    void dfs(TreeNode *root, std::vector<int> &path,
             std::vector<std::vector<int>> &ans, int targetSum)
    {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right)
        {
            if (targetSum == root->val)
            {
                ans.push_back(path);
            }
            // Do not return. This will lead to one missed pop_back
        }

        dfs(root->left, path, ans, targetSum - root->val);
        dfs(root->right, path, ans, targetSum - root->val);
        path.pop_back();
    }
    std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        std::vector<int> path;
        std::vector<std::vector<int>> ans;
        dfs(root, path, ans, targetSum);
        return ans;
    }
};