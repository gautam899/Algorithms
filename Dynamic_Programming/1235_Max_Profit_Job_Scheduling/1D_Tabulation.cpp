#include <algorithm>
#include <limits.h>
#include <tuple>
#include <vector>

/*
    Until now, our state was with previous job picked as prev and current job as
   idx, what is the max profit that can be achieved What if we change our state
   to curr job being idx, what is the max profit that can be achived. Why do we
   not need prev, we have already sorted.
*/
class Solution
{
public:
    int jobScheduling(std::vector<int> &startTime, std::vector<int> &endTime,
                      std::vector<int> &profit)
    {

        std::vector<int> dp(startTime.size() + 1, 0);

        // Sort the vectors as per starTime.
        std::vector<std::tuple<int, int, int>> intervals;
        for (int i = 0; i < startTime.size(); i++)
        {
            intervals.push_back(
                std::make_tuple(startTime[i], endTime[i], profit[i]));
        }

        std::sort(intervals.begin(), intervals.end()); // O(LogN)

        for (int idx = intervals.size() - 1; idx >= 0; idx--)
        {
            int not_pick = dp[idx + 1];

            int pick = INT_MIN;
            int j = intervals.size();
            int low = idx + 1;
            int high = intervals.size() - 1;
            while (low <= high)
            {
                int mid = (high + low) / 2;
                if (std::get<0>(intervals[mid]) >=
                    std::get<1>(intervals[idx]))
                {
                    j = mid; // Possible next job. But it is possible to have a
                             // job index smaller than mid and start time
                             // greater than end time of job index idx.
                    // std::cout << j << std::endl;

                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            pick = std::get<2>(intervals[idx]) + dp[j];

            dp[idx] = std::max(pick, not_pick);
        }
        return dp[0];
        /*
            If n is the size of the interval.
            Time complexity is O(NLogN)
        */
    }
};