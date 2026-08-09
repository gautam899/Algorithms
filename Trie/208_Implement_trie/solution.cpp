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

        Node()
        {
            children = std::vector<Node *>(26, nullptr);
            isEndOfWord = false;
        }
    };

    Node *root;
    Trie()
    {
        root = new Node(); // Initialize the trie.
    }

    void insert(std::string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->children[word[i] - 'a'] == nullptr)
            {
                temp->children[word[i] - 'a'] = new Node();
            }
            temp = temp->children[word[i] - 'a'];
        }
        temp->isEndOfWord = true;
    }

    bool search(std::string word)
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

    bool startsWith(std::string prefix)
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

    int helper(Node *temp)
    {
        int count = 0;
        if (temp->isEndOfWord)
            count++;
        for (int i = 0; i < 26; i++)
        {
            if (temp->children[i] != nullptr)
                count += helper(temp->children[i]);
        }
        // std::cout << "Returning " << count << std::endl;
        return count;
    }

    // Count the number of words that have the string "word" as there prefix
    int countWordStartingWith(std::string word)
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
        return helper(temp);
    }

    // Count the number of time the string "word" occurs in the trie. Note: Not just as a prefix but also as substrings
    int countWordsEqualTo(std::string word)
    {
        return 0;
    }
};

int main()
{
    /*["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]*/
    Trie *t = new Trie();
    t->insert("apple");
    t->insert("bantana");
    t->insert("app");
    t->insert("aban");
    bool param_1 = t->startsWith("ban");
    bool param_2 = t->search("bana");
    int param_3 = t->countWordStartingWith("a");
    std::cout << param_3 << std::endl;
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
