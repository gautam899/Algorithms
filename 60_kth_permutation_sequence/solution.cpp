class Solution {
public:
    void helper(vector<int> &nums, int fact, string &ans, int k){
        // Base case. If only one element left in the vector push.
        if(nums.size() == 1){
            ans += to_string(nums[0]);
            return;
        }

        // What block our answer lies in.
        int block_no = k/fact;
        // corner case. If k is a multiple for fact then we reduce the block_no by one.
        // Example n = 4, fact = 6. k = 12. Our permutation will be in block 1 but 12/6=2
        if(k%fact == 0){
            block_no--;
        }
        // Push nums[block_no] in ans
        ans += to_string(nums[block_no]);
        // Remove the element at block_no index in nums.
        nums.erase(nums.begin()+block_no); 
        k = k - fact*block_no; // We have already skipped fact*block_no element.
        // Update the factorial 3!->2! i.e 3!/3(the new size of the vector);
        fact = fact/nums.size();
        helper(nums,fact,ans,k);

    }
    string getPermutation(int n, int k) {
        // Base case
        if(n==1){
            return to_string(n);
        }
        // evaluate the factorial n-1 to start with
        vector<int> nums;
        int fact = 1, i;
        // for loop from 1->n-1, because for n we evaluate (n-1)!.
        for(i=1;i<n;i++){
            nums.push_back(i);
            fact *= i;
        }
        nums.push_back(i); // In the for loop we only pushed till n-1.
        /*
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<"\n"<<fact<<"\n";
        */
        string ans = "";
        helper(nums, fact, ans, k); // Ensure passing the string by reference.
        return ans;
    }
};
