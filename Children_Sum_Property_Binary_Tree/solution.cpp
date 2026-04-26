#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {};
};

class Solution
{
public:
    bool helper(TreeNode *root)
    {
        if ((!root) || (!root->left && !root->right))
            return true;

        int sum = 0;
        if (root->left)
        {
            sum += root->left->val;
        }
        if (root->right)
        {
            sum += root->right->val;
        }

        return (root->val == sum) && helper(root->left) && helper(root->right);
    }
    bool isChildrenSumProperty(TreeNode *root)
    {
        return helper(root);
    }
};
int main()
{
    // TODO: Create a Binary Tree.
    return 0;
    // Time Complexity: Every node is visited once and a constant time operation is performed
    // on each node, hence the time complexity is O(N).
    // Space Complexity: Auxiliary stack space of O(H) where H is the height of the tree.
    // Worst Case: O(N) for skewed tree and best case O(LogN) for balanced tree.
}