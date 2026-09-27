#include <iostream>
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
    /*
        The intution is to return a pair [incr, decr] for every node.
        1. incr represents the max length of increasing consecutive sequence ending at the current node.
        2. decr represents the max length of decreasing consecutive sequence ending at the current node.
    */
    int ans = -1;
    std::pair<int, int> dfs(TreeNode *root)
    {
        if (root == nullptr)
            return {0, 0};

        int incr = 1;
        int decr = 1;
        const auto [i1, d1] = dfs(root->left);
        const auto [i2, d2] = dfs(root->right);

        // Left child. If it exist
        if (root->left != nullptr)
        {
            if (root->left->val + 1 == root->val)
            {
                incr = i1 + 1; // Add 1 to the max dec length of the left child. Extra 1 for the current node
            }

            if (root->left->val - 1 == root->val)
            {
                decr = d1 + 1; // Add 1 to max dec length of left child. Extra 1 for the current node
            }
        }

        if (root->right != nullptr)
        {
            if (root->right->val + 1 == root->val)
            {
                incr = std::max(incr, i2 + 1); // Why do we take max? In case both children can make increasing paths.
            }

            if (root->right->val - 1 == root->val)
            {
                decr = std::max(decr, d2 + 1);
            }
        }

        ans = std::max(ans, incr + decr - 1); // -1 here because the root node appears in both the paths. We wish to only consider it once.
        return {incr, decr};
    }
    int longestConsecutiveSequenceII(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        dfs(root);
        return ans;
    }
};

int main()
{
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(3);
    TreeNode *node3 = new TreeNode(2, node1, node2);

    TreeNode *root = node3;
    Solution sol;
    int ans = sol.longestConsecutiveSequenceII(root);
    std::cout << ans << std::endl;
    return 0;

    // Time complexity: O(N)
    // Space Complexity: O(1), auxiliary space complexity O(N)
}