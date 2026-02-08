#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<utility>

class Solution {
public:
	std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
	std::unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        // mp-> {num, freq}
	std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> minH;
        for(auto pair: mp){
            minH.push({pair.second, pair.first});
            if(minH.size()>k){
                minH.pop();
            }
        }
        // minH-> {freq, num} // Sorted based on freq.
	std::vector<int> ans;
        while(!minH.empty()){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }
};

int main() {
    std::vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution sol;
    std::vector<int> ans = sol.topKFrequent(nums,k);
    for(auto it: ans){
       std::cout<<it<<" ";
    }
    return 0;
}
