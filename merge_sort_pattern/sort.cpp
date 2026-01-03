#include<bits/stdc++.h>
using namespace std;

int main() {
   vector<int> v1 = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};  
   sort(v1.begin(), v1.end());
   for(auto it:v1){
   	cout<<it<<" ";
   }
   return 0; 
}
