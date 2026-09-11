#include <iostream>
#include <vector>
#include <string>
#include <sstream>
class Solution
{
public:
    /*
        The approach that we will be using here is to process the leaf nodes and once a leaf node is processed, we replace it with a # / nullptr.
        The first thing we do is use stringstream and getline function to store all the comma seperated element into a vector and then simulate a stack with a vector. Every time we see a number followed by two #, that is leaf node. We process this leaf node and replace it with a #. At the end if we only have one # left, that means this is a valid tree pre-order.
    */
    bool isValidSerialization(std::string preorder)
    {
        std::vector<std::string> element;
        std::stringstream ss(preorder);
        while (ss.good())
        {
            std::string substr;
            getline(ss, substr, ',');
            element.push_back(substr);
        }

        std::vector<std::string> st;
        for (const std::string &s : element)
        {
            st.push_back(s);
            while (st.size() >= 3 && st.back() == "#" && *(st.rbegin() + 1) == "#" && *(st.rbegin() + 2) != "#")
            {
                st.pop_back();
                st.pop_back();
                st.pop_back();
                st.push_back("#");
            }
        }
        return st.size() == 1 && st.back() == "#";
    }
};
int main()
{
    return 0;
}