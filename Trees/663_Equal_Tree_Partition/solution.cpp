#include <iostream>
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

class Codec
{
public:
    int dfs(TreeNode *root, std::unordered_map<int, int> &mp)
    {
        if (!root)
            return 0;

        int leftSum = dfs(root->left, mp);
        int rightSum = dfs(root->right, mp);

        int sum = root->val + leftSum + rightSum;
        mp[sum]++; // Keep store of all the subtree sum.
        return sum;
    }
    bool equalTreePartition(TreeNode *root)
    {
        if (!root)
            return false;
        std::unordered_map<int, int> mp;
        int total_sum = dfs(root, mp);
        if (total_sum % 2 == 0 && mp.find(total_sum / 2) != mp.end())
        {
            return true;
        }
        return false;
    }
};
