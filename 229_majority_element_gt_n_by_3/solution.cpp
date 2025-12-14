#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // We can again use the boore-moore-voting algorithm here. But instead of finding one majority element. This time we need to find two majority element.
        // If we observe carefully how many elements can occur more than n/3 times. Clearly not more than 2. So ans vector will be of size atmost 2.
        int count1=0,count2=0,n=nums.size();
        int ans1=-1,ans2=-1;
        for(auto it:nums){
            if(it == ans1){
                count1++;
            } else if(it == ans2){
                count2++;
            } else if(count1 == 0){
                ans1 = it;
                count1++;
            } else if(count2 == 0){
                ans2 = it;
                count2++;
            } else{
                count1--;count2--;
            }
        }
        // In this moment we have two majority elements but we can't say if both of them occur more than n/3 times. This is because the above iteration will give us elements that could be occuring more that n/3 times but still needs verification.
        vector<int> ans;
        count1=0;
        count2=0;
        for(auto it:nums){
            if(it==ans1){
                count1++;
            }
            else if(it == ans2){
                count2++;
            }
        }
        if(count1>floor(n/3)){
            ans.push_back(ans1);
        }
        if(count2>floor(n/3)){
            ans.push_back(ans2);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> v = {3,2,3};
    vector<int> ans = sol.majorityElement(v);
    for(int i=0;i<ans.size();i++){
      cout<<ans[i]<<" "<<endl;
    }
    return 0;
}
