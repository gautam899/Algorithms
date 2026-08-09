#include <vector>
#include <iostream>

/* Observing carefully:
    dp[idx + 1][a] belong to the next row
    dp[idx][a - coin[idx]] belongs to the curr row.
    This implies at a time we do not need more that two rows, curr and next
*/
class Solution
{
public:
    int change(int amount, std::vector<int> &coins)
    {
        int n = coins.size();
        std::vector<unsigned long long> curr(amount + 1, 0);
        std::vector<unsigned long long> next(amount + 1, 0);
        curr[0] = 1; // If the amount is zero, there is always 1 way
        next[0] = 1;

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int a = 1; a <= amount; a++)
            {
                unsigned long long np = next[a];
                unsigned long long p = 0;
                if (coins[idx] <= a)
                {
                    p = curr[a - coins[idx]];
                }
                curr[a] = np + p;
            }
            next = curr;
        }

        return curr[amount];
    }
    /*
        Time Complexity: O(N*Amount)
        Space Complexity: O(Amount)
    */
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