#include <iostream>
#include <stack>

struct TreeNode
{
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
    void preorder(TreeNode *root, std::stack<TreeNode *> &st)
    {
        if (!root)
            return;

        st.push(root);
        preorder(root->left, st);
        preorder(root->right, st);
        return;
    }
    void flatten(TreeNode *root)
    {
        std::stack<TreeNode *> st;
        preorder(root, st);
        TreeNode *prev = nullptr;
        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();
            curr->right = prev;
            curr->left = nullptr;
            prev = curr;
        }
    }
};

int main()
{
    // TODO: Create a Tree.
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(2, node1, node2);
    TreeNode *node4 = new TreeNode(6);
    TreeNode *node5 = new TreeNode(5, nullptr, node4);
    TreeNode *node6 = new TreeNode(1, node3, node5);
    TreeNode *root = node6;
    Solution sol;
    sol.flatten(root);
    while (root)
    {
        std::cout << root->val << " ";
        root = root->right;
    }
    std::cout << std::endl;
    return 0;
}
