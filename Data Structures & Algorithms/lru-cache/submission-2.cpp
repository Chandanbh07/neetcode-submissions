class LRUCache {
public:
    struct Node {
        int key, val;
        Node *prev, *next;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    LRUCache(int cap) {
        capacity = cap;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        removeNode(node);
        insertFront(node);

        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (mp.count(key)) {
            Node* node = mp[key];
            node->val = value;

            removeNode(node);
            insertFront(node);
        }
        else {
            if (mp.size() == capacity) {
                Node* lru = tail->prev;

                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }

            Node* node = new Node(key, value);
            insertFront(node);
            mp[key] = node;
        }
    }
};