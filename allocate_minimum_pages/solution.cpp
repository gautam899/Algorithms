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
        int max_pages = accumulate(arr.begin(), arr.end(),0);
	std::cout<<"Sum: "<<max_pages<<"\n";
        for(int page=low;page<=max_pages;page++){
	    std::cout<<"Sending Page: "<<page<<"\n";
            if(allocateBooks(arr, page) <= k){
		std::cout<<"Page: "<<page<<"\n";
                return page; // 
            }
        }
	return low;
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
