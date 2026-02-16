class LFUCache {
public:
    class freqNode {
    public:
        int value; // freq count
        freqNode* prev = NULL;
        freqNode* next = NULL;
        list<int> keys; // Keep a list of key. Allows O(1 removal and insertion)
        freqNode(int _val, freqNode* _prev, freqNode* _next) {
            this->value = _val;
            this->prev = _prev;
            this->next = _next;
        }
    };

    class elementNode {
    public:
        int value;
        freqNode* parent;
        list<int>::iterator it; // Iterator pointing to it's current position in the freq list.
        elementNode(int _val, freqNode* _freq) {
            this->value = _val;
            this->parent = _freq;
        }
    };

    unordered_map<int, elementNode*> mp;
    freqNode* head = new freqNode(-1, NULL, NULL);
    freqNode* tail = new freqNode(-1, NULL, NULL);
    int cap;
    LFUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // void addToFreqNode(freqNode* freq, int key, elementNode* node);
    // void removeFromFreqNode(freqNode* freq, elementNode* node);
    // freqNode* newFreqNode(int value, freqNode* prev, freqNode* next);
    // int getLRU(freqNode* freq);
    // void deleteNode(freqNode* node); // Delete a freqNode.
    // void deleteLRU(freqNode* freq); // Delete a LRU 

    // A a new key in the list(key) of freq node
    void addToFreqNode(freqNode* freq, int key, elementNode* node){
        freq->keys.push_front(key); // Most recently used
        node->it = freq->keys.begin(); // store the iterator.
        node->parent = freq;
    }

    // Remove the key from the freqNode list
    void removeFromFreqNode(freqNode* freq, elementNode* node){
        freq->keys.erase(node->it); // Just erase the iterator
    }

    // A new freq Node
    freqNode* newFreqNode(int value, freqNode* prev, freqNode* next) {
        freqNode* node = new freqNode(value, prev, next);
        return node;
    }

    // In case we wish to remove the LRU from a freq list(keys)
    int getLRU(freqNode* freq){
        return freq->keys.back(); // LRU at the back and MRU at the front.
    }

    // Delete a freqNode node
    void deleteNode(freqNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    // Remove the LRU
    void deleteLRU(freqNode* freq){
        freq->keys.pop_back();
    }

    int get(int key) {
        // If the key does not exist.
        if (mp.find(key) == mp.end())
            return -1;

        elementNode* node = mp[key];
        int temp = node->value;
        freqNode* freq = node->parent;
        freqNode* next_freq = freq->next; // Next freq node of the parent.

        // If the next freq do not exist or is not equal to freq.val+1 then we
        // create a new node.
        if (next_freq == tail || next_freq->value != freq->value + 1) {
            next_freq = new freqNode(freq->value + 1, freq, next_freq);
            freq->next->prev = next_freq;
            freq->next = next_freq;
        }
        // Remove the from old freq list and then add to new. Revering the order can lead to access to invalid memory.

        // Remove the node entry from the key_list of the freq node.
        removeFromFreqNode(freq,node);

        // add the key in the next freq list.
        addToFreqNode(next_freq, key, node);

        // If the list of nodes have freq as freq->value is zero delete the freq node itself.
        if (freq->keys.size() == 0) {
            deleteNode(freq);
        }
        return temp;
    }

    void put(int key, int value) {
        // Case 1: Cap is 0
        if(cap == 0)return;

        // Case 2: Key exist->value and call get(key) 
        if (mp.find(key) != mp.end()) {
            // 1. Update the value
            // 2. Call get to update the freq stuff.
            elementNode* node = mp[key];
            node->value = value;
            get(key); // Update 
            return;
        } else if (mp.size() == cap) {
            // 1. Remove the LRU from the min_freq list. If the list becomes empty then remove the freq Node.
            // 2. Remove the entry for the key from the map
            // 3. If the list becomes empty then remove the freq node.
            // ****

            // 1. 
            freqNode* minFreq = head->next;
            int delKey = getLRU(minFreq);
            elementNode* delNode = mp[delKey];

            deleteLRU(minFreq); 
            // 2.
            mp.erase(delKey);
            delete delNode; // Prevent Memory leak
            // 3.
            if(minFreq->keys.empty()){
                deleteNode(minFreq);
            }
        }

        // Check if a freqNode with value one exist. If not then add one just
        freqNode* freq = head->next;
        if (freq == tail || freq->value != 1) {
            // 1. Add a freqNode with value 1 between head and head->next
            // 2. Add a new element node this new freqNode's list
            // 3. Create a corresponding entry in the map
            // ****
            freq = new freqNode(1, head,
                                head->next);
            head->next->prev = freq;
            head->next = freq;
            
            elementNode* node = new elementNode(value, freq);
            addToFreqNode(freq, key, node);
            
            mp[key] = node;
        } else {
            // Just add a new node.
            elementNode* node = new elementNode(value, freq);
            addToFreqNode(freq, key, node);
            mp[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
