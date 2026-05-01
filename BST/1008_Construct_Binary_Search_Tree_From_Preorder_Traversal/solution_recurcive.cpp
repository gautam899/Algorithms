#include <iostream>
#include <vector>
#include <stack>

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {};
};

class Solution
{
public:
    TreeNode *helper(int start, int end, std::vector<int> &preorder, std::vector<int> &_nextGreater)
    {
        if (start > end)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[start]);
        int ng = _nextGreater[start];

        // If the ng is -1, then the left child space extends from the start+1, to end. and not right child.
        root->left = (ng == -1) ? helper(start + 1, end, preorder, _nextGreater) : helper(start + 1, ng - 1, preorder, _nextGreater);
        root->right = (ng == -1) ? nullptr : helper(ng, end, preorder, _nextGreater);
        return root;
    }
    TreeNode *bstFromPreorder(std::vector<int> &preorder)
    {
        int n = preorder.size();
        std::stack<int> st;
        std::vector<int> _nextGreater(n, -1);
        for (int i = 0; i < n; i++)
        {
            int curr = preorder[i];
            while (!st.empty() && preorder[st.top()] < curr)
            {
                _nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for (auto it : _nextGreater)
        {
            std::cout << it << " ";
        }
        std::cout << "\n";
        return helper(0, n - 1, preorder, _nextGreater);
    }
};

int main()
{
    std::vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution sol;
    TreeNode *root = sol.bstFromPreorder(preorder);
    return 0;
}