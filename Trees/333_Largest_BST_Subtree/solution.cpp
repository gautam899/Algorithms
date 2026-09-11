#include <iostream>
#include <climits>
#include <vector>
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
    int ans = INT_MIN;
    std::vector<int> helper(TreeNode *root)
    {
        if (!root)
            return {INT_MAX, INT_MIN, 0}; // Return something which is true for the BST condition.

        std::vector<int> left = helper(root->left);
        std::vector<int> right = helper(root->right);

        int size = 0;
        if (root->val > left[1] && root->val < right[0])
        {
            // Valid BST
            size = 1 + left[2] + right[2];
            ans = std::max(ans, size);
        }
        else
        {
            return {INT_MIN, INT_MAX, 0}; // Invalid BST. Return something which will be false for all nodes.
        }

        // Update the minimum and the maximum.
        return {std::min(left[0], root->val), std::max(right[1], root->val), size};
    }
    int largestBst(TreeNode *root)
    {
        // code here
        helper(root);
        return ans;
    }
};