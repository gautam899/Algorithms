#include<string>
#include<iostream>
class Solution {
public:
    std::string helper(int n) {
        if (n == 1)
            return "1";
	std::string curr = helper(n - 1);
	std::string s = "";
        for(int i=0;i<curr.size();){
            int count = 0;
            char c = curr[i];
            while(i<n && c == curr[i]){
                i++; count++;
            }
            s += (std::to_string(count) + c);
        }
        return s;
    }
    std::string countAndSay(int n) { return helper(n); }
};

int main() {
   Solution sol;
   std::string ans = sol.countAndSay(5);
   std::cout<<ans;
   return 0; 
}
