#include <vector>
#include <algorithm>
class Solution
{
public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        int n = coins.size();
        std::vector<std::vector<int>> dp(n + 1,
                                         std::vector<int>(amount + 1, 0));

        // base case. If we are past the last index and still have some amount left, we do not want this
        // combination. Since we are only considering min, make it max.
        for (int a = 1; a <= amount; a++)
        {
            dp[n][a] = amount + 1;
        }

        // We rely on larger index and smaller amount in dp, so opposite in tabulation
        // dp[ind][x]. Starting from index ind with x amount with us, what is the minimum number of coins that we can pick to make up the amount.
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int x = 1; x <= amount; x++)
            {
                int not_pick = 0 + dp[ind + 1][x];

                int pick = 1e9;
                if (x >= coins[ind])
                {
                    pick = 1 + dp[ind][x - coins[ind]];
                }
                dp[ind][x] = std::min(not_pick, pick);
            }
        }
        return (dp[0][amount] > amount) ? -1 : dp[0][amount];
    }
};