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
        /*
            The brute force approach is to perform inorder traversal in two passes and store the
            order in a vector. And then sort the vector.
            Once done we perform the inorder traversal again and match the values of the node with the
            respective index in the vector. If the value does not match, swap the values
            T.C: O(N).
            S.C: O(N)
        */
        std::stack<TreeNode *> st;
        std::vector<int> v;
        TreeNode *curr = root;
        // First pass
        while (curr || !st.empty())
        {
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            v.push_back(curr->val);
            curr = curr->right;
        }

        // Second Pass
        std::sort(v.begin(), v.end());
        int index = 0;
        curr = root;
        st = std::stack<TreeNode *>();
        while (curr || !st.empty())
        {
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if (curr->val != v[index])
            {
                curr->val = v[index];
            }
            index++;
            curr = curr->right;
        }
    }
};

int main()
{
    return 0;
}