#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    // Constructor for root node.
    TreeNode(int val = 0, TreeNode *parent = nullptr) : val(val), left(nullptr), right(nullptr), parent(parent) {};
    // For non-leaf node.
    TreeNode(int val, TreeNode *left, TreeNode *right, TreeNode *parent) : val(val), left(left), right(right), parent(parent) {};
};

class Operations
{
public:
    // We can use the property of BST that inorder traversal of a BST is always sorted.
    // While traversing inorder keep track of the inorder predecessor and make sure that
    // curr node->val is not smaller than the inorder predecessor.
    TreeNode *prev = nullptr;
    bool _validate_BST(TreeNode *root)
    {
        std::stack<TreeNode *> st;
        while (root || !st.empty())
        {
            // Keep moving to the left.
            while (root->left)
            {
                st.push(root);
                root = root->left;
            }
            // If no left child. The curr node in the inorder traversal is at the stack top.
            root = st.top();
            st.pop();
            // Compare the value with the last visited node(inorder predecessor)
            if (prev && prev->val >= root->val)
                return false;
            prev = root;
            root = root->right;
        }
        // Time complexity: O(N), every node is visited once.
        // Space Complexity: O(N), worst case for skewed tree. For a balanced tree,
        // that would be O(logN) which is the height of the tree.
    }
};

int main()
{
    Operations op;

    TreeNode *node1 = new TreeNode(8, nullptr);
    TreeNode *node2 = new TreeNode(3, nullptr, nullptr, node1);
    TreeNode *node3 = new TreeNode(10, nullptr, nullptr, node1);
    TreeNode *node4 = new TreeNode(1, nullptr, nullptr, node2);
    TreeNode *node5 = new TreeNode(6, nullptr, nullptr, node2);
    TreeNode *node6 = new TreeNode(14, nullptr, nullptr, node3);
    TreeNode *node7 = new TreeNode(4, nullptr, nullptr, node5);
    TreeNode *node8 = new TreeNode(7, nullptr, nullptr, node5);
    TreeNode *node9 = new TreeNode(13, nullptr, nullptr, node6);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node5->left = node7;
    node5->right = node8;
    node3->right = node6;
    node6->left = node9;

    bool ans = op._validate_BST(node1);
    return 0;
}