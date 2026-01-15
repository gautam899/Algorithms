class Solution {
public:
    /****** Memoize********/
    // What if at index idx, I know already that if idx->i is a palindrom or
    // not? I need not to check same substring repeatedly.
    bool isPalindrome(int l, int r, string s) {
        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void helper(int idx, string s, vector<string>& curr,
                vector<vector<string>>& ans, vector<vector<int>>& dp) {
        // Base case
        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if(dp[idx][i] == 0){
                dp[idx][i] = isPalindrome(idx, i, s);
            }

            // If we know the substring is a palindrome.
            if (dp[idx][i] == 1) {
                curr.push_back(s.substr(idx, i - idx + 1));
                helper(i + 1, s, curr, ans, dp);
                curr.pop_back(); // backtrack.
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); // memoize.
        vector<vector<string>> ans;
        vector<string> curr;
        helper(0, s, curr, ans, dp);
        return ans;
    }
};
