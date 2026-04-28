#include <iostream>
#include <queue>
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/*
                  1 -> nullptr
               /    \
            2 ------> 3 -> nullptr
           /  \      /   \
        4---->5-->6----->7 -> nullptr
*/
class Solution
{
public:
    Node *populate(Node *root)
    {
        if (!root)
            return nullptr;
        Node *levelStart = root;
        while (levelStart->left)
        {
            Node *curr = levelStart;
            // Traverse the current level and make the connections for the next pointer for the next level.
            while (curr)
            {
                curr->left->next = curr->right;
                // If curr is not the last node of the level.
                if (curr->next)
                {
                    curr->right->next = curr->next->left;
                }
                curr = curr->next;
            }
            // Move to the next level.
            levelStart = levelStart->left;
        }
        return root;
    }
};

int main()
{
    Node *node1 = new Node(4);
    Node *node2 = new Node(5);
    Node *node3 = new Node(6);
    Node *node4 = new Node(7);
    Node *node5 = new Node(2, node1, node2, nullptr);
    Node *node6 = new Node(2, node3, node4, nullptr);
    Node *node7 = new Node(1, node5, node6, nullptr);
    Solution sol;
    Node *ans = sol.populate(node7);
    return 0;
}

// Time complexity: Every Node here is visited once and constant time operation is peformed on it.
// Hence the time complexity is O(N).
// Space Complexity: O(1). We are not using any extra space.