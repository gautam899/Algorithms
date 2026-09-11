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
    TreeNode *dfs(TreeNode *root)
    {
        // Base Case. If the root is nullptr or does not have a leftptr
        if (!root || !root->left)
        {
            return root;
        }
        TreeNode *new_root = dfs(root->left);

        root->left->right = root;
        root->left->left = root->right;

        // Break the old parent child relation to avoid cycle
        root->left = nullptr;
        root->right = nullptr;

        return new_root;
    }
    TreeNode *binaryTreeUpsideDown(TreeNode *root)
    {
        return dfs(root);
    }
    // T.C: O(N).
    // S.C: O(1).
};

int main()
{
    Solution sol;
    return 0;
}