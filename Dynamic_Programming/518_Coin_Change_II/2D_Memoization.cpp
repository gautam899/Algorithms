#include <vector>
#include <iostream>

class Solution
{
public:
    int solve(int idx, int amount, std::vector<int> &coins, std::vector<std::vector<int>> &dp)
    {
        if (amount == 0)
            return 1;
        if (idx == coins.size() && amount != 0)
            return 0;

        if (dp[idx][amount] != -1)
        {
            return dp[idx][amount];
        }
        int not_pick = solve(idx + 1, amount, coins, dp);
        int pick = 0;
        if (coins[idx] <= amount)
        {
            pick = solve(idx, amount - coins[idx], coins, dp);
        }
        return dp[idx][amount] = pick + not_pick;
    }
    int change(int amount, std::vector<int> &coins)
    {
        std::vector<std::vector<int>> dp(coins.size() + 1, std::vector<int>(amount + 1, -1));
        return solve(0, amount, coins, dp);
    }
};

int main()
{
    Solution sol;
    int amount = 5;
    std::vector<int> change = {1, 2, 5};
    int ans = sol.change(amount, change);
    std::cout << ans << std::endl;
    return 0;
}