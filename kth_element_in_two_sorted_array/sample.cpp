#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>
int main(){
    std::vector<int> v = {10,20,30,30,20,10,10,20};
    std::sort(v.begin(),v.end());
    std::vector<int>::iterator up = std::upper_bound(v.begin(), v.end(), 20);
    std::cout<<"Upper bound: " << (up-v.begin()) << "\n";
    return 0;
}
