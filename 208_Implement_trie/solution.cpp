class Trie {
public:
    struct Node {
        vector<Node*> children;
        bool isEndOfWord; // If the node is the end of the word.

        Node() {
            children = vector<Node*>(26, nullptr);
            isEndOfWord = false;
        }
    };

    Node* root;
    Trie() {
        root = new Node(); // Initialize the trie.
    }

    void insert(string word) {
        Node* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->children[word[i] - 'a'] == nullptr) {
                temp->children[word[i] - 'a'] = new Node();
            }
            temp = temp->children[word[i] - 'a'];
        }
        temp->isEndOfWord = true;
    }

    bool search(string word) {
        Node* temp = root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->children[word[i] - 'a'] == nullptr) {
                return false; // The string does not exist
            }
            temp = temp->children[word[i] - 'a'];
        }
        return temp->isEndOfWord;
    }

    bool startsWith(string prefix) {
        Node* temp = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (temp->children[prefix[i] - 'a'] == nullptr) {
                return false; // The string 'prefix' does not exist as prefix
            }
            temp = temp->children[prefix[i] - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
