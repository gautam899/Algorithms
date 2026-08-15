#include <vector>
#include <iostream>
#include <stack>

class TreeNode
{
public:
    int val;
    std::vector<TreeNode *> children;

    TreeNode() {}

    TreeNode(int _val)
    {
        val = _val;
    }

    TreeNode(int _val, std::vector<TreeNode *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    std::vector<int> preorder(TreeNode *root)
    {
        if (!root)
            return {};
        std::vector<int> ans;
        std::stack<TreeNode *> st;
        TreeNode *curr = root;
        st.push(curr);
        while (!st.empty())
        {
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            for (auto it = curr->children.rbegin(); it != curr->children.rend();
                 it++)
            {
                st.push(*it);
            }
        }
        return ans;
    }
};