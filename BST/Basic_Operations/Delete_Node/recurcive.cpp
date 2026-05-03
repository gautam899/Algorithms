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
    TreeNode *_find_successor(TreeNode *root)
    {
        while (root->left)
        {
            root = root->left;
        }
        return root;
    }
    TreeNode *_deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;

        if (key < root->val)
        {
            root->left = _deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = _deleteNode(root->right, key);
        }
        else
        {
            // Found the key.
            // For the key node having 0 or 1 children
            if (!root->left)
            {
                TreeNode *temp = root->right;
                delete (root);
                return temp;
            }

            if (!root->right)
            {
                TreeNode *temp = root->left;
                delete (root);
                return temp;
            }

            // If the node have two children. Find the inorder successor i.e smallest value larger than the root->val
            TreeNode *succ = _find_successor(root->right);
            // Replace the root->val with succ->val. Now we delete succ->val which will lie in either one of the above case.
            root->val = succ->val;
            root->right = _deleteNode(root->right, succ->val);
        }
        return root;
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
    TreeNode *ans = op._deleteNode(node1, 8);
    print_inorder(node1);
    std::cout << "\n";
    return 0;
}