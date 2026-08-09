#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    struct Activity
    {
        int startTime;
        int finishTime;
        int index;
    };

    std::vector<int> maxMeetings(std::vector<int> &s, std::vector<int> &f)
    {
        std::vector<Activity> meeting;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            meeting.push_back({s[i], f[i], i});
        }

        std::sort(meeting.begin(), meeting.end(), [](const Activity &a, const Activity &b)
                  { return a.finishTime < b.finishTime; });

        std::vector<int> ans;
        ans.push_back(meeting[0].index + 1);
        int k = 0;
        for (int i = 1; i < n; i++)
        {
            if (meeting[i].startTime > meeting[k].finishTime)
            {
                ans.push_back(meeting[i].index + 1);
                k = i;
            }
        }
        std::sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    std::vector<int> startTime = {34, 45, 44, 41, 31, 11, 44, 42, 4};
    std::vector<int> endTime = {70, 48, 93, 44, 56, 55, 92, 45, 42};

    Solution sol;
    std::vector<int> ans = sol.maxMeetings(startTime, endTime);
    for (auto it : ans)
    {
        std::cout << it << std::endl;
    }
    return 0;
}
