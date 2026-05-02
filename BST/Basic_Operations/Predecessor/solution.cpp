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
    // Predecessor is the largest key smaller than the root->val. When we say smaller, that means on the left.
    TreeNode *_predecessor(TreeNode *node)
    {
        if (node->left)
        {
            return BST_maximum(node->left);
        }

        // If there is no left, we keep propogating upward and only stop when the node is the right child of it's parent.
        // This is because, the subtree the node is a part of must be the right subtree of the node's inorder predecessor.
        TreeNode *y = node->parent;
        while (y && node == y->left)
        {
            node = y;
            y = y->parent;
        }
        return y;
    }

    TreeNode *BST_maximum(TreeNode *root)
    {
        // We wish to find the right most node of the tree.
        while (root->right)
        {
            root = root->right;
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
    TreeNode *ans = op._predecessor(node8);
    std::cout << ans->val << "\n";
    return 0;
}
