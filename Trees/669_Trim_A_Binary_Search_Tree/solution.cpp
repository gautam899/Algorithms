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
    TreeNode *dfs(TreeNode *root, int low, int high)
    {
        if (!root)
            return nullptr;

        if (root->val < low)
        {
            // Discard the node and it's left subtree and recurse into it's
            // right subtree
            return dfs(root->right, low, high);
        }
        else if (root->val > high)
        {
            // Discard the node and it's right subtree and recurse into it's
            // right subtree
            return dfs(root->left, low, high);
        }
        else
        {
            // If the root->val within the range, recurse in both left and right
            // subtree
            root->left = dfs(root->left, low, high);
            root->right = dfs(root->right, low, high);
        }
        return root;
    }
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        root = dfs(root, low, high);
        return root;
    }
    // Time Complexity: O(N).
    // Space Complexity: O(H).
};