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
    int xDepth = -1, yDepth = -2;
    TreeNode *xParent = nullptr, *yParent = nullptr;
    void dfs(TreeNode *root, TreeNode *parent, int x, int y, int depth)
    {
        if (!root)
            return;
        if (x == root->val)
        {
            xDepth = depth;
            xParent = parent;
        }
        else if (y == root->val)
        {
            yDepth = depth;
            yParent = parent;
        }
        else
        {
            dfs(root->left, root, x, y, depth + 1);
            dfs(root->right, root, x, y, depth + 1);
        }
    }
    bool isCousins(TreeNode *root, int x, int y)
    {
        dfs(root, nullptr, x, y, 0);
        return (xDepth == yDepth) && (xParent != yParent);
    }
};

int main()
{
    Solution sol;
    // TODO: Create a BST and call the function isUnival
    return 0;
}