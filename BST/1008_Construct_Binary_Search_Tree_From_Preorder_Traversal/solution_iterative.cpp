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
    // In this approach, unlike the recurcive one, where I pre-evaluated the nextGreater vector, here we do this on the go
    // and parallelly make the connections.
    TreeNode *_bstFromPreorderIterative(std::vector<int> &preorder)
    {
        int n = preorder.size();
        if (n == 0)
            return nullptr;
        std::stack<TreeNode *> st;
        TreeNode *root = new TreeNode(preorder[0]);
        st.push(root); // Start with the root.
        for (int i = 1; i < n; i++)
        {
            TreeNode *node = new TreeNode(preorder[i]);
            // The node->val or preorder[i] is less than the st.top()->val then the node is the left child of the
            // st.top().
            if (preorder[i] < st.top()->val)
            {
                st.top()->left = node;
            }
            else // If the curr node val is greater than the st.top() val, then the st.top() could be a possible parent
            // So keep popping until the st.top is smaller than curr. And while we do that update the parent.
            {
                TreeNode *parent = nullptr;
                while (!st.empty() && st.top()->val < preorder[i])
                {
                    parent = st.top();
                    st.pop();
                }
                // Parent's right node will the current node.
                parent->right = node;
            }
            // Push the node.
            st.push(node);
        }
        return root;
    }
    void print_preorder(TreeNode *root)
    {
        if (!root)
            return;
        std::cout << root->val;
        print_preorder(root->left);
        print_preorder(root->right);
    }
};
int main()
{
    std::vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution sol;
    TreeNode *root = sol._bstFromPreorderIterative(preorder);

    // Print the preorder to verify.
    sol.print_preorder(root);
    return 0;
}