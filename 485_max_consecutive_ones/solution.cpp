#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        /*
	int i = 0;
        int maxi = 0;
        while (i < n) {
            if (nums[i] == 1) {
                int count = 0;
                while ( i < n && nums[i] == 1) {
                    count++;
                    i++;
                }
                maxi = max(count, maxi);
            } else {
                i++;
            }
        }
        return maxi;
	*/
	// or more consise and straight forward in terms of avoiding all the while loops.
	int result = 0, count = 0;
	for(int i=0;i<n;i++){
		if(nums[i] == 0){
			count = 0;
		} else {
			count++;
			result = max(result, count);
		}
	}
	return result;
    }
};

int main() {
	Solution sol;
	vector<int> arr = {1,1,0,1,1,1};
	int ans = sol.findMaxConsecutiveOnes(arr);
	cout<<ans;
	return 0;
}
