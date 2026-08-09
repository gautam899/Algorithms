#include <vector>
#include <string>
#include <iostream>

class Trie
{
public:
    struct Node
    {
        std::vector<Node *> children;
        bool isEndOfWord; // If the node is the end of the word.
        int prefixCount;

        Node()
        {
            children = std::vector<Node *>(26, nullptr);
            isEndOfWord = false;
            prefixCount = 0;
        }
    };

    Node *root;
    Trie()
    {
        root = new Node(); // Initialize the trie.
    }

    void insert(const std::string &word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->children[word[i] - 'a'] == nullptr)
            {
                temp->children[word[i] - 'a'] = new Node();
            }
            temp = temp->children[word[i] - 'a'];
            temp->prefixCount++;
        }
        temp->isEndOfWord = true;
    }

    bool search(const std::string &word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->children[word[i] - 'a'] == nullptr)
            {
                return false; // The string does not exist
            }
            temp = temp->children[word[i] - 'a'];
        }

        return temp->isEndOfWord;
    }

    bool startsWith(const std::string &prefix)
    {
        Node *temp = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (temp->children[prefix[i] - 'a'] == nullptr)
            {
                return false; // The string 'prefix' does not exist as prefix
            }
            temp = temp->children[prefix[i] - 'a'];
        }
        return true;
    }

    // Count the number of words that have the string "word" as there prefix
    /* The recursive approach is good if we evaluate only few times. But if the calculation is   being done more frequently, then it is better to add 1 more field in the node i.e. a prefix count. Every node carries a prefix count and that count will be incremented every time we insert a new word
    T.C: O(Length of Prefix)
     */
    int countWordStartingWith(const std::string &word)
    {
        Node *temp = root;

        // We need to find total EOW (End of Words) that we can find on this path
        for (int i = 0; i < word.size(); i++)
        {
            if (!temp->children[word[i] - 'a'])
            {
                return 0; // The whole word does not exist as a prefix
            }
            temp = temp->children[word[i] - 'a'];
        }
        // From the current position of temp find all possible EOW recursively
        return temp->prefixCount;
    }

    // Delete a word
    Node *delete_word(Node *temp, int index, const std::string &key, bool &deleted)
    {
        if (!temp) // If the Word doesn't exist in the trie
            return nullptr;
        else if (index == key.size())
        {
            if (!temp->isEndOfWord)
                return temp; // The word is not present

            temp->isEndOfWord = false;
            deleted = true;
        }
        else
        {
            int c = key[index] - 'a';
            temp->children[c] = delete_word(temp->children[c], index + 1, key, deleted);
        }

        if (deleted)
            temp->prefixCount--; // Prefix count must be delete only if the word is deleted.

        if (temp == root)
            return temp;

        // If the current node is end of some word, keep the node
        if (temp->isEndOfWord)
            return temp;
        for (int i = 0; i < 26; i++)
        {
            if (temp->children[i])
                return temp; // Has children. That means the word is prefix of some other word. Keep the node.
        }
        // If no children, remove the node by returning nullptr
        delete (temp);
        return nullptr;
    }
};

int main()
{
    Trie *t = new Trie();
    t->insert("apple");
    t->insert("app");

    int param_3 = t->countWordStartingWith("a");
    std::cout << param_3 << std::endl;

    bool deleted = false;
    t->delete_word(t->root, 0, "app", deleted);
    int param_4 = t->countWordStartingWith("a");
    std::cout << param_4 << std::endl;
}
