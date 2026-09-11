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

class Solution
{
public:
    Node *populate(Node *root)
    {
        if (!root)
            return nullptr;
        std::queue<Node *> q;
        q.push(root);
        Node *prev = nullptr;
        while (!q.empty())
        {
            int size = q.size();
            prev = nullptr;
            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();
                if (prev)
                {
                    prev->next = curr;
                }
                prev = curr;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
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
// Space Complexity: O(N) worst case