#include <vector>
#include <algorithm>
class Solution
{
public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        int n = coins.size();
        int MAX = amount + 1;
        std::vector<int> curr(amount + 1, MAX);
        std::vector<int> next(amount + 1, MAX);
        curr[0] = 0;
        next[0] = 0;

        // We rely on larger index and smaller amount in dp, so opposite in
        // tabulation dp[ind][x]. Starting from index ind with x amount with us,
        // what is the minimum number of coins that we can pick to make up the
        // amount.
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int x = 1; x <= amount; x++)
            {
                if (x >= coins[ind])
                    curr[x] = std::min(next[x], curr[x - coins[ind]] + 1);
            }
            next = curr;
        }
        return (curr[amount] > amount) ? -1 : curr[amount];
    }
};