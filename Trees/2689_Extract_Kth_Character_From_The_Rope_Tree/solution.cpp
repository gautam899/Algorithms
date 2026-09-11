#include <iostream>
#include <string>

class TreeNode
{
public:
    int len;
    std::string val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
    TreeNode(std::string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
    TreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : len(x), val(""), left(left), right(right) {}
};

class Solution
{
public:
    std::string dfs(TreeNode *root)
    {
        if (!root)
            return "";
        if (root->len == 0)
            return root->val;

        return dfs(root->left) + dfs(root->right);
    }
    char extractKth(TreeNode *root, int k)
    {
        std::string ans = dfs(root);
        return ans[k - 1];
    }
};

int main()
{
    return 0;
}