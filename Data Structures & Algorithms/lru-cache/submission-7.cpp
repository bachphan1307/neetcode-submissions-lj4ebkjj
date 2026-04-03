struct Node{
    int key;
    int val;
    struct Node* prev;
    struct Node* next;
    Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
    int cap;
    unordered_map<int, Node*> hmap;
    // least to most (left to right)
    Node* lru,* mru;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
        lru = new Node(0,0);
        mru = new Node(0,0);
        lru -> next = mru;
        mru -> prev = lru;
    }
    void remove(Node* node){
        Node* nxt = node->next,* prv = node->prev;
        nxt -> prev =  prv;
        prv -> next = nxt;
        cap ++;
    }
    void add_to_last(Node* add){
        if(cap<=0){
            hmap.erase(lru->next->key);
            remove(lru->next);
        }
        add->next = mru;
        Node* tmp = mru->prev;
        mru->prev = add;
        add->prev = tmp;
        tmp->next = add;
        cap --;
    }
    int get(int key) {
        if(hmap.count(key) == 0) return -1;
        int res = hmap[key]->val;
        remove(hmap[key]);
        add_to_last(hmap[key]);
        return res;
    }
    
    void put(int key, int value) {
        if(hmap.count(key) == 0){
            Node* add = new Node(key, value);
            add_to_last(add);
            hmap[key] = add;
        }
        else{
            hmap[key]->val = value;
            remove(hmap[key]);
            add_to_last(hmap[key]);
        }
    }
};
