class Solution {
public:
    int maxlen = 0;
    int helper(int idx, string& s, unordered_set<string>& st, vector<int> &dp) {
        if(idx == s.size()) return 0; // No possibility of extra characters.
        if(dp[idx] != -1) return dp[idx];
        int mini = s.size();
        // 1. Consider the current character as extra
        mini = 1 + helper(idx+1, s, st, dp);
        // 2. Match the dictionary.
        for (int i = idx; i < s.size(); i++) {
            string curr = s.substr(idx, i - idx + 1);
            if (st.find(curr) != st.end()) {
                mini = min(mini, helper(i + 1, s, st, dp));
            }
        }
        return dp[idx] = mini;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        vector<int> dp(s.size()+1, -1);
        for (auto& word : dictionary) {
            maxlen = max(maxlen, (int)word.size());
        }
        int res = helper(0, s, st, dp);
        return res;
    }
};
