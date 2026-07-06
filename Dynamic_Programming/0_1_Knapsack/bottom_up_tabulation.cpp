#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int knapsack(int W, std::vector<int> &val, std::vector<int> &wt)
    {
        int n = val.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1));
        // dp[i][j] represents that, using the first i elements with the knapsack capacity of j, what is
        // the maximum value than can be achived.
        // Base cases if there are no elements i.e. i=0 or the knapsack has no capacity i.e. w = 0,
        // No value can be picked
        for (int i = 0; i <= n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                if (i == 0 || w == 0)
                {
                    dp[i][w] = 0;
                }
                else
                {
                    int pick = 0;
                    if (wt[i - 1] <= w)
                    {
                        pick = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                    }

                    int not_pick = dp[i - 1][w];
                    dp[i][w] = std::max(pick, not_pick);
                }
            }
        }
        return dp[n][W];
    }
};

int main()
{
    Solution sol;
    std::vector<int> values = {1, 2, 3};
    std::vector<int> weight = {4, 5, 1};
    int w = 4;
    std::cout << "Maximum value that can be achived is " << sol.knapsack(w, values, weight) << std::endl;
    return 0;
}