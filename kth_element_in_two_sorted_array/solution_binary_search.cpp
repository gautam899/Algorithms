class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        if(a.size() > b.size()){
            swap(a,b);
        }
        
        int l=max(0, k - (int)b.size())-1, r=min(k, (int)a.size())-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            int mid2 = k - mid - 2;
            int lefta = (mid>=0) ? a[mid] : INT_MIN;
            int righta = (mid+1 < a.size()) ? a[mid+1] : INT_MAX;
            int leftb = (mid2>=0) ? b[mid2] : INT_MIN;
            int rightb = (mid2+1 < b.size()) ? b[mid2+1] : INT_MAX;
            if((lefta <= rightb )&& (leftb <= righta)){
                return max(lefta, leftb);
            } else if(lefta > rightb){
                r = mid - 1;
            } else if(leftb > righta) {
                l = mid + 1;
            }
        }
        return -1;
    }
};
