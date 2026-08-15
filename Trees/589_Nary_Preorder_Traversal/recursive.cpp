#include <vector>
#include <iostream>

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
    void helper(TreeNode *root, std::vector<int> &ans)
    {
        if (!root)
            return;

        ans.push_back(root->val);
        for (TreeNode *it : root->children)
        {
            helper(it, ans);
        }
    }
    std::vector<int> preorder(TreeNode *root)
    {
        if (!root)
            return {};
        std::vector<int> ans;
        helper(root, ans);
        return ans;
    }
};