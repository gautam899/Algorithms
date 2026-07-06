#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
class MCM
{
public:
    int rec(int start, int end, std::vector<int> &arr, std::vector<std::vector<int>> &dp)
    {
        if (start == end)
            return 0;

        if (dp[start][end] != INT_MAX)
            return dp[start][end];
        // Try all possible splits b/w start and end.
        for (int k = start; k < end; k++)
        {
            dp[start][end] = std::min(dp[start][end], rec(start, k, arr, dp) + rec(k + 1, end, arr, dp) + (arr[start - 1] * arr[k] * arr[end]));
        }
        return dp[start][end];
    }
    int matrix_chain_multiplication(std::vector<int> &arr)
    {
        int n = arr.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, INT_MAX));
        for (int i = 1; i < n; i++)
        {
            dp[i][i] = 0; // From i:i there is only one matrix, hence no cost for multiplication
        }
        int x = rec(1, n - 1, arr, dp);
        std::cout << x << std::endl;
        return x;
    }
};
int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 3};
    MCM helper;
    int ans = helper.matrix_chain_multiplication(arr);
    return 0;
}