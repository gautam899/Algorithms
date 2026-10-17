#include <iostream>
#include <stack>
#include <vector>

class TreeNode
{
public:
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode()
    {
        val = 0;
    }

    TreeNode(int _val)
    {
        val = _val;
    }

    TreeNode(int _val, TreeNode *_left, TreeNode *_right)
    {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Codec
{
public:
    TreeNode *maxBinaryTree(std::vector<int> &nums)
    {
        std::stack<TreeNode *> st;
        for (int i = 0; i < nums.size(); i++)
        {
            TreeNode *node = new TreeNode(nums[i]);
            TreeNode *last = nullptr;

            // Pop the smaller node.
            while (!st.empty() && st.top()->val < nums[i])
            {
                last = st.top();
                st.pop();
            }
            // The last node popped will the largest among all popped and will
            // be the left child of the current node. The last popped node will the largest b/w the current node and the st.top right now.
            node->left = last;

            // The current node will be the stack top's right child.
            if (!st.empty())
            {
                st.top()->right = node;
            }

            st.push(node);
        }
	// Now at this point stack might not be empty. We want to have the last node in the stack as that would be the max value node.
        TreeNode *ans = nullptr;
        while (!st.empty())
        {
            ans = st.top();
            st.pop();
        }
        return ans;
    }
};
int main()
{
    return 0;
}
