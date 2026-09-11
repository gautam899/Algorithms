#include <iostream>
#include <vector>
#include <climits>
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
    bool ans = true;
    // {minium in the current tree, max in the current tree}
    std::vector<long long> helper(TreeNode *root)
    {
        if (!root)
            return {LLONG_MAX, LLONG_MIN};                  // Return something that always comes out
                                                            // to be true for the parent node.
        std::vector<long long> left = helper(root->left);   // left->{leftMax, rightMin}
        std::vector<long long> right = helper(root->right); // right -> {leftMax, rightMin}

        // root's value must be greater than left's max and lesser than right's
        // min.
        if (root->val > left[1] && root->val < right[0])
        {
        }
        else
        {
            ans = false;
        }
        // Update the minimum and the max in the current subtree
        return {std::min(left[0], (long long)root->val), std::max(right[1], (long long)root->val)};
    }
    bool isValidBST(TreeNode *root)
    {
        helper(root);
        return ans;
    }
};

int main()
{
    return 0;
}