#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
class Solution {
public:
	std::string reverseWords(std::string s) {
        int n = s.size();
        // another approach that we can take here is to store all the words into a vector. Reverse the vector and create a new string out of it.
	std::vector<std::string> v;
        int i=0,j=0;
        while(i<n){
            while(i<n && s[i] == ' ')i++;
            j = i;
            while(j<n && s[j] != ' ')j++;
            v.push_back(s.substr(i, j-i));
            i = j;
        } // O(N). i and j traverse the string once and each character is traversed atmost twice, once with i and then j.
	std::reverse(v.begin(), v.end()); // O(w), where w is the number of words in the string. w<=n.
	std::string ans;
        for(int k = 0;k<v.size();k++){
            ans += (ans.size() == 0) ? v[k] : (' ' + v[k]);
        }
        return ans;
        // Time complexity for this solution is O(N).
    }
};

int main() {
    std::string s = "   the   sky  is    blue  ";
    Solution sol;
    std::string ans = sol.reverseWords(s);
    std::cout<<ans;
    return 0;
}
