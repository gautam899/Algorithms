#include <iostream>
#include <vector>
#include <climits>
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
    bool isValidBST(TreeNode *root)
    {
        // The prev implementation was a overkill. Just perform a inorder traversal and keep track of the prev node.
        std::stack<TreeNode *> st;
        TreeNode *prev = nullptr; // Prev node in the inorder traversal
        TreeNode *curr = root;
        while (curr || !st.empty())
        {
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if (prev && curr->val <= prev->val)
                return false;
            prev = curr;
            curr = curr->right;
        }
        return true;
        // Time Complexity: O(N) Visiting each node once.
    }
};

int main()
{
    return 0;
}