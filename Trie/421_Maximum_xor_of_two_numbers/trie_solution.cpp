#include <iostream>
#include <vector>
#include <algorithm>

class Node
{
public:
    std::vector<Node *> link = std::vector<Node *>(2, nullptr);

    // Check if the bit path exist in the trie
    bool containsKey(int bit)
    {
        return link[bit] != nullptr;
    }

    // Get the child node for the bit
    Node *get(int bit)
    {
        return link[bit];
    }

    // Create a link for the bit
    void put(int bit, Node *node)
    {
        link[bit] = node;
    }
};

class Solution
{
public:
    Node *root;
    Solution()
    {
        root = new Node();
    }
    // Insert a number into the trie
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    // Find maxXor for a given number
    int getMaxXor(int num)
    {
        int maxXor = 0;
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            // Go to the opposit bit to maximize the xor
            if (node->containsKey(1 - bit))
            {
                maxXor |= (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxXor;
    }
};

int main()
{
    Solution sol;

    return 0;
}