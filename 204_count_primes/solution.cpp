class Solution {
public:
    int countPrimes(int n) {
        // Seive of eratosthenes.
        if(n==0)return 0;
        vector<int> pool(n+1,0);
        int count = 0;
        for(int i=2;i<=n;i++){
            if(pool[i] == 1){
                continue; // Not a prime
            }
            if(pool[i] == 0){
                // It is a prime
                (i != n ) ? count++ : 0;
                if(i<=sqrt(n)){
                    // Mark all the multiples of i as true in pool.
                    int x = 2;
                    int temp = i;
                    while(temp*x < n){
                        pool[temp*x] = 1;
                        x++;
                    }
                }
            }
        }
        // If the size of the prime vector is not zero and 
        return count;
    }
};
