class Solution {
  public:
    int helper(std::vector<std::vector<int>> &mat, int row, int col, int mid){
        int count = 0;
        for(int r = 0;r<row;r++){
            std::vector<int>::iterator up = std::upper_bound(mat[r].begin(), mat[r].end(), mid);
            count += (up-mat[r].begin());
        }
        return count;
    }
    int median(std::vector<std::vector<int>> &mat) {
        // code here
        int row = mat.size(), col = mat[0].size();
        int half = (row*col)/2;
        int low = mat[0][0];
        int high = mat[row-1][col-1];
        for(int r=0;r<row;r++){
            low = std::min(low, mat[r][0]);
            high = std::max(high, mat[r][col-1]);
        }
        // std::cout<<low<<" "<<high<<"\n";
        while(low<high){
            int mid = low + (high-low)/2;
            // Find the total number of elements in the matrix less than
            // or equal to mid.
            int num_of_elements_less = helper(mat, row, col, mid);
            // cout<<"number of element less than or equal to mid "<<mid<<" are: "<<num_of_elements_less;
            if(num_of_elements_less <= half){
                low = mid+1;
            } else{
                high = mid; // We wish to find the first occurence such that number of element
                // less than or equal to mid are greater that half the total elements in the matrix.
            }
        }
        return low;
        
    }
};

