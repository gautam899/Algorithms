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
    int findSecondMinimum(TreeNode *root)
    {
        long long ans = LLONG_MAX;
        int mini = root->val;
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            root = q.front();
            q.pop();
            if (root->val > mini)
            {
                ans = std::min(ans, (long long)root->val);
            }
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        return (ans == LLONG_MAX) ? -1 : ans;
    }
};