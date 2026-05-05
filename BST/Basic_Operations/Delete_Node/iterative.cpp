/*
    Deleting a node in a BST using iterative approach includes pointer manipulation
    Deletion of node in BST has 3 cases:
    1. If Z is a leaf node, it is replaced by nullptr
    2. If Z has only one child, the child node of Z gets elevated by modifying the parent node
       of Z to point to the child node, consequently taking Z's position in the tree.
    3. If Z has both left and right children, the in-order successor of Z, say Y, displaces Z by following two cases.
        1. If Y is Z's right child, Y displaces Z and Y's right child remain unchanged
        2. If Y lies in the right subtree but it's not Z's right child,, Y first gets displaced by it's own
           right child, then it displaces Z's position in the tree.
*/

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
    TreeNode *BST_successor(TreeNode *node)
    {
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }

    TreeNode *helper(TreeNode *root, TreeNode *node)
    {
        // If the node to be deleted has 0 or 1 children
        if (!node->left)
        {
            root = _shift_node(root, node, node->right); // O(1)
        }
        else if (!node->right)
        {
            root = _shift_node(root, node, node->left); // O(1)
        }
        else
        {
            // If the node has two children
            // Two Cases:
            // 1. If the BST successor(Y) is immidiate right child of the node to be delete(Z). Y displaces
            //  Z, and Y's right child remains unchanged.
            // 2. If Y lies in the right subtree of node to be deleted(Z), but not an immediate right child of Z, then first Y is displaced with its'
            // right child, and then Y displaces Z.
            TreeNode *succ = BST_successor(node->right); // O(H)
            if (succ->parent != node)
            {
                // Replace succ with successor's right node
                root = _shift_node(root, succ, succ->right);
                // At this point succ's right is still pointing at it's original right.
                // Rewire it, the succ's right pointer now points to Z's(node to be deleted) right pointer. And successor's(Y) right's parent
                // is now updated to be successor(Y) itself.
                succ->right = node->right;
                succ->right->parent = succ;
            }
            // The below peice of code remains comman for both the two cases when Z has two children.
            // In case when the BST successor is the direct right child of Z, the "if" block above does not get excecuted, but in the second case
            // when the successor(Z) has been displaced by its' right child, now we displace Z with the successor.
            root = _shift_node(root, node, succ);
            succ->left = node->left;
            succ->left->parent = succ;
        }
        node->left = nullptr;
        node->right = nullptr;
        node->parent = nullptr;
        // std::cout << "New root: " << root->val << "\n";
        return root;

        // Upon dry run it is observed that the removed node is still in the memory and still points to its left, right and parent. The point
        // is the algorithm guarantees that there no node in the tree pointing to the deleted node anymore. The delete node might exist in the
        // memory still but that is not the purpose of the algorithm.
    }

    // Function to replace node u with node v
    TreeNode *_shift_node(TreeNode *root, TreeNode *u, TreeNode *v) // O(1)
    {
        if (u->parent == nullptr)
        {
            root = v;
        }
        else if (u == u->parent->left)
        {
            u->parent->left = v;
        }
        else
        {
            u->parent->right = v;
        }
        if (v)
        {
            v->parent = u->parent;
        }
        // std::cout << "Root: " << root->val << "\n";
        return root;
        // delete (u);
    }

    // Search the node associated with the key
    TreeNode *search(TreeNode *node, int key) // O(logN)
    {
        while (node && node->val != key)
        {
            if (key < node->val)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        return node;
    }

    TreeNode *_deleteNode(TreeNode *root, int key)
    {
        TreeNode *node = search(root, key);
        if (!node)
        {
            std::cout << "Key not found\n";
            exit(1);
        }
        return helper(root, node);
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
    std::cout << "\n";
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
    TreeNode *root = node1;
    print_inorder(root);
    root = op._deleteNode(root, 8);
    print_inorder(root);
    return 0;

    // Overall time complexity is O(H) or O(LogN), balanced tree.
    // For skewed tree O(N)
}