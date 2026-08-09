#include <vector>
#include <algorithm>
#include <queue>
class Solution
{
public:
    struct jobs
    {
        int deadline;
        int profit;
    };

    std::vector<int> jobSequencing(std::vector<int> &deadline, std::vector<int> &profit)
    {
        // code here
        int n = deadline.size();
        std::vector<jobs> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({deadline[i], profit[i]});
        }
        std::sort(v.begin(), v.end(), [](const auto &a, const auto &b)
                  { return a.deadline < b.deadline; });

        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (const auto &it : v)
        {
            // If the jobs can be scheduled. The size of the queue here means the number of seconds passed
            // Because every job takes 1 unit of time to complete. For eg: If the size of the minH is 2 and the
            // deadline for the current job is the 4, we can perform the job.
            if (it.deadline > pq.size())
            {
                pq.push(it.profit);
            } // If that is not the case, remove the top minimum if there is one and perform the job. This
            // will make sure that we only perform the max profit jobs
            else if (!pq.empty() && it.profit > pq.top())
            {
                pq.pop();
                pq.push(it.profit);
            }
        }

        int count = pq.size();
        int ans = 0;
        while (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return {count, ans};
    }
};
