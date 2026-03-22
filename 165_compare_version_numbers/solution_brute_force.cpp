#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    void helper(std::string s, std::vector<int> &v) {
        int n = s.size();
        int j = 0;
        int num = 0;
        while(j<n){
            if(s[j] == '.'){
                num = 0; // Reset the num and move ahead.
                j++;
            } else {
                // Skip the leading zeros
                while(j<n && s[j] == '0')j++;
                while(j<n && s[j] != '.'){
                    num = num*10 + (s[j]-'0');
                    j++;
                }
                v.push_back(num);
            }
        }
    }

    int compareVersion(std::string version1, std::string version2) {
        // Brute force approach.
        // 1. Write a helper function to push the revisions of the string into a vector for each string. 
        // 2. Compare the vectors and decide.
	std::vector<int> v1,v2;
        helper(version1, v1);
        helper(version2, v2);
        int i=0,j=0;
        /*
        for(auto it:v1){
            cout<<it<<" ";
        }
        cout<<endl;
        for(auto it:v2){
            cout<<it<<" ";
        }
        */
        while(i<v1.size() && j<v2.size()){
            if(v1[i] < v2[j]) return -1;
            if(v1[i] > v2[j]) return 1;
            i++;j++;
        }
        // If one of the vector is still left
        while(i<v1.size()){
            if(v1[i] > 0)return 1;
            i++;
        }
        
        while(j<v2.size()){
            if(v2[j] > 0)return -1;
            j++;
        }
        return 0;
    }
};

int main() {
    std::string version1 = "1.0.1";
    std::string version2 = "1";
    Solution sol;
    int ans = sol.compareVersion(version1, version2);
    std::cout<<ans;
    return 0;
}
