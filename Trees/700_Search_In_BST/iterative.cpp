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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while (root)
        {
            if (val > root->val)
            {
                root = root->right;
            }
            else if (val < root->val)
            {
                root = root->left;
            }
            else
            {
                return root;
            }
        }
        return nullptr;
    }
};