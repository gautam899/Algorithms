#include <iostream>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(nullptr), right(nullptr) {};
};

class Solution
{
public:
    bool helper(TreeNode *root)
    {
        std::stack<TreeNode *> st;
        if (root->left)
        {
            if (!root->right) // If the left is not null but right is.
                return false;
            st.push(root->left);
            st.push(root->right);
        }
        else if (root->right) // If the left is null and right is not null.
        {
            return false;
        }

        while (!st.empty())
        {
            TreeNode *left = st.top();
            st.pop();
            TreeNode *right = st.top();
            st.pop();
            if (left->val != right->val)
                return false;

            if (left->left)
            {
                if (!right->right)
                    return false;
                st.push(left->left);
                st.push(right->right);
            }
            else if (right->right)
            {
                return false;
            }

            if (left->right)
            {
                if (!right->left)
                    return false;
                st.push(left->right);
                st.push(right->left);
            }
            else if (right->left)
            {
                return false;
            }
        }
        return true;
    }
    bool isSymmetric(TreeNode *root)
    {
        return root == NULL || helper(root);

        return true;
    }
};

int main()
{
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(4);
    TreeNode *node4 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(2, node1, node2);
    TreeNode *node6 = new TreeNode(2, node3, node4);
    TreeNode *node7 = new TreeNode(1, node5, node6);
    Solution sol;
    bool ans = sol.isSymmetric(node7);
    std::cout << ans << "\n";
    return 0;
    // Time complexity: Every node is visited once and upon every node we perform constant operation.
    // Hence time complexity is O(N), where N is the number of nodes.
    // Space complexity: We are using a stack data structure which in worst case keep N nodes incase of skew tree.
}