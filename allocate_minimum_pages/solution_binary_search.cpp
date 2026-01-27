#include<vector>
#include<iostream>
#include<numeric>
#include<algorithm>
class Solution {
  public:
    int allocateBooks(std::vector<int> &arr, int max_pages){
        int n = arr.size();
        int student = 1;
        int currStudentPages = 0;
        for(int i=0;i<n;i++){
            if(currStudentPages+arr[i] <= max_pages){
                currStudentPages+=arr[i];
            } else {
                student++;
                currStudentPages=arr[i];
            }
        }
        return student;
    }
    int findPages(std::vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k>n){
            return -1;
        }
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(),0);
        // for(int page=low;page<=high;page++){
        //     if(allocateBooks(arr, page) <= k){
        //         return page; // 
        //     }
        // }
        
        // Instead of performing the above search in a linear manner we can
        // perform binary search.
        int ans = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            int allocated_students = allocateBooks(arr, mid);
            if( allocated_students <= k){
                ans = std::min(ans, mid); // A possible ans but we might have smaller
                // answers on the left side.
                high = mid-1;
            } else if(allocated_students > k) {
                // Increase the range
                low = mid+1;
            }
        }
        return ans;
    }
};

int main(){
        std::vector<int> arr = {15, 10, 19, 10, 5, 18, 7};
        int k = 5;
        Solution sol;
        int ans = sol.findPages(arr, k);
        std::cout<<ans;
        return ans;
}
