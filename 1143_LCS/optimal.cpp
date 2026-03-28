#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        // Solution Inspired from.
        // https://en.wikipedia.org/wiki/Longest_common_subsequence
        int m = text1.size(), n = text2.size();
        int start = 0;
        int end1 = m - 1;
        int end2 = n - 1;

        // Trim the beginning
        while (start <= end1 && start <= end2 && text1[start] == text2[start])
            start++;

        // If one of the string is already exhausted
        if (start == m || start == n)
            return start;

        // Trim the end
        while (start <= end1 && start <= end2 && text1[end1] == text2[end2]) {
            end1--;
            end2--;
        }

        int new_m = end1 - start + 1;
        int new_n = end2 - start + 1;

        // Take the comman that is needed to be added at the end.
        int common = start + (m - end1 - 1);

        std::vector<std::vector<int>> v(new_m + 1, std::vector<int>(new_n + 1, 0));
        for (int i = 1; i <= new_m; i++) {
            for (int j = 1; j <= new_n; j++) {
                // We do not compare text1[i-1] and text2[j-1] now. Our search string is changed. Now we access elements at text1[start + i - 1] == text2[start + j - 1]
                if (text1[start + i - 1] == text2[start + j - 1]) {
                    v[i][j] = (1 + v[i - 1][j - 1]);
                } else {
                    v[i][j] = std::max(v[i - 1][j], v[i][j - 1]);
                }
            }
        }
        return common + v[new_m][new_n];
    }
};

int main() {
    std::string text1 = "abc";
    std::string text2 = "def";
    Solution sol;
    int ans = sol.longestCommonSubsequence(text1, text2);
    std::cout<<ans<<std::endl;
    return 0;
}