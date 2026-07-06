#include <vector>

class Solution
{
public:
    int change(int amount, std::vector<int> &coins)
    {
        int n = coins.size();
        std::vector<std::vector<unsigned long long>> dp(coins.size() + 1,
                                                        std::vector<unsigned long long>(amount + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1; // If the amount is zero, there is always 1 way
        }

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int a = 1; a <= amount; a++)
            {
                unsigned long long np = dp[idx + 1][a];
                unsigned long long p = 0;
                if (coins[idx] <= a)
                {
                    p = dp[idx][a - coins[idx]];
                }
                dp[idx][a] = np + p;
            }
        }

        return dp[0][amount];
    }
};