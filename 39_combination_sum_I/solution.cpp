#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    void helper(int idx, vector<int> arr, int target, vector<int> &curr, vector<vector<int>> &ans){
        // Base cases.
        if(idx == arr.size()){
            if(target == 0){
                ans.push_back(curr);
                return;
            }
            return; // else return if target is not equal to zero.
        }

        // Pick the element but do not move to the next index. and only pick if nums[idx] <= target because we will be subtracting nums[idx] from target and we need it to be >=0.
        if(arr[idx] <= target){
            curr.push_back(arr[idx]);
            helper(idx, arr, target-arr[idx], curr, ans);
            // backtrack
            curr.pop_back();
        }

        // Not pick
        helper(idx+1, arr, target, curr, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> curr;
        // What needs to be passed to the function?
        // current index, target, curr, ans
        helper(0, candidates, target, curr, ans);
        return ans;
    }
};

int main() {
	vector<int> candidates = {2,3,6,7};
	int target = 7;
	Solution sol;
	vector<vector<int>> ans = sol.combinationSum(candidates, target);
	return 0;
}
