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

// The brute-force approach is to use the property of the BST that the inorder traversal of a BST is sorted.
// We can perform a inorder traversal and sort the traversed vector and compare it the original traverse.
class Operations
{
public:
    void traverse_inorder(TreeNode *root, std::vector<int> &v)
    {
        if (!root)
            return;
        traverse_inorder(root->left, v);
        v.push_back(root->val);
        traverse_inorder(root->right, v);
    }
    bool _validate_BST(TreeNode *root)
    {
        std::vector<int> v;
        traverse_inorder(root, v);
        // Another property we must keep in mind is to make sure that the left child and the
        // right child are strictly smaller and greater that root value respectively.
        for (int i = 0; i < v.size(); i++)
        {
            if (i > 0 && v[i] == v[i - 1])
            {
                return false;
            }
        }
        std::vector<int> v1 = v;
        std::sort(v1.begin(), v1.end());
        return v1 == v;
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