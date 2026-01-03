#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Looking at the problem we will think of solving it using 2 pointer approach. But that is only applicable when we do not have any negatives.
        // Conside this example: [3,4,7,-2,2,1,4,2] and k=7. In the subset [-2,2,1,4] using two pointer approach we see sum is less than 7 and hence we include one 2 and make it [-2,2,1,4,2]. But we miss out on [2,1,4]. This is because we are under assumption that is the sum of current subset is less than 7 than there is no possibility of an answer which would have been right if there were no negatives. 
        // The optimal solution would be store the sum frequency. 
        // Mental Checklist:
        // 1. Contigious: prefix sum
        // 2. Does it have negative: If yes, then the two pointer approach is not valid because of the above reason.
        // 3. If no, then prefix sum+hash_map
        // prefix[i] = nums[0]+nums[1]+nums[2]+....+nums[i]
        // prefix[i]-prefix[j] = k
        // prefix[j] = prefix[i] - k
        // How many time we see the prefix_sum = prefix[i]-k?
        unordered_map<int,int> mp; // sum->(number of times seen)
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(mp.find(sum - k) != mp.end()){
                count += mp[sum-k];
            }
            mp[sum]++;
        }
        return count;


    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,4,7,-2,2,1,4,2};
    int k = 7;
    int ans = sol.subarraySum(nums, k);
    cout<<ans;
    return 0;
}
