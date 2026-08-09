#include <vector>
#include <limits.h>
#include <algorithm>
class Solution
{
public:
    int superEggDrop(int k, int n)
    {
        // What's DP[i][j] here?
        // whith i eggs and j floors remaining, what is minimum number of moves to figure our the threshold floor.
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n + 1, 0));

        // Base cases
        for (int i = 1; i <= n; i++)
        {
            dp[1][i] = i;
        }

        // If we are on 0 floor remaining, 0 attempt. If we have 1 floor remaining, 1 attempt
        for (int i = 1; i <= k; i++)
        {
            dp[i][1] = 1;
        }

        for (int eggs = 2; eggs <= k; eggs++)
        {
            for (int floors = 2; floors <= n; floors++)
            {
                int ans = INT_MAX;
                for (int tf = 1; tf <= floors; tf++)
                {
                    int not_break = dp[eggs][floors - tf]; // If the eggs does not break, the remaining floor to check will floors - tf
                    int egg_break = dp[eggs - 1][tf - 1];  // If the egg break, remaining floors will be tf-1
                    ans = std::min(ans, 1 + std::max(not_break, egg_break));
                }
                dp[eggs][floors] = ans;
            }
        }
        return dp[k][n];
    }
};