class Solution {
public:
    int maxline = 0;
    void helper(int idx, string& s, string curr, vector<string>& ans,
                unordered_set<string>& st) {
        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = idx; i < s.size() && (i-idx+1) <= maxline; i++) {
            string s1 = s.substr(idx, i - idx + 1);
            if (st.find(s1) != st.end()) {
                if (curr.size() == 0) {
                    helper(i + 1, s, curr + s1, ans, st);
                } else {
                    helper(i + 1, s, curr+" "+s1, ans, st);
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        for (auto& word : wordDict) {
            maxline = max(maxline, (int)word.size());
        }
        vector<string> ans;
        helper(0, s, "", ans, st);
        return ans;
    }
};
