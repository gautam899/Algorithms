class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        string ans;
        while(i<n){
            if(s[i] == ' ') i++;
            else {
                int j = i;
                string s1;
                while(j < n & s[j] != ' '){
                    s1 += s[j++];
                }
                // cout<<s1<<endl;
                ans = (ans.size() == 0) ? (s1 + ans) : (s1 + ' ' + ans);
                i = j;
            }
        }
        return ans;
    }
};
