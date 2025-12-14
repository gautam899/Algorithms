#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool searchMatrix(int matrix[][4], int target, int rows, int cols){
    int low = 0;
    int high = rows*cols - 1;
    while(high >= low){
    	int mid = low + (high-low)/2;
	int r = mid/cols;
	int c = mid%cols;
	int val = *(*(matrix+r)+c);
	if(val == target){
	    return true;
	}

	if(val > target){
	    high = mid - 1;
	}
	else{
	    low = mid + 1;
	}
    }
    return false;
}
int main() {
    int matrix[][4] = {
            {1,3,5,7},
            {10,11,16,20},
            {23,30,34,60}};
    int target = 2;
    bool ans = searchMatrix(matrix, target, 3, 4);
    printf("Ans: %d",ans);
    return 0;
}
