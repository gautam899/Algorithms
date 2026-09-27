#include <iostream>

class Node
{
public:
    int val;
    Node *left = nullptr;
    Node *right = nullptr;
    Node *parent = nullptr;

    Node() = default;

    Node(int _val) : val(_val) {};

    Node(int _val, Node *_left, Node *_right, Node *_parent) : val(_val), left(_left), right(_right), parent(_parent) {};
};

class Codec
{
public:
    Node *leftMost(Node *node)
    {
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }
    Node *inorderSuccessor(Node *node)
    {
        if (!node)
            return nullptr;

        if (node->right)
        {
            return leftMode(node->right);
        }

        Node *y = node->parent;
        while (node == y->right)
        {
            node = y;
            y = y->parent;
        }
        return y;
    }
};

int main()
{
    Node *node1 = new Node(2);
    Node *node2 = new Node(4);
    Node *node3 = new Node(6);
    // Node *node4 = new Node(8);
    Node *node5 = new Node(11);
    Node *node6 = new Node(13);

    Node *node7 = new Node(3, node1, nullptr, nullptr);
    Node *node8 = new Node(7, node3, nullptr, nullptr);
    Node *node9 = new Node(12, node5, node6, nullptr);

    node1->parent = node7;
    node2->parent = node7;

    node3->parent = node8;
    // node4->parent = node8;

    node5->parent = node9;
    node6->parent = node9;

    Node *node10 = new Node(5, node7, node8, nullptr);
    Node *node11 = new Node(10, node10, node9, nullptr);

    node7->parent = node10;
    node8->parent = node10;

    node10->parent = node11;
    node9->parent = node11;

    Node *root = node11;
    Codec code;
    Node *ans = code.inorderSuccessor(node11);
    std::cout << ans->val << std::endl;
    return 0;
}
