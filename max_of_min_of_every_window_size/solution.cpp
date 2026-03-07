#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

class Solution {
  public:
    std::vector<int> maxOfMins(std::vector<int>& arr) {
	std::vector<int> ans(arr.size(), 0);
	std::stack<int> st;
        // Instead of finding minimum in every window size, for every element find the largest windows
        // size in which it is minimum. In order to do that find the left_smaller and right_smaller.
        
        for(int i=0;i<=arr.size();i++){
            int curr = i==arr.size() ? 0 : arr[i];
            while(!st.empty() && curr < arr[st.top()]){
                int num_to_process = arr[st.top()];
                st.pop();
                int r = i;
                int l = (!st.empty()) ? st.top() : -1;
                int window_size = r - l - 1; // The largest window size in which the num_to_process is
                // the minimum.
                ans[window_size - 1] = std::max(ans[window_size - 1], num_to_process);
                
            }
            st.push(i);
        }
        // There might we still some indices empty.
        // When we enlarge a window and add one more element, the minimum can either dec or stay the 
        // same. Therefore one thing we can say is the ans will be always non-inc.
        for(int j=arr.size()-2;j>=0;j--){
            ans[j] = std::max(ans[j], ans[j+1]);
        }
        return ans;
    }
};

int main(){
    std::vector<int> nums = {10, 20, 30, 50, 10, 70, 30};
    Solution sol;
    std::vector<int> ans = sol.maxOfMins(nums);
    for (auto it:ans) {
	    std::cout<<it<<" "<<std::endl;
    }
    return 0;
}
