#include<vector>
#include<limits.h>
#include<iostream>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& A, std::vector<int>& B) {
        // Make sure the first vector is the smaller one always to make things easier.
        if(A.size() > B.size()){
		std::swap(A,B);
        }
        // Perform binary search on A
        int l=-1,r=A.size()-1; // l = -1 is required in case l=0 and r = -1. In this case a valid partition will have m = -1 but 0 + -1 /2 give 0 same m as the prev iteration. This keeps going and gives a TLE.
        int total = A.size()+B.size();
        int half = (A.size() + B.size())/2;
	//std::cout<<"Total: "<<total<<" Half: "<<half;
        double ans=0.0;
        while(true){
            int m = l + (r-l)/2;
            int m2 = half - m - 2;

            int leftA = (m>=0) ? A[m] : INT_MIN;
            int rightA = (m+1 < A.size()) ? A[m+1] : INT_MAX; // if m+1 is out of bounds that means all the elements of left partition are taken from A.
            int leftB = (m2>=0) ? B[m2] : INT_MIN;
            int rightB = (m2+1 < B.size()) ? B[m2+1] : INT_MAX;
	    std::cout<<leftA;
	    std::cout<<rightB;
	    std::cout<<leftB;
	    std::cout<<rightB;
            // Check for a perfect partition
            if((leftB <= rightA) && (leftA <= rightB)){
                // if even
                if(total%2 == 0){
                    ans = (std::max(leftA, leftB) + std::min(rightA, rightB))/2.0;
                } else {
                    ans = std::min(rightA, rightB);
                }
                break;
            }

            // If some comparision fails.
            if(leftB > rightA){
                // Increase the left of A
                l = m+1;
            } else if(leftA > rightB){
                // shrink the left of A
                r = m-1;
            }
        }
        return ans;
        
    }
};

int main() {
	Solution sol;
	std::vector<int> A = {1,2};
	std::vector<int> B = {3, 4};
	double ans = sol.findMedianSortedArrays(A, B);
	std::cout<<ans;
	return 0;
}
