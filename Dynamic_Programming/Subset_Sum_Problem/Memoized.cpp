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
        // We have two variables in the recurcive solution.
        std::vector<std::vector<int>> dp(arr.size() + 1, std::vector<int>(sum + 1, -1));
        return solve(0, arr, sum, dp);
    }
};