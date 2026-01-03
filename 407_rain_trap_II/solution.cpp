#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // Pretty much the same as trap_water_1. Just we need to find out next
        // largest for every index in the four directions.
        int rows = heightMap.size(), cols = heightMap[0].size();
        // Edge case
        if (rows <= 2 || cols <= 2)
            return 0; // No water can be stored.
        int ans = 0;

        // Brute force.
        for (int r = 1; r < rows - 1; r++) {
            for (int c = 1; c < cols - 1; c++) {
                int top_largest = heightMap[r][c];
                int bottom_largest = heightMap[r][c];
                int left_largest = heightMap[r][c];
                int right_largest = heightMap[r][c];
                // Traverse in all 4 directions.
                // Top_largest
		
                for (int i = r; i >= 0; i--) {
                    // colum stays the same
                    if (heightMap[i][c] > top_largest) {
                        top_largest = heightMap[i][c];
                    }
                }
		
                // Bottom_largest
                for (int i = r; i < rows; i++) {
                    // column stays the same
                    if (heightMap[i][c] > bottom_largest) {
                        bottom_largest = heightMap[i][c];
                    }
                }
		
                // left_largest
                for (int i = c; i >= 0; i--) {
                    // row stays the same
                    if (heightMap[r][i] > left_largest) {
                        left_largest = heightMap[r][i];
                    }
                }
	        	
                // right_largest
                for (int i = c; i < cols; i++) {
                    // colum stays the same
                    if (heightMap[r][i] > right_largest) {
                        right_largest = heightMap[r][i];
                    }
                }
		
		cout<<top_largest<<" "<<bottom_largest<<" "<<left_largest<<" "<<right_largest<<"\n";
		cout<<"curr: "<<heightMap[r][c]<<"\n";
		int mini = min(left_largest,
                         min(right_largest, min(top_largest, bottom_largest)));
	        cout<<"mini: "<<mini<<"\n";
                ans +=
                    (min(left_largest,
                         min(right_largest, min(top_largest, bottom_largest))) -
                     heightMap[r][c]);
		//cout<<ans<<" ";
            }
        }
        return ans;
    }
};

int main() {
	//vector<vector<int>> heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
	vector<vector<int>> heightMap = {{12,13,1,12},{13,4,13,12},{13,8,10,12},{12,13,12,12},{13,13,13,13}};
	Solution sol;
	int ans = sol.trapRainWater(heightMap);
	return 0;
}
