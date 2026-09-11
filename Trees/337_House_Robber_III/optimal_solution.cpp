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
    std::pair<int, int> helper(TreeNode *root)
    {
        if (!root)
            return {0, 0};

        std::pair<int, int> left = helper(root->left);
        std::pair<int, int> right = helper(root->right);

        // What is max the thief can steal if he decide to pick the current
        // node. NOTE: If the thief pick the curr node, he cannot pick the child
        // nodes.
        int robCurr = root->val + left.second + right.second;

        // What is max the thief can steal if he decide to skip the current
        // node. NOTE: If the thief decides to skip the curr node, the maximum
        // amount that can be stolen would be the max of pick/not_pick from left
        // and max of pick/not_pick from the right.
        int notRobCurr = std::max(left.first, left.second) +
                         std::max(right.first, right.second);

        return {robCurr, notRobCurr};
    }
    int rob(TreeNode *root)
    {
        /*
            The intution is to return two values for each node.
            1. First: What is the maxmium amount that can be stolen if the thief decides to rob this node.
            2. Second: What is the maxmium amount that can be stolen if the thief decides to not rob this node.

            If the thief decides to rob the current node, it cannot rob the immediate left and right child nodes.
        */
        std::pair<int, int> ans = helper(root);
        return std::max(ans.first, ans.second);
    }
};