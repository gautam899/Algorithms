#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int knapsack(int W, std::vector<int> &val, std::vector<int> &wt)
    {
        int n = val.size();
        // Upon carefully observing we are only using two rows at a time. The curr row that we are filling and the prev
        // that we use to fill the curr.
        std::vector<int> prev(W + 1, 0), curr(W + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                if (i == 0 || w == 0)
                {
                    curr[w] = 0;
                }
                else
                {
                    int pick = 0;
                    if (wt[i - 1] <= w)
                    {
                        pick = val[i - 1] + prev[w - wt[i - 1]];
                    }

                    int not_pick = prev[w];
                    curr[w] = std::max(pick, not_pick);
                }
            }
            prev = curr;
        }
        return curr[W];
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