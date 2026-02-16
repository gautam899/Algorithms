#include<iostream>
#include<vector>
#include<stack>
#include<utility>
class Solution {
  public:
	std::vector<int> nextSmallerEle(std::vector<int>& arr) {
        //  code here
	std::stack<std::pair<int,int>> st;
	std::vector<int> ans(arr.size(), -1);
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && st.top().first > arr[i]){
                ans[st.top().second] = arr[i];
                st.pop();
            }
            st.push({arr[i], i});
        }
        return ans;
    }
};

int main(){
	std::vector<int> nums = {5,9,2,1,5,8};
	Solution sol;
	std::vector<int> ans = sol.nextSmallerEle(nums);
	for(auto it: ans){
	   std::cout<<it<<" ";
	}
	std::cout<<std::endl;
	return 0;
}
