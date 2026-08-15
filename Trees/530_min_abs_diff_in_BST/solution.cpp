#include <iostream>
#include <vector>

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

/*
    The idea is to traverse the tree in a inorder fashion that will allow us find the minimum difference
    between two node values. This is because when traversing the tree in a sorted fashion, the minimum difference will be between
    adjacent node values.
*/
class Solution
{
public:
    void helper(TreeNode *root, int &diff, TreeNode *&prev)
    {
        if (!root)
            return;

        helper(root->left, diff, prev);
        if (prev != nullptr)
            diff = std::min(diff, std::abs(root->val - prev->val));
        prev = root;
        helper(root->right, diff, prev);
    }
    int getMinimumDifference(TreeNode *root)
    {
        int diff = 1e9;
        TreeNode *prev = nullptr;
        helper(root, diff, prev);
        return diff;
    }
};

int main()
{
    Solution sol;
    TreeNode *node1 = new TreeNode(236);
    TreeNode *node2 = new TreeNode(104);
    TreeNode *node3 = new TreeNode(227);
    TreeNode *node4 = new TreeNode(701);
    TreeNode *node5 = new TreeNode(911);
    node2->right = node3;
    node1->left = node2;
    node1->right = node4;
    node4->right = node5;
    TreeNode *root = node1;
    int val = sol.getMinimumDifference(root);
    std::cout << val << std::endl;
    return 0;
}