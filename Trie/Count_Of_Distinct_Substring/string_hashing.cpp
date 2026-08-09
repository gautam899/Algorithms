#include <vector>
#include <iostream>
#include <unordered_set>

class Solution
{
public:
    int countDistinctSubstring(const std::string &s)
    {
        int n = s.size();
        const int p = 31; // Pow
        const int m = 1e9 + 9;
        std::vector<long long> p_pow(n, 0); // Pre Compute powers
        p_pow[0] = 1;
        for (int i = 1; i < n; i++)
        {
            p_pow[i] = (p_pow[i - 1] * p) % m;
        }

        std::vector<long long> hashes(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            hashes[i + 1] = (hashes[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
            // why hash[i+1]? prefix of length 1 i.e index s[0..0]. Prefix of length 2 s[0..1]
        }

        int cnt = 0;
        for (int l = 1; l <= n; l++)
        {
            std::unordered_set<long long> st;
            for (int i = 0; i <= n - l; i++)
            {
                int curr_h = (hashes[i + 1] + m - hashes[i]) % m;
                // Normalize
                curr_h = (curr_h * p_pow[n - i - l]) * m;
                st.insert(curr_h);
            }
            cnt += st.size();
        }
        return cnt;
    }
};

int main()
{
    Solution sol;
    std::string s = "aaa";
    int ans = sol.countDistinctSubstring(s);
    std::cout << ans << std::endl;
    return 0;
    // T.C: O(N^2)
}