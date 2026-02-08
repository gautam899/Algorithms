#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
	    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for(int num: nums){
            pq.push(num);
            // If the size of the heap becomes greater than k then we pop.
            if(pq.size() > k){
                pq.pop();
            }
        }
        // At this moment we have the kth largest element at the top of the heap.
        return pq.top();
    }
};

int main() {
    std::vector<int> v = {3,2,1,5,6,4};
    int k = 2;
    Solution sol;
    int ans = sol.findKthLargest(v, k);
    std::cout<<"Ans: "<<ans;
    return 0;
}

