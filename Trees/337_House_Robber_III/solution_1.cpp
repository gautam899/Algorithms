#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
    int helper(TreeNode *root, bool canPick, std::unordered_map<TreeNode *, std::vector<int>> &dp)
    {
        if (!root)
            return 0;

        if (dp.find(root) != dp.end() && dp[root][canPick] != -1)
        {
            return dp[root][canPick];
        }
        else
        {
            dp[root] = std::vector<int>(2, -1);
        }
        int pick = 0;
        int not_pick = 0;
        // If we can't pick this
        if (!canPick)
        {
            not_pick = helper(root->left, !canPick, dp) + helper(root->right, !canPick, dp);
        }
        else
        {
            // If we are allowed to pick the current node, we can either pick or not_pick
            pick = root->val + helper(root->left, !canPick, dp) + helper(root->right, !canPick, dp);
            not_pick = helper(root->left, canPick, dp) + helper(root->right, canPick, dp);
        }
        return dp[root][canPick] = std::max(pick, not_pick);
    }
    int rob(TreeNode *root)
    {
        bool canPick = true;

        /*
            To memoize this, we can think of it as, "With this node, what is the max amount that can be stolen
            without picking or with picking this node."
        */
        std::unordered_map<TreeNode *, std::vector<int>> dp;
        dp[root] = std::vector<int>(2, -1);
        return helper(root, canPick, dp);
    }
};