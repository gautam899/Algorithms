#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // As we can notice in the problem description it is required to write a O(log(m*n)) solution. Hence we can think of binary search. 
        int row = matrix.size(),col = matrix[0].size();
        int low = 0;
        int high = row*col - 1;

        while(high >= low){
            int mid = low + (high-low)/2;
            if(matrix[mid/col][mid%col] == target){
                return true;
            }

            if(matrix[mid/col][mid%col] > target){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false; // Target not found.
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
	    {1,3,5,7},
	    {10,11,16,20},
	    {23,30,34,60}};
    int target = 3;
    bool ans = sol.searchMatrix(matrix, target);
    cout << ans;
    return 0;
}
