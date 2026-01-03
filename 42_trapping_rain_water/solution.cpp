#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // We will create two arrays such that one will keep the largest wall to the left and the other will keep the largest to the right.
        int n = height.size();
        if(n==1)return 0; // Just one wall of any height cannot store any water.
        vector<int> left = height;
        vector<int> right = height;
        int largest = height[0];
        // process left.
        for(int i=1;i<n;i++){
            if(height[i] >= largest){
                largest = height[i];
            } else {
                left[i] = largest;
            }
        }
	// Print left
	cout<<"Printing left\n";
	for(int i=0;i<n;i++){
	   cout<<left[i]<<" ";
	}
        cout<<"\n";
        // Process right
        largest = height[n-1];
        for(int i=n-2;i>=0;i--){
            if(height[i] >= largest){
                largest = height[i];
            } else {
                right[i] = largest;
            }
        }

        cout<<"Printing right\n";
	for(int i=0;i<n;i++){
           cout<<right[i]<<" ";
        }
	cout<<"\n";
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += (min(left[i], right[i]) - height[i]);
        }
        return ans;
    }
};


int main() {
	vector<int> heights = {4,2,0,3,2,5};
	Solution sol;
	int ans = sol.trap(heights);
	cout<<ans;
	return 0;
}
