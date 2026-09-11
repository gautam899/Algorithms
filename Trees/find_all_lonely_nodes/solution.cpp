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
    void dfs(TreeNode *root, std::vector<int> &ans)
    {
        if (!root || root->left == root->right)
        {
            return;
        }

        if (!root->left && root->right)
        {
            ans.push_back(root->right->val);
        }

        if (root->left && !root->right)
        {
            ans.push_back(root->left->val);
        }
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
    std::vector<int> lonelyChild(TreeNode *root)
    {
        std::vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};

int main()
{
    return 0;
}