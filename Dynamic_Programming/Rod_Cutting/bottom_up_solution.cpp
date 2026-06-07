#include <iostream>
#include <vector>
#include <limits.h>

class ROD_CUT
{
public:
    std::pair<std::vector<int>, std::vector<int>> find_cost(std::vector<int> &prices, int n)
    {
        std::vector<int> dp(n + 1, -1);
        std::vector<int> positions(n + 1, 0);
        dp[0] = 0; // If the length of the rod is zero, it can be sold for zero.

        for (int j = 1; j <= n; j++)
        {
            int res = INT_MIN;
            for (int i = 1; i <= j; i++)
            {
                // res = std::max(res, prices[i - 1] + dp[j - i]);
                if (res < prices[i - 1] + dp[j - i])
                {
                    res = prices[i - 1] + dp[j - i];
                    positions[j] = i; // best cut location so far for length j.
                }
            }
            dp[j] = res;
        }
        return {dp, positions};
    }
};

int main()
{
    std::vector<int> prices = {3, 5, 8, 9, 10, 17, 17, 20};
    int n = prices.size();
    ROD_CUT helper;
    auto [v, positions] = helper.find_cost(prices, n);
    std::cout << "Maximum Profit obtained is " << v[n] << std::endl;

    std::cout << "Cut position for Maximum selling price \n";
    int len = n;
    while (len > 0)
    {
        std::cout << positions[len] << " ";
        len = len - positions[len];
    }
    std::cout << std::endl;
    return 0;
}