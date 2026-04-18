#include <algorithm>
#include <iostream>
#include <limits.h>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode *left, TreeNode *right)
        : val(val), left(left), right(right) {};
};
class Solution
{
public:
    int ans = INT_MIN;
    int helper(TreeNode *root)
    {
        if (!root)
            return 0;
        int left_sum = helper(root->left);
        int right_sum = helper(root->right);

        // Update the answer with the max of sum of root->val and the left and right sum
        ans = std::max(ans, root->val + left_sum + right_sum);

        // We never return a negative sum. If the root->val + max(left_sum, right_sum) < 0, we return zero instead.
        return (root->val + std::max(left_sum, right_sum)) < 0 ? 0 : (root->val + std::max(left_sum, right_sum));
    }
    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;
        helper(root);
        return ans;
    }
};

int main()
{
    TreeNode *node1 = new TreeNode(15);
    TreeNode *node2 = new TreeNode(7);
    TreeNode *node3 = new TreeNode(9);
    TreeNode *node4 = new TreeNode(20, node1, node2);
    TreeNode *node5 = new TreeNode(-10, node3, node4);
    Solution sol;

    int ans = sol.maxPathSum(node5);
    std::cout << ans << "\n";
    return 0;
}