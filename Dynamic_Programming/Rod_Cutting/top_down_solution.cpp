#include <iostream>
#include <vector>
#include <limits.h>

class ROD_CUT
{
public:
    int find_cost(std::vector<int> &prices, int n, std::vector<int> &dp)
    {
        if (dp[n] != -1)
            return dp[n];
        if (n == 0)
            return dp[n] = 0;
        int res = INT_MIN;
        // We have a choice of cutting the rod in lengths going from 1 -> n
        for (int i = 1; i <= n; i++)
        {
            res = std::max(res, prices[i - 1] + find_cost(prices, n - i, dp));
        }

        return dp[n] = res;
    }
};

int main()
{
    std::vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = prices.size();
    std::vector<int> dp(n + 1, -1);
    ROD_CUT helper;
    int ans = helper.find_cost(prices, n, dp);
    std::cout << ans << std::endl;
    return 0;
}