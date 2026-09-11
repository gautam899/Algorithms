#include <iostream>

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {};
    Node(int val) : val(val), left(nullptr), right(nullptr) {};
    Node(int val, Node *left, Node *right) : val(val), left(left), right(right) {};
};

// The intution of solving this problem is to use the property of sorted order of BST.
// Unlike normal binary tree, where inorder to find the LCA we traverse both side of the root,
// here we can use the property that the every node->val in the left subtree is smaller than the root->val
// and every node in the right subtree has value larger that the root.
// Hence, if p and q are both smaller than root, the LCA lies in the left subtree and if p and q are both larger than
// than the root, the LCA lies in the right subtree.
// If p is smaller and q is larger or p is larger and q is smaller than the root, then the root is the LCA.
// Time complexity is O()
class Solution
{
public:
    Node *_LCA_Iterative(Node *root, Node *p, Node *q)
    {
        while (root)
        {

            if ((p->val < root->val) && (q->val < root->val))
            {
                root = root->left;
            }
            else if ((p->val > root->val) && (q->val > root->val))
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return nullptr;
    }
};

int main()
{
    Node *node1 = new Node(2);
    Node *node2 = new Node(4);
    Node *node3 = new Node(6);
    Node *node4 = new Node(9);
    Node *node5 = new Node(3, node1, node2);
    Node *node6 = new Node(8, node3, node4);
    Node *node7 = new Node(5, node5, node6);
    Solution sol;
    Node *ans = sol._LCA_Iterative(node7, node5, node6);
    std::cout << ans->val << "\n";
    return 0;
}