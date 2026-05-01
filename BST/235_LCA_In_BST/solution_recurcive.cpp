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
    Node *helper(Node *root, Node *p, Node *q)
    {
        if ((p->val < root->val) && (q->val < root->val))
        {
            return helper(root->left, p, q);
        }
        else if ((p->val > root->val) && (q->val > root->val))
        {
            return helper(root->right, p, q);
        }
        else
        {
            return root;
        }
        return nullptr;
    }
    Node *_LCA_Recurcive(Node *root, Node *p, Node *q)
    {
        if (!root)
            return nullptr;
        return helper(root, p, q);
    }
};

int main()
{
    Node *node1 = new Node(4);
    Node *node2 = new Node(5);
    Node *node3 = new Node(6);
    Node *node4 = new Node(7);
    Node *node5 = new Node(2, node1, node2);
    Node *node6 = new Node(3, node3, node4);
    Node *node7 = new Node(1, node5, node6);
    Solution sol;
    Node *ans = sol._LCA_Recurcive(node7, node5, node6);
    std::cout << ans->val << "\n";
    return 0;
}