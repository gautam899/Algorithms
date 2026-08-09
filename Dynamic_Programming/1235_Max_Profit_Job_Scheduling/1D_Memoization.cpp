#include <tuple>
#include <vector>
#include <algorithm>
#include <limits.h>

/*
    Until now, our state was with previous job picked as prev and current job as idx, what is the max profit that can be achieved
    What if we change our state to curr job being idx, what is the max profit that can be achived.
    Why do we not need prev, we have already sorted
*/
class Solution
{
public:
    int solve(int idx, std::vector<std::tuple<int, int, int>> &intervals, std::vector<int> &dp)
    {
        if (idx == intervals.size())
            return 0; // No more profit

        if (dp[idx] != -1)
            return dp[idx];

        int notPick = 0 + solve(idx + 1, intervals, dp);
        int pick = INT_MIN;
        // Find the next compatible j
        // int j = idx + 1;
        // while (j < intervals.size())
        // {
        //     // If the starting time of jth job is greater than or equal to ending time of the curr job
        //     if (std::get<0>(intervals[j]) >= std::get<1>(intervals[idx]))
        //     {
        //         break;
        //     }
        //     j++;
        // }

        int j = intervals.size();
        int low = idx + 1;
        int high = intervals.size() - 1;
        while (low <= high)
        {
            int mid = (high + low) / 2;
            if (std::get<0>(intervals[mid]) >= std::get<1>(intervals[idx]))
            {
                j = mid; // Possible next job. But it is possible to have a job
                         // index smaller than mid and start time greater than
                         // end time of job index idx.
                // std::cout << j << std::endl;

                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        pick = std::get<2>(intervals[idx]) + solve(j, intervals, dp);

        return dp[idx] = std::max(notPick, pick);
    }
    int jobScheduling(std::vector<int> &startTime, std::vector<int> &endTime,
                      std::vector<int> &profit)
    {

        std::vector<int> dp(startTime.size() + 1, -1);

        // Sort the vectors as per starTime.
        std::vector<std::tuple<int, int, int>> combined;
        for (int i = 0; i < startTime.size(); i++)
        {
            combined.push_back(std::make_tuple(startTime[i], endTime[i], profit[i]));
        }

        std::sort(combined.begin(), combined.end()); // O(LogN)
        return solve(0, combined, dp);
        /*
            If n is the size of the interval.
            Time complexity is O(NLogN)
        */
    }
};