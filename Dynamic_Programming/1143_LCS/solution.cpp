#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Solution
{
public:
    int longestCommonSubsequence(std::string text1, std::string text2)
    {
        int n = text1.size();
        int m = text2.size();

        std::vector<std::vector<int>> lcs(n + 1, std::vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                }
                else
                {
                    lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }
        return lcs[n][m];
    }
};

int main()
{
    std::string text1 = "gac";
    std::string text2 = "agcat";
    Solution sol;
    int ans = sol.longestCommonSubsequence(text1, text2);
    std::cout << ans << std::endl;
    return 0;

    // Time complexity: O(N*M).
}