#include <iostream>
#include <vector>

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
    int helper(int n, std::vector<int> &dp)
    {
        if (dp[n] != -1)
            return dp[n];

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += (helper(i - 1, dp) * helper(n - i, dp));
        }
        return dp[n] = ans;
    }
    int numTrees(int n)
    {
        std::vector<int> dp(n + 1, -1);
        dp[0] = 1;
        dp[1] = 1;
        return helper(n, dp);
    }
};

int main()
{
    return 0;
}