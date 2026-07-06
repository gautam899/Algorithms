#include <vector>
#include <algorithm>
#include <limits.h>
#include <iostream>

/*
    dp[ind][W] depends upon solve(ind+1, W) and solve(ind, W-wt[ind])
    i.e larger value of index and smaller value of W
*/
class Solution
{
public:
    int knapsack(int W, std::vector<int> &val, std::vector<int> &wt)
    {
        int n = val.size();
        std::vector<std::vector<int>> dp(val.size() + 1, std::vector<int>(W + 1, 0));

        // What is dp[i][j]. Starting at index i, with knapsack capacity j, what is max value achieved.
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = W; j >= 0; j--)
            {
                int not_pick = 0 + dp[i + 1][j];
                int pick = INT_MIN;
                if (wt[i] <= j)
                {
                    pick = val[i] + dp[i + 1][j - wt[i]];
                }
                dp[i][j] = std::max(pick, not_pick);
            }
        }
        return dp[0][W];
    }
};

int main()
{
    int W = 4;
    std::vector<int> val = {1, 2, 3};
    std::vector<int> wt = {4, 5, 1};
    Solution sol;
    int ans = sol.knapsack(W, val, wt);
    std::cout << ans << std::endl;
    return 0;
}