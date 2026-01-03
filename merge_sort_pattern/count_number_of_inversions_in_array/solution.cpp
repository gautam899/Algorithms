#include<bits/stdc++.h>
using namespace std;

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
int count_inv(vector<int> &arr, int l, int r)
{
   int res=0;
   if(l<r){
   	int mid = (r+l)/2;
	res+=count_inv(arr,l,mid);
	res+=count_inv(arr,mid+1,r);

	// Merge and count inv
	res+=merge_and_count(arr,l,mid,r);
   }
   return res;
}
int main() {
   vector<int> arr = {3,5,1,10,9,2,6,8};
   int n = arr.size();
   int ans = count_inv(arr,0,n-1);
   cout<<"The number of inversions in the array are: " << ans;
   return 0;
}
