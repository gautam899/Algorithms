#include <vector>
#include <iostream>

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
    bool helper(TreeNode *root, int target)
    {
        // If leaf node.
        if (!root->left && !root->right)
        {
            return target == root->val;
        }
        bool l = root->left ? helper(root->left, target - root->val) : false;
        bool r = root->right ? helper(root->right, target - root->val) : false;
        return l || r;
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        return helper(root, targetSum);
    }
    // T.C: In worst Case i.e a skewed Tree, the time complexity is O(N).
};

int main()
{
}