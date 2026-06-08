class Node {
public:
    int key, val;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int cap;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {
        Node* afterHead = head->next;

        head->next = node;
        node->prev = head;

        node->next = afterHead;
        afterHead->prev = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        deleteNode(node);
        insertAfterHead(node);

        return node->val;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            node->val = value;

            deleteNode(node);
            insertAfterHead(node);

            return;
        }

        if (mp.size() == cap) {
            Node* lru = tail->prev;

            deleteNode(lru);
            mp.erase(lru->key);

            delete lru;
        }

        Node* newNode = new Node(key, value);

        insertAfterHead(newNode);

        mp[key] = newNode;
    }
};