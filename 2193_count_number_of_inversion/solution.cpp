#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1000000009;
    int merge_and_count(vector<int> &arr, int left, int mid, int right) {
        // Divide the left and right side into two arrays.
        int n1 = mid-left+1;
        int n2 = right-mid;
        vector<int> l1(n1),l2(n2);
        for(int i=0;i<n1;i++){
            l1[i] = arr[left+i];
        }
        for(int i=0;i<n2;i++){
            l2[i] = arr[mid+i+1]; // +1 because mid lies in the end of left side array.
        }
        int ans=0;
        int i=0,j=0,k=left;
        while(i<n1 && j<n2){
            if(l1[i] <= l2[j]){
                arr[k++] = l1[i++];
            }
            else{
                arr[k++] = l2[j++];
                // if l1[i] > l2[j], then all the element greater than l1[i](inclusive) in l1 are greater than l2[j] since l1 is sorted.
                ans += (n1-i);
            }
        }
        // Any remaining elements.
        while(i<n1){
            arr[k++] = l1[i++];
        }
        while(j<n2){
            arr[k++] = l2[j++];
        }
        return ans;
    }

    int count_inv(vector<int> &arr, int l, int r){
        int res=0;
        if (l<r){
            int mid = (r+l)/2;
            res+=count_inv(arr,l,mid);
            res+=count_inv(arr,mid+1,r);

            // Merge and count inv
            res+=merge_and_count(arr,l,mid,r);
        }
        return res;
    }

    bool hasInv(vector<int> &v, int inv){
        vector<int> temp = v;
        return count_inv(temp, 0, temp.size()-1) == inv;
    }

    bool checkFun(vector<int> &perm, vector<vector<int>>& requirements){
        // Loop through all the requirements.
        for(auto &req: requirements){
            int index = req[0];
            int inv = req[1]; // The current perm must have `inv` number of inversions.
            vector<int> v1(index+1);
            for(int j=0;j<=index;j++){
                v1[j] = perm[j];
            }
            if(!hasInv(v1,inv)) return false;
        }
        return true;
    }
    
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        // We can check for each permutation if the condition satisfies.
        int count=0;
        vector<int> perm(n);
        iota(perm.begin(),perm.end(),0);
        do {
            if(checkFun(perm, requirements) == true){
                count = (count + 1)%MOD;
            }
        } while(next_permutation(perm.begin(),perm.end()));
        return count;
    }
    
    // The above solution works but give TLE after 250 test case. Needs optmization.
};

int main() {
    vector<vector<int>> requirements = {{2,2},{0,0}};
    int n=3;
    Solution sol;
    int ans = sol.numberOfPermutations(n, requirements);
    cout<<ans;
    return 0;

}
