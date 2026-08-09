#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
    The problem at hand is to take a string and generate all possible subsequence include the string and and empty string.
    To solve this problem we can use the concept of power set. If n is the length of the string, we generate all numbers in binary from
    0->n and for every number we can check for all the set bits. The character corresponding to the index of the set bit will be included
    in the subsequence.
*/
class Solution
{
public:
    void solve(int ind, const std::string &s, std::vector<std::string> &ans, std::string &curr)
    {
        if (ind == s.size())
        {
            ans.push_back(curr);
            return;
        }

        // pick
        curr.push_back(s[ind]);
        solve(ind + 1, s, ans, curr);
        // Backtrack
        curr.pop_back();
        solve(ind + 1, s, ans, curr);
    }
    std::vector<std::string> allStringSubsequence(const std::string &s)
    {
        std::vector<std::string> ans;
        std::string curr = "";
        solve(0, s, ans, curr);
        return ans;
    }
};

int main()
{
    std::string s = "abc";
    Solution sol;
    std::vector<std::string> ans = sol.allStringSubsequence(s);
    std::sort(ans.begin(), ans.end());
    for (const std::string &it : ans)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return 0;
}