#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Solution
{
public:
    /*
        Another approach is to consider slots. Every node takes one slots(decrement) and if
        it's non-null node, it introduces two more slots i.e. its' children.
        If a valid binary tree pre-order, the number of slots remaining at the end must be zero.
    */
    bool isValidSerialization(std::string preorder)
    {
        int slots = 1;
        std::stringstream ss(preorder);
        while (ss.good())
        {
            std::string substr;
            std::getline(ss, substr, ',');
            slots--;
            if (slots < 0)
                return false;
            if (substr != "#") // If it's non-null node, it will introduce two more slots for the children node.
                slots += 2;
        }
        return slots == 0;
    }

    // Time Complexity: O(N), N is the number of nodes.
};
int main()
{
    return 0;
}