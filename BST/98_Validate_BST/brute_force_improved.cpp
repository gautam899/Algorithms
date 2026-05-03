#include <iostream>
#include <vector>
#include <algorithm>

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
    bool helper(TreeNode *root)
    {
        if (!root)
            return true;

        if (!helper(root->left))
            return false;
        // Compare the root->val with the inorder predecessor.
        if (prev && prev->val >= root->val)
            return false;
        prev = root;
        if (!helper(root->right))
            return false;
        return true;
    }
    bool _validate_BST(TreeNode *root)
    {
        return helper(root);
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