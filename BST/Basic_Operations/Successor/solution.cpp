#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    // Constructor for root node.
    TreeNode(int val = 0, TreeNode *parent = nullptr) : val(val), left(nullptr), right(nullptr), parent(parent) {};
    // For non-root node.
    TreeNode(int val, TreeNode *left, TreeNode *right, TreeNode *parent) : val(val), left(left), right(right), parent(parent) {};
};

class Operations
{
public:
    // BST successor/inorder-successor is the smallest key larger than the root->val.
    TreeNode *_successor(TreeNode *node)
    {
        // If the root has a right, the BST successor will be the left most node of the right subtree.
        if (node->right)
        {
            return BST_minimum(node->right);
        }

        // If the right is null then keep propogating upward and we only stop when the node is the left child of the parent.
        // This is because the subtree the node is a part of, must be the left subtree of the inorder/BST successor.
        TreeNode *y = node->parent;
        while (y && node == y->right)
        {
            node = y;
            y = y->parent;
        }
        return y;
    }

    TreeNode *BST_minimum(TreeNode *root)
    {
        // We wish to find the left most node in the tree.
        while (root->left)
        {
            root = root->left;
        }
        return root;
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
    TreeNode *ans = op._successor(node8);
    std::cout << ans->val << "\n";
    return 0;
}
