#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Optimal solution is to use moore voting algorithm.
        int ans = 0;
        int count = 0;

        for(auto it: nums){
            if(count == 0){
                ans = it;
		count++;
            } else if(it == ans){
                count++;
            } else{
                count--;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> array = {3,3,4};
    Solution sol;
    int ans = sol.majorityElement(array);
    cout<<ans;
    return 0;
}
