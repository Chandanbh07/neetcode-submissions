class LRUCache {
   public:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;

        Node() {
            key = 0;
            val = 0;
            next = nullptr;
            prev = nullptr;
        }

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
    };

    unordered_map<int, Node*> mp;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int capacity = 0;

    LRUCache(int cap) {
        capacity = cap;

        head->prev = NULL;
        head->next = tail;

        tail->prev = head;
        tail->next = NULL;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* lru = mp[key];

        lru->prev->next = lru->next;
        lru->next->prev = lru->prev;

        Node* currLRU = head->next;

        head->next = lru;
        lru->prev = head;

        lru->next = currLRU;
        currLRU->prev = lru;

        return lru->val;
    }

    void put(int key, int value) {
        if(capacity == 0) return;
        
        if (mp.size() >= capacity && mp.find(key) == mp.end()) {
            Node* lru_node = tail->prev;

            lru_node->prev->next = lru_node->next;
            lru_node->next->prev = lru_node->prev;

            mp.erase(lru_node->key);
            delete (lru_node);
        }

        if (mp.count(key)) {
            Node* alter = mp[key];
            alter->val = value;

            alter->prev->next = alter->next;
            alter->next->prev = alter->prev;

            Node* currLRU = head->next;

            head->next = alter;
            alter->prev = head;

            alter->next = currLRU;
            currLRU->prev = alter;
        } else {
            Node* copy = new Node(key, value);

            mp[key] = copy;

            Node* currHead = head->next;

            head->next = copy;
            copy->prev = head;

            copy->next = currHead;
            currHead->prev = copy;
        }
    }
};
