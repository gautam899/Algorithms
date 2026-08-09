#include <string>
#include <unordered_map>
#include <iostream>
#include <unordered_set>

class Solution
{
public:
    int countSubs(std::string &s)
    {
        // code here
        // std::unordered_map<std::string, int> mp;
        // int n = s.size();
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i; j < n; j++)
        //     {
        //         mp[s.substr(i, j - i + 1)]++;
        //     }
        // }
        // return mp.size();

        std::unordered_set<std::string_view> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                st.insert(std::string_view(s).substr(i, j - i + 1));
            }
        }
        return st.size();
        /* This is better than using an s.substr which create a new string everytime. String

        */
    }
};

int main()
{
    std::string s = "ababa";
    Solution sol;
    int ans = sol.countSubs(s);
    std::cout << ans << std::endl;
    // Time complexity: O(N^2)
}
