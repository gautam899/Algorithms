#include <iostream>
#include <vector>
#include <stack>

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
    void preorder(TreeNode *root, std::stack<TreeNode *> &st)
    {
        if (!root)
            return;

        st.push(root);
        preorder(root->left, st);
        preorder(root->right, st);
    }
    void flatten(TreeNode *root)
    {
        // The first approach using extra space can be done using a stack. Store the pre-order in a stack and then re-arrange the nodes later.
        std::stack<TreeNode *> st;
        preorder(root, st);
        TreeNode *prev = nullptr;
        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();
            curr->right = prev;
            prev = curr;
            curr->left = nullptr;
        }
    }
    // T.C: O(N)
    // S.C: O(N)
};