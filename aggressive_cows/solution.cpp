class Solution {
  public:
    bool canPlace(vector<int> &stalls, int d, int k){
        // Place the first cow at the first stall
        int count = 1;
        int last_cow = stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i] - last_cow >= d){
                count++;
                last_cow = stalls[i];
            }
            if(count >= k){
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        // sort(stalls.begin(), stalls.end());
        // int n = stalls.size();
        // int high = stalls[n-1]-stalls[0];
        // int ans = 0;
        // for(int i=1;i<=high;i++){
        //     if(canPlace(stalls, i, k)){
        //         ans = i;
        //     }
        // }
        // The above for loop operation can be performed using binary search
        
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int high = stalls[n-1]-stalls[0], low = 1;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(canPlace(stalls, mid, k)){
                ans = mid; // Possible answer but we can still have a larger value
                low = mid+1;
            } else {
                high = mid-1; // If mid as the minimum distance is too large.
            }
        }
        return ans;
    }
};
