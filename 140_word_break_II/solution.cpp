class Solution {
public:
    int maxline = 0;
    void helper(int idx, string& s, string& curr, vector<string>& ans,
                unordered_set<string>& st) {
        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            string s1 = s.substr(idx, i - idx + 1);
            if (st.find(s1) != st.end()) {
                string old = curr; // To backtrack efficiently. As we can see we are adding a space in case curr is not empty. This will make it difficult to backtrack one we get back from the function call. So store the old state.
                if (curr.size() == 0) {
                    curr += s1;
                } else {
                    curr = curr + " " + s1;
                }
                helper(i + 1, s, curr, ans, st);
                // Backtrack
                curr = old;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        for (auto& word : wordDict) {
            maxline = max(maxline, (int)word.size());
        }
        vector<string> ans;
        string curr = "";
        helper(0, s, curr, ans, st);
        return ans;
    }
};
