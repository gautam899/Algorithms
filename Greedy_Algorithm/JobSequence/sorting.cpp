#include <vector>
#include <algorithm>
class Solution
{
public:
    struct jobs
    {
        int ind;
        int deadline;
        int profit;
    };

    std::vector<int> jobSequencing(std::vector<int> &deadline, std::vector<int> &profit)
    {
        // code here
        int n = deadline.size();
        std::vector<jobs> v;
        int maxDeadline = deadline[0];
        for (int i = 0; i < n; i++)
        {
            v.push_back({i, deadline[i], profit[i]});
            maxDeadline = std::max(maxDeadline, deadline[i]);
        }

        std::sort(v.begin(), v.end(), [](const auto &a, const auto &b)
                  { return a.profit > b.profit; });

        std::vector<int> temp(maxDeadline, -1);
        int ans = 0;
        int count = 0;
        for (const auto &it : v)
        {
            // Can this job be performed on its' last day
            int d = it.deadline;
            int p = it.profit;
            int id = it.ind;
            int j = d - 1;
            while (j >= 0)
            {
                if (temp[j] == -1)
                {
                    temp[j] = id;
                    ans += p;
                    count++;
                    break;
                }
                j--;
            }
        }
        return {count, ans};
    }
};
