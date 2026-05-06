#include <iostream>
#include <stack>

struct TreeNode
{
    int val;
    int subtree_size = 0; // An extra field to keep count of number of node smaller than the current node.
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
    TreeNode *BST_Kth_Smaller(TreeNode *root, int k)
    {
        while (root)
        {
            // Evaluate the size of the
            int leftsize = (root->left) ? root->left->subtree_size : 0;
            if (k == leftsize + 1)
            {
                return root;
            }
            else if (k <= leftsize)
            {
                root = root->left;
            }
            else
            {
                k -= (leftsize + 1);
                root = root->right;
            }
        }
        return nullptr; // Not found, invalid k.
        // Time complexity of the above method of finding the kth smallest element in O(H) or O(LogN) in a balanced tree.
    }
};

// Because I have mannually created a tree, there is a need of a function to iterate the tree and update
// the size of the node. Otherwise this can be done on the go while inserting the nodes while creating the tree.
int compute_size(TreeNode *root)
{
    if (!root)
        return 0;

    int leftsize = compute_size(root->left);
    int rightsize = compute_size(root->right);

    root->subtree_size = 1 + leftsize + rightsize;
    return root->subtree_size;
}

/*
// Insert node: Alternate
TreeNode *prev = nullptr;
TreeNode *insert(TreeNode *root, int key)
{
    if (!root)
    {
        TreeNode *node = new TreeNode(key);
        node->parent = prev;
        if (!prev)
        {
            root = node;
        }
        else if (node->val < prev->val)
        {
            prev->left = node;
        }
        else
        {
            prev->right = node;
        }
    }
    prev = root;
    if (key < root->val)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }

    root->subtree_size = 1 +
                         ((root->left)
                              ? root->left->subtree_size
                              : 0) +
                         ((root->right)
                              ? root->right->subtree_size
                              : 0);
    return root;
}
*/
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

    TreeNode *root = node1;
    int final_size = compute_size(root);
    std::cout << final_size << "\n";
    TreeNode *ans = op.BST_Kth_Smaller(root, 3);
    (ans) ? std::cout << ans->val << " \n" : std::cout << "Not found\n";
    return 0;
}
