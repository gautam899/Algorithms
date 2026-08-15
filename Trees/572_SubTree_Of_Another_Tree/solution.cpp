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
    bool isPart(TreeNode *root, TreeNode *subRoot)
    {
        if (!root || !subRoot)
            return root == subRoot;

        return (root->val == subRoot->val) &&
               isPart(root->left, subRoot->left) &&
               isPart(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (!root)
            return false;

        if (root->val == subRoot->val)
        {
            if (isPart(root, subRoot))
                return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};