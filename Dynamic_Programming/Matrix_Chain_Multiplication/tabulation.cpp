#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
class MCM
{
public:
    int matrix_chain_multiplication(std::vector<int> &arr)
    {
        int n = arr.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, INT_MAX));
        std::vector<std::vector<int>> position(n, std::vector<int>(n, 0));
        for (int i = 1; i < n; i++)
        {
            dp[i][i] = 0; // From i:i there is only one matrix, hence no cost for multiplication
        }

        // Process all possible lengths of the matrix.
        // Ex: {1,2,3,4,3}
        // We start at index 2, so the length of the chain will always be atleast 2.
        for (int l = 2; l < n; l++)
        {
            // i starts at 1. Till what index: l=2, n-l+1 = 5-2+1 = 4. i can go uptill 3
            for (int i = 1; i < n - l + 1; i++)
            {
                int j = i + l - 1; // Chain ends at j.
                for (int k = i; k <= j - 1; k++)
                {
                    int q = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    if (q < dp[i][j])
                    {
                        position[i][j] = k;
                        dp[i][j] = q;
                    }
                }
            }
        }
        return dp[1][n - 1];
        // Time complexity: O(N^3).
    }
};
int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 3};
    MCM helper;
    int ans = helper.matrix_chain_multiplication(arr);
    std::cout << ans << std::endl;
    return 0;
}