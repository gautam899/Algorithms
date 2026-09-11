#include <iostream>
#include <vector>
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
    int findHeight(TreeNode *root)
    {
        return !root ? -1 : findHeight(root->left) + findHeight(root->right);
    }
    int helper(TreeNode *root)
    {
        if (!root)
            return;
        int ans = 0;
        TreeNode *temp = root;
        int h = findHeight(temp);
        while (root)
        {
            temp = root->right;
            int rightH = findHeight(temp);
            if (rightH == h - 1)
            {
                /*
                    Left subtree is complete.
                    2^h-1  -> left subtree
                    1     -> root
                    Total = 2^h-1 + 1 = 2^h = (1<<h)
                */
                ans += 1 << h;
                root = root->right;
            }
            else
            {
                ans += 1 << h - 1; // Right subtree is complete
                root = root->left;
            }
        }
        return ans;
    }
    int countCompleteTreeNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        return helper(root);
    }
};