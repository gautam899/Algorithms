#include <iostream>
#include <vector>
#include <unordered_map>

class Node
{
public:
    int val;
    std::vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = std::vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = std::vector<Node *>();
    }

    Node(int _val, std::vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    void dfs(Node *node, Node *clonedNode, std::unordered_map<int, Node *> &mp)
    {
        if (!node)
            return;

        mp[node->val] = clonedNode; // Create a mapping of the original node with it's clone.

        for (auto it : node->neighbors)
        {
            // If the clone of the neighbor 'it' already exist, then add it to the neighbors list for the
            // clone of node.
            if (mp.find(it->val) != mp.end())
            {
                clonedNode->neighbors.push_back(mp[it->val]);
            }
            else
            {
                // Create a clone of the neighbor and add it to the nigh
                Node *newNode = new Node(it->val);
                clonedNode->neighbors.push_back(newNode);
                dfs(it, newNode, mp);
            }
        }
    }
    Node *__cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        std::unordered_map<int, Node *> mp;
        Node *head = new Node(node->val);
        dfs(node, head, mp);
    }
};

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    // Adjacency list
    node1->neighbors = {node2, node4, node5};
    node2->neighbors = {node1, node5, node3};
    node3->neighbors = {node2, node4, node5};
    node4->neighbors = {node1, node3, node5};
    node5->neighbors = {node1, node2, node3, node4};

    Node *head = node1;
    Solution sol;
    Node *newHead = sol.__cloneGraph(head);
    return 0;
}