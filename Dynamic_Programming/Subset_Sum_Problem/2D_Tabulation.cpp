#include <vector>
class Solution
{
public:
    bool solve(int idx, std::vector<int> &arr, int sum, std::vector<std::vector<int>> &dp)
    {
        if (sum == 0)
        {
            return true;
        }
        if (idx == arr.size() && sum != 0)
        {
            return false;
        }
        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        bool np = solve(idx + 1, arr, sum, dp);

        bool p = false;
        if (arr[idx] <= sum)
        {
            p = solve(idx + 1, arr, sum - arr[idx], dp);
        }
        return dp[idx][sum] = p || np;
    }
    bool isSubsetSum(std::vector<int> &arr, int sum)
    {
        // code here
        std::vector<std::vector<int>> dp(arr.size() + 1, std::vector<int>(sum + 1, 0));
        int n = arr.size();
        // Base case
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        // dp[i][j]? Starting from index i with remaining sum j, is there a subset with target sum.
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= sum; j++)
            {
                bool np = dp[i + 1][j];
                bool p = false;
                if (arr[i] <= j)
                {
                    p = dp[i + 1][j - arr[i]];
                }
                dp[i][j] = p || np;
            }
        }
        return dp[0][sum];
    }
};