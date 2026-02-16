#include<unordered_map>

class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    // Create a Head and a tail
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    // Function to add node in front of head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    // Delete a node.
    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    int get(int key) {
        int temp = -1;
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            temp = node->val;
            deleteNode(node); // remove the node from its position.
            addNode(node);    // Add to the front. Most recently used
        }
        return temp;
    }

    void put(int key, int value) {
        // If the key exist then we just update the value and move the node to
        // the front i.e next to the head
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            temp->val = value;
            deleteNode(temp);
            addNode(temp);
        } else {
            Node* node = new Node(key, value);
            // Check for capacity
            if (mp.size() == cap) {
                // Remove the least recently used node and add the latest.
                mp.erase(tail->prev->key); // erase the entry from the map.
                deleteNode(tail->prev);
                addNode(node);
            } else {
                addNode(node);
            }
            // Add an entry for unordered_map.
            mp[node->key] = node;
        }
    }
};

int main() {

}
