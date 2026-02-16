class LFUCache {
public:
    long long timer = 0;
    class mapNode {
    public:
        int value;
        int freq;
        long long timestamp;
        mapNode(int _value, int _freq, long long _timestamp){
            this->value = _value;
            this->freq = _freq;
            this->timestamp = _timestamp;
        }
    };
    class heapNode {
    public:
        int freq;
        long long timestamp;
        int key;
        heapNode(int _f, long long _t, int _k){
            this->freq = _f;
            this->timestamp = _t;
            this->key = _k;
        }
    };
    struct compare {
        bool operator()(heapNode* a, heapNode* b) {
            if (a->freq == b->freq)
                return a->timestamp > b->timestamp;
            return a->freq > b->freq;
        }
    };
    unordered_map<int, mapNode*> mp;
    priority_queue<heapNode*, vector<heapNode*>, compare> minH;
    int cap;
    LFUCache(int capacity) { cap = capacity; }

    // Add a new entry in Heap.
    void AddInHeap(int key) {
        heapNode* node = new heapNode(mp[key]->freq, mp[key]->timestamp, key);
        minH.push(node);
    }

    void AddInMap(int key, int value) {
        // Create a new map node.
        mapNode* node = new mapNode(value, 1, timer++);
        mp[key] = node;
        AddInHeap(key);
    }

    // Update map. Increment the time and freq and add a new entry for the key
    // in the heap.
    void updateMap(int key) {
        mp[key]->freq++;
        mp[key]->timestamp = timer++;
        AddInHeap(key);
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        int val = mp[key]->value;
        updateMap(key);
        return val;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        // exist -> update
        if (mp.find(key) != mp.end()) {
            mp[key]->value = value;
            updateMap(key);
        } else if (mp.size() == cap) {
            // Evict the top of the heap and check if it matches the state for
            // that key in map
            while (!minH.empty()) {
                heapNode* top = minH.top();
                minH.pop();
                // Check if this heap entry matches current map state
                if (mp.find(top->key) != mp.end() &&
                    mp[top->key]->freq == top->freq &&
                    mp[top->key]->timestamp == top->timestamp) {

                    mp.erase(top->key);
                    break;
                }
            }
            // new node.
            AddInMap(key, value);
        } else {
            AddInMap(key, value);
        }
        
    };
};
    /**
     * Your LFUCache object will be instantiated and called as such:
     * LFUCache* obj = new LFUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */
