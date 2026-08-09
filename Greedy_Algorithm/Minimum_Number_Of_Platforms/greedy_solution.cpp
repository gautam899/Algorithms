#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int findPlatforms(std::vector<int> &arrivals, std::vector<int> &departures)
    {
        int n = arrivals.size();
        std::sort(arrivals.begin(), arrivals.end());
        std::sort(departures.begin(), departures.end());
        /*
            Why sort separately and process? We do not care when does a specific train departs but rather at time t, how many trains are
            at the station simultaneously.
        */
        int i = 1;
        int j = 0;
        int platforms = 1; // One platform is always needed
        int ans = 1;
        while (i < n && j < n)
        {
            if (arrivals[i] <= departures[j])
            {
                // We need one more platform
                platforms++;
                i++;
            }
            else
            {
                // Free a platform
                platforms--;
                j++;
            }
            ans = std::max(ans, platforms);
        }
        return ans;
    }
};

int main()
{
    std::vector<int> arrivals = {};
    std::vector<int> departures = {};
    Solution sol;
    int ans = sol.findPlatforms(arrivals, departures);
    std::cout << ans << std::endl;
    // Time complexity: O(N*LogN). LogN for the sorting.
    return 0;
}