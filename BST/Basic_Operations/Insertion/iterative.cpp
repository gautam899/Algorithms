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
    void BST_insert(TreeNode *root, int key)
    {
        TreeNode *y = nullptr;
        while (root)
        {
            y = root;
            if (key < root->val)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        // At this moments the root is at null and y point to the node next to which the new node
        // needs to be attached.
        TreeNode *new_node = new TreeNode(key);
        new_node->parent = y;
        if (!y)
        {
            root = new_node;
        }
        else if (new_node->val < y->val)
        {
            y->left = new_node;
        }
        else
        {
            y->right = new_node;
        }
    }
};

void print_inorder(TreeNode *root)
{
    if (!root)
        return;
    std::stack<TreeNode *> st;

    while (root || !st.empty())
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        std::cout << root->val << " ";
        root = root->right;
    }
}
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

    print_inorder(node1);
    std::cout << "\n";
    op.BST_insert(node1, 5);
    std::cout << "\n";
    print_inorder(node1);
    return 0;
    // Time complexity O(H). This is because we are only only going either left or right. In the worst case
    // We go from root to leaf which is the height of the tree.
    // Space complexity: Auxiliary stack space O(H). (extra or temporary memory space used by an algorithm during its execution)
}