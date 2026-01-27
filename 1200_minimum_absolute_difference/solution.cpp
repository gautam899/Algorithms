class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        int l=0;
        while(l<n-1){
            int diff = arr[l+1] - arr[l];
            if(diff < mini){
                mini = diff;
                ans.clear(); // remove the existing pairs.
                ans.push_back({arr[l],arr[l+1]});
            } else if(diff == mini){
                ans.push_back({arr[l],arr[l+1]});
            }
            l++;
        }
        return ans;
    }
};
