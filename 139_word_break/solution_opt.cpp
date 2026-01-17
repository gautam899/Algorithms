class Solution {
public:
    int maxline = INT_MIN;
    bool helper(int idx, string& s, unordered_set<string>& st,
                vector<int>& dp) {
        if (idx == s.size())
            return true;
        if (dp[idx] != -1)
            return dp[idx];
        // We do not have to check for string size more than the longest in the dict.
        for (int i = idx; i < s.size() && (i-idx+1 <= maxline); i++) {
            string curr = s.substr(idx, i-idx+1); // Instead of creating a new string every iteration.
            if (st.find(curr) != st.end()) {
                if (helper(i + 1, s, st, dp))
                    return dp[idx] = true;
            }
        }
        return dp[idx] = false; // went through a possible string from idx till end but
                      // did not found any that is in the dictionary.
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &word: wordDict){
            int j = word.size();
            maxline = max(maxline, j);
        }
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n, -1);
        return helper(0, s, st, dp);
    }
};
