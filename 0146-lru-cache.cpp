class LRUCache {
private:
    struct Node {
        Node* next;
        Node* prev;
        int key;
        int val;
        Node(int k, int v):next(NULL), prev(NULL), key(k), val(v) {}
    };
    Node* head = NULL, *tail = NULL;
    unordered_map<int, Node*> dict;
    
    int capacity;
    
    void promote(Node*& p) {
        if (p != head) {
            Node* pn = p->next;
            Node* pp = p->prev;
            
            if (pn) {
                pn->prev = pp;
            }
            if (pp) {
                pp->next = pn;
            }
            
            if (p == tail) {
                tail = pp;
            }
            
            p->prev = NULL;
            p->next = head;
            head->prev = p;
            head = p;
        }
    }
    void evict() {
        tail->prev->next = NULL;
        Node* tmp = tail;
        tail = tail->prev;
        dict.erase(tmp->key);
        delete tmp;
    }

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
    }
    // tail->prev...next<-head
    int get(int key) {
        unordered_map<int, Node*>::iterator it = dict.find(key);
        if (it == dict.end()) return -1;
        
        Node* p = it->second;
        promote(p);
        return p->val;
    }
    
    void put(int key, int value) {
        unordered_map<int, Node*>::iterator it = dict.find(key);
        if (it != dict.end()) {
            Node* p = it->second;
            p->val = value;
            
            promote(p);
        } else {
            Node* p = new Node(key, value);
            if (head == NULL) {
                head = p, tail = p;
            } else {
                p->next = head;
                head->prev = p;
                head = p;
            }
            dict[key] = p;
            if (dict.size() > capacity) {
                evict();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
