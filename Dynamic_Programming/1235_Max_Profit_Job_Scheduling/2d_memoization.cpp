#include <tuple>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int solve(int idx, int prev, std::vector<std::tuple<int, int, int>> &intervals, std::vector<std::vector<int>> &dp)
    {
        if (idx == intervals.size())
            return 0; // No more profit

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int pick = 0;
        if (prev == -1 || std::get<0>(intervals[idx]) >= std::get<1>(intervals[prev]))
        {
            pick = std::get<2>(intervals[idx]) +
                   solve(idx + 1, idx, intervals, dp);
        }
        int notPick = 0 + solve(idx + 1, prev, intervals, dp);

        return dp[idx][prev + 1] = std::max(notPick, pick);
    }
    int jobScheduling(std::vector<int> &startTime, std::vector<int> &endTime,
                      std::vector<int> &profit)
    {

        std::vector<std::vector<int>> dp(startTime.size() + 1,
                                         std::vector<int>(startTime.size() + 1, -1));

        // Sort the vectors as per starTime.
        std::vector<std::tuple<int, int, int>> combined;
        for (int i = 0; i < startTime.size(); i++)
        {
            combined.push_back(std::make_tuple(startTime[i], endTime[i], profit[i]));
        }

        std::sort(combined.begin(), combined.end());
        return solve(0, -1, combined, dp);
    }
};