#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // This is not the same a 2 sum. The approach we need to take is sort and two pointer.
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // Moves for 0
        for(int i=0;i<nums.size()-2;i++){
            if(i==0 || nums[i] != nums[i-1]) // The if condition is needed to avoid duplicates. ex: [-1,0,1,2,-1,-4] sorting makes it [-4,-1,-1,0,1,2].
            // If i is pointing at index 1 i.e -1. We get a triplet -1,0,1.
            // Now in the next iteration when i points at index 2, this will again generate triplet [-1,0,1]. So we skip index if this is same as previous.
            {
                int lo = i+1,hi = nums.size()-1;
                int sum = 0-nums[i];
                while(lo<hi){
                    if(nums[lo]+nums[hi] == sum){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        ans.push_back(temp);
                        // Now, in this moment we need to take care of duplicates.
                        // Ex: [-5,-5, 0, 0, 5, 5].
                        // i = 0, nums[i] = -5, sum = 5.
                        // lo=2, hi=5 sum = 5. Triplet [-5,0,5]. lo++, hi--.
                        // lo=3, hi=4 sum 5 but this produces a duplicate.
                        // Hence.
                        while(lo<hi && nums[lo] == nums[lo+1]) lo++;
                        while(lo<hi && nums[hi] == nums[hi-1]) hi--;
                        lo++;
                        hi--;
                    }
                    else if(nums[lo]+nums[hi]<sum){
                        lo++;
                    } else{
                        hi--;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    //vector<int> v = {-1,0,1,2,-1,-4};
    vector<int> v = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    Solution sol;
    vector<vector<int>> ans = sol.threeSum(v);
    for(const auto& row: ans){
    	for(auto r: row) cout<<r<<' ';
	cout<<"\n";
    }
    return 0;
}
