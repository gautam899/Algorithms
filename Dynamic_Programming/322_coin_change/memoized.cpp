#include <vector>
#include <algorithm>
class Solution
{
public:
    int helper(int ind, std::vector<int> &coins, int amount, std::vector<std::vector<int>> &dp)
    {
        if (amount == 0)
            return 0; // No more coins to be picked if we have remaining amount is 0
        if (ind == coins.size())
            return 1e9; // If we have reached the last index and the remaining target is > 0. We do not want to consider this combination, return INT_MAX

        if (dp[ind][amount] != -1)
            return dp[ind][amount];
        int not_pick = 0 + helper(ind + 1, coins, amount, dp);

        int pick = 1e9;
        if (amount >= coins[ind])
        {
            pick = 1 + helper(ind, coins, amount - coins[ind], dp);
        }

        return dp[ind][amount] = std::min(not_pick, pick);
    }
    int coinChange(std::vector<int> &coins, int amount)
    {
        std::vector<std::vector<int>> dp(coins.size() + 1, std::vector<int>(amount + 1, -1));
        int ans = helper(0, coins, amount, dp);
        return (ans == 1e9) ? -1 : ans;
    }
};