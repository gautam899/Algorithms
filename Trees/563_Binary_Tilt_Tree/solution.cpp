#include <iostream>
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
    int helper(TreeNode *root, int &ans)
    {
        if (!root)
            return 0;

        int left_sum = helper(root->left, ans);
        int right_sum = helper(root->right, ans);
        ans += std::abs(left_sum - right_sum);
        return root->val + left_sum + right_sum;
    }

    int findTilt(TreeNode *root)
    {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
    // T.C: The time complexity of this approach is O(N) since we are visit all the nodes
};

int main()
{
    return 0;
}