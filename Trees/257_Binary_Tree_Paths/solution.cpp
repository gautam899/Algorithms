#include <iostream>
#include <vector>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void helper(TreeNode *root, std::string &s, std::vector<std::string> &paths)
    {
        if (!root)
        {
            return;
        }
        int len = s.size();
        s += std::to_string(root->val);
        if (!root->left && !root->right)
        {
            paths.push_back(s);
            s.resize(len); // Backtrack
            return;
        }
        else
        {
            s += "->";
        }

        helper(root->left, s, paths);
        helper(root->right, s, paths);
        s.resize(len);
    }
    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        std::vector<std::string> paths;
        std::string p = "";
        helper(root, p, paths);
        return paths;
    }
};

int main()
{
    Solution sol;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    std::vector<std::string> ans = sol.binaryTreePaths(node1);
    return 0;
}