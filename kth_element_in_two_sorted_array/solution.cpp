#include<vector>
#include<iostream>

class Solution {
  public:
    int kthElement(std::vector<int> &a, std::vector<int> &b, int k) {
        // code here
        // Brute for approach: Use merge part of the merge sort algo to merge
        // and then return the kth position element.
        int n1 = a.size(), n2 = b.size();
	std::vector<int> com;
        int l=0,r=0;
        while(l<n1 && r<n2){
            if(a[l] <= b[r]){
                com.push_back(a[l++]);
            } else{
                com.push_back(b[r++]);
            }
        }
        
        while(l<n1){
            com.push_back(a[l++]);
        }
        while(r<n2){
            com.push_back(b[r++]);
        }
        return com[k-1];
    }
};

int main() {
	std::vector<int> a = {2, 3, 6, 7, 9};
	std::vector<int> b = {1, 4, 8, 10};
	Solution sol;
	int ans = sol.kthElement(a,b, 5);
	std::cout<<ans;
	return 0;
}
