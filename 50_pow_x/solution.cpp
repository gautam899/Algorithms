#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long n_2 = n;
        if(n_2 < 0){
            n_2 *= -1; // Turn the power positive for our own convinience.
        }
        while(n_2 != 0) {
            // If the power is even
            if(n_2 % 2 == 0) {
                x = x*x;
                n_2 /= 2;
            } else {
                // odd power
                ans = ans*x;
                n_2 -= 1;
            }
        }
        if(n<0) {
            ans = 1.0/ans;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    double x = 2.0;
    int n = -10;
    double ans = sol.myPow(x, n);
    cout << ans;
    return 0;
}
