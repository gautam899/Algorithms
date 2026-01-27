class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        if(m==0)return 0; // edge case.
        int ans = -1;
        int low=1, high=m;
        while(low <= high){
            int mid = low + (high-low)/2;
            int x = (int)pow(mid, n);
            if(x == m){
                ans = mid; break;
            } else if(x < m){
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }
};
