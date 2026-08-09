#include <vector>
#include <limits.h>
#include <algorithm>
class Solution
{
public:
    int solve(int eggs, int floors, std::vector<std::vector<int>> &dp)
    {
        if (floors <= 1)
            return floors;

        if (eggs == 1)
            return floors;
        if (dp[eggs][floors] != -1)
            return dp[eggs][floors];

        int ans = INT_MAX;
        // Drop the egg from floor x, where 1 >= x >= floors
        for (int tf = 1; tf <= floors; tf++)
        {
            int not_break = solve(eggs, floors - tf, dp);
            int egg_break = solve(eggs - 1, tf - 1, dp);
            ans = std::min(ans, 1 + std::max(not_break, egg_break));
        }
        return dp[eggs][floors] = ans;
    }
    int superEggDrop(int k, int n)
    {
        // What's DP[i][j] here?
        // whith i eggs and j floors remaining, what is minimum number of moves to figure our the threshold floor.
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n + 1, -1));
        return solve(k, n, dp);
    }
};