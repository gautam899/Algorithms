#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>

class Solution
{
public:
    bool isPreorderValid(std::vector<int> &preorder)
    {
        int lb = INT_MIN; // Lower Bound

        std::stack<int> st;

        for (const auto &it : preorder)
        {
            // If the number is less than the lower bound, return false.
            if (it < lb)
            {
                return false;
            }

            // Check if this node takes us into a right subtree. If yes, what is the parent.
            while (!st.empty() && st.top() < it)
            {
                lb = st.top();
                st.pop();
            }

            st.push(it);
        }
        return true;
    }
};

int main()
{
}