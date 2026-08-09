#include <iostream>
#include <vector>

class Trie
{
public:
    struct Node
    {
        std::vector<Node *> child;
        bool isEndOfWord;

        Node()
        {
            child = std::vector<Node *>(26, nullptr);
            isEndOfWord = false;
        }
    };
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(const std::string &word)
    {
        Node *temp = root;
        for (const char &ch : word)
        {
            int ind = ch - 'a';
            if (temp->child[ind] == nullptr)
            {
                temp->child[ind] = new Node();
            }
            temp = temp->child[ind];
        }
        temp->isEndOfWord = true;
    }

    bool allPrefixExist(const std::string &word)
    {
        Node *temp = root;
        for (const char &ch : word)
        {
            int ind = ch - 'a';
            temp = temp->child[ind];
            if (!temp || !temp->isEndOfWord)
            {
                return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    std::string long_word_with_all_prefix(const std::vector<std::string> &words)
    {
        Trie *t = new Trie();
        // Insert all the words from the vector into the trie
        for (const std::string &word : words)
        {
            t->insert(word);
        }

        std::string ans = "";
        for (const std::string &word : words)
        {
            if (t->allPrefixExist(word))
            {
                if (word.size() > ans.size() || (ans.size() == word.size() && word < ans))
                {
                    ans = word;
                }
            }
        }
        return ans;
    }
};
int main()
{
    // "xkvu" ,"xkd" ,"l" ,"xkv" ,"xkvuu" ,"xj" ,"xk" ,"xkvn" ,"xkvug" ,"x"
    std::vector<std::string> words = {"xkvu", "xkd", "l", "xkv", "xkvuu", "xj", "xk", "xkvn", "xkvug", "x"};
    Solution sol;
    std::string ans = sol.long_word_with_all_prefix(words);
    std::cout << ans << std::endl;
    // T.C: O(N*k) one pass for iteration, and one pass for prefix check. k is the average length of the word
    return 0;
}