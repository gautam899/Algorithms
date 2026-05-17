#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution
{
public:
    int dfs(int l, int r, std::vector<int> &cuts, std::vector<std::vector<int>> &dp)
    {
        if (l > r)
            return 0; // No more cuts can be made.

        if (dp[l][r] != -1)
            return dp[l][r];

        int res = INT_MAX; // Because we wish to minimize
        for (int ind = l; ind <= r; ind++)
        {
            res = std::min(res, cuts[r + 1] - cuts[l - 1] + dfs(l, ind - 1, cuts, dp) + dfs(ind + 1, r, cuts, dp));
            // The cost of making the cut at ind is just like what we mentioned in the comments of __find_min_cost function
            // cuts[r+1] - cuts[l-1].
        }

        return dp[l][r] = (res == INT_MAX) ? 0 : res;
    }
    int __find_min_cost(int n, std::vector<int> &cuts)
    {
        int size = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0); // Insert 0 at the beginning
        std::sort(cuts.begin(), cuts.end());
        /*
            Why do we insert 0 and 7 at the beginning and the end respectively.
            Consider the cuts = {1,3,4,5}. Let's say we made a cut at index 4. How do I find the length
            of the stick of which 4 is a part of?. If I have a 0 and 7 in the front and the end then find the length
            of the stick becomes easy. If i and j points to the beginning and end of the original stick before pusing 0 and 7
            at the end, length of the stick will be cuts[j+1] - cuts[i-1].

            Once the cut is made at 4, we will have subproblems [1,3] and [5]. We can solve them independently
            why? Because our cuts vector is sorted. That is another thing we need to keep in mind.
            To keep the subproblems independent of each other we must sort the cuts vector.
        */
        std::vector<std::vector<int>> dp(cuts.size(), std::vector<int>(cuts.size(), -1));
        return dfs(1, size, cuts, dp);

        // Time Complexity: Two changing parameters gives O(M^2) and another looping variable approx O(M).
        // The time complexity will be ~= O(M^3)
    }
};

int main()
{
    int n = 7; // Length of the rod
    std::vector<int> cuts = {1, 3, 4, 5};
    Solution sol;
    int ans = sol.__find_min_cost(n, cuts);
    std::cout << "Minimum cost to cut the stick is: " << ans << std::endl;
    return 0;
}