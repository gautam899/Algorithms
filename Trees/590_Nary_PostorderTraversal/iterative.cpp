#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
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
    std::vector<int> postorder(TreeNode *root)
    {
        if (!root)
            return {};
        std::vector<int> ans;
        std::stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            for (TreeNode *it : root->children)
            {
                st.push(it);
            }
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};