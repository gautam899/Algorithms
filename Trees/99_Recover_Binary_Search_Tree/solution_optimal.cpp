#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
    void recoverBST(TreeNode *root)
    {
        TreeNode *prev = nullptr;
        TreeNode *curr = root;
        TreeNode *pred = nullptr;
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        while (curr)
        {
            if (curr->left)
            {
                pred = curr->left;
                // Find the inorder predecessor and link
                while (pred->right && pred->right != curr)
                {
                    pred = pred->right;
                }

                if (!pred->right)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    if (prev && prev->val > curr->val)
                    {
                        if (!first)
                            first = prev;
                        second = curr;
                    }
                    prev = curr;
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
            else
            {
                if (prev && prev->val > curr->val)
                {
                    if (!first)
                        first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            }
        }
        if (first && second)
        {
            std::swap(first->val, second->val);
        }
        return;
    }
};

int main()
{
    return 0;
}