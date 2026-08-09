#include <vector>
#include <set>
#include <iostream>

class Solution
{
public:
    int findMaximumXOR(std::vector<int> &nums)
    {
        int maxi = 0;
        int mask = 0;
        // Why start from 31 ?. Because we want to maximize the most significant bit first. 1000 > 0111.
        for (int i = 31; i >= 0; i--) // O(32)-> constant
        {
            mask = mask | 1 << i;
            std::set<int> st;
            for (const int &num : nums) // O(N)
            {
                st.insert(mask & num); // Only the left part of num from ith bit. i.e the prefix bits.
            }

            int maxHopingFor = maxi | 1 << i; // If maxi was 11000, we would
                                              // want to add an extra i.e 11100.
            // a^b = c and a^c = b, we have our c as maxHoping for, and a as num
            // in st. if we have our b in the st, then we are good to go
            for (const int &num : st)
            {
                int b = maxHopingFor ^ num;
                if (st.find(b) != st.end())
                {
                    maxi = maxHopingFor; // This means there exist two nums in the vector whose prefixes xor to maximum that we want.
                    break;
                }
            }
        }
        return maxi;
    }
};

int main()
{
    std::vector<int> nums = {3, 10, 5, 25, 2, 8};
    Solution sol;
    int ans = sol.findMaximumXOR(nums);
    std::cout << ans << std::endl;
    return 0;
}